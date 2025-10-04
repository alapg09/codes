#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Calculator function prototypes
float addition(float a, float b);
float subtraction(float a, float b);
float multiplication(float a, float b);
float division(float a, float b);
int remainder(int a, int b);
float exponentiation(float a, float b);

// Number guessing game function prototypes
void numberGuessingGame();

// Menu functions
void calculatorMenu();
void mainMenu();

int main()
{
    mainMenu();
    return 0;
}

// Main menu function
void mainMenu()
{
    char choice;
    do
    {
        cout << "\n--- Main Menu ---" << endl;
        cout << "1. Calculator" << endl;
        cout << "2. Number Guessing Game" << endl;
        cout << "x. Exit Program" << endl;
        cout << "Select an option: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            calculatorMenu();
            break;
        case '2':
            numberGuessingGame();
            break;
        case 'x':
            cout << "Exiting program. Goodbye!" << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 'x');
}

// Calculator menu function
void calculatorMenu()
{
    float num1 = 0, num2 = 0;
    char option;

    do
    {
        cout << "\nFirst Number = " << num1 << ", Second Number = " << num2 << endl;
        cout << "n- Enter new numbers" << endl;
        cout << "a- Addition" << endl;
        cout << "s- Subtraction" << endl;
        cout << "m- Multiplication" << endl;
        cout << "d- Division" << endl;
        cout << "r- Remainder" << endl;
        cout << "e- Exponentiation" << endl;
        cout << "b- Back to Main Menu" << endl;
        cout << "Select an option: ";
        cin >> option;

        if ((num1 == 0 && num2 == 0) && option != 'n' && option != 'b')
        {
            cout << "Both numbers are 0. Please enter new numbers." << endl;
            option = 'n'; // Prompt to enter new numbers
        }

        switch (option)
        {
        case 'n':
            cout << "Enter first number: ";
            cin >> num1;
            cout << "Enter second number: ";
            cin >> num2;
            break;
        case 'a':
            cout << "**********" << endl
                 << "Addition: " << addition(num1, num2) << endl
                 << "**********";
            break;
        case 's':
            cout << "Subtraction: " << subtraction(num1, num2) << endl;
            break;
        case 'm':
            cout << "Multiplication: " << multiplication(num1, num2) << endl;
            break;
        case 'd':
            if (num2 != 0)
                cout << "Division: " << division(num1, num2) << endl;
            else
                cout << "Error: Division by zero is not allowed." << endl;
            break;
        case 'r':
            if (num2 != 0)
                cout << "Remainder: " << remainder(static_cast<int>(num1), static_cast<int>(num2)) << endl;
            else
                cout << "Error: Division by zero is not allowed." << endl;
            break;
        case 'e':
            cout << "Exponentiation: " << exponentiation(num1, num2) << endl;
            break;
        case 'b':
            cout << "Returning to Main Menu..." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    } while (option != 'b');
}

// Function definitions for calculator operations
float addition(float a, float b)
{
    return a + b;
}

float subtraction(float a, float b)
{
    return a - b;
}

float multiplication(float a, float b)
{
    return a * b;
}

float division(float a, float b)
{
    return a / b;
}

int remainder(int a, int b)
{
    return a % b;
}

float exponentiation(float a, float b)
{
    return pow(a, b);
}

// Number guessing game function
void numberGuessingGame()
{
    srand(time(0));                 // Initialize random number generator
    int target = rand() % 1000 + 1; // Random number between 1 and 1000
    int guess = 0, attempts = 0, score = 1000;
    bool correct = false;

    cout << "\nWelcome to the Number Guessing Game!" << endl;
    cout << "Try to guess the number between 1 and 1000!" << endl;

    while (!correct)
    {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        // Calculate the difference between the guess and the target
        int difference = abs(guess - target);

        // Give feedback based on the guess
        if (guess == target)
        {
            cout << "Correct! You've guessed the number!" << endl;
            correct = true;
        }
        else if (difference > 200)
        {
            if (guess > target)
                cout << "Too high!" << endl;
            else
                cout << "Too low!" << endl;
        }
        else if (difference > 10)
        {
            if (guess > target)
                cout << "High!" << endl;
            else
                cout << "Low!" << endl;
        }
        else
        {
            if (guess > target)
                cout << "Slightly high!" << endl;
            else
                cout << "Slightly low!" << endl;
        }

        // Dynamic penalty based on the difference
        if (difference > 500)
            score -= 100;
        else if (difference > 300)
            score -= 50;
        else if (difference > 200)
            score -= 30;
        else if (difference > 100)
            score -= 20;
        else if (difference > 10)
            score -= 10;
    }

    // Additional penalties based on number of attempts
    if (attempts >= 2 && attempts <= 5)
        score -= 10 * attempts;
    else if (attempts >= 6 && attempts <= 10)
        score -= 20 * attempts;
    else if (attempts > 10)
        score -= 50 * attempts;

    // Award bonus points for fewer attempts
    if (attempts <= 3)
        score += 200;
    else if (attempts <= 6)
        score += 100;

    // Ensure the score doesn't go below zero
    if (score < 0)
        score = 0;

    // Display the final score and attempts
    cout << "Game Over! You guessed the number in " << attempts << " attempts." << endl;
    cout << "Your final score is: " << score << endl;
}
