#include <iostream>
#include <string>

using namespace std;

int reversed(string n);

int main()
{
    string answer;

    cout << " Enter the number: ";
    cin >> answer;

    reversed(answer);

    return 0;
}

int reversed(string n)
{
    int size = sizeof(n) / 8;
    cout << size << endl;

    for (int i = size - 1; i >= 0; i--)
    {
        cout << n[i];
    }
    cout << endl;
    cout << n[3] << n[2] << n[1] << n[0];
    return 0;
}