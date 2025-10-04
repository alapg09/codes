
def levenshtein(s1, s2):
    m = len(s1)
    n = len(s2)

     # empty strings case
    if m == 0:
        return n
    if n == 0:
        return m

    # creating the matrix
    matrix = [[0 for _ in range(n+1)] for _ in range(m+1)]

    # first row and columnn
    for i in range(m+1):
        matrix[i][0] = i
    for j in range(n+1):
        matrix[0][j] = j

    # looping from secocnd column and row
    for i in range(1, m+1):
        for j in range(1, n+1):
            if s1[i - 1] == s2[j - 1]:  # same letters
                matrix[i][j] = matrix[i - 1][j - 1] # assign the diagonal value
            else:
                matrix[i][j] = 1 + min(matrix[i][j-1], matrix[i - 1][ j], matrix[i-1][j - 1]) # choosing min from tip, left, diagonal
 
    # backtracking to count operations
    i, j = m, n
    insertions = deletions = substitutions = 0
    while i > 0 or j > 0:
        if i > 0 and j > 0 and s1[i - 1] == s2[j - 1]:
            i -= 1
            j -= 1
        elif i > 0 and j > 0 and matrix[i][j] == matrix[i - 1][j - 1] + 1:
            substitutions += 1
            i -= 1
            j -= 1
        elif i > 0 and matrix[i][j] == matrix[i - 1][j] + 1:
            deletions += 1
            i -= 1
        elif j > 0 and matrix[i][j] == matrix[i][j - 1] + 1:
            insertions += 1
            j -= 1

    for row in matrix:
        print(row)
    
    print("\n\n")
    print(f"Levenshtein Distance: {matrix[m][n]}")
    print("\n")
    print(f"Insertions: {insertions}")
    print(f"Deletions: {deletions}")
    print(f"Substitutions: {substitutions}")


def main():
    str1 = "kitten"
    str2 = "sitting"

    levenshtein(str1, str2)
    


if __name__ == "__main__":
    main()