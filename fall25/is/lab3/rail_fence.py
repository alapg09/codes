import math

# quick helper to display the fence in a readable way
def show_matrix(mat):
    for row in mat:
        # I like using '.' to show blanks so it's easier to see gaps
        print(' '.join(ch if ch != ' ' else '.' for ch in row))
    print("")   # add some breathing space


def rail_fence_encrypt(msg, rails):
    # remove spaces & uppercase for simplicity
    cleaned = ''.join(msg.split()).upper()
    length = len(cleaned)

    if rails <= 1:
        return cleaned   # trivial case, nothing to do

    cycle_len = 2 * (rails - 1)
    # I overcompensated here by forcing a multiple of cycle_len
    total_cols = math.ceil(length / cycle_len) * cycle_len

    # pad with X if needed
    if len(cleaned) < total_cols:
        cleaned += "X" * (total_cols - len(cleaned))

    # create empty grid (rows = rails, cols = text length)
    cols = len(cleaned)
    fence = [[' ' for _ in range(cols)] for _ in range(rails)]

    row = 0
    direction = 1  # 1 = going down, -1 = going up
    for col, ch in enumerate(cleaned):
        fence[row][col] = ch
        row += direction
        if row == rails - 1:
            direction = -1
        elif row == 0:
            direction = 1

    print("=== Encryption matrix ===")
    show_matrix(fence)

    # flatten row by row (ignoring spaces)
    cipher = ''
    for r in fence:
        cipher += ''.join(x for x in r if x != ' ')

    return cipher


def rail_fence_decrypt(cipher, rails):
    n = len(cipher)
    if rails <= 1:
        return cipher

    # figure out zigzag path (which row for each col)
    row, dirn = 0, 1
    zigzag_path = []
    for i in range(n):
        zigzag_path.append(row)
        row += dirn
        if row == rails - 1:
            dirn = -1
        elif row == 0:
            dirn = 1

    # build empty matrix with placeholders
    fence = [[' ' for _ in range(n)] for _ in range(rails)]
    for c, r in enumerate(zigzag_path):
        fence[r][c] = '*'

    print("=== Decryption placeholders ===")
    show_matrix(fence)

    # fill placeholders row by row with cipher chars
    idx = 0
    for r in range(rails):
        for c in range(n):
            if fence[r][c] == '*' and idx < n:
                fence[r][c] = cipher[idx]
                idx += 1

    print("=== Filled matrix ===")
    show_matrix(fence)

    # now rebuild plaintext following zigzag path
    plain_chars = []
    for c in range(n):
        r = zigzag_path[c]
        plain_chars.append(fence[r][c])

    return ''.join(plain_chars)


def try_all_keys(cipher):
    print("=== Brute force trial ===")
    guesses = []
    for k in range(2, len(cipher)+1):
        attempt = rail_fence_decrypt(cipher, k)
        print(f"Key {k:2d} -> {attempt}")
        guesses.append((k, attempt))
    return guesses


if __name__ == "__main__":
    # --- Task 1 ---
    text = "defend the east wall"
    print("Plaintext :", text)
    enc = rail_fence_encrypt(text, 3)
    print("Ciphertext:", enc)
    dec = rail_fence_decrypt(enc, 3)
    print("Decrypted (raw):", dec)
    print("Decrypted (strip Xs):", dec.rstrip("X"))
    print("\n" + "="*40 + "\n")

    # --- Task 2 ---
    test_cases = ["HOLELWRDLOX", "AAXTKTNXTCDWXAAX", "CYTGAHRPORPY"]
    for ctext in test_cases:
        print(f"\nCiphertext: {ctext}")
        try_all_keys(ctext)
        print("-"*40)
