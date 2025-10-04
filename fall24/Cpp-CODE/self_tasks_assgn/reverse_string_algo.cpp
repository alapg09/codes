#include <iostream>

using namespace std;

int main()
{

    // int num, remainder, reversed;

    // cout << "Enter a number: ";
    // cin >> num;

    // while (num != 0)
    // {
    //     remainder = num % 10;
    //     reversed = reversed * 10 + remainder;
    //     num /= 10;
    // }

    // cout << reversed;

    string num;

    cin >> num;

    int i = num.length() - 1;
    while (i >= 0)
    {
        cout << num[i];
        i--;
    }

    return 0;
}