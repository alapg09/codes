items = {}

while True:
    try:
        item = input().strip().upper()
    except EOFError:
        break
    else:
        if item in items:
            items[item] += 1
        else:
            items[item] = 1


sorted_items = sorted(items.items())
print("\n")
for key, value in sorted_items:
    print(value, key)





