#include <iostream>
#include <string>

using namespace std;

struct product
{
    int id;
    string name;
    int price;
    int stock;
};

int main()
{
    product products[100];
    products[0] = {0010, "Milk", 250, 100};
    products[1] = {0035, "Eggs", 40, 500};
    products[2] = {0055, "Bread", 120, 30};
    int current = 2;

    do
    {

        int choice;
        cout << "Please Select an Option: " << endl
             << "1. Add Product" << endl
             << "2. Manage Products" << endl
             << "3. Place an Order" << endl
             << "4. Exit" << endl;
        cin >> choice;

        while (choice != 1 && choice != 2 && choice != 3 && choice != 4)
        {
            cout << "Invalid! Please enter a number 1-5";
            cin >> choice;
        }

        switch (choice)
        {
        case 1:
        {
            string new_p;
            cout << "Enter the name of product that you want to add: ";
            cin >> new_p;
            products[current + 1].name = new_p;

            cout << "Enter the product id (4 digit): ";
            cin >> products[current + 1].id;

            cout << "Enter the price: ";
            cin >> products[current + 1].price;

            cout << "Enter the stock: ";
            cin >> products[current + 1].stock;
            current++;
            break;
        }
        case 2:
        {
            int temp_id;
            cout << "Please enter the id of product that you want to manage: ";
            cin >> temp_id;
            for (int i = 0; i < current; i++)
            {
                if (products[i].id == temp_id)
                {
                    cout << "Product:  \"" << products[i].name << "\"" << endl;
                }
                else if (i == current - 1)
                {
                    cout << "No product of this ID Found! Returning to main menu.";
                    break;
                }
            }
            int choice;
            cout << "Which attribute would you like to change : " << endl
                 << "1. For name." << endl
                 << "2. For id." << endl
                 << "3. For price." << endl
                 << "4. For stock." << endl;
            cin >> choice;
        }
        break;
        case 3:
            /* code */
            break;
        case 4:
            /* code */
            break;
        default:
            cout << "Invalid Input" << endl;
            break;
        }
    } while (true);

    return 0;
}