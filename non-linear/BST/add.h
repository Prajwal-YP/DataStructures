Node* insert(Node *root,int val)
{
    if(root==NULL)
    {
        return createNode(val);
    }
    else
    {
        if(val < root->data)
                root->left = insert(root->left,val);
        else
                root->right = insert(root->right,val);
    }
    return root;
}
