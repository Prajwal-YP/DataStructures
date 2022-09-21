void in(Node* root)
{

    if(root==NULL)
        return;
    else
    {
        in(root->left);
        std::cout<<root->data<<" -> ";
        in(root->right);
    }
}

void pre(Node* root)
{

    if(root==NULL)
        return;
    else
    {
        std::cout<<root->data<<" -> ";
        pre(root->left);
        pre(root->right);
    }
}

void post(Node* root)
{

    if(root==NULL)
        return;
    else
    {
        post(root->left);
        post(root->right);
        std::cout<<root->data<<" -> ";
    }
}

void view(Node *root)
{
    int ch;
    std::cout<<std::endl<<"1.inorder";
    std::cout<<std::endl<<"2.preorder";
    std::cout<<std::endl<<"3.postorder";
    std::cout<<std::endl<<"enter:\t";
    std::cin>>ch;

    std::cout<<"\nElements are :\n";

    switch (ch)
    {
        case 1:
            in(root);
            break;
        
        case 2:
            pre(root);
            break;
        
        case 3:
            post(root);
            break;
        
        default:
            break;
    }
}
