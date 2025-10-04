months = [
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
]


while True:
    mmddyyyy = input("Date: ").strip().title()
    try:
        mm, dd, yyyy = mmddyyyy.split("/")
        if not mm.isdigit():
            continue
    except ValueError:
        try:
            parts = mmddyyyy.split()
            if not "," in parts[1]:
                continue
            mm = parts[0]
            dd = int(parts[1].strip(','))
            yyyy = int(parts[2])
        except ValueError:
            pass
        else:
            if mm in months:
                mm = months.index(mm) + 1
            else:
                continue

            if mm > 12:
                continue
            if dd > 31:
                continue
            break
    else:
        mm = int(mm)
        dd = int(dd)
        if dd > 31:
            continue
        if mm > 12:
            continue
        yyyy = int(yyyy)
        break



print(f"{yyyy}-{mm:02}-{dd:02}")
