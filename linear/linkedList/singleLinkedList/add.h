void add_pos(struct Node **head,int val,int pos)
{
    int count;
    struct Node *curPtr=*head;
    struct Node *newPtr=(struct Node *)malloc(sizeof(struct Node));
    newPtr->data=val;
    if(pos==1)
    {
        newPtr->link=*head;
        *head=newPtr;
        return;
    }
    for(count=2;count<pos;count++)
    {
        if(curPtr==NULL)
        {
            free(newPtr);
            printf("\nInvalid Position !!");
            return;
        }
        curPtr = curPtr->link;
    }
    newPtr->link = curPtr->link;
    curPtr->link=newPtr;
    return;
}

void add_beg(struct Node **head,int val)
{
    if(*head==NULL)
    {
        *head=(struct Node *)malloc(sizeof(struct Node));
        (*head)->data=val;
        (*head)->link=NULL;
    }
    else
    {
        struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
        (newNode)->data=val;
        (newNode)->link=*head;
        *head=newNode;
    }
    printf("\nDATA SUCCESSFULY ADDED AT THE BEGINNING OF THE LINKED LIST");
    return;
}

void add_end(struct Node **head,int val)
{
    struct Node *lastNode = *head;
    if(*head==NULL)
    {
        *head=(struct Node *)malloc(sizeof(struct Node));
        (*head)->data=val;
        (*head)->link=NULL;
    }
    else
    {
        while(lastNode->link!=NULL)
            lastNode = lastNode->link;
        lastNode->link=(struct Node*)malloc(sizeof(struct Node));
        lastNode->link->data=val;
        lastNode->link->link=NULL;
    }
    printf("\nDATA SUCCESSFULY ADDED AT THE ENDING OF THE LINKED LIST");
    return;
}

struct Node* add(struct Node *head)
{
    int ch,val,pos;
    printf("Enter the new-data to be added\t: ");
    scanf("%d",&val);
    printf("\n\t\tAdd Menu");
    printf("\n\t\t--------");
    printf("\n\n1. Add at beginning\n2. Add at end\n3. Add at specific-position\n\nEnter your Option\t: ");
    scanf("%d",&ch);
    
    switch(ch)
    {
        case 1: add_beg(&head,val); break;
        case 2: add_end(&head,val); break;
        case 3: 
            printf("\nEnter the position of element:\t");
            scanf("%d",&pos);
            add_pos(&head,val,pos); 
            break;
    }
    return head;
}
