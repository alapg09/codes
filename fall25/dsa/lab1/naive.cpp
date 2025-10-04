#include <iostream>
#include <string>
using namespace std;

int naivePatternMatch(const string &text, const string &pattern)
{
    if (pattern.empty())
        return 0; // empty pattern matches at start

    // respective sizes
    int n = text.size();
    int m = pattern.size();

    // naive algorithm
    for (int i = 0; i <= n - m; i++)
    {
        int j = 0;
        while (j < m && text[i + j] == pattern[j])
        {
            j++;
        }
        if (j == m)
        {
            return i; // found at index i
        }
    }
    return -1; // not found
}

int main()
{
    // test1
    cout << naivePatternMatch("hello world", "hello") << endl; // 0

    // test2
    cout << naivePatternMatch("hello world", "world") << endl; // 6

    // test3
    cout << naivePatternMatch("hello world", "abc") << endl; // -1

    // test3
    cout << naivePatternMatch("hello world", "") << endl; // 0

    return 0;
}
