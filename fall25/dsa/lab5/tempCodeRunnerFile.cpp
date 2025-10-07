nt main()
{
    BST<int> bst1;

    bst1.insert(3);
    bst1.insert(2);
    bst1.insert(16);
    bst1.insert(10);
    bst1.insert(1);
    bst1.insert(3);

    bst1.printTree();

    bst1.inOrderTraversal();
    bst1.preOrderTraversal();
    bst1.postOrderTraversal();

    bst1.deleteNode(3);

    bst1.printTree();
    return 0;
}