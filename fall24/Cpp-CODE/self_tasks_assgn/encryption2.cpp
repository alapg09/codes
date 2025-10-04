#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Number: ";
    cin >> n;

    // Last 4 digits of your roll number
    int roll_number = 2082;
    
    // Step 2: Calculate mod with 11
    int mod11 = roll_number % 11;
    
    // Check to prevent division by zero
    if (mod11 == 0) {
        cout << "Error: Division by zero due to roll number mod 11 being zero." << endl;
        return 1;
    }

    // Step 3: Add 200 to the number
    double step3 = mod11 + 200;

    // Step 4: Multiply the new number with n
    double step4 = step3 * n;

    // Step 5: Divide by mod11
    double step5 = step4 / mod11;

    // Step 6: Multiply by 17
    double step6 = step5 * 17;

    // Step 7: Subtract 5
    double step7 = step6 - 5;

    // Step 8: Divide by the mod of the last 4 digits with 9
    int mod9 = roll_number % 9;

    // Check to prevent division by zero
    if (mod9 == 0) {
        cout << "Error: Division by zero due to roll number mod 9 being zero." << endl;
        return 1;
    }

    double step8 = step7 / mod9;

    // Step 9: Add 3
    double result = step8 + 3;

    cout << "The encrypted number is: " << result << endl;

    return 0;
}