import re
import sys


def main():
    print(count(input("Text: ").strip()))


def count(s):
    groups = re.findall(r"\bum\b",s,re.IGNORECASE)
    return len(groups)





if __name__ == "__main__":
    main()
