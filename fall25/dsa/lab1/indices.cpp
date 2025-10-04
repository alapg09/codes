#include <iostream>
#include <vector>
using namespace std;

vector<int> findAllIndices(const vector<int> &arr, int key)
{
    vector<int> indices; // holds the indxes
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == key)
        {
            indices.push_back(i); // appending
        }
    }
    return indices;
}

int main()
{
    // test1
    vector<int> arr1 = {1, 2, 3, 2, 4, 2, 5}; // sample array with mltiple occurences
    vector<int> result1 = findAllIndices(arr1, 2);
    cout << "Indices of 2: ";
    for (int idx : result1)
        cout << idx << " ";
    cout << endl;

    // test2
    vector<int> arr2 = {10, 20, 30};
    vector<int> result2 = findAllIndices(arr2, 15);
    cout << "Indices of 15: ";
    for (int idx : result2)
        cout << idx << " ";
    cout << "(empty if not found)" << endl;

    // test3
    vector<int> arr3 = {};
    vector<int> result3 = findAllIndices(arr3, 5);
    cout << "Indices of 5: ";
    for (int idx : result3)
        cout << idx << " ";
    cout << "(empty if array is empty)" << endl;

    // another test for practicing git
    vector<int> arr4 = {10, 11, 12, 13, 10};
    vector<int> result3 = findAllIndices(arr3, 10);
    cout << "Indices of 10: ";
    for (int idx : result1)
        cout << idx << " ";
    cout << endl;

    return 0;
}
