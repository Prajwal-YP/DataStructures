#include<stdio.h>
#include<stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};
struct Node *top=NULL;

void push(char val)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=top;
    top=newNode;
}

void pop()
{
    struct Node *p=top;
    while(top!=NULL)
    {
        printf("%c",top->data);
        top = top->next;
        free(p);
        p=top;
    }
}

int main()
{
    int i;
    //STRING
    char string[100];
    printf("\nEnter input:\t");
    scanf("%[^\n]",string);

    for(i=0;string[i]!='\0';i++)
    {    
        push(string[i]);
    }

    for(i=0;string[i]!='\0';i++)
    {    
        pop();
    }
}