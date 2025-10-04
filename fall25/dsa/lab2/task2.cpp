#include <iostream>

using namespace std;

int main()
{
    int size;
    cout << "Enter the size of array: ";
    cin >> size;

    int *arr = new int[size];

    int sum;
    for (int i = 0; i < size; i++)
    {

        cout << "Enter the " << i + 1 << "th element: ";
        cin >> arr[i];
    }

    for (int i = 0; i < size; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
        sum += arr[i];
    }

    cout << "\n\nSum: " << sum << endl;
    cout << "Average: " << (float)sum / size;
    delete[] arr;

    return 0;
}
