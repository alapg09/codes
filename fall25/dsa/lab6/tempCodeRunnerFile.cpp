int main()
{
    BST<int> tree;
    tree.insertWithoutDuplication(10);
    tree.insertWithoutDuplication(20);
    tree.insertWithoutDuplication(12);
    tree.insertWithoutDuplication(11);
    tree.insertWithoutDuplication(15);
    tree.insertWithoutDuplication(20);

    tree.printTree();
    tree.printLargestValue();

    return 0;
}