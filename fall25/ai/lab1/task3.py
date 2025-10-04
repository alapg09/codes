# ------------------------TASK3----------------------------

def levenshtein_words_ignore(ref_words, hyp_words, ignore_words):
    m, n = len(ref_words), len(hyp_words)

    # DP matrix
    matrix = [[0 for _ in range(n+1)] for _ in range(m+1)]
    for i in range(m+1):
        matrix[i][0] = i
    for j in range(n+1):
        matrix[0][j] = j

    # fill DP but also look for ignore word
    for i in range(1, m+1):
        for j in range(1, n+1):
            if ref_words[i-1] == hyp_words[j-1]:
                matrix[i][j] = matrix[i-1][j-1]
            else:
                cost_sub = 1
                if ref_words[i-1] in ignore_words and hyp_words[j-1] in ignore_words:
                    cost_sub = 0  # ignore substitution

                cost_del = 0 if ref_words[i-1] in ignore_words else 1
                cost_ins = 0 if hyp_words[j-1] in ignore_words else 1

                matrix[i][j] = min(
                    matrix[i-1][j] + cost_del,      # deletion # isntead of adding 1, we add the cost_sub which will be zero of the woeds are ignore words
                    matrix[i][j-1] + cost_ins,      # insertion
                    matrix[i-1][j-1] + cost_sub     # substitution
                )

    # backtrack with same cost rules
    i, j = m, n
    insertions = deletions = substitutions = 0

    while i > 0 or j > 0:
        if i > 0 and j > 0 and ref_words[i-1] == hyp_words[j-1]:
            i -= 1
            j -= 1
        else:
            # recompute costs for this cell
            cost_sub = 1
            if i > 0 and j > 0 and ref_words[i-1] in ignore_words and hyp_words[j-1] in ignore_words:
                cost_sub = 0

            cost_del = 1
            if i > 0 and ref_words[i-1] in ignore_words:
                cost_del = 0

            cost_ins = 1
            if j > 0 and hyp_words[j-1] in ignore_words:
                cost_ins = 0

            if i > 0 and j > 0 and matrix[i][j] == matrix[i-1][j-1] + cost_sub:
                if cost_sub == 1:
                    substitutions += 1
                i -= 1
                j -= 1
            elif i > 0 and matrix[i][j] == matrix[i-1][j] + cost_del:
                if cost_del == 1:
                    deletions += 1
                i -= 1
            elif j > 0 and matrix[i][j] == matrix[i][j-1] + cost_ins:
                if cost_ins == 1:
                    insertions += 1
                j -= 1
            else:
                # fallback (shouldn't hit often)
                i -= 1
                j -= 1

    return matrix[m][n], insertions, deletions, substitutions



def main():
    # read files
    with open("d:\\MyCODES\\fall25\\ai\\lab1\\reference.txt", "r") as f:
        reference = f.read().strip().split()

    with open("d:\\MyCODES\\fall25\\ai\\lab1\\hypothesis.txt", "r") as f:
        hypothesis = f.read().strip().split()

    ignore_words = {"the", "of", "and", "a", "be", "this", "there", "an", "been", "some"}

    distance, ins, dele, subs = levenshtein_words_ignore(reference, hypothesis, ignore_words)

    # write result2.txt
    with open("d:\\MyCODES\\fall25\\ai\\lab1\\result2.txt", "w") as f:
        f.write(f"Levenshtein distance is {distance}\n")
        f.write(f"Insertions {ins}\n")
        f.write(f"Deletions {dele}\n")
        f.write(f"Substitutions {subs}\n")

    print("Result written to result2.txt")


if __name__ == "__main__":
    main()
