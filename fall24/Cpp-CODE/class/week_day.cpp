#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i <= 3; i++)
    {
        cout << "Week : " << i << endl;

        for (int j = 1; j <= 7; j++)
        {
            if (j % 2 != 0)
            {
                continue;
            }
            cout << "     Day:" << j << endl;
        }
    }

    return 0;
}