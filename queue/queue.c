#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int queue[MAX];
int front=-1;
int rear=-1;

void enqueue(int val)
{
    if(rear == MAX-1)
    {
        printf("\nQueue is full!!");
    }
    else
    {
        if(rear==-1)
            front=rear=0;    
        else
            rear++;
        queue[rear]=val;
    }
}

int dequeue()
{
    int eke;
    if(front==-1)
    {
        printf("\nQueue is empty!!");
        exit(0);
    }
    else
    {
        eke=queue[front];
        front++;
        if(front>rear)
            front=rear=-1;
        
        return eke;
    }
}

void display()
{
    int i;
    if(front==-1)
    {
        printf("\nQueue is empty!!");
        return;
    }

    for(i=front;i<=rear;i++)
    {
        printf("\nElement:\t%d",queue[i]);
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
                printf("\nElement deleted:\t%d",dequeue());
                break;
            case 3:
                printf("\nElements are:\n");
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
