
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

def permute(bits64: str, table):
    # rearranges acc to p table
    return ''.join(bits64[i-1] for i in table) # i-1 for 0 indexing

def desInitialPermutation(block64: str):
    
    if len(block64) != 64: # validation
        raise ValueError("Input must be exactly 64 bits")
    return permute(block64, IP_table)

# Run demo
if __name__ == "__main__":
    block = "0000000100100011010001010110011110001001101010111100110111101111"  # 64-bit
    ip = desInitialPermutation(block)
    print("Original Block:     ", block)
    print("After Initial Perm:", ip)
