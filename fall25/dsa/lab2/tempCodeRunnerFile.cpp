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

    // inserting
    list.insertAtHead(10);
    list.insertAtHead(20);
    list.insertAtHead(30);
    cout << "After insertAtHead: ";
    list.displayList();

    // insert at location (3rd position)
    list.insertAtLocation(3, 15);
    cout << "After insertAtLocation (pos 3, val 15): ";
    list.displayList();

    // count nodes
    cout << "Node count: " << list.countList() << endl;

    // delete last node
    list.deleteLastNode();
    cout << "\nAfter deleteLastNode: ";
    list.displayList();

    return 0;
}
