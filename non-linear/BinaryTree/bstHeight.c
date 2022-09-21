#include<stdio.h>
#include<stdlib.h>

int count=0;
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

int height(struct Node* node)
{
    int l,r;
    if(node==NULL)
        return -1;
    l=height(node->left);
    r=height(node->right);

    if(l>r)
        return ++l;
    else
        return ++r;
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

    printf("\nHeight:\t%d",height(root));

    return 0;
}