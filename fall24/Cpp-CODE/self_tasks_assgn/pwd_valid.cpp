#include<iostream>
#include<string>
using namespace std;
int main(){
    string pwd;
    bool upper = false, lower = false, digit = false;
    while (true) {
        cout << "Enter the password: ";
        cin >> pwd;
        int size = pwd.length();
        if (size < 8) {
            cout << "Invalid password. Must be at least 8 characters long. Enter again." << endl;
        }
        
        int i = 0;
        while (i < size) {
            char c = pwd[i];
            if (isupper(c)) {
                upper = true;
            }
            if (islower(c)) {
                lower = true;
            }
            if (isdigit(c)) {
                digit = true;
            }
            i++;
        }
        if (!lower)
            cout << "Invalid. No lowercase letter" << endl;
        if (!upper)
            cout << "Invalid. No uppercase letter" << endl;
        if (!digit)
            cout << "Invalid. No digit" << endl;
        if (upper==true && lower==true && digit==true) {
            cout << "Valid password!" << endl;
            break;
        }
        
    }
    return 0;
}