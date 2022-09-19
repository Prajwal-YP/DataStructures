#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *link;
};

struct Node* createNode(struct Node *head,int n)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=n;
    newNode->link=head;
    return newNode;
}

struct Node* list(int n)
{
    struct Node* head=NULL;
    while(n!=0)
    {
        head=createNode(head,n%10);
        n /= 10;
    }
    return head;
}

void print(struct Node *head)
{
    while(head->link!=NULL)
    {
        printf("%d ->",head->data);
        head=head->link;
    }
    printf("%d\n",head->data);
}

struct Node* reverse(struct Node *head)
{
    if(head->link==NULL)
    {
        return head;
    }
    struct Node *cur= head->link;
    struct Node *next= head->link->link;
    head->link=NULL;

    while(next!=NULL)
    {
        cur->link=head;
        head=cur;
        cur=next;
        next=next->link;
    }
    cur->link=head;
    return cur;
}

struct Node* add(struct Node *p1,struct Node *p2)
{
    int sum=0,carry=0;
    struct Node *ans=NULL;

    while(p1!=NULL || p2!=NULL)
    {
        sum=0;
        if(p1)
        {
            sum +=p1->data;
            p1=p1->link;
        }
        if(p2)
        {
            sum +=p2->data;
            p2=p2->link;
        }
        sum += carry;
        carry = sum/10;
        sum = sum%10;
        ans=createNode(ans,sum);
    }
    return ans; 
}

int main()
{
    int n1,n2;

    printf("\nEnter number 1:\t");
    scanf("%d",&n1);
    struct Node *head1=list(n1);
    printf("\n\nList representation of number 1 :\n");
    print(head1);

    printf("\nEnter number 2:\t");
    scanf("%d",&n2);
    struct Node *head2=list(n2);
    printf("\n\nList representation of number 2 :\n");
    print(head2);


    printf("\n\nReversed List representation :\n");
    head1=reverse(head1);
    head2=reverse(head2);
    print(head1);
    print(head2);

    printf("\n\nsum:\n");
    print(add(head1,head2));

    return 0;
}