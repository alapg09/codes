import csv  # parsing the csv
from datetime import datetime
import heapq
import math
import json
from pathlib import Path

# constatns
GRID_ROWS = GRID_COLS = 10
FIRE_STATIONS = [(1, 1), (10, 10)]
CELL_METERS = 100.0  # 100 m per grid cell
DEFAULT_SPEED_KMH = 36.0  # default when no road record exists -- indicating an open road

# conversion: cells/min = speed_kmh / 6 (since 1 cell = 0.1 km => speed_kmh/60/0.1)
def kmh_to_cells_per_min(kmh):
    return float(kmh) / 6.0

DEFAULT_SPEED_CELLS_PER_MIN = kmh_to_cells_per_min(DEFAULT_SPEED_KMH)


# file loccations
ROADS_CSV = Path("roads.csv")
EMERGENCY_CSV = Path("emergency.csv")
OUTPUT_CSV = Path("results.csv")


# these are the helpign
def parse_coord(txt):
    s = txt.strip()
    if s.startswith("(") and s.endswith(")"):
        s = s[1:-1]
    parts = s.split(",")
    return (int(parts[0]), int(parts[1]))

def time_to_min(tstr):
    # H:MM or HH:MM; returns minutes since midnight
    tstr = tstr.strip()
    try:
        dt = datetime.strptime(tstr, "%H:%M")
    except ValueError:
        # try H:M variants (though %H:%M handles)
        dt = datetime.strptime(tstr, "%H:%M")
    return dt.hour * 60 + dt.minute

# edge records: for each directed edge key (u,v) we store sorted list of snapshots:
# records[(u,v)] = [ (time_min, status_str, speed_cells_per_min), ... ] sorted by time_min ascending
records = {}

def add_record(u, v, time_min, status, speed_kmh):
    key = (u, v)
    speed_cells = None
    if status.lower() == "open" and (speed_kmh is not None):
        # speed_kmh might be 'N/A' or empty when blocked
        speed_cells = kmh_to_cells_per_min(float(speed_kmh))
    elif status.lower() == "open" and (speed_kmh is None):
        speed_cells = DEFAULT_SPEED_CELLS_PER_MIN
    else:
        speed_cells = None
    records.setdefault(key, []).append((time_min, status.lower(), speed_cells))

def finalize_records():
    # sort lists by time
    for k in list(records.keys()):
        records[k].sort(key=lambda x: x[0])

def get_snapshot(u, v, time_min):
    
    # Return (status, speed_cells_per_min) for edge (u,v) at given time_min.
    # if records[(u,v)] exists: pick last snapshot with time <= time_min; if none, pick earliest.
    # else, try (v,u) as fallback.
    # if none present anywhere, return ('open', DEFAULT_SPEED_CELLS_PER_MIN)
    
    def pick_from_list(lst):
        # lst sorted ascending times
        chosen = None
        for t, st, sp in lst:
            if t <= time_min:
                chosen = (t, st, sp)
            else:
                break
        if chosen is None:
            # take earliest snapshot
            t, st, sp = lst[0]
            return (st, sp)
        else:
            return (chosen[1], chosen[2])

    key = (u, v)
    if key in records and records[key]:
        return pick_from_list(records[key])
    key_rev = (v, u)
    if key_rev in records and records[key_rev]:
        # assume reverse direction snapshot is acceptable fallback
        return pick_from_list(records[key_rev])
    # no data at all -> default open speed
    return ("open", DEFAULT_SPEED_CELLS_PER_MIN)


if not ROADS_CSV.exists():
    raise FileNotFoundError(f"{ROADS_CSV} not found in current directory.")

with ROADS_CSV.open(newline='', encoding='utf-8') as f:
    reader = csv.DictReader(f)
    # Road Segment Start,Road Segment End,Status,Current Speed (km/h),Time
    for row in reader:
        raw_u = row.get("Road Segment Start") or row.get("Road SegmentStart") or row.get("Start")
        raw_v = row.get("Road Segment End") or row.get("Road SegmentEnd") or row.get("End")
        status = row.get("Status", "").strip()
        speed_raw = row.get("Current Speed (km/h)") or row.get("Current Speed") or row.get("Speed (km/h)") or row.get("Speed")
        time_raw = row.get("Time") or row.get("time") or "0:00"
        if not raw_u or not raw_v or not status:
            # skip malformed
            continue
        try:
            u = parse_coord(raw_u)
            v = parse_coord(raw_v)
        except Exception as e:
            # skip if bad coords
            continue
        tr_min = time_to_min(time_raw)
        # Normalize speed: treat 'N/A' or empty as None
        speed_kmh = None
        if speed_raw is not None:
            speed_raw = speed_raw.strip()
            if speed_raw.upper() not in ("N/A", "", "NA"):
                try:
                    speed_kmh = float(speed_raw)
                except:
                    speed_kmh = None
        add_record(u, v, tr_min, status, speed_kmh)

finalize_records()

# compute maximum observed speed (cells/min) for admissible heuristic scaling
max_speed_cells = DEFAULT_SPEED_CELLS_PER_MIN
for lst in records.values():
    for t, st, sp in lst:
        if sp is not None and sp > max_speed_cells:
            max_speed_cells = sp

# time-dependent A* search


def neighbors(node):
    r, c = node
    for dr, dc in [(1,0),(-1,0),(0,1),(0,-1)]: # direction vectors
        nr, nc = r+dr, c+dc
        if 1 <= nr <= GRID_ROWS and 1 <= nc <= GRID_COLS:
            yield (nr, nc) # returns one by one while maintain ig the current state of the ftn

def heuristic(a, b):
    # anhattan distance / max_speed_cells => lower-bound time in minutes
    md = abs(a[0]-b[0]) + abs(a[1]-b[1])
    # avoid division by zero
    if max_speed_cells <= 1e-6:
        return md / DEFAULT_SPEED_CELLS_PER_MIN
    return md / max_speed_cells

def traversal_time(u, v, current_time_min):
    # get snapshot at time current_time_min (start time of traversing this edge)
    status, speed_cells = get_snapshot(u, v, current_time_min)
    if status == "blocked":
        return math.inf
    if speed_cells is None or speed_cells <= 0:
        return math.inf
    # each edge length = 1 cell -> time = 1 / speed_cells (minutes)
    return 1.0 / speed_cells

def astar_time_dependent(start, goal, start_time_min=0, max_search_nodes=20000):
    # returns dict {'path': [nodes], 'time': travel_time_minutes} or None if no route
    open_heap = []
    # heap items: (f_score, g_score, node, path)
    start_h = heuristic(start, goal)
    heapq.heappush(open_heap, (start_h, 0.0, start, [start]))
    g_scores = {start: 0.0}
    visited = 0
    while open_heap:
        f, g, node, path = heapq.heappop(open_heap)
        visited += 1
        if visited > max_search_nodes:
            break
        if node == goal:
            return {"path": path, "time": g}
        for nb in neighbors(node):
            # compute time to traverse node->nb given traversal starts at start_time_min + g
            t_edge = traversal_time(node, nb, start_time_min + g)
            if t_edge == math.inf:
                continue
            ng = g + t_edge
            if nb not in g_scores or ng < g_scores[nb]:
                g_scores[nb] = ng
                fscore = ng + heuristic(nb, goal)
                heapq.heappush(open_heap, (fscore, ng, nb, path + [nb]))
    return None


if not EMERGENCY_CSV.exists():
    raise FileNotFoundError(f"{EMERGENCY_CSV} not found in current directory.")

emergencies = []
with EMERGENCY_CSV.open(newline='', encoding='utf-8') as f:
    reader = csv.DictReader(f)
    # columns: Emergency Site,Coordinates,Time
    for row in reader:
        name = row.get("Emergency Site") or row.get("Site") or row.get("Name")
        coord_raw = row.get("Coordinates") or row.get("Coordinate") or row.get("Coords")
        time_raw = row.get("Time") or row.get("time") or "0:00"
        if not coord_raw:
            continue
        try:
            loc = parse_coord(coord_raw)
        except:
            continue
        tmin = time_to_min(time_raw)
        emergencies.append({"name": name or "", "loc": loc, "time_min": tmin, "time_str": time_raw})

# for each emergency, find best station route (lowest travel time)
results = []
for e in emergencies:
    best = None
    for st in FIRE_STATIONS:
        res = astar_time_dependent(st, e["loc"], start_time_min=e["time_min"])
        if res is None:
            continue
        if best is None or res["time"] < best["time"]:
            best = {"station": st, "path": res["path"], "time": res["time"]}
    if best is None:
        results.append({
            "Site": e["name"],
            "Coordinates": f"{e['loc']}",
            "CallTime": e["time_str"],
            "Station": "none",
            "TravelTimeMin": "",
            "Path": ""
        })
    else:
        results.append({
            "Site": e["name"],
            "Coordinates": f"{e['loc']}",
            "CallTime": e["time_str"],
            "Station": str(best["station"]),
            "TravelTimeMin": round(best["time"], 4),
            "Path": json.dumps(best["path"])
        })

# saving th eresults
with OUTPUT_CSV.open("w", newline='', encoding='utf-8') as f:
    fieldnames = ["Site", "Coordinates", "CallTime", "Station", "TravelTimeMin", "Path"]
    writer = csv.DictWriter(f, fieldnames=fieldnames)
    writer.writeheader()
    for r in results:
        writer.writerow(r)

# print summary
print(f"Wrote {len(results)} results to {OUTPUT_CSV}\n")
for r in results:
    print(f"Site: {r['Site']:12s} Loc: {r['Coordinates']:10s} Time: {r['CallTime']:6s} -> Station: {r['Station']:10s} Travel (min): {r['TravelTimeMin']}")
