#include <iostream>
#include <algorithm>
using namespace std;

template <typename T>
struct Node
{
    T data;
    Node<T> *left;
    Node<T> *right;
    int height; // store height for balancing

    Node(const T &val)
    { // constructor
        data = val;
        left = right = nullptr;
        height = 0; // leaf height = 0
    }
};

template <typename T>
class AVL
{
private:
    Node<T> *root;

    void destroy(Node<T> *node) // helper
    {
        if (node == nullptr)
            return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

    int getHeight(Node<T> *n)
    {
        return (n == nullptr) ? -1 : n->height;
    }

    void updateHeight(Node<T> *n)
    {
        if (n) // only if node exists
            n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    }

    int getBalance(Node<T> *n)
    {
        return (n == nullptr) ? 0 : getHeight(n->left) - getHeight(n->right); // left - right if n is not null
    }

    // ---------- Rotations ----------

    Node<T> *rightRotate(Node<T> *y) //  here, i have added detailed comments for my own understanding as well as clarity of variables
    {
        // before:         y                 ater:      x
        //               /   \                         /   \
        //              x     T3                      T1    y
        //            /   \                                /  \
        //           T1    T2                             T2   T3

        Node<T> *x = y->left;   // x is the left child that will become new root
        Node<T> *T2 = x->right; // saveing t2 subtree - it will move from x's right to y's left

        // rotation
        x->right = y; // make y the right child of x
        y->left = T2; // move T2 to become left child of y

        // update heights after the rotation'

        updateHeight(y); // y's height may change based on T2 -- we chnge it first as x's dependds on it
        updateHeight(x); // x's height depends on updated y's height

        return x; // x is now the new root of this subtree
    }

    Node<T> *leftRotate(Node<T> *x)
    {
        // before:     x                    aftter:      y
        //           /   \                            /   \
        //          T1    y                          x     T3
        //              /   \                      /   \
        //             T2    T3                   T1    T2

        Node<T> *y = x->right; // y is the right child that will become new roo
        Node<T> *T2 = y->left; // t2 subtree - it will move from y's left to x's right

        y->left = x;   // making x the left child of y
        x->right = T2; // moving T2 to become right child of x

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    Node<T> *insertNode(Node<T> *node, T key)
    {
        if (node == nullptr) // empty tree
            return new Node<T>(key);

        // same algo as given in lab manual
        if (key < node->data)
            node->left = insertNode(node->left, key);
        else if (key > node->data)
            node->right = insertNode(node->right, key);
        else
        {
            cout << "Duplicate value ignored: " << key << endl;
            return node; // duplicates not allowed
        }

        // Update height of current node
        updateHeight(node);

        int balance = getBalance(node); // reblance if needed

        if (balance > 1)
        {
            // left heavy
            if (getHeight(node->left->left) >= getHeight(node->left->right))
            {
                // LL case
                return rightRotate(node);
            }
            else
            {
                // LR case
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        else if (balance < -1)
        {
            // right heavy
            if (getHeight(node->right->right) >= getHeight(node->right->left))
            {
                // RR case
                return leftRotate(node);
            }
            else
            {
                // RL case
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }

        return node;
    }

    void preOrderUtility(Node<T> *node) // already implemented in prev labs
    {
        if (node == nullptr)
            return;
        cout << node->data << " ";
        preOrderUtility(node->left);
        preOrderUtility(node->right);
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
    AVL()
    {
        root = nullptr;
    }

    ~AVL()
    {
        destroy(root); // helper for destroying
        root = nullptr;
        cout << "\n[AVL Destructor] All nodes deleted.\n";
    }

    void insert(T key)
    {
        root = insertNode(root, key);
    }

    void preOrder()
    {
        cout << "Preorder : ";
        preOrderUtility(root);
        cout << endl;
    }

    void printTree()
    {
        printTreeUtil(root, 0);
        cout << endl;
    }
};

int main()
{
    AVL<int> tree;

    int arr[] = {10, 20, 30, 40, 50, 60, 70}; // for demonstrating right based tree
    for (int val : arr)
    {
        cout << "Inserting " << val << "..." << endl;
        tree.insert(val);
        tree.printTree();
        tree.preOrder();
    }

    cout << "\nFinal AVL Tree: ";
    tree.preOrder();
    tree.printTree();

    return 0;
}