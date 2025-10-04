#include <iostream>
using namespace std;

int main() {
    int n = 5; 

    for (int a = 1; a <= 5 ; a++) {
        for (int b = 4; b >= a; b--) {
            cout << "*";
        }

        for (int b = 1; b <= a; b++) {
            cout << b;
        }

        for (int b = a - 1; b >= 1; b--) {
            cout << b;
        }

        for (int b = 4; b >= a; b--) {
            cout << "*";
        }

        cout << endl;
    }

    for (int a = 1; a <= 5-1; a++) {
        for (int b = 1; b <= a; b++) {
            cout << "*";
        }

        for (int b = 1; b <= 5-a; b++) {
            cout << b;
        }
        
        for(int b = 1; b<=(5-a)-1; b++)
        {
            cout<<" ";
        }

        for (int b = 1; b <= a; b++) {
            cout << "*";
        }

        cout << endl;
    }

    return 0;
}