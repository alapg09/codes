expression = input("Expression: ").lower().strip()

x, y, z = expression.split(" ")

match y:
    case "+":
        print(f"{float(x) + float(z) :.1f}")
    case "-":
        print(f"{float(x) - float(z) :.1f}")
    case "*":
        print(f"{float(x) * float(z) :.1f}")
    case "/":
        print(f"{float(x) / float(z) :.1f}")
    case _:
        print("Invalid Operator")

