
#include <iostream>

using namespace std;

int main()
{
    int leading_spaces = 25, mid_spaces = 4;

    // for leading spaces and asterisk
    for (int r = 1; r <= 16; r++) // 16 rows
    {
        for (int i = 1; i <= leading_spaces; i++) // printing spaces
        {
            cout << " ";
        }
        if (r % 3 == 0) // reducing spaces after 3 rows
        {
            leading_spaces -= 5;
        }

        // for steps
        if (r == 1 || r == 4 || r == 7 || r == 10 || r == 13 || r == 16)
        {
            cout << "*****";
        }
        cout << "*"; // first asterisk

        // for spaces in between the asterisk and last asterisk
        for (int j = 1; j <= mid_spaces; j++) // spaces in between
        {
            if (r != 16)
            {
                cout << " ";
            }
            else if (r == 16)
            {
                cout << "*"; // last row
            }
        }
        if (r != 1) // no need for last asterisk in row 1
        {
            if (r == 4 || r == 7 || r == 10 || r == 13)
            {
                mid_spaces += 5; // incrementing the spaces
            }
            cout << "*"; // last asterisk
        }
        cout << endl;
    }
    return 0;
}