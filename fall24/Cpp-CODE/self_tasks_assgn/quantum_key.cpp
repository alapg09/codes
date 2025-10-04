#include <iostream>
#include <bitset>  

using namespace std;

int main() {
    unsigned int num;  
    cout << "Enter an integer: ";
    cin >> num;
 
    
    unsigned char byte1 = num & 0xFF;         
    unsigned char byte2 = (num >> 8) & 0xFF;  
    unsigned char byte3 = (num >> 16) & 0xFF; 
    unsigned char byteconst = (num >> 24) & 0xFF; 
    
    
    cout << "Gate 1: " << bitset<8>(byte1) << endl;
    cout << "Gate 2: " << bitset<8>(byte2) << endl;
    cout << "Gate 3: " << bitset<8>(byte3) << endl;
    cout << "Constant: " << bitset<8>(byteconst) << endl;

   
    unsigned char final = byteconst ^ (byte1^byte2^byte3);  

        bitset<8>key(final);
        cout << "The Key is:  " << key<<endl;
    

    return 0;
}