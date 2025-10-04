#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int val) : data(val), next(NULL) {} // ctor
};

class LinkedList
{
private:
    Node *head;

    Node *insertRec(Node *node, int value)
    {
        if (node == NULL)
            return new Node(value);                // if empty then make new node
        node->next = insertRec(node->next, value); // go next until end
        return node;
    }

    Node *deleteRec(Node *node, int value)
    {
        if (node == NULL)
            return NULL; // nothing here

        if (node->data == value)
        { // found it
            Node *temp = node->next;
            delete node; // del
            return temp; // jump over deleted node
        }
        node->next = deleteRec(node->next, value); // keep going
        return node;
    }

    // recursively printing
    void printRec(Node *node)
    {
        if (node == NULL)
        {
            cout << "NULL\n"; // end
            return;
        }
        cout << node->data << " -> ";
        printRec(node->next); // print next one
    }

public:
    LinkedList() : head(NULL) {}

    void insert(int value)
    {
        head = insertRec(head, value); // call helper
    }

    void deleteValue(int value)
    {
        head = deleteRec(head, value); // call helper
    }

    void printList()
    {
        printRec(head); // print all
    }
};

int main()
{
    LinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    cout << "List after insertion: ";
    list.printList();

    list.insert(40);
    cout << "List after inserting 40: ";
    list.printList();

    list.deleteValue(20);
    cout << "List after deleting 20: ";
    list.printList();

    list.deleteValue(10);
    cout << "List after deleting 10: ";
    list.printList();

    return 0;
}
