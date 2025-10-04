import sys
import csv

if len(sys.argv) < 3:
    sys.exit("Too few arguments")
elif len(sys.argv) > 3:
    sys.exit("Too many arguments")

try:
    with open(sys.argv[1]) as infile:
        reader = csv.DictReader(infile)

        with open(sys.argv[2], "w") as file:

            writer = csv.DictWriter(file, fieldnames = ["first", "last", "house"])

            writer.writeheader()

            for row in reader:
                last, first = row['name'].split(",")
                last = last.strip()
                first = first.strip()

                writer.writerow({"first": first, "last": last, "house": row["house"]})




except FileNotFoundError:
    sys.exit(f"Could not read {sys.argv[1]}")



