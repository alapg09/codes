
import sys

if len(sys.argv) < 2:
    sys.exit("Too few command line arguments")

elif len(sys.argv) > 2:
    sys.exit("Too many command line arguments")

if not sys.argv[1].endswith(".py"):
    sys.exit("Not a Python file")

try:

    line_counter = 0

    with open(sys.argv[1]) as file:



        for line in file:

            line = line.strip()

            try:
                if line[0] != '#':
                    line_counter += 1

            except IndexError:
                pass

except FileNotFoundError:
    sys.exit("File does not exist")

else:
    print(line_counter)
