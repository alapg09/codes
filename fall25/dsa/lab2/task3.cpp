#include <iostream>
#include <cassert> // for assert

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;
    Node *getLastNode() // for retrieving the last node;
    {
        if (head == nullptr) // empty list
        {
            return nullptr;
        }
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        return temp;
    }
    Node *getNodePtr(int pos)
    {
        if (pos < 1)
        {
            cout << "pos must be greater than or equal to 1" << endl;
            return nullptr;
        }

        int count = 0;
        Node *temp = head;

        // error handling
        if (head == nullptr)
        {
            cout << "Empty List" << endl;
            return nullptr;
        }

        while (temp != nullptr) // checking for last node
        {
            count++;

            if (count == pos) // found
            {
                return temp;
            }

            temp = temp->next;
        }

        cout << "node number doesn't exist" << endl;
        return nullptr;
    }

public:
    LinkedList()
    {
        head = nullptr;
    }
    void insertAtHead(int value)
    {
        Node *temp = new Node;
        temp->data = value;
        temp->next = head;
        head = temp;
    }
    void insertAtLocation(int location, int value)
    {

        if (location == 1) // mimicing addatfront
        {
            Node *temp = new Node;
            temp->data = value;
            temp->next = head;
            head = temp;
            return;
        }

        Node *prev_node = getNodePtr(location - 1); // gets the previous node so that we can insert at the required location
        if (prev_node == nullptr)
        {
            cout << "Invalid Position." << endl;
        }

        assert(prev_node != nullptr);

        Node *new_node = new Node;
        new_node->data = value;
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }

    void deleteLastNode()
    {
        Node *last = getLastNode();

        if (head == nullptr)
        {
            cout << "Empty List--Nothing to delete" << endl;
            return;
        }
        int size = countList();
        if (size == 1) // mimicing the deleteAtFront function's usability but didnt define it seperately because it was not required
        {
            Node *temp = head;
            head = head->next;

            int n = temp->data;
            delete temp;
            cout << "Deleted the node with data: " << n;
            return;
        }
        // finding second last node
        Node *secondLast = getNodePtr(size - 1);
        secondLast->next = nullptr;

        int n = last->data;
        cout << "Deleted the node with data: " << n;
        delete last;
    }
    void displayList()
    {
        Node *temp = head;

        while (temp != nullptr)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    int countList()
    {
        Node *temp = head;
        int count = 0;
        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }
};

int main()
{
    LinkedList list;
    int choice, value, location;

    do
    {
        cout << "\n--- Linked List Menu ---\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Location\n";
        cout << "3. Display List\n";
        cout << "4. Delete Last Node\n";
        cout << "5. Count Nodes\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtHead(value);
            break;

        case 2:
            cout << "Enter location: ";
            cin >> location;
            cout << "Enter value: ";
            cin >> value;
            list.insertAtLocation(location, value);
            break;

        case 3:
            list.displayList();
            break;

        case 4:
            list.deleteLastNode();
            break;

        case 5:
            cout << "Total nodes: " << list.countList() << endl;
            break;

        case 6:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice, try again." << endl;
        }
    } while (choice != 6);

    return 0;
}
