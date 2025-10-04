//******BUBBLE SORT********/

// #include <iostream>

// using namespace std;
// void swap(int &a, int &b);

// int main()
// {
//     int arr[8] = {10, 9, 4, 5, 7, 15, 1, 0};
//     int size = sizeof(arr) / sizeof(arr[0]);
//     for (int i = 0; i < size - 1; i++)
//     {
//         for (int j = 0; j < size - 1 - i; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 swap(arr[j], arr[j + 1]);
//             }
//         }
//     }
//     for (int i = 0; i < size; i++)
//     {
//         cout << arr[i] << endl;
//     }

//     return 0;
// }
// void swap(int &a, int &b)
// {
//     int temp = b;
//     b = a;
//     a = temp;
// }
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    int x = 15;

    int size = sizeof(arr) / sizeof(arr[0]);
    int i = 0, j = size - 1, location = -1;

    while (i < j)
    {
        int m = floor((i + j) / 2);
        if (x > arr[m])
        {
            i = m + 1;
        }
        else
        {
            j = m;
        }
    }
    if (x == arr[i])
    {
        location = i;
    }

    if (location != -1)
    {

        cout << "Location: element number " << location + 1;
    }
    else
    {
        cout << "Not found";
    }

    return 0;
}