#include <iostream>

using namespace std;

int main()
{

    for (int i = 1; i <= 7; i++)
    {
        for (int j = 8; j >= i; j--)
        {
            cout << " ";
        }
        if (i % 2 == 0)
        {
            cout << "- ";
        }
        else
        {
            cout << "* ";
        }
        if (i == 3)
        {
            cout << "-";
        }
        else if (i > 3)
        {
            if (i % 2 == 0)
            {
                cout << "*";
            }
            else
            {
                cout << "-";
            }
            for (int k = 1; k <= (2 * i) - 7; k++)
            {
                cout << " ";
            }
            if (i % 2 == 0)
            {
                cout << "*";
            }
            else
            {
                cout << "-";
            }
        }
        if (i == 2)
        {
            cout << "-";
        }
        if (i > 2)
        {
            if (i % 2 == 0)
            {
                cout << " -";
            }
            else
            {
                cout << " *";
            }
        }
        cout << endl;
    }

    return 0;
}