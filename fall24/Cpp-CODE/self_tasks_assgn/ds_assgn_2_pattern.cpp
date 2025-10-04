#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n = 0, rows;

    cout << "Enter a number: ";
    cin >> rows;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = rows; j > i; j--)
        {
            cout << setw(3) << " ";
        }
        for (int j = 1; j <= i; j++)
        {
            cout << setw(3) << j + n;
        }
        for (int k = (i + n) - 1; k >= i; k--)
        {
            cout << setw(3) << k;
        }

        cout << endl;
        n++;
    }

    return 0;
}