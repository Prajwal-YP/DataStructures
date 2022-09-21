#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int key)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=key;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void insert(struct Node *root,int key)
{
    if(key < root->data)
    {
        if(root->left==NULL)
        {
            root->left=createNode(key);
            return;
        }
        insert(root->left,key);
    }
    else
    {
        if(root->right==NULL)
        {
            root->right=createNode(key);
            return;
        }
        insert(root->right,key);
    }
}

void in(struct Node *root)
{
    if(root==NULL)
        return;
    in(root->left);
    printf("\nELEMENT:\t%d",root->data);
    in(root->right);
}

void pre(struct Node *root)
{
    if(root==NULL)
        return;
    printf("\nELEMENT:\t%d",root->data);
    pre(root->left);
    pre(root->right);
}

void leaf(struct Node *root)
{
    if(root==NULL)
        return;
    leaf(root->left);
    if(root->left==NULL && root->right==NULL)
        printf("%d ->",root->data);
    leaf(root->right);
}

void boundary(struct Node *root)
{
    struct Node *p=root;

    while(p->left!=NULL)
    {
        printf("%d ->",p->data);
        p=p->left;
    }

    leaf(root);
    
    p=root->right;
    while(p->right!=NULL)
    {
        printf("%d ->",p->data);
        p=p->right;
    }
}

int main()
{
    struct Node *root=createNode(49);

    insert(root,25);
    insert(root,6);
    insert(root,18);
    insert(root,41);
    insert(root,31);
    insert(root,63);
    insert(root,99);
    insert(root,-7);
    insert(root,29);
    insert(root,86);
    insert(root,105);

    // in(root);
    // pre(root);
    boundary(root);
    free(root);

    return 0;
}