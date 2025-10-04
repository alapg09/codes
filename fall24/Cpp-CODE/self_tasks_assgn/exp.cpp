#include <iostream>
using namespace std;

int main() {
    int day;
    cout << "Enter a day number (1-365): ";
    cin >> day;

    if (day < 1 || day > 365) {
        cout << "Invalid input! Please enter a number between 1 and 365." << endl;
        return 1;
    }

    // Defining the number of days in each month (non-leap year)
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int month = 0; // Index of the month (0 = January)
    int dayCount = 0;

    // Loop to find which month the day belongs to
    for (int i = 0; i < 12; ++i) {
        dayCount += daysInMonth[i];
        if (day <= dayCount) {
            month = i;
            break;
        }
    }

    // Output the month name
    cout << "The day " << day << " falls in " << months[month] << "." << endl;

    return 0;
}
