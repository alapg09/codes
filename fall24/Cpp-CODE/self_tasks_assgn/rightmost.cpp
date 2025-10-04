#include <iostream>

using namespace std;

int main()
{
    int num1, num2, num3;
    cout << "Please enter 3 non-negative integers: ";
    cin >> num1 >> num2 >> num3;

    if (num1 < 0 || num2 < 0 || num3 < 0)
    {
        cout << "Please rerun the program and enter a non-negative integer.";
        return 0;
    }

    int last_num1 = num1 % 10, last_num2 = num2 % 10, last_num3 = num3 % 10;
    cout << "The rightmost digits(respectively) are" << last_num1 << "," << last_num2 << "," << last_num3 << "," << endl;

    if (last_num1 == last_num2 || last_num1 == last_num3 || last_num3 == last_num2)
        cout << "The result is: " << "True";
    else
        cout << "The result is: " << "False";

    return 0;
}