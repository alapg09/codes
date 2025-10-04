#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

int main()
{
    srand(time(0));

    cout << (rand() % (100 - 90 + 1)) + 90 << " ";

    return 0;
}