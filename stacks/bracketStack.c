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

void pop(char val)
{
    int flag=0;
    if(top == NULL)
    {
        printf("\nNOT-BALANCED!!");
        exit(0);
    }
    
    switch(val)
    {
        case '}':
            if(top->data != '{')
                flag=1;
                break;
        case ']':
            if(top->data != '[')
                flag=1;
                break;
        case ')':
            if(top->data != '(')
                flag=1;
                break;
    }

    if(flag)
    {
        // printf("\n %c  %c",top->data,val);
        printf("\nNOT BALANCED!!");
        exit(0);
    }
    struct Node *ptr = top;
    top = top->next;
    free(ptr);
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
        if( (string[i]=='{') || (string[i]=='[') || (string[i]=='('))
            push(string[i]);
        if( (string[i]=='}') || (string[i]==']') || (string[i]==')'))
            pop(string[i]);
    }
    
    printf("\n BALANCED!!");
        
    return 0;
}