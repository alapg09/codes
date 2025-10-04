#include <iostream>

using namespace std;

int main()
{
    // upper triangle
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

    // middle
    for (int m = 1; m <= 5; m++)
    {
        if (m == 1)
        {
            cout << " ";
        }
        else if (m % 2 == 0 && m != 1)
        {
            cout << "*";
        }
        else
        {
            cout << "-";
        }
        if (m == 1)
        {
            cout << "-";
        }

        if (m % 2 == 0 && m != 1)
        {
            cout << " -";
        }
        else
        {
            cout << " *";
        }
        if (m != 1)
        {
            cout << " ";
        }
        for (int b = 4; b >= m; b--)
        {
            cout << "*";
        }

        for (int b = 1; b <= m; b++)
        {
            cout << b;
        }

        for (int b = m - 1; b >= 1; b--)
        {
            cout << b;
        }

        for (int b = 4; b >= m; b--)
        {
            cout << "*";
        }
        if (m == 1)
        {
            cout << "";
        }
        else if (m % 2 == 0 && m != 1)
        {
            cout << " -";
        }
        else
        {
            cout << " *";
        }
        if (m == 1)
        {
            cout << "*";
        }

        if (m % 2 == 0 && m != 1)
        {
            cout << " *";
        }
        else
        {
            cout << " -";
        }
        if (m != 1)
        {
            cout << " ";
        }

        cout << endl;
    }
    // lower triangle
    for (int a = 1; a <= 5 - 1; a++)
    {
        if (a % 2 == 0)
        {
            cout << "*";
        }
        else
        {
            cout << "-";
        }

        if (a % 2 == 0)
        {
            cout << " - ";
        }
        else
        {
            cout << " * ";
        }
        for (int b = 1; b <= a; b++)
        {
            cout << "*";
        }

        for (int b = 1; b <= 5 - a; b++)
        {
            cout << b;
        }

        for (int b = 1; b <= (5 - a) - 1; b++)
        {
            cout << " ";
        }

        for (int b = 1; b <= a; b++)
        {
            cout << "*";
        }
        if (a % 2 == 0)
        {
            cout << " *";
        }
        else
        {
            cout << " -";
        }

        if (a % 2 == 0)
        {
            cout << " -";
        }
        else
        {
            cout << " *";
        }

        cout << endl;
    }
    for (int i = 1; i <= 8; i++)
    {
        for (int j = 1; j <= i; j++)
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
        if (i % 2 == 0 && i <= 6)
        {
            cout << "* ";
        }
        else if (i % 2 != 0 && i <= 6)
        {
            cout << "- ";
        }
        for (int l = 9; l >= (2 * i) - 1; l--)
        {
            cout << " ";
        }
        if (i % 2 == 0 && i <= 5)
        {
            cout << "* ";
        }
        else if (i % 2 != 0 && i <= 5)
        {
            cout << "- ";
        }
        if (i % 2 == 0 && i <= 7)
        {
            cout << "-";
        }
        else if (i % 2 != 0 && i <= 7)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}