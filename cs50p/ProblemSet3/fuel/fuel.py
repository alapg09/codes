while True:
    try:
        fraction = input("Fraction: ").strip()
        x, y = fraction.split("/")
        x = int(x)
        y = int(y)
        percent = round(x/y*100)
        if x >  y:
            continue
    except ValueError:
        pass
    except ZeroDivisionError:
        pass
    else:
        break


if percent <= 1:
    print("E")
elif percent >= 99:
    print("F")
else:
    print(percent, "%", sep = "")
