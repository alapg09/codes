from pyfiglet import Figlet
import sys
import random

figlet = Figlet()
fonts = figlet.getFonts()

if len(sys.argv) == 1:
    # random
    max = len(fonts)
    index = random.randint(0, max - 1)
    figlet.setFont(font = fonts[index])

elif len(sys.argv) == 3:
    # input validation
    if sys.argv[1] != "-f" and sys.argv[1] != "--font" :
        sys.exit("Not a valid argument")

    # font selection
    if not sys.argv[2] in fonts:
        sys.exit("Invalid Font Name")
    else:
        figlet.setFont(font = sys.argv[2])
else:
    sys.exit("Invalid number of arguments")


s = input("Input: ")

print(figlet.renderText(s))

