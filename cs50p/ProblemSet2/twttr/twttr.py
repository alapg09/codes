def isvowel(c):
    c = c.lower()
    return c == "a" or c == "e" or c == "i" or c == "o" or c == "u"

def main():
    text = input("Input: ").strip()

    short = ""
    for t in text:
        if isvowel(t):
            continue
        else:
            short += t

    print("Output:", short)



main()
