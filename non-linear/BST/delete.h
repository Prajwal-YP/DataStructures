Node* min(Node*root)
{
    while(root->left!=NULL)
        root=root->left;
    return root; 
}

Node* max(Node*root)
{
    while(root->right!=NULL)
        root=root->right;
    return root; 
}

Node* del(Node* root,int val)
{
    if(root==NULL)
    {
        std::cout<<"\nElement not found!!";
        return root;
    }
    if(val < root->data)
        root->left=del(root->left,val);
    else if(val > root->data)
        root->right=del(root->right,val);
    else
    {
        if(root->left==NULL)
        {
            Node *temp=root->right;
            delete root;
            return temp;
        }
        else if(root->right==NULL)
        {
            Node *temp=root->left;
            delete root;
            return temp;
        }
        else
        {
            Node *temp= min(root->right);
            root->data=temp->data;
            root->right=del(root->right,temp->data);
        }
    }
    return root;
}
