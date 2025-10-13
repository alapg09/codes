# Alap Gohar - 502082

import math

def encrypt(message, key):

    cols = len(key)
    rows = math.ceil(len(message) / cols)

    # populate grid row by row -- i included spaces
    grid = [[' ' for _ in range(cols)] for _ in range(rows)]
    index = 0 # keeping track of msg len
    for r in range(rows):
        for c in range(cols):
            if index < len(message):
                grid[r][c] = message[index]
                index += 1

    # determining column order 
    key_list = list(key)
    sorted_key = sorted(key_list)
    col_order = []
    for letter in sorted_key:
        col_order.append(key_list.index(letter))
        key_list[key_list.index(letter)] = '_'  # mark used letter for duplicate detection

    # read columns in sorted order
    ciphertext = ""
    for c in col_order:
        for r in range(rows):
            ciphertext += grid[r][c]

    return ciphertext, grid, col_order


def decrypt(ciphertext, key):
    cols = len(key)
    rows = math.ceil(len(ciphertext) / cols)

    key_list = list(key)
    sorted_key = sorted(key_list)
    col_order = []
    for letter in sorted_key:
        col_order.append(key_list.index(letter))
        key_list[key_list.index(letter)] = '_'

    # make empty grid
    grid = [[' ' for _ in range(cols)] for _ in range(rows)]

    # fill columns in the same sorted order
    index = 0
    for c in col_order:
        for r in range(rows):
            if index < len(ciphertext):
                grid[r][c] = ciphertext[index]
                index += 1

    # read row by row to get plaintext
    plaintext = ""
    for r in range(rows):
        for c in range(cols):
            plaintext += grid[r][c]

    return plaintext.strip(), grid


def main():
    message = "Believe you can and you are halfway there"
    key = "GREAT"

    ciphertext, enc_grid, order = encrypt(message, key)
    decrypted, dec_grid = decrypt(ciphertext, key)

    print("Plaintext :", message)
    print("Key       :", key)

    print("\nEncryption Grid:")
    for row in enc_grid:
        print(row)

    print("\nColumn Order:", order)
    print("Ciphertext  :", ciphertext)

    print("\nDecryption Grid:")
    for row in dec_grid:
        print(row)

    print("\nDecrypted   :", decrypted)


if __name__ == "__main__":
    main()

# Alap Gohar - 502082
