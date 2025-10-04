import inflect
p = inflect.engine()
names = []
while True:
    try:
        name = input("Name: ").strip().title()
        names.append(name)
    except EOFError:
        break
farewell = p.join(names)

print(f"Adieu, adieu, to {farewell}")
