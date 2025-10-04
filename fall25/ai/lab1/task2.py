def levenshtein_words(ref_words, hyp_words):
    m, n = len(ref_words), len(hyp_words)

    if m == 0:
        return n, 0, n, 0
    if n == 0:
        return m, m, 0, 0

    matrix = [[0 for _ in range(n+1)] for _ in range(m+1)]

    for i in range(m+1):
        matrix[i][0] = i
    for j in range(n+1):
        matrix[0][j] = j

    for i in range(1, m+1):
        for j in range(1, n+1):
            if ref_words[i-1] == hyp_words[j-1]:    # comparing words
                matrix[i][j] = matrix[i-1][j-1]
            else:
                matrix[i][j] = 1 + min(
                    matrix[i][j-1],    
                    matrix[i-1][j],     
                    matrix[i-1][j-1]    
                )

    
    i, j = m, n
    insertions = deletions = substitutions = 0
    while i > 0 or j > 0:
        if i > 0 and j > 0 and ref_words[i-1] == hyp_words[j-1]:
            i -= 1
            j -= 1
        elif i > 0 and j > 0 and matrix[i][j] == matrix[i-1][j-1] + 1:
            substitutions += 1
            i -= 1
            j -= 1
        elif i > 0 and matrix[i][j] == matrix[i-1][j] + 1:
            deletions += 1
            i -= 1
        elif j > 0 and matrix[i][j] == matrix[i][j-1] + 1:
            insertions += 1
            j -= 1

    return matrix[m][n], insertions, deletions, substitutions


def main():
    # read files
    with open("d:\\MyCODES\\fall25\\ai\\lab1\\reference.txt", "r") as f:
        reference = f.read().strip().split()

    with open("d:\\MyCODES\\fall25\\ai\\lab1\\hypothesis.txt", "r") as f:
        hypothesis = f.read().strip().split()

    # compute word-level Levenshtein
    distance, ins, dele, subs = levenshtein_words(reference, hypothesis)

    # write to result.txt
    with open("d:\\MyCODES\\fall25\\ai\\lab1\\result.txt", "w") as f:
        f.write(f"Levenshtein distance is {distance}\n")
        f.write(f"Insertions {ins}\n")
        f.write(f"Deletions {dele}\n")
        f.write(f"Substitutions {subs}\n")

    print("Result written to result.txt")


if __name__ == "__main__":
    main()
