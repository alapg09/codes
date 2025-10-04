#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string data;
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
        if (last == nullptr)
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
    void insertAtEnd(string value)
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
    void rearrange()
    {
        if (last == nullptr || last->next == last)
            return; // empty or single-node

        Node *head = last->next; // for comparing the stop condition
        Node *curr = head;
        bool flag = true;

        do
        {
            Node *nextNode = curr->next;
            if (flag)
            {
                // expect curr < nextNode because true flag stands for <
                if (curr->data > nextNode->data)
                {
                    swap(curr->data, nextNode->data);
                }
            }
            else
            {
                // expecting curr > nextNode
                if (curr->data < nextNode->data)
                {
                    swap(curr->data, nextNode->data); // swap
                }
            }
            flag = !flag;
            curr = curr->next;
        } while (curr != head);
    }

    bool isPalindrome()
    {
        if (!last || last->next == last)
            return true; // empty or single-node

        Node *head = last->next;
        Node *curr = head;

        // countig the nodes
        int count = 0;
        do
        {
            count++;
            curr = curr->next;
        } while (curr != head);

        // copying data into array
        string *arr = new string[count];
        curr = head;
        for (int i = 0; i < count; i++)
        {
            arr[i] = curr->data;
            curr = curr->next;
        }

        // checking palindrome normally
        int i = 0, j = count - 1;
        while (i < j)
        {
            if (arr[i] != arr[j])
            {
                delete[] arr;
                return false;
            }
            i++;
            j--;
        }

        delete[] arr;
        return true;
    }
};

int main()
{
    CircularLinkedList cll;
    // same as the one given in lab
    cll.insertAtEnd("a");
    cll.insertAtEnd("b");
    cll.insertAtEnd("c");
    cll.insertAtEnd("d");

    cout << "List: ";
    cll.print();

    if (cll.isPalindrome())
        cout << "List is a Palindrome\n";
    else
        cout << "List is NOT a Palindrome\n";

    return 0;
}