#include <iostream>
#include<limits>
using namespace std;

int main ()
{
int num1, num2;
char o;

cout<<"Please enter the first integer number: ";
    \
while (true)
{
    cin>>num1;
        if(cin.fail()){             //checking if input is an int
            cin.clear();            //clearing input
            cin.ignore(numeric_limits<streamsize>::max(),'\n'); //ignoring the input
            cout<<"invalid input. please try again: ";}
        else
            break;
}

cout<<"Please enter the second integer number: ";
  
while(true)
{
    cin>>num2;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"invalid input. please try again : ";}
        else
            break;
}

    
cout<<"Select  a character corresponding to the desired operator: \n"
<<"A : + (ADDITION)\n"
<<"B : - (SUBSTRACTION)\n"
<<"C : * (MULTIPLICATION)\n"
<<"D : / (QUOTIENT)\n"
<<"E : % (REMAINDER)\n";


while (true)
{
    cin >> o;
         if (cin.fail() || cin.peek() != '\n') {  //check if input is char and one char
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a valid operator: ";
        } 
        else {
            // Check if operator is one of the allowed ones
            if (o == 'A' || o == 'a' || o == 'B' || o == 'b' || o == 'C' || o == 'c' ||
                o == 'D' || o == 'd' || o == 'E' || o == 'e') {
                break; // Break the loop if a valid operator is entered
            } else {
                cout << "Invalid operator. Please try again: ";
            }
        }
    }

    // Perform the operation based on the selected operator
    if (o == 'A' || o == 'a')
        cout << "The result is: " << num1 + num2;
    else if (o == 'B' || o == 'b')
        cout << "The result is: " << num1 - num2;
    else if (o == 'C' || o == 'c')
        cout << "The result is: " << num1 * num2;
    else if (o == 'D' || o == 'd') {
        if (num2 != 0)
            cout << "The result is: " << num1 / num2;
        else
            cout << "ERROR: CAN'T DIVIDE BY ZERO";
    } else if (o == 'E' || o == 'e') {
        if (num2 != 0)
            cout << "The result is: " << num1 % num2;
        else
            cout << "ERROR: CAN'T DIVIDE BY ZERO";
    }

    return 0;
}
















