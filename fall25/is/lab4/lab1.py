

def desPlaintextBlock(plaintext: str):

    plaintext = plaintext.strip()  # remove leading/trailing spaces

    # dettect if input looks like HEX using all() and checking igf length is even
    
    is_hex = all(c in "0123456789abcdefABCDEF" for c in plaintext) and (len(plaintext) % 2 == 0)

    if is_hex:
        # convertig to binary -> 4 bits for each hex
        bin_text = bin(int(plaintext, 16))[2:].zfill(len(plaintext) * 4) # bin() adds 0bv prefix and 2: removes it and then we pad with zeros
    else:
        # asxii to binarry -> 8 bits
        bin_text = ''.join(format(ord(c), '08b') for c in plaintext) # ocd() returns unicode value which is formatted to 8bit binary

    # pad with zeros to make length multiple of 64
    if len(bin_text) % 64 != 0:
        needed = ((len(bin_text) // 64) + 1) * 64
        bin_text = bin_text.ljust(needed, '0')  # pad right with '0'

    # split into 64-bit blocks
    blocks = [bin_text[i:i+64] for i in range(0, len(bin_text), 64)] # start, stop and step size are providded
    return blocks

# Run demo
if __name__ == "__main__":
    sample = "HELLO"
    blocks = desPlaintextBlock(sample)
    print("Input:", sample)
    print("64-bit blocks:")
    for b in blocks:
        print(b)
