#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int diceroll();

int main()
{

    string name1, name2;
    int rollnumber1, rollnumber2, dieroll1, dieroll2, score1 = 0, score2 = 0;
    char choice;

    cout << "Player 1 Full Name: ";
    getline(cin, name1);
    cout << "Player 1 CMS ID: ";
    cin >> rollnumber1;

    cin.ignore();

    cout << "Player 2 Full Name: ";
    getline(cin, name2);
    cout << "Player 2 CMS ID: ";
    cin >> rollnumber2;

    for (int i = 1; i <= 5; i++)
    {

        cout << "Round " << i << " begins." << endl;

        cout << "Player One's First Turn\n"
             << "Enter \"y/Y\" to roll the first dice or \"q/Q\" to quit the game" << endl;
        cin >> choice;

        if (choice == 'Y' || choice == 'y')
        {
            dieroll1 = diceroll();
            cout << "You rolled: " << dieroll1 << endl;
            score1 += dieroll1;
        }
        else if (choice == 'q' || choice == 'Q')
        {
            cout << "Thank you for playing. GoodBye!";
            return 0;
        }

        cout << "Player One's Second Turn\n"
             << "Enter \"y/Y\" to roll the second dice or \"q/Q\" to quit the game" << endl;
        cin >> choice;

        if (choice == 'Y' || choice == 'y')
        {
            dieroll1 = diceroll();
            cout << "You rolled: " << dieroll1 << endl;
            score1 += dieroll1;
        }
        else if (choice == 'q' || choice == 'Q')
        {
            cout << "Thank you for playing. GoodBye!";
            return 0;
        }

        cout << "Player Two's First Turn\n"
             << "Enter \"y/Y\" to roll the first dice or \"q/Q\" to quit the game" << endl;
        cin >> choice;

        if (choice == 'Y' || choice == 'y')
        {
            dieroll2 = diceroll();
            cout << "You rolled: " << dieroll2 << endl;
            score2 += dieroll2;
        }
        else if (choice == 'q' || choice == 'Q')
        {
            cout << "Thank you for playing. GoodBye!";
            return 0;
        }

        cout << "Player Two's Second Turn\n"
             << "Enter \"y/Y\" to roll the second dice or \"q/Q\" to quit the game" << endl;
        cin >> choice;

        if (choice == 'Y' || choice == 'y')
        {
            dieroll2 = diceroll();
            cout << "You rolled: " << dieroll2 << endl;
            score2 += dieroll2;
        }
        else if (choice == 'q' || choice == 'Q')
        {
            cout << "Thank you for playing. GoodBye!";
            return 0;
        }
    }

    cout << "Name" << "\t" << "CMS ID" << "\t" << "TOTAL SCORE" << endl
         << name1 << "\t" << rollnumber1 << "\t" << score1 << endl
         << name2 << "\t" << rollnumber2 << "\t" << score2 << endl;

    return 0;
}

int diceroll()
{

    srand(time(0));

    int randomNumber = (rand() % 6) + 1;

    return randomNumber;
}