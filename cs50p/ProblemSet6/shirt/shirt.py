
import sys
from PIL import Image, ImageOps

import os

if len(sys.argv) < 3:
    sys.exit("too few arguments")
elif len(sys.argv) > 3:
    sys.exit("too many arguments")

ext1 = os.path.splitext(sys.argv[1])[1]
ext2 = os.path.splitext(sys.argv[2])[1]

if ext1 != ext2:
    sys.exit("The files have different extensions")


try:
    shirt = Image.open("shirt.png")
    photo = Image.open(sys.argv[1])


    output_image = ImageOps.fit(photo, shirt.size, method=Image.Resampling.BICUBIC)

    output_image.paste(shirt, (0, 0), shirt)

    output_image.save(sys.argv[2])

except FileNotFoundError:
    sys.exit("file not found")
