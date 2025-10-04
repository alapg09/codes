import sys
import csv
from tabulate import tabulate

if len(sys.argv) < 2:
    sys.exit("Too few command-line arguments")
elif len(sys.argv) > 2:
    sys.exit("Too many command-line arguments")
if not sys.argv[1].endswith(".csv"):
    sys.exit("Not a csv file")

table = []
try:
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            table.append(row)
        if not table:
            sys.exit("CSV file is empty")


    print(tabulate(table, headers = "keys", tablefmt="grid"))


except FileNotFoundError:
    sys.exit("FILE NOT FOUND")
