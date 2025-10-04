#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class CircularLinkedList
{
private:
    Node *last;

public:
    CircularLinkedList() { last = nullptr; }
    ~CircularLinkedList()
    {
        if (!last)
            return;
        Node *curr = last->next;
        while (curr != last)
        {
            Node *temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete last;
        last = nullptr;
    }
    void insertAtEnd(int value)
    {
        Node *newNode = new Node{value, nullptr};
        if (!last)
        {
            last = newNode;
            newNode->next = newNode;
            return;
        }
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    void insertAtFront(int value)
    {
        Node *newNode = new Node{value, nullptr};
        if (!last)
        {
            last = newNode;
            newNode->next = newNode;
            return;
        }
        newNode->next = last->next;
        last->next = newNode;
    }
    void deleteFromFront()
    {
        if (!last)
            return;
        Node *head = last->next;
        if (last == head)
        {
            delete last;
            last = nullptr;
            return;
        }
        last->next = head->next;
        delete head;
    }
    void deleteFromEnd()
    {
        if (!last)
            return;
        Node *head = last->next;
        if (last == head)
        {
            delete last;
            last = nullptr;
            return;
        }
        Node *temp = head;
        while (temp->next != last)
            temp = temp->next;
        temp->next = last->next;
        delete last;
        last = temp;
    }
    bool search(int value)
    {
        if (!last)
            return false;
        Node *temp = last->next;
        do
        {
            if (temp->data == value)
                return true;
            temp = temp->next;
        } while (temp != last->next);
        return false;
    }
    void print()
    {
        if (!last)
        {
            cout << "List is empty\n";
            return;
        }
        Node *temp = last->next;
        do
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != last->next);
        cout << "(head)" << endl;
    }
};

int main()
{
    CircularLinkedList clist;
    clist.insertAtEnd(10);
    clist.insertAtEnd(20);
    clist.insertAtFront(5);
    clist.print();
    clist.deleteFromFront();
    clist.print();
    clist.deleteFromEnd();
    clist.print();
    cout << "Search 10: " << (clist.search(10) ? "Found" : "Not Found") << endl;
    cout << "Search 20: " << (clist.search(20) ? "Found" : "Not Found") << endl;
    return 0;
}