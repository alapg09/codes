#include <iostream>
#include <bitset>

using namespace std;

int main()
{
    unsigned short num;
    cout << "Enter the number: ";
    cin >> num;

    unsigned short grey = num ^ (num >> 1);
    unsigned char grey_binary = grey & 0xffff;
    unsigned char num_binary = num & 0xfffff;

    bitset<16> original(num);
    bitset<16> grey_bits(grey_binary);

    cout << original << endl;
    cout << grey_bits;

    return 0;
}