#include <iostream>
using namespace std;


int main() {
    int n1, n2;
    cout << "Enter two numbers: ";
    cin >> n1 >> n2;

    // Find the smaller number for GCD calculation
    int smallest = (n1 < n2) ? n1 : n2;
    int gcd = 1; // Initialize GCD

    for (int i = 1; i <= smallest; i++) { // Start from 1 to avoid division by zero
        if (n1 % i == 0 && n2 % i == 0) {
            gcd = i; // Update GCD
        }
    }

    cout << "The GCD is: " << gcd << endl;

    return 0;
}