#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    // Taking input from user
    int a, b, c;
    cout << " Write the value of  a :" << endl;
    cin >> a;

    cout << " Write the value of  b :" << endl;
    cin >> b;

    cout << " Write the value of  c :" << endl;
    cin >> c;
    // Calculating discriminant

    double discriminant = b * b - 4 * a * c;

    cout << "The discriminant is " << discriminant << endl;

    // Calculating roots for equation
    if (discriminant > 0)
    {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "The roots of this equation are : " << root1 << " and " << root2 << endl;
    }
    else if (discriminant == 0)
    {
        double root = -b / (2 * a);
        cout << "The root is : " << root << endl;
    }
    else
        cout << "This quadratic equation has no real roots";

    return 0;
}