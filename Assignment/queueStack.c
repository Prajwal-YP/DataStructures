#include<stdio.h>
#include<stdlib.h>

//IMPLEMENTATION OF QUEUES USING STACK :)

struct Node
{
    int data;
    struct Node *next;
};
struct Node *topInput=NULL;
struct Node *topOutput=NULL;

int isEmpty(struct Node *top)
{
    if(top==NULL)
        return 1;
    else
        return 0;
}

struct Node* push(struct Node *top,int val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=top;
    return newNode;
}

struct Node* pop(struct Node *top)
{
    struct Node *p=top->next;
    free(top);
    return p;
}

void fillOutput()
{
    struct Node *p=NULL; 
    p=topInput;
    while(p!=NULL)
    {
        topOutput = push(topOutput,p->data);
        p=pop(p);            
    }
    topInput=NULL;
}

void enqueue(int val)
{
    topInput = push(topInput,val);
}

void dequeue()
{
    if(isEmpty(topInput) && isEmpty(topOutput))
    {
        printf("Queue is Empty");
    }
    else if(isEmpty(topOutput))
    {
        fillOutput();
        printf("\nELEMENT DELETED:\t%d",topOutput->data);
        topOutput=pop(topOutput);
    }
    else
    {
        printf("\nELEMENT DELETED:\t%d",topOutput->data);
        topOutput=pop(topOutput);
    }


}

void peek()
{
    if(isEmpty(topInput) && isEmpty(topOutput))
    {
        printf("Queue is Empty");
    }
    else if(isEmpty(topOutput))
    {
        fillOutput();
        printf("\nELEMENT:\t%d",topOutput->data);
    }
    else
    {
        printf("\nELEMENT:\t%d",topOutput->data);
    }
}

int main()
{
    int ch,n;

    printf("\nQUEUE IMPLEMENTATION");
    printf("\n--------------------");
    while(1)
    {
        printf("\n1.enqueue\n2.dequeue\n3.Peek\n4.exit");
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
                printf("\nFront elements is:\n");
                peek();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid option");
        }
    }

    return 0;
}
