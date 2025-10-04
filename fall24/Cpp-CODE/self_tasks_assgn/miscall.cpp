#include <iostream>
#include <iomanip>
using namespace std;

int calculate_profit(int desired);

int main()
{
    cout << "DESIRED Profit" << setw(10) << setfill(' ') << "\t" << " Minimum Quantity to be sold" << endl;
    for (int i = 50000; i <= 1000000; i += 50000)
    {

        cout << "" << i << setw(15) << setfill(' ') << " \t " << calculate_profit(i) << endl;
    }

    return 0;
}

int calculate_profit(int desired)
{
    int min;
    if (desired >= 0 && desired <= 1000)
    {                  // inputs between 0 and 1000
        min = desired; // calculates using algorithm on lab assignment
    }
    else if (desired <= 9000)
    { // inputs less than 9000
        min = 1000 + ((desired - 1000) / 2);
    }
    else if (desired > 9000)
    { // greater inputs
        min = 1000 + 4000 + ((desired - 9000) / 5);
    }
    else
    {
        cout << "Invalid Input";
        return -1;
    }

    return min;
}
