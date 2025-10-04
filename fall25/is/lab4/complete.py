# des_lab.py
# Implements: desPlaintextBlock, desInitialPermutation, desFinalPermutation
# Use: python3 des_lab.py
# Based on Lab04 DES tables and tasks. (See uploaded lab doc.)

IP_table = [
 58,50,42,34,26,18,10,2,
 60,52,44,36,28,20,12,4,
 62,54,46,38,30,22,14,6,
 64,56,48,40,32,24,16,8,
 57,49,41,33,25,17,9,1,
 59,51,43,35,27,19,11,3,
 61,53,45,37,29,21,13,5,
 63,55,47,39,31,23,15,7
]

FP_table = [
 40,8,48,16,56,24,64,32,
 39,7,47,15,55,23,63,31,
 38,6,46,14,54,22,62,30,
 37,5,45,13,53,21,61,29,
 36,4,44,12,52,20,60,28,
 35,3,43,11,51,19,59,27,
 34,2,42,10,50,18,58,26,
 33,1,41,9,49,17,57,25
]

def desPlaintextBlock(plaintext: str):
    """
    Accepts plaintext either as ASCII string or hex string (if only hex digits present).
    Returns list of 64-bit binary strings (padded with '0's on the right if needed).
    """
    plaintext = plaintext.strip()
    # If user input looks like hex (all characters hex and length even), treat as hex bytes
    is_hex = all(c in "0123456789abcdefABCDEF" for c in plaintext) and (len(plaintext) % 2 == 0)
    if is_hex:
        # convert hex string to binary representation (keep leading zeros)
        bin_text = bin(int(plaintext, 16))[2:].zfill(len(plaintext) * 4)
    else:
        # ASCII string -> bytes -> bits
        bin_text = ''.join(format(ord(c), '08b') for c in plaintext)

    # pad to multiple of 64 bits with '0' on the right
    if len(bin_text) % 64 != 0:
        needed = ((len(bin_text) // 64) + 1) * 64
        bin_text = bin_text.ljust(needed, '0')

    blocks = [bin_text[i:i+64] for i in range(0, len(bin_text), 64)]
    return blocks

def permute(bits64: str, table):
    """Generic permutation: bits64 is a string of '0'/'1' (length >= max(table)), table contains 1-based indices."""
    # Table entries are 1-based positions into the 64-bit input.
    return ''.join(bits64[i-1] for i in table)

def desInitialPermutation(block64: str):
    """Apply IP table to a 64-bit block string and return 64-bit result."""
    if len(block64) != 64:
        raise ValueError("desInitialPermutation expects a 64-bit string.")
    return permute(block64, IP_table)

def desFinalPermutation(block64: str):
    """Apply FP table to a 64-bit block string and return 64-bit result."""
    if len(block64) != 64:
        raise ValueError("desFinalPermutation expects a 64-bit string.")
    return permute(block64, FP_table)

def pretty_bits(bits: str, group=8):
    return ' '.join(bits[i:i+group] for i in range(0, len(bits), group))

if __name__ == "__main__":
    print("DES Lab helper — split plaintext into 64-bit blocks, apply IP and FP.")
    user_input = input("Enter plaintext (ASCII) or HEX (even-length hex string): ").rstrip('\n')
    blocks = desPlaintextBlock(user_input)
    print("\nTotal blocks:", len(blocks))

    for idx, blk in enumerate(blocks, start=1):
        print(f"\nBlock {idx}:")
        print("  Original (bin):")
        print("   ", pretty_bits(blk))
        ip = desInitialPermutation(blk)
        print("  After Initial Permutation (IP):")
        print("   ", pretty_bits(ip))
        fp = desFinalPermutation(ip)
        print("  After Final Permutation (FP) [FP(IP(block))]:")
        print("   ", pretty_bits(fp))
        same = "YES" if fp == blk else "NO"
        print(f"  Does FP(IP(block)) == original block? {same}")

    # quick demonstration: show hex conversions for convenience
    print("\nSummary (blocks in hex):")
    for idx, blk in enumerate(blocks, start=1):
        hexblk = hex(int(blk, 2))[2:].zfill(16).upper()
        print(f" Block {idx}: 0x{hexblk}")
