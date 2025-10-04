import random

while True:
    try:
        level = int(input("Level: "))
    except ValueError:
        continue
    if level < 1 :
        continue
    break


random_number = random.randint(1, level)

while True:
    try:
        guess = int(input("Guess: "))
    except ValueError:
        continue
    if guess < 1:
        continue
    if guess > level:
        print("Too Large!")
        continue
    break



if guess == random_number:
    print("Just Right!")
elif guess < random_number:
    while True:
        print("Too small!")
        guess = int(input("Guess: "))
        if guess == random_number:
            print("Just Right")
            break
else:
    while True:
        print("Too Large!")
        guess = int(input("Guess: "))
        if guess == random_number:
            print("Just Right")
            break
