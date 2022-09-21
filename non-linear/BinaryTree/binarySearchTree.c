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


int main()
{   
    int r,n,i,ele;
    printf("\nEnter the root Element:\t");
    scanf("%d",&r);
    struct Node *root=createNode(r);

    printf("\nEnter element size:\t");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("\nEnter element-%d:\t",i+1);    
        scanf("%d",&ele);
        insert(root,ele);
    }
    in(root);
    pre(root);

    return 0;
}