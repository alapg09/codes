#include <iostream>

using namespace std;

int main()
{

    float answer, income;
    float tax;
    cout << "Press 0 for single filers. \n" // getting filer status
         << "1 for married filing jointly or qualified widow(er). \n"
         << "2 for married filing separately.\n"
         << "3 for head of household)\n"
         << "Please enter your filling status by following the instructions mentioned above: \n";

    cin >> answer;

    while (answer < 0 || answer > 3) // input validation for filer status
    {
        cout << "Invalid input! Please enter a valid \"integer\" between 0 and 3: ";
        cin >> answer;
    }

    cout << "Enter your taxable income: ";
    cin >> income;

    while (income < 0) // validation for income
    {
        cout << "Invalid input! Please enter a valid taxable income: ";
        cin >> income;
    }

    if (answer == 0) // calculating tax for different income ranges
    {
        if (income >= 0 && income <= 8350)
        {
            tax = 0.1 * income;
        }
        else if (income > 8350 && income <= 33950)
        {
            tax = (0.1 * 8350) + ((income - 8350) * 0.15);
        }
        else if (income > 33950 && income <= 82250)
        {
            tax = (0.1 * 8350) + ((33950 - 8350) * 0.15) + ((income - 33950) * 0.25);
        }
        else if (income > 82250 && income <= 171550)
        {
            tax = (0.1 * 8350) + ((33950 - 8350) * 0.15) + ((82250 - 33950) * 0.25) + ((income - 82250) * 0.28);
        }
        else if (income > 171550 && income <= 372950)
        {
            tax = (0.1 * 8350) + ((33950 - 8350) * 0.15) + ((82250 - 33950) * 0.25) + ((171550 - 82250) * 0.28) + ((income - 171550) * 0.33);
        }
        else
        {
            tax = (0.1 * 8350) + ((33950 - 8350) * 0.15) + ((82250 - 33950) * 0.25) + ((171550 - 82250) * 0.28) + ((372950 - 171550) * 0.33) + ((income - 372950) * 0.35);
        }
    }

    else if (answer == 1) // same procedure for other filer statuses
    {
        if (income >= 0 && income <= 16700)
        {
            tax = 0.1 * income;
        }
        else if (income > 16700 && income <= 67900)
        {
            tax = (0.1 * 16700) + ((income - 16700) * 0.15);
        }
        else if (income > 67900 && income <= 137050)
        {
            tax = (0.1 * 16700) + ((67900 - 16700) * 0.15) + ((income - 67900) * 0.25);
        }
        else if (income > 137050 && income <= 208850)
        {
            tax = (0.1 * 16700) + ((67900 - 16700) * 0.15) + ((137050 - 67900) * 0.25) + ((income - 137050) * 0.28);
        }
        else if (income > 208850 && income <= 372950)
        {
            tax = (0.1 * 16700) + ((67900 - 16700) * 0.15) + ((137050 - 67900) * 0.25) + ((208850 - 137050) * 0.28) + ((income - 208850) * 0.33);
        }
        else
        {
            tax = (0.1 * 16700) + ((67900 - 16700) * 0.15) + ((137050 - 67900) * 0.25) + ((208850 - 137050) * 0.28) + ((372950 - 208850) * 0.33) + ((income - 372950) * 0.35);
        }
    }

    else if (answer == 2)
    {
        if (income >= 0 && income <= 8350)
        {
            tax = 0.1 * income;
        }
        else if (income > 8350 && income <= 33950)
        {
            tax = (0.1 * 8350) + ((income - 8350) * 0.15);
        }
        else if (income > 33950 && income <= 68525)
        {
            tax = (0.1 * 8350) + ((33950 - 8350) * 0.15) + ((income - 33950) * 0.25);
        }
        else if (income > 68525 && income <= 104425)
        {
            tax = (0.1 * 8350) + ((33950 - 8350) * 0.15) + ((68525 - 33950) * 0.25) + ((income - 68525) * 0.28);
        }
        else if (income > 104425 && income <= 186475)
        {
            tax = (0.1 * 8350) + ((33950 - 8350) * 0.15) + ((68525 - 33950) * 0.25) + ((104425 - 68525) * 0.28) + ((income - 104425) * 0.33);
        }
        else
        {
            tax = (0.1 * 8350) + ((33950 - 8350) * 0.15) + ((68525 - 33950) * 0.25) + ((104425 - 68525) * 0.28) + ((186475 - 104425) * 0.33) + ((income - 186475) * 0.35);
        }
    }

    else if (answer == 3)
    {
        if (income >= 0 && income <= 11950)
        {
            tax = 0.1 * income;
        }
        else if (income > 11950 && income <= 45500)
        {
            tax = (0.1 * 11950) + ((income - 11950) * 0.15);
        }
        else if (income > 45500 && income <= 117450)
        {
            tax = (0.1 * 11950) + ((45500 - 11950) * 0.15) + ((income - 45500) * 0.25);
        }
        else if (income > 117450 && income <= 190200)
        {
            tax = (0.1 * 11950) + ((45500 - 11950) * 0.15) + ((117450 - 45500) * 0.25) + ((income - 117450) * 0.28);
        }
        else if (income > 190200 && income <= 372950)
        {
            tax = (0.1 * 11950) + ((45500 - 11950) * 0.15) + ((117450 - 45500) * 0.25) + ((190200 - 117450) * 0.28) + ((income - 190200) * 0.33);
        }
        else
        {
            tax = (0.1 * 11950) + ((45500 - 11950) * 0.15) + ((117450 - 45500) * 0.25) + ((190200 - 117450) * 0.28) + ((372950 - 190200) * 0.33) + ((income - 372950) * 0.35);
        }
    }

    cout << "The total income tax is : " << tax;
    return 0;
}