#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    unsigned short num;
    cout << "Enter a non-zero 16-bit integer: ";
    cin >> num;

    // Create a bitset of size 16 and initialize it with the number
    bitset<16> binary(num);

    // Output the binary representation
    cout << "Binary representation: " << binary << endl;

    return 0;
}