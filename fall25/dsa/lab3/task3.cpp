#include <iostream>

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

    // the actual logic
    void printForwardRec(Node *node)
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        printForwardRec(node->next);
    }

    // functions in private to make use of head
    void printReverseRec(Node *node)
    {
        if (node == nullptr)
            return;
        printReverseRec(node->next);
        cout << node->data << " ";
    }
    
    // utility for addAtLast
    Node *getLastNode()
    {
        if (head == nullptr)
            return nullptr; // empty
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
    
        return temp;
    }
    
    // utility for addAtLast
    void addAtFront(int n)
    {
        Node *temp = new Node;
        temp->data = n;
        temp->next = head;
        head = temp;
    }
public:
    LinkedList() { head = nullptr; }


    // for making the list
    void addAtLast(int n)
    {
        if (head == nullptr)
            addAtFront(n);
        else
        {
            Node *last = getLastNode();
            last->next = new Node;
            last->next->data = n;
            last->next->next = nullptr;
        }
    }

    // sample functions that can be called from main
    void printForward()
    {
        printForwardRec(head);
        cout << endl;
    }
    void printReverse()
    {
        printReverseRec(head);
        cout << endl;
    }
};

int main()
{
    LinkedList list;

    // Add elements to the list: 1  2  3  4
    list.addAtLast(1);
    list.addAtLast(2);
    list.addAtLast(3);
    list.addAtLast(4);

    cout << "Forward: ";
    list.printForward();
    cout << "Reverse: ";
    list.printReverse();

    return 0;
}