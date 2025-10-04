#include <iostream>

using namespace std;

int main()
{
    int n = 10;
    for (int i = 1; i <= n; i++)
    {
        int num = 1;
        for (int j = n; j > i; j--)
        {
            cout << " ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout << num << " ";
            num = num * (i - k) / (k);
        }
        cout << endl;
    }

    // i are rows and k are columns so, num*(rows-columns)/columns
    return 0;
}