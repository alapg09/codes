import itertools
import string
import time # noting time

# timer for keeping note of time
start_time = time.time()

password = input("Enter the password (1-4 lowercase letters): ")


letters = string.ascii_lowercase    # all lowecase
found = False

# generating the comibnations required 1-4 letters
for length in range(1, 5):
    for guess in itertools.product(letters, repeat=length):
        attempt = ''.join(guess)    # constructig the string
        if attempt == password:
            print(f"Password found: {attempt}")
            print(f"Time taken: {time.time() - start_time:.2f} seconds")
            found = True
            break
    if found:
        break

if not found:
    print("Password not found within 4 letters.")
