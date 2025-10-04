import string


# ----------------------matrix construction--------------------------

keyword = input("KEYWORD: ").upper().replace('J', 'I')

# removing duplicates

seen = set()

# for keeping track of all the words that will be added to the matrix
matrix_list = []

for ch in keyword:
    if ch not in seen and ch in string.ascii_uppercase: # using string library for getting upepr case leters
        seen.add(ch)

        # skipping the duplicates adn adding side by side to the matrix list in an order
        matrix_list.append(ch)


# empty 5*5 matrix

matrix = [["" for _ in range(5)] for _ in range(5)]

# filling remaining letters into the matrix list
for ch in string.ascii_uppercase:
    if ch == 'J':
        continue
    if ch not in matrix_list:
        matrix_list.append(ch)

# populating usign nested loop
k = 0 # for keeping track of matrix list elements
for i in range(5):
    for j in range(5):
        matrix[i][j] = matrix_list[k]
        k += 1



# ---------------------creating diagraphs------------------

plaintext = input("PlainText: ").upper().replace('J' , 'I')
# removign spaces
stripped = "".join(ch for ch in plaintext if ch in string.ascii_uppercase)


diagraphs = []
i = 0

while i < len(stripped):
    a = stripped[i]

    # next letter
    if i + 1 < len(stripped):
        b = stripped[i+1]
    else:
        b = ""
    # same letters -> append x
    if a == b:
        diagraphs.append(a + "X")
    else:
        if b:
            # make a pair
            diagraphs.append(a + b)
            i += 2
        else:
            # pair with z at end
            diagraphs.append(a + "Z") # z at end
            i += 1
    

# --------------encryption-----------------

cipher = ""

for pair in diagraphs:
    a, b = pair[0], pair[1]

    # nexted looop for traversing the matrix adn retrieving coordiantes of both letters
    for r in range(5):
        for c in range(5):
            if matrix[r][c] == a:
                r1, c1 = r, c
            if matrix[r][c] == b:
                r2, c2 = r, c

    if r1 == r2: # same row
        cipher += matrix[r1][( c1 + 1 ) % 5] + matrix[r2][( c2 + 1 ) % 5] # mod 5 for wrapping around if necessarry
    elif c1 == c2:  # same column
        cipher += matrix[( r1 + 1 ) % 5][c1] + matrix[( r2 + 1 ) % 5][c2]
    else:  # rectangle
        cipher += matrix[r1][c2] + matrix[r2][c1]





print("\n\nKey: ", keyword)
print("\nKey Matrix: ")

for row in matrix:
    print(row)

print("\n\nPlainText: ", plaintext)
print("\nStrippedText: ", stripped)
print("\n\nDiagraphs: ", diagraphs)
print("\nCipherText: ", cipher)