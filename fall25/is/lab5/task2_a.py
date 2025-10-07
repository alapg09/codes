from task1_a import desExpansionPermutation
from task1_b import getSubBoxes
from task1_c import desRoundPermutation
from task1_d import desFinalPermutation

def desEncryption(plaintext, round_keys):
    """
    Encrypts a 64-bit plaintext block using DES algorithm.
    (As per Lab 05 instructions — no initial permutation used here)
    """

    left = plaintext[:32]
    right = plaintext[32:]

    for i in range(16):
        expanded_right = desExpansionPermutation(right)

        # XOR with round key (48 bits)
        key = round_keys[i]
        xor_result = ""
        for j in range(len(expanded_right)):
            xor_result += "0" if expanded_right[j] == key[j] else "1"

        # S-box substitution (48 -> 32)
        substituted = getSubBoxes(xor_result)

        # Round permutation (P-box)
        permuted = desRoundPermutation(substituted)

        # XOR with left half (32 bits)
        new_right = ""
        for k in range(len(left)):
            new_right += "0" if left[k] == permuted[k] else "1"

        # Swap for next round
        left, right = right, new_right

    # Combine right + left for final permutation
    combined_block = right + left

    # Final permutation
    cipher_block = desFinalPermutation(combined_block)

    return cipher_block


plaintext = "0110110101101100011011010110110001101101011011000110110101101100"
# Each round key must be 48 bits for proper XOR
round_keys = [
    "110011001100110011001100110011001100110011001100" for _ in range(16)
]

print("Encrypted Ciphertext:")
print(desEncryption(plaintext, round_keys))
