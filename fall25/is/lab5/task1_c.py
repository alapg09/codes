
RP_TABLE = [
    16, 7, 20, 21,
    29, 12, 28, 17,
    1, 15, 23, 26,
    5, 18, 31, 10,
    2, 8, 24, 14,
    32, 27, 3, 9,
    19, 13, 30, 6,
    22, 11, 4, 25
]

def desRoundPermutation(block32):
    
    result = ""
    for i in RP_TABLE:
        result += block32[i - 1]
    return result


block32 = "01101101011011000110110101101100"
print("Input (32 bits): ", block32)
print("Output (32 bits):", desRoundPermutation(block32))
