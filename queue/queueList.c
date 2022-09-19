#include<stdio.h>
#include<stdlib.h>

struct Node     
{
    int data;
    struct Node *next;
};

struct Node *front=NULL;
struct Node *rear=NULL;

void enqueue(int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    
    if(rear==NULL)
        front=rear=newNode;
    else
    {
        rear->next=newNode;
        rear=newNode;
    }
}

void dequeue()
{
    struct Node *temp=front;

    if(front==NULL)
    {
        printf("\nQUEUE is empty");
    }
    else
    {
        if(front==rear)
        {
            front=rear=NULL;
        }
        else
        {
            front=front->next;
        }
        printf("\nElement deleted:\t%d",temp->data);
        free(temp);        
    }
}

void display()
{
    if(front==NULL)
    {
        printf("\nQUEUE is empty");
        return;
    }

    struct Node *temp=front;
    while(temp!=NULL)
    {
        printf("\nELEMENT:\t%d",temp->data);
        temp=temp->next;
    }
}

int main()
{
    int ch,n;

    printf("\nQUEUE IMPLEMENTATION");
    printf("\n--------------------");
    while(1)
    {
        printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter the value to be inserted:\t");
                scanf("%d",&n);
                enqueue(n);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                printf("\nElements are:\n");
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid option");
        }
    }

    return 0;
}
