#include <iostream>

using namespace std;

struct Node
{
    string name;
    Node *next;
    Node *prev;
};

class DoublyList
{
private:
    Node *head;
    Node *tail;

public:
    DoublyList()
    {
        head = nullptr;
        tail = nullptr;
    }
    ~DoublyList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
    void insertFront(string s)
    {
        Node *new_node = new Node;
        new_node->name = s;
        new_node->prev = nullptr;

        // if empty
        if (head == nullptr)
            tail = new_node;

        else
            head->prev = new_node;

        // universal but need to do it at end
        new_node->next = head;
        head = new_node;
    }
    void insertEnd(string s)
    {
        Node *new_node = new Node;
        new_node->name = s;
        new_node->next = nullptr;

        if (head == nullptr && tail == nullptr)
            head = new_node;
        else
            tail->next = new_node;
        // when list is empty tail = nullptr
        // otherwise its a node at tail
        new_node->prev = tail;
        tail = new_node;
    }
    void displayForward()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->name << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void displayBackward()
    {
        cout << "\n\n";
        Node *temp = tail;
        while (temp != nullptr)
        {
            cout << temp->name << " -> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    void reverseList()
    {
        Node *current = head;
        Node *temp = nullptr;
        // Swap next and prev for all nodes
        while (current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        // Swap head and tail
        if (temp != nullptr)
        {
            temp = head;
            head = tail;
            tail = temp;
        }
    }
    
};

int main()
{
    DoublyList d1;
    // d1.insertEnd("alap");
    // d1.insertEnd("bahroz");
    // d1.insertEnd("raaj");

    d1.displayForward();
    d1.reverseList();
    d1.displayForward();

    return 0;
}