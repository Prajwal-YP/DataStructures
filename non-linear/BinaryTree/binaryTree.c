#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;       //4
    struct Node *left;  //1
    struct Node *right; //1
};

struct Node* createNode(int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}

void in(struct Node *root)
{
    if(root==NULL)
        return;
    in(root->left);
    printf("%d ->",root->data);
    in(root->right);
}

void pre(struct Node *root)
{
    if(root==NULL)
        return;
    printf("%d ->",root->data);
    pre(root->left);
    pre(root->right);
}

void post(struct Node *root)
{
    if(root==NULL)
        return;
    post(root->left);
    post(root->right);
    printf("%d ->",root->data);
}


int main()
{
    struct Node *root=createNode(1);
    root->left = createNode(2);
    root->left->left = createNode(3);
    root->left->left->left = createNode(4);
    root->left->left->right = createNode(5);
    root->left->left->left->right = createNode(11);

    root->right = createNode(6);
    root->right->right = createNode(7);
    root->right->right->right = createNode(8);
    root->right->right->left = createNode(9);
    root->right->right->left->left = createNode(10);

    in(root);
    printf("\n");
    pre(root);
    printf("\n");
    post(root);

    return 0;
}
