#include <iostream>
#include <cassert>
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
    Node *getLastNode()
    {
        if (head == nullptr)
            return nullptr; // empty
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        return temp;
    }
    Node *getNodePtr(int pos)
    {

        if (pos < 1)
        {
            cout << "\n pos must be greater than or equal to 1";
            return nullptr;
        }

        int count = 0;
        Node *temp = head;

        if (head == nullptr)
        {
            cout << "\n Empty list..Nothing to return";
            return nullptr; // empty
        }
        while (temp != nullptr)
        {

            count++;

            if (count == pos)
                return temp;

            temp = temp->next;
        }

        cout << "\n node number doesnt exist";
        return nullptr;
    }
    void addNode(Node *nodeOfFirstList, Node *nodeOfSecondList)
    {
        Node *temp1 = head;

        while (temp1 != nodeOfFirstList)
        {
            temp1 = temp1->next;
        }
    }

public:
    LinkedList()
    {
        head = nullptr;
    }
    ~LinkedList()
    {
        Node *current = head;
        while (current != nullptr)
        {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }
    
    Node *getHead()
    {
        return head;
    }
    void setHead(Node *newHead)
    {
        head = newHead;
    }
    int getLength()
    {
        int count = 0;

        Node *temp = head;

        while (temp != nullptr)
        {
            count++;
            temp = temp->next;
        }

        return count;
    }

    void addAtEnd(int value)
    {
        if (head == nullptr)
            addAtFront(value);
        else
        {
            Node *last = getLastNode();
            last->next = new Node;
            last->next->data = value;
            last->next->next = nullptr;
        }
    }
    void addAtFront(int n)
    {
        Node *temp = new Node;
        temp->data = n;
        temp->next = head;
        head = temp;
    }
    int deleteFromFront()
    {
        if (head == nullptr)
        {
            cout << "\n List is empty .. nothing to delete";
            return -1;
        }
        Node *temp = head;
        head = head->next;

        int n = temp->data;
        delete temp;
        return n;
    }
    void addAfterPosition(int pos, int data)
    {
        // find the node after which we insert implicit meaning list is non-empty
        Node *ptr = getNodePtr(pos);
        if (ptr == nullptr)
        {
            cout << "\n invalid position.. please check";
            return;
        }

        assert(ptr != nullptr); // now pos is a valid position

        Node *new_node = new Node;
        new_node->data = data;
        new_node->next = ptr->next; // this will work for last node
        ptr->next = new_node;
    }

    void print()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    int getMiddle()
    {
        // ********* approach 1 *************

        int size = getLength();
        int mid_index = size / 2;

        Node *temp = head;

        while (mid_index--)
        {
            temp = temp->next;
        }

        return temp->data;
    }

    int deleteNode(int pos)
    {

        if (pos == 1)
            return deleteFromFront();

        // since it is not first node it will always have a prev
        // node .. even for end node .
        Node *ptr = getNodePtr(pos);
        Node *prev_ptr = getNodePtr(pos - 1);

        // now we adjust pointers
        prev_ptr->next = ptr->next; // for end node.prev - ptr->next == nullptr

        int temp_num = ptr->data;
        delete ptr;
        return temp_num;
    }

    void reverse()
    {
        Node *curr = head;
        Node *next = nullptr;
        Node *prev = nullptr;

        while (curr != nullptr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }

    void rotate(int k)
    {

        if (k == 0 || head == nullptr)
        {
            cout << "Empty list..." << endl;
            return;
        }

        Node *curr = head;
        int length = 1;

        while (curr->next != nullptr)
        {
            curr = curr->next;
            length++;
        }

        k %= length;

        if (k == 0)
        {
            cout << "No change made..";
            return;
        }

        curr->next = head;

        curr = head;
        for (int i = 1; i < k; i++)
        {
            curr = curr->next;
        }

        head = curr->next;
        curr->next = nullptr;
    }
    int nthFromEnd(int N)
    {
        Node *mainptr = head;
        Node *refptr = head;

        for (int i = 1; i < N; i++)
        {
            refptr = refptr->next;

            if (refptr == nullptr)
            {
                return -1;
            }
        }

        while (refptr->next != nullptr)
        {
            refptr = refptr->next;
            mainptr = mainptr->next;
        }

        return mainptr->data;
    }
    void delLastOcc(int key)
    {
        Node *temp = head;

        int curr_pos = 1;
        int last_occ = 0;

        while (temp != nullptr)
        {
            if (temp->data == key)
            {
                last_occ = curr_pos;
            }
            temp = temp->next;
            curr_pos++;
        }

        if (last_occ == 0)
        {
            cout << "Not Found..." << endl;
            return;
        }
        deleteNode(last_occ);
    }

    Node *merge(Node *head2)
    /*
    Given two singly linked lists,
    The task is to insert nodes of the second list into the first list at alternate positions
    of the first list and leave the remaining nodes of the second list if it is longer.
    */
    {

        if (head2 == nullptr)
        {
            cout << "List 2 is empty. Nothing to add..";
            return nullptr;
        }

        Node *temp1 = head;
        Node *temp2 = head2;
        Node *prev2 = nullptr;
        while (temp1 != nullptr && temp2 != nullptr)
        {
            Node *next1 = temp1->next;
            Node *next2 = temp2->next;

            // Insert temp2 after temp1
            temp1->next = temp2;
            temp2->next = next1;

            // Move to next positions
            temp1 = next1;
            prev2 = temp2;
            temp2 = next2;
        }

        // Disconnect merged part from remaining
        if (prev2 != nullptr)
            prev2->next = nullptr;

        // Return pointer to first unmerged node
        return temp2;
    }
    void pairWiseSwap()
    {
        if (head == nullptr || head->next == nullptr)
            return;

        Node *prev = head;
        Node *curr = head->next;

        head = curr; // update the member head to new head
        while (true)
        {
            Node *next = curr->next;
            curr->next = prev;

            if (next == nullptr || next->next == nullptr)
            {
                prev->next = next;
                break;
            }
            prev->next = next->next;
            
            prev = next;
            curr = prev->next;
        }
    }




    // detecting a cycle.
    bool detectCycle(){
        Node* fast = head;
        Node* slow = head;

        while(fast != nullptr && fast->next != nullptr && slow != nullptr){
            slow = slow->next;
            fast = fast->next->next;
            
            if (fast == slow){
                return true;
            }
        }

        return false;
    }
};

int main()
{


    // LinkedList l1;
    // // LinkedList l2;

    // l1.addAtEnd(1);
    // l1.addAtEnd(2);
    // l1.addAtEnd(3);
    // l1.addAtEnd(4);
    // l1.addAtEnd(5);

    // cout << "\nBefore: " << endl;
    // cout << "L1: " << endl;
    // l1.print();

    // l1.pairWiseSwap();
    // cout << "\nAfter: " << endl;
    // cout << "L1: " << endl;
    // l1.print();

    // l2.addAtEnd(4);
    // l2.addAtEnd(5);
    // l2.addAtEnd(6);
    // l2.addAtEnd(7);
    // l2.addAtEnd(8);

    // cout << "\nL2: " << endl;
    // l2.print();

    // Node *newHead2 = l1.merge(l2.getHead());
    // l2.setHead(newHead2);

    // cout << "\nL2: " << endl;
    // l2.print();

    // cout << "3rd from end: " << l1.nthFromEnd(3) << endl;
    // cout << "initial linked list: " << endl;
    // l1.print();

    // cout << "\nmiddle: ";
    // cout << l1.getMiddle() << endl;

    // l1.reverse();

    // cout << "\nafter reversing: " << endl;
    // l1.print();

    // cout << "\nBefore Rotating: " << endl;
    // l1.print();

    // l1.rotate(6);

    // cout << "\nAfter Rotating: " << endl;
    // l1.print();

    return 0;
}
