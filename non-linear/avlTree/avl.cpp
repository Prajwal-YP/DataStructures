#include<iostream>

struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};



int main()
{
    Node *root=NULL;
    
    root=insert(root,6);
    root=insert(root,21);
    root=insert(root,102);
    root=insert(root,-7);
    root=insert(root,-2);
    root=insert(root,7);
    root=insert(root,2);
    root=insert(root,4);

    return 0;
}