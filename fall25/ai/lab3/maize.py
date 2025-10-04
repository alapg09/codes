import heapq    # for priority queue

class RobotVacuumAStar:
    def __init__(self, house, start, goal):
        self.house = house  # grid with free cells ( ) and obstacles (#)
        self.start = start  # dock position
        self.goal = goal    # dirty spot

        self.height = len(house)
        self.width = len(house[0])

    def heuristic(self, pos): # calculates the manhattan distance --> manhattan is calculating by comparing the x and y coordinates and adding the absolute differencies
        return abs(pos[0] - self.goal[0]) + abs(pos[1] - self.goal[1])

    def get_neighbors(self, pos):
        x, y = pos
        moves = [(0,1),(0,-1),(1,0),(-1,0)]  # right, left, down, up
        result = []
        for dx, dy in moves:
            nx, ny = x + dx, y + dy # checking next cells
            if 0 <= nx < self.height and 0 <= ny < self.width:
                if self.house[nx][ny] != "#":   # not furniture
                    result.append((nx, ny))
        return result

    def a_star(self):
        """
        Implements the A* search algorithm to find the shortest path from start to goal.
        
        Uses a priority queue (min-heap) to always expand the node with the lowest estimated total cost f = g + h:
            - g: actual cost from start to current node
            - h: heuristic estimate from current node to goal
            - f = g + h: total estimated cost
        Returns:
            - path: list of positions from start to goal
            - g: total cost of the path
        """
    
        # initialize priority queue (min-heap) with the start node
        # each element is a tuple: (f, g, position, path_so_far)
        # f = estimated total cost = g + h
        # g = cost from start to current position (initially 0)
        # position = current node
        # path = list of nodes visited to reach this node
        open_list = [(self.heuristic(self.start), 0, self.start, [self.start])]
        
        # Set to keep track of visited nodes to avoid revisiting them
        visited = set()

        # Main loop: continue until there are no more nodes to explore
        while open_list:
            # Pop the node with the smallest f value from the priority queue
            est, g, pos, path = heapq.heappop(open_list)

            # Check if the current position is the goal
            if pos == self.goal:
                # Goal reached: return the path and its total cost
                return path, g

            # If this position has already been visited, skip it
            if pos in visited:
                continue
            visited.add(pos)

            # Explore all neighbors of the current position
            for n in self.get_neighbors(pos):
                # Calculate new cost to reach neighbor: assume uniform cost of 1 per move
                new_cost = g + 1
                
                # Calculate estimated total cost f = g + h for the neighbor
                est_total = new_cost + self.heuristic(n)
                
                # Add the neighbor to the priority queue with updated cost and path
                # path + [n] creates a new path list including this neighbor
                heapq.heappush(open_list, (est_total, new_cost, n, path + [n]))

        # If the loop ends without finding the goal, return None and infinite cost
        return None, float("inf")



# House grid (5x6)
# ' ' = empty floor
# '#' = furniture/obstacle
house = [
    list("      "),  # row 0
    list(" ###  "),  # row 1
    list("   #  "),  # row 2
    list(" #    "),  # row 3
    list("     #")   # row 4
]


start = (0, 0)   # Robot dock
goal = (4, 4)    # Dirty spot

agent = RobotVacuumAStar(house, start, goal)
path, cost = agent.a_star()

print("Robot path:", path)
print("Steps required:", cost)

