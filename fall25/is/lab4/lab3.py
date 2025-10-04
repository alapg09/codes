
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

def permute(bits64: str, table): # smae from prev task
    return ''.join(bits64[i-1] for i in table)

def desFinalPermutation(block64: str):

    if len(block64) != 64:
        raise ValueError("Input must be exactly 64 bits")
    return permute(block64, FP_table)

if __name__ == "__main__":
    block = "0000000100100011010001010110011110001001101010111100110111101111"  # 64-bit
    # Apply IP then FP → should get back original
    from lab2 import desInitialPermutation
    ip = desInitialPermutation(block)
    fp = desFinalPermutation(ip)

    print("Original Block:   ", block)
    print("After IP:         ", ip)
    print("After FP(IP(.)):  ", fp)
    print("FP(IP(block)) == original?", fp == block)
