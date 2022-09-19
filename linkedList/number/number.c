#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>


struct Node
{
    int digit;
    struct Node *link;
};

struct Node* createNode(int n)
{
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->digit=n;
    newNode->link=NULL;
    return newNode;
}

struct Node* createList(int num)
{
    struct Node* list=createNode(num%10);
    struct Node* p=list;
    num = num/10;
    while(num!=0)
    {
        p->link=createNode(num%10);
        p=p->link;
        num = num/10;
    }
    return list;
}

void view(struct Node *h)
{
    while(h!=NULL)
    {
        printf("%d",h->digit);
        h=h->link;
    }
}

void sum(struct Node *n1,struct Node *n2)
{
    int ans,carry,final,i=1;
    while( (n1!=NULL) && (n2!=NULL) )
    {
        carry=0;
        ans=carry+n1->digit+n2->digit;
        if(ans>9)
        {
            carry=ans%10;
            ans /= 10;
        }
        final += ans*i;
        i *= 10;
        n1=n1->link;
        n2=n2->link;

    }
    while(n1!=NULL)
    {
        ans=carry+n1->digit;
        final += ans*i;
        i *= 10;
        carry=0;
        n1=n1->link;
    }
    while(n2!=NULL)
    {
        ans=carry+n2->digit;
        final += ans*i;
        i *= 10;
        carry=0;
        n2=n2->link;
    }
    printf("%d",final);
}

int main()
{
    int num1,num2;
    printf("\nEnter number-1:\t");
    scanf("%d",&num1);
    printf("\nEnter number-2:\t");
    scanf("%d",&num2);
    struct Node *n1=createList(num1);
    struct Node *n2=createList(num2);

    printf("\n\nNUMBER1 ");
    view(n1);
    printf("\nNUMBER2 ");
    view(n2);

    printf("\n\nSum:\t");
    sum(n1,n2);

    return 0;
}