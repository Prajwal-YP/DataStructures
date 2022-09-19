#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct Node
{
    int a[MAX];
    int top;
};
typedef struct Node st;

st* createStack()
{
    st *head = (st*)malloc(sizeof(st));
    head->top=-1;
    return head;
}

int isFull(st *head)
{
    if(head->top==MAX-1)
        return 1;
    else
        return 0;
}

int isEmpty(st *head)
{
    if(head->top == -1)
        return 1;
    else
        return 0;
}

void push(st *head,int val)
{
    if(isFull(head))
    {
        printf("\nSTACK OVERFLOW!!");
    }
    else
    {
        head->top++;
        head->a[head->top]=val;
        printf("\nElement inserted:\t%d",head->a[head->top]);
    }
}

void pop(st *head)
{
    if(isEmpty(head))
    {
        printf("\nSTACK UNDERFLOW!!");
    }
    else
    {
        printf("\nElement deleted:\t%d",head->a[head->top]);
        head->top--;
    }
}

void display(st *head)
{
    int i;

    for(i=0;i<=head->top;i++)
    {
        printf("\nElement-%d:\t%d",i+1,head->a[i]);
    }
}

int main()
{
    st *stack = createStack();

    push(stack,1);
    push(stack,2);
    push(stack,3);
    push(stack,4);

    printf("\nAfter poping:\n");
    pop(stack);
    display(stack);

    return 0;
}