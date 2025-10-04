import re
import sys


def main():
    print(convert(input("Hours: ").strip()))

 
def convert(s):
    matches =  re.search(r"^([0-9]{1,2})(:([0-9]{2}))?\s(AM|PM)\sto\s([0-9]{1,2})(:([0-9]{2}))?\s(AM|PM)$", s)
    if matches:
        start_h = int(matches.group(1))
        start_m = int(matches.group(3) or 0)
        zone_start =    matches.group(4)

        end_h = int(matches.group(5))
        end_m = int(matches.group(7) or 0)
        zone_end = matches.group(8)

        if not (0 <= start_m < 60 and 0 <= end_m < 60):
            raise ValueError


        if zone_start == "PM" and start_h != 12:
                start_h += 12
        if zone_start == "AM" and start_h == 12:
            start_h = 0

        if zone_end == "PM" and end_h != 12:
                end_h += 12
        if zone_end == "AM" and end_h == 12:
            end_h = 0

        return f"{start_h:02}:{start_m:02} to {end_h:02}:{end_m:02}"

    else:
        raise ValueError





if __name__ == "__main__":
    main()
