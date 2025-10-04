#include <iostream>
#include <string>

using namespace std;

bool isvalid(string card_number);
bool luhn(string card_number);
string type(string card_number);

int main()
{
    string card_number;

    cout << "Please enter your card number: ";
    cin >> card_number;

    if (isvalid(card_number))
    {
        bool valid = luhn(card_number);
        if (valid)
        {
            cout << "The card number is valid." << endl;
            string card_type = type(card_number);
            cout << "The type of card is: " << card_type << endl;
        }
        else
        {
            cout << "Invalid Card Number according to Luhn's algorithm!" << endl;
        }
    }
    else
    {
        cout << "Invalid Card Number. The number should contain 13-16 digits and be numeric." << endl;
    }

    return 0;
}

bool isvalid(string card_number)
{
    if (card_number.length() < 13 || card_number.length() > 16) // Check length before loop
        return false;

    for (int i = 0; i < card_number.length(); i++)
    {
        if (!isdigit(card_number[i]))
        {
            return false; // Check for non-digit characters
        }
    }
    return true; // All checks passed
}

bool luhn(string card_number)
{
    int sum = 0;               // Initialize sum
    bool second_digit = false; // Track every second digit

    // Iterate over the card number from right to left
    for (int i = card_number.length() - 1; i >= 0; i--)
    {
        int digit = card_number[i] - '0'; // Convert char to int

        // Check if it's every second digit from the right
        if (second_digit)
        {
            digit *= 2;    // Double the digit
            if (digit > 9) // If doubling results in two digits
            {
                digit = (digit / 10) + (digit % 10); // Add the two digits
            }
        }

        sum += digit;                 // Add the (possibly modified) digit to the sum
        second_digit = !second_digit; // Toggle the second_digit flag
    }

    return (sum % 10 == 0); // Valid if the sum is divisible by 10
}

string type(string card_number)
{
    if (card_number[0] == '4')
        return "VISA";
    if (card_number[0] == '5' && (card_number[1] >= '1' && card_number[1] <= '5'))
        return "MasterCard";
    if (card_number[0] == '3' && (card_number[1] == '4' || card_number[1] == '7'))
        return "American Express";
    if (card_number[0] == '3' && card_number[1] == '6')
        return "Diners Club";
    if (card_number[0] == '5' && (card_number[1] >= '0' && card_number[1] <= '8'))
        return "Maestro";

    return "None"; // No valid type found
}
