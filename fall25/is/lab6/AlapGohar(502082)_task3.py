
password = input("Enter the password: ")
found = False

with open("CommonPasswordList.txt", "r") as file:
    for line in file:   
        word = line.strip()
        if word == password:
            print(f"Password found in list: {word}")
            found = True
            break

if not found:
    print("Password not found in list.")
