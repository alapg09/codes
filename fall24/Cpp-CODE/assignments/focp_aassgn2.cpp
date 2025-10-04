#include <iostream>
#include <string>

using namespace std;

bool isvalid(string card_number); // checks the length and whether the input is digit or not
bool luhn(string card_number);
string type(string card_number);
string clean_input(string initial); // for ignoring hyphens and spaces

int main()
{
    string card_number, initial;

    cout << "Please enter your card number: ";
    getline(cin, initial);

    card_number = clean_input(initial);

    if (isvalid(card_number)) // if valid confirmed
    {
        bool valid = luhn(card_number);
        if (valid) // if luhn satisfied
        {
            cout << "The card number is valid." << endl;
            string card_type = type(card_number);
            cout << "The type of card is: " << card_type;
        }
        else
        {
            cout << "The card number is not valid." << endl;
        }
    }
    else
    {
        cout << "Invalid Card Number. the number should contain 13-16 \"digits\".";
    }

    return 0;
}

string clean_input(string card_number)
{
    string cleaned;
    for (char c : card_number)
    {
        if (isdigit(c))
        {
            cleaned += c; // adds the character if it is a digit
        }
    }
    return cleaned;
}

bool isvalid(string card_number)
{
    bool answer = false;
    if (card_number.length() >= 13 && card_number.length() <= 16)
    {
        answer = true;
    }
    for (int i = 0; i < card_number.length(); i++) // for iterating over the entire string
    {
        if (isdigit(card_number[i]))
        {
            answer = true;
        }
    }
    return answer;
}

bool luhn(string card_number)
{
    int sum = 0;
    bool second_digit = false;
    for (int i = card_number.length() - 1; i >= 0; i--) // luhn algorithm
    {
        int digit = card_number[i] - '0';
        if (second_digit)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = (digit / 10) + (digit % 10);
            }
        }
        sum += digit;
        second_digit = !second_digit;
    }

    if (sum % 10 == 0)
    {
        return true;
    }
    return false;
}

string type(string card_number)
{
    if (card_number[0] == '4')
        return "VISA\n";
    else if (card_number[0] == '5' && (card_number[1] == '1' || card_number[1] == '2' || card_number[1] == '3' || card_number[1] == '4' || card_number[1] == '5'))
        return "MasterCard\n";
    else if (card_number[0] == '3' && (card_number[1] == '4' || card_number[1] == '5' || card_number[1] == '7'))
        return "American Express\n";
    else if (card_number[0] == '3' && (card_number[1] == '6'))
        return "Diners Club\n";
    else if (card_number.substr(0, 2) == "50" || (card_number[0] == '5' && card_number[1] >= '6' && card_number[1] <= '9') || (card_number[0] == '6' && card_number[1] >= '0' && card_number[1] <= '9'))
        return "Maestro\n";

    return "Your card number doesn't corresponnd to any leading card type.";
}