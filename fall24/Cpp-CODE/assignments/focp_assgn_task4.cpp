#include <iostream>
#include <cmath> //for mathematical operations

using namespace std;

int main()
{

    float x1, y1, x2, y2, r1, r2, distance;

    // getting inputs
    cout << "Enter the x-coordinate of the Center of first circle: ";
    cin >> x1;
    cout << "Enter the y-coordinate of the Center of first circle: ";
    cin >> y1;
    cout << "Enter the radius of first circle: ";
    cin >> r1;
    while (r1 <= 0)
    {
        cout << "Please enter a positive value for radius: ";
        cin >> r1;
    }

    cout << "Enter the x-coordinate of the Center of second circle: ";
    cin >> x2;
    cout << "Enter the y-coordinate of the Center of second circle: ";
    cin >> y2;
    cout << "Enter the radius of second circle: ";
    cin >> r2;

    while (r1 <= 0) // radius can not be negative and 0 radius
    {
        cout << "Please enter a positive value for radius: ";
        cin >> r1;
    }

    distance = sqrt((pow((x2 - x1), 2)) + ((pow((y2 - y1), 2)))); // distance between centres

    if (distance <= abs(r1 - r2)) // first condition
    {
        cout << "The second function is inside the first";
    }

    else if (distance <= (r1 + r2)) // second
    {
        cout << "Second circle overlaps the first";
    }
    else
    {
        cout << "The second circle is neither inside the first nor does it overlap the first";
    }

    return 0;
}
