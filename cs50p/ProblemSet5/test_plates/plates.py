def main():
    plate = input("Plate: ").strip()
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):

    if len(s) > 6 or len(s) < 2:
        return False

    for i in range(len(s)):
        if s[i].isalnum() == False:
            return False

        if s[i].isdigit():
            if len(s[0:i]) < 2:
                return False
            for j in range(i, len(s)):
                if s[j].isalpha():
                    return False
    index = 0
    for i in range(len(s)):
        if s[i].isdigit():
            index = i
            break
    if s[index] == '0':
        return False

    return True

if __name__ == "__main__":
    main()
