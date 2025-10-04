ans = input("What is the Answer to the Great Question of Life, the Universe, and Everything? ")

# converting to lower case for case-insensitivity and ambiguity
ans = ans.lower().strip()

# checking all cases
if ans == "42" or ans == "forty two" or ans == "forty-two":
    print("Yes")

else:
    print("No")
