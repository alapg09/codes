import string

# creating matrix similarly as taks1
keyword = input("KEYWORD: ").upper().replace('J', 'I')

seen = set()
matrix_list = []

for ch in keyword:
    if ch not in seen and ch in string.ascii_uppercase:
        seen.add(ch)
        matrix_list.append(ch)

matrix = [["" for _ in range(5)] for _ in range(5)]

for ch in string.ascii_uppercase:
    if ch == 'J':
        continue
    if ch not in matrix_list:
        matrix_list.append(ch)

k = 0
for i in range(5):
    for j in range(5):
        matrix[i][j] = matrix_list[k]
        k += 1



# ----------cipher input----------
ciphertext = input("CipherText: ").upper()

# strippign spaces
stripped = "".join(ch for ch in ciphertext if ch in string.ascii_uppercase)

# split into digraphs -- a lot simpler because no additions of x and z are required
digraphs = [stripped[i:i+2] for i in range(0, len(stripped), 2)]
# substring of cipher text of size 2 adn the step size of for loop is 2 to ensure correcr pairing




# ---------- Step 3: Decrypt ----------
plaintext = ""

for pair in digraphs:
    a, b = pair[0], pair[1]

    # find positions
    for r in range(5):
        for c in range(5):
            if matrix[r][c] == a:
                r1, c1 = r, c
            if matrix[r][c] == b:
                r2, c2 = r, c

    if r1 == r2:  # same row → take left
        plaintext += matrix[r1][(c1-1)%5] + matrix[r2][(c2-1)%5]
    elif c1 == c2:  # same column → take above
        plaintext += matrix[(r1-1)%5][c1] + matrix[(r2-1)%5][c2]
    else:  # rectangle rule
        plaintext += matrix[r1][c2] + matrix[r2][c1]



print("\n\nKey: ", keyword)
print("\nKey Matrix:")

for row in matrix:
    print(row)

print("\n\nCipherText: ", ciphertext)
print("\nStrippedText: ", stripped)
print("\n\nCipher Digraphs:", digraphs)
print("\nDecrypted Plaintext:", plaintext)
