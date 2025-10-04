#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << setw(2) << " ";
        }
        for (char ch = 'a'; ch <= 'a' + 8 - i; ch++)
        {
            cout << setw(2) << ch;
        }
        for (char ch = 'a' + 8 - i; ch >= 'a'; ch--)
        {
            cout << setw(2) << ch;
        }
        cout << endl;
    }
    cout << setw(19) << right << 'a';

    return 0;
}