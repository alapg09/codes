#include <iostream>

using namespace std;

int main()
{
    int birthday = 0;
    char answer;

    // printing the sets
    cout << "1  3  5  7" << endl
         << "9  11 13 15" << endl
         << "17 19 21 23" << endl
         << "25 27 29 31" << endl;
    cout << "Is the day of the month of your birthday in this set of numbers?(Y/y or N/n)" << endl;
    cin >> answer;

    while ((answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n')) // error handling
    {
        cout << "Invalid Input. Please enter Y/y for yes or N/n for no: " << endl;
        cin >> answer;
    }

    if (answer == 'Y' || answer == 'y') // adds 1 i.e the fist element of the set if answer is a yes
    {                                   // same for all sets
        birthday += 1;
        cout << "OK, a few more" << endl;
    }
    else
    {
        cout << "Alright. Please Proceed." << endl;
    }

    cout << "2  3  6  7" << endl
         << "10 11 14 15" << endl
         << "18 19 22 23" << endl
         << "26 27 30 31" << endl;
    cout << "Is the day of the month of your birthday in this set of numbers?(Y/y or N/n)" << endl;
    cin >> answer;

    while ((answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n'))
    {
        cout << "Invalid Input. Please enter Y/y for yes or N/n for no: " << endl;
        cin >> answer;
    }

    if (answer == 'Y' || answer == 'y')
    {
        birthday += 2;
        cout << "We are getting there. 3 to go" << endl;
    }
    else
    {
        cout << "3 more to go" << endl;
    }

    cout << "4  5  6  7" << endl
         << "12 13 14 15" << endl
         << "20 21 22 23" << endl
         << "28 29 30 31" << endl;
    cout << "Is the day of the month of your birthday in this set of numbers?(Y/y or N/n)" << endl;
    cin >> answer;

    while ((answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n'))
    {
        cout << "Invalid Input. Please enter Y/y for yes or N/n for no: " << endl;
        cin >> answer;
    }

    if (answer == 'Y' || answer == 'y')
    {
        birthday += 4;
        cout << "Alright! Please proceed" << endl;
    }
    else
    {
        cout << "Last 2 left" << endl;
    }

    cout << "8  9  10 11" << endl
         << "12 13 14 15" << endl
         << "24 25 20 27" << endl
         << "28 29 30 31" << endl;
    cout << "Is the day of the month of your birthday in this set of numbers?(Y/y or N/n)" << endl;
    cin >> answer;

    while ((answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n'))
    {
        cout << "Invalid Input. Please enter Y/y for yes or N/n for no: " << endl;
        cin >> answer;
    }

    if (answer == 'Y' || answer == 'y')
    {
        cout << "Last one!" << endl;
        birthday += 8;
    }
    else
    {
        cout << "OK! 1 to go." << endl;
    }

    cout << "16 17 18 19" << endl
         << "20 21 22 23" << endl
         << "24 25 26 27" << endl
         << "28 29 30 31" << endl;
    cout << "Is the day of the month of your birthday in this set of numbers?(Y/y or N/n)" << endl;
    cin >> answer;

    while ((answer != 'Y' && answer != 'y' && answer != 'N' && answer != 'n') || cin.fail())
    {
        cout << "Invalid Input. Please enter Y/y for yes or N/n for no: " << endl;
        cin >> answer;
    }

    if (answer == 'Y' || answer == 'y')
    {
        cout << "There we go." << endl;
        birthday += 16;
    }
    else
    {
        cout << "And here comes the birthday" << endl;
    }

    cout << "Your birthday is on the day " << birthday << " of the month";

    return 0;
}
