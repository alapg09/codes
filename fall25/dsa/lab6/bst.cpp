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
    void PrintLeafNodesUtility(Node<T> *node)
    {
        if (node == nullptr)
            return;

        if (node->left == nullptr && node->right == nullptr)
        {
            cout << node->data << " ";
            return;
        }

        // # recursive calls
        PrintLeafNodesUtility(node->left);
        PrintLeafNodesUtility(node->right);
    }
    int countLeafNodesUtility(Node<T> *node)
    {
        if (node == nullptr)
            return 0;

        if (node->left == nullptr && node->right == nullptr)
            return 1;

        return countLeafNodesUtility(node->left) + countLeafNodesUtility(node->right);
    }

    int countInternalNodesUtility(Node<T> *node)
    {
        if (node == nullptr || (node->left == nullptr && node->right == nullptr))
            return 0;

        return 1 + countInternalNodesUtility(node->left) + countInternalNodesUtility(node->right);
    }

    int heightUtility(Node<T> *node)
    {
        if (node == nullptr)
        {
            return -1;
        }

        int left_height = heightUtility(node->left);
        int right_height = heightUtility(node->right);

        return 1 + max(left_height, right_height);
    }

    int depthUtility(Node<T> *node)
    {
        if (node == nullptr)
        {
            return -1;
        }

        int left_depth = depthUtility(node->left);
        int right_depth = depthUtility(node->right);

        return 1 + max(left_depth, right_depth);
    }
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

public:
    BST() // constructor
    {
        root = nullptr;
    }

    int height()
    {
        return heightUtility(root);
    }
    int depth()
    {
        return depthUtility(root);
    }

    int countInternalNodes()
    {
        return countInternalNodesUtility(root);
    }
    int countLeafNodes()
    {
        // empty case handled inside utility
        return countLeafNodesUtility(root);
    }
    void PrintLeafNodes() // calls the private utilitty function for logic
    {
        if (root == nullptr)
        {
            cout << "Tree is empty. No leaf nodes." << endl;
            return;
        }
        cout << "Leaf Nodes: ";
        PrintLeafNodesUtility(root);
        cout << endl;
    }

    void printSmallestValue()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty. No smallest value." << endl;
            return;
        }
        Node<T> *curr = root;
        while (curr->left != nullptr)
            curr = curr->left;

        cout << "Smallest Value: " << curr->data;
    }
    void printLargestValue()
    {
        if (root == nullptr)
        {
            cout << "Tree is empty. No smallest value." << endl;
            return;
        }

        Node<T> *curr = root;
        while (curr->right != nullptr)
            curr = curr->right;

        cout << "Largest Value: " << curr->data;
    }

    void insertWithoutDuplication(const T &value)
    {
        Node<T> **searchResult = search(value); // unpacking
        Node<T> *loc = searchResult[0];
        Node<T> *ploc = searchResult[1];

        if (loc != nullptr) // duplicate check
        {
            cout << "The value " << value << " already exists.";
            return;
        }

        Node<T> *new_node = new Node<T>; // newnode
        new_node->data = value;
        new_node->left = nullptr;
        new_node->right = nullptr;

        if (ploc == nullptr) // empty tree
        {
            root = new_node;
            cout << value << " inserted as root node." << endl;
        }
        else if (value < ploc->data)
        {
            ploc->left = new_node;
            cout << value << " inserted to the LEFT of " << ploc->data << endl;
        }
        else
        {
            ploc->right = new_node;
            cout << value << " inserted to the RIGHT of " << ploc->data << endl;
        }
    }
    Node<T> **search(const T &value) // double pointer (points at array of pointers)
    {
        static Node<T> *result[2]; // static so it persists after return
        Node<T> *loc = root;
        Node<T> *ploc = nullptr;

        while (loc != nullptr && loc->data != value)
        {
            ploc = loc;
            if (value < loc->data)
                loc = loc->left;
            else
                loc = loc->right;
        }

        result[0] = loc;  // location (where value found or NULL)
        result[1] = ploc; // parent (may be NULL)
        return result;
    }

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

    void inOrderTraversal()
    {
        inOrderUtility(root); // so that root is nto exposed and we can easily implement a recursive ftn.
        cout << endl;
    }

    void preOrderTraversal()
    {
        preOrderUtility(root);
        cout << endl;
    }

    void postOrderTraversal()
    {
        postOrderUtility(root);
        cout << endl;
    }
};
int main()
{
    BST<int> tree;
    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(4);
    tree.insert(6);
    tree.insert(15);
    tree.insert(25);
    tree.insert(3);
    tree.printTree();

    cout << endl
         << "preOrder: ";
    tree.preOrderTraversal();
    cout << endl
         << "InOrder: ";
    tree.inOrderTraversal();
    cout << endl
         << "postOrder: ";
    tree.postOrderTraversal();

    return 0;
}