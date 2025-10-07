#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

template <typename T>
struct Node // representing a node with pointers to their left and right nodes
{
    Node<T> *left;
    Node<T> *right;
    T data;
};

template <typename T>
class BST
{
private:
    Node<T> *root;

    // ---task1 utility-----
    void inOrderUtility(Node<T> *const ptr)
    {
        if (ptr == nullptr) // base condition
            return;

        // left - node - right
        inOrderUtility(ptr->left);
        cout << " " << ptr->data;
        inOrderUtility(ptr->right);
    }

    void preOrderUtility(Node<T> *const ptr)
    {
        if (ptr == nullptr)
            return;

        // node - left - right
        cout << " " << ptr->data;
        preOrderUtility(ptr->left);
        preOrderUtility(ptr->right);
    }

    void postOrderUtility(Node<T> *const ptr)
    {
        if (ptr == nullptr)
            return;

        // left - right - node
        postOrderUtility(ptr->left);
        postOrderUtility(ptr->right);
        cout << " " << ptr->data;
    }

    // helper function for printing the tree(made for my own convenience) -- print in a left to right manner where right subtree is above and left is below
    void printTreeUtil(Node<T> *ptr, int space) const
    {
        if (ptr == nullptr)
            return;
        const int INDENT = 6; // spacing per level

        // increase distance between levels
        space += INDENT;

        // print right child first
        printTreeUtil(ptr->right, space);

        // print current node after space
        cout << endl;
        for (int i = INDENT; i < space; ++i)
            cout << ' ';
        cout << ptr->data << "\n";

        // print left child
        printTreeUtil(ptr->left, space);
    }

public:
    BST() // constructor
    {
        root = nullptr;
    }

    // ---task a------
    void insert(const T &value)
    {
        Node<T> *new_node = new Node<T>;
        // creating and populating the new node
        new_node->data = value;
        new_node->left = nullptr;
        new_node->right = nullptr;

        if (!root) // empty tree
        {
            root = new_node;
            return;
        }

        Node<T> *previous = nullptr; // to keep track of the last node
        Node<T> *curr = root;

        while (curr != nullptr)
        {
            previous = curr; /// incrementing the prev

            if (value < previous->data) // checks
                curr = curr->left;
            else if (value > previous->data)
                curr = curr->right;
            else // removing duplicates
            {
                delete new_node;
                return;
            }
        }
        if (value < previous->data) // curr now points to null and prev is pointing to the relevant node
            previous->left = new_node;
        else
            previous->right = new_node;
    }

    // --------task b---------
    void inOrderTraversal()
    {
        inOrderUtility(root); // so that root is nto exposed and we can easily implement a recursive ftn.
        cout << endl;
    }

    // ---------task c --------

    void preOrderTraversal()
    {
        preOrderUtility(root);
        cout << endl;
    }

    // ------task d-------
    void postOrderTraversal()
    {
        postOrderUtility(root);
        cout << endl;
    }

    // ---- task e-------------

    T deleteNode(const T &value)
    {
        Node<T> *node = root;
        Node<T> *prev = nullptr;

        // finding node
        while (node != nullptr && node->data != value)
        {
            prev = node;
            node = (value < node->data) ? node->left : node->right;
        }

        if (node == nullptr)
        {
            cout << "Value not found\n";
            return T(); // return default value
        }

        T temp = node->data;

        // leaf node
        if (node->left == nullptr && node->right == nullptr)
        {
            if (prev == nullptr) // deleting root
                root = nullptr;
            else
                (node->data > prev->data) ? prev->right = nullptr : prev->left = nullptr;

            delete node;
        }
        // one child
        else if (node->left == nullptr || node->right == nullptr)
        {
            Node<T> *child = (node->left == nullptr) ? node->right : node->left;

            if (prev == nullptr) // root node
                root = child;
            else
                (node->data > prev->data) ? prev->right = child : prev->left = child;

            delete node;
        }
        // two children
        else
        {
            // inorder successor (smallest in right subtree)
            Node<T> *successorParent = node; // keeping track of parent as well
            Node<T> *successor = node->right;
            while (successor->left != nullptr)
            {
                successorParent = successor;
                successor = successor->left;
            }

            node->data = successor->data; // replace value

            // Delete the successor node
            if (successorParent->left == successor)
                successorParent->left = successor->right;
            else
                successorParent->right = successor->right;

            delete successor;
        }

        return temp;
    }

    void printTree() const
    {
        printTreeUtil(root, 0);
        cout << endl;
    }
};
int main()
{
    BST<int> bst;
    int choice, value;
    // menu
    do
    {
        cout << "\n===== Binary Search Tree Menu =====\n";
        cout << "1. Insert new data\n";
        cout << "2. In-Order Traversal\n";
        cout << "3. Pre-Order Traversal\n";
        cout << "4. Post-Order Traversal\n";
        cout << "5. Delete an item\n";
        cout << "6. Print Tree (visual)\n";
        cout << "7. Exit\n";
        cout << "8. Test with random arrays (TASK 5)\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            bst.insert(value);
            cout << value << " inserted successfully.\n";
            break;

        case 2:
            cout << "In-Order Traversal: ";
            bst.inOrderTraversal();
            break;

        case 3:
            cout << "Pre-Order Traversal: ";
            bst.preOrderTraversal();
            break;

        case 4:
            cout << "Post-Order Traversal: ";
            bst.postOrderTraversal();
            break;

        case 5:
            cout << "Enter value to delete: ";
            cin >> value;
            try
            {
                int deleted = bst.deleteNode(value);
                cout << deleted << " deleted successfully.\n";
            }
            catch (...)
            {
                cout << "Deletion failed.\n";
            }
            break;

        case 6:
            cout << "Tree Structure:\n";
            bst.printTree();
            break;

        case 7:
            cout << "Exiting program...\n";
            break;
        case 8:
        {
            srand(time(0)); // seed random numbers

            int sizeChoice;
            cout << "Enter test size (e.g. 10, 20, 50, 100): ";
            cin >> sizeChoice;

            vector<int> testValues;
            for (int i = 0; i < sizeChoice; ++i)
                testValues.push_back(rand() % 1000); // random numbers 0–999

            cout << "\nInserting " << sizeChoice << " random values:\n";
            for (int v : testValues)
                bst.insert(v);

            cout << "\nIn-Order Traversal (Sorted Order): ";
            bst.inOrderTraversal();

            cout << "\nPre-Order Traversal: ";
            bst.preOrderTraversal();

            cout << "\nPost-Order Traversal: ";
            bst.postOrderTraversal();

            cout << "\nVisual Tree Structure:\n";
            bst.printTree();
            break;
        }

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}