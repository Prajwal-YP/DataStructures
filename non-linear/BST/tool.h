Node* createNode(int val)
{
    Node *newNode = new Node();
    newNode->data=val;
    newNode->left = newNode->right = NULL;
    return newNode;
}
