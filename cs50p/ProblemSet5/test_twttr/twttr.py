def main():
    text = input("Text: ").strip()
    short = shorten(text)

    print("Output:", short)

def isvowel(c):
    c = c.lower()
    return c == "a" or c == "e" or c == "i" or c == "o" or c == "u"


def shorten(word):

    short = ""
    for t in word:
        if isvowel(t):
            continue
        else:
            short += t

    return short




if __name__ == "__main__":
    main()
