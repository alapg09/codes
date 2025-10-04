#include <iostream>

using namespace std;

int binarySearch(int arr[], int left, int right, int key)
{
    if (left > right)
    {
        return -1;
    }

    int mid = (left + right) / 2;

    if (key > arr[mid])
    {
        return binarySearch(arr, mid + 1, right, key);
    }
    else if (key < arr[mid])
    {
        return binarySearch(arr, left, mid - 1, key);
    }
    else
    {
        return mid;
    }
}

int main()
{
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;

    if (size % 2 != 0)
    {
        cout << "The size should be a multiple of 2";
        return -1;
    }

    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cout << "Enter the element at index " << i << ": ";
        cin >> arr[i];
    }
    int key;
    cout << endl
         << "Enter the key: ";
    cin >> key;

    int ans = binarySearch(arr, 0, size - 1, key);

    if (ans == -1)
    {
        cout << "Not found...";
    }
    else
    {
        cout << "Element " << key << " found at index " << ans;
    }

    return 0;
}