#include <iostream>
using namespace std;

int main()
{
    char letter;
    cout << "Enter an alphabet: " << endl;
    cin >> letter;

    // Convert every uppercase letter in lower case
    letter = tolower(letter);

    // Check the corresponding number to  each letter
    if (letter >= 'a' && letter <= 'c')
    {
        cout << "2" << endl;
    }
    else if (letter >= 'd' && letter <= 'f')
    {
        cout << "3" << endl;
    }
    else if (letter >= 'g' && letter <= 'i')
    {
        cout << "4" << endl;
    }
    else if (letter >= 'j' && letter <= 'l')
    {
        cout << "5" << endl;
    }
    else if (letter >= 'm' && letter <= 'o')
    {
        cout << "6" << endl;
    }
    else if (letter >= 'p' && letter <= 's')
    {
        cout << "7" << endl;
    }
    else if (letter >= 't' && letter <= 'v')
    {
        cout << "8" << endl;
    }
    else if (letter >= 'w' && letter <= 'z')
    {
        cout << "9" << endl;
    }
    else
    {
        cout<< letter << " is an invalid input." << endl;
    }

    return 0;
}
