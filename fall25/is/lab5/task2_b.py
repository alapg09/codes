






from task1_a import desExpansionPermutation
from task1_b import getSubBoxes
from task1_c import desRoundPermutation
from task1_d import FP_TABLE
from task2_a import desEncryption


def inverse_permutation_table(table):
    
    inv = [0] * len(table)
    for i, pos in enumerate(table):
        inv[pos - 1] = i + 1
    return inv

def apply_permutation(bitstring, table):
    return ''.join(bitstring[i - 1] for i in table)


INV_FP_TABLE = inverse_permutation_table(FP_TABLE)


def desDecryption(ciphertext, round_keys):
    """
    Decrypts a 64-bit ciphertext block using DES-like lab steps.
    Important: encryption applied FINAL permutation (desFinalPermutation),
    so to decrypt we 1) undo FP, 2) run 16 Feistel rounds with reversed keys,
    3) return the 64-bit plaintext (no extra permutation at the end).
    """

    # u ndo final permutation (inverse of the FP used in encryption)
    preoutput = apply_permutation(ciphertext, INV_FP_TABLE)

    # split into left and right halves (these correspond to R16, L16)
    left = preoutput[:32]
    right = preoutput[32:]

    # run 16 rounds using keys in forward order of reversed_keys
    reversed_keys = round_keys[::-1]
    for i in range(16):
        # expansion 
        expanded_right = desExpansionPermutation(right)

        # XOR with round key
        key = reversed_keys[i]
        xor_result = ""
        for j in range(len(expanded_right)):
            xor_result += "0" if expanded_right[j] == key[j] else "1"

        # s-box substitution (48 -> 32)
        substituted = getSubBoxes(xor_result)

        # round permutation (P-box)
        permuted = desRoundPermutation(substituted)

        # XOR with left half
        new_right = ""
        for k in range(len(left)):
            new_right += "0" if left[k] == permuted[k] else "1"

        # swap for next round
        left, right = right, new_right

    # after 16 rounds, the correct 64-bit plain (pre any FP) is left + right
    plaintext_block = left + right

    return plaintext_block


plaintext = "0110110101101100011011010110110001101101011011000110110101101100"
round_keys = ["110011001100110011001100110011001100110011001100"] * 16

ciphertext = desEncryption(plaintext, round_keys)
print("Ciphertext after encryption:")
print(ciphertext)
print()

decrypted_text = desDecryption(ciphertext, round_keys)
print("Plaintext after decryption:")
print(decrypted_text)
print()

if decrypted_text == plaintext:
    print("Validation Passed: Decrypted text matches original plaintext!")
else:
    print("Validation Failed: Something is still wrong.")
