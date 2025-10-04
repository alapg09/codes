#include <iostream>

using namespace std;

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int *arr = new int[size];

    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 1;
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }

    delete[] arr;

    return 0;
}