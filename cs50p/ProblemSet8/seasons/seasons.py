from datetime import date
import sys
import re
import inflect

p = inflect.engine()

def main():
    dob = input("Date of Birth: ").strip()
    yyyy, mm, dd = validate(dob)
    date_of_birth = date(yyyy, mm, dd)
    current_date = date.today()
    time = current_date - date_of_birth

    days = time.days

    minutes = days*24*60
    print(p.number_to_words(minutes, andword="").capitalize(), "minutes")






def validate(s):
    matches = re.search(r"(\d{4})-(\d{2})-(\d{2})", s)
    if matches:
        yyyy = int(matches.group(1))
        mm = int(matches.group(2))
        dd = int(matches.group(3))
        date_objects = [yyyy, mm, dd]
        return date_objects
    else:
        sys.exit("Invalid Date Format")

    return False



if __name__ == "__main__":
    main()
