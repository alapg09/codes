items = {
    "Baja Taco": 4.25,
    "Burrito": 7.50,
    "Bowl": 8.50,
    "Nachos": 11.00,
    "Quesadilla": 8.50,
    "Super Burrito": 8.50,
    "Super Quesadilla": 9.50,
    "Taco": 3.00,
    "Tortilla Salad": 8.00
}

total_cost = 0
while True:
    try:
        order_item = input("Item: ").strip().title()
    except EOFError:
        print("\n")
        break
    except KeyError:
        pass
    else:
        if order_item in items:
            total_cost += items[order_item]
        print(f"Total: ${total_cost:.2f}")
        continue


print("\n", end = "")
