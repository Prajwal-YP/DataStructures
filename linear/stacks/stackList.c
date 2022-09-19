#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
struct Node *top=NULL;

void push(int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=top;
    top=newNode;
}

void pop()
{
    if(top == NULL)
    {
        printf("\nSTACK UNDERFLOW!!");
        return;
    }
    printf("\nElement deleted:\t%d",top->data);
    struct Node *ptr = top;
    top = top->next;
    free(ptr);
}

void display()
{
    struct Node *ptr = top;

    while(ptr!=NULL)
    {
        printf("%d -> ",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL");
}

int main()
{
    int ch,ele;
    printf("\nSTACK IMPLEMENTATION!!!");
    while(1)
    {
        printf("\n1.push\n2.pop\n3.display\n4.exit");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter the element:\t");
                scanf("%d",&ele);
                push(ele);
                break;
            case 2:
                pop(ele);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("\nInvalid option");
        }
    }
    return 0;
}