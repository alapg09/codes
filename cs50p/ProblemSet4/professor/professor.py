import random


def main():
    level = get_level()
    correct = 0
    for _ in range(10):

        n1 = generate_integer(level)
        n2 = generate_integer(level)

        while True:
            try:
                answer = int(input(f"{n1} + {n2} = "))
            except ValueError:
                print("EEE")
            else:
                break

        if answer == n1 + n2 :
            correct += 1
            continue
        else:
            counter = 0
            while True:
                print("EEE")
                counter += 1
                if counter == 3:
                    print(n1 , "+", n2, "=", n1 + n2)
                    break
                while True:
                    try:
                        answer = int(input(f"{n1} + {n2} = "))
                    except ValueError:
                        print("EEE")
                        counter += 1
                    else:
                        break
                if answer == n1+n2:
                    correct += 1
                    break

    print("Score:", correct)





def get_level():
    while True:
        try:
            level = int(input("Level: "))
        except ValueError:
            continue

        if level != 1 and level != 2 and level != 3:
            continue

        return level


def generate_integer(level):
    if level == 1:
        return random.randint(0, 9)
    elif level == 2:
        return random.randint(10 , 99)
    elif level == 3:
        return random.randint(100, 999)
    else:
        raise ValueError


if __name__ == "__main__":
    main()
