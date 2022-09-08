void delete_pos(struct Node **head,int pos)
{
    int count =1;
    if(*head==NULL)
    {
        printf("Linked List is Empty !!!");
        return;
    }
    else if(pos==1)
    {
        struct Node *curPtr=*head;
        *head=(*head)->link;
        free(curPtr);
    }
    else
    {
        struct Node *curPtr=*head;
        struct Node *prevPtr=NULL;
        for(count=1;count<pos;count++)
        {
            prevPtr = curPtr;
            curPtr = curPtr->link;
            if(curPtr==NULL)
            {
                printf("\nInvalid Position !!");
                return;
            }
        }
        prevPtr->link = curPtr->link;
        free(curPtr);
    }
    printf("\n DATA AT THE SPECIFIC-POSITION OF THE LINKED LIST SUCCESSFULY REMOVED");
    return;
}

void delete_end(struct Node **head)
{
    if(*head==NULL)
    {
        printf("Linked List is Empty !!!");
        return;
    }
    else if((*head)->link==NULL)
    {
        free(*head);
        *head=NULL;
    }
    else
    {
        struct Node *ptr= *head;
        while((ptr->link->link)!=NULL)
            ptr = ptr->link;
        free(ptr->link);
        ptr->link=NULL;
    }
    printf("\n DATA AT THE BEGINING OF THE LINKED LIST SUCCESSFULY REMOVED");
    return;
}

void delete_beg(struct Node **head)
{
    if(*head==NULL)
    {
        printf("Linked List is Empty !!!");
        return;
    }
    else if((*head)->link==NULL)
    {
        free(*head);
        *head=NULL;
    }
    else
    {
        struct Node *ptr= *head;
        *head = (*head)->link;
        free(ptr);
    }
    printf("\n DATA AT THE BEGINING OF THE LINKED LIST SUCCESSFULY REMOVED");
    return;
}

void delete_all(struct Node **head)
{
    if(*head==NULL)
    {
        printf("Linked List is Empty !!!");
        return;
    }
    struct Node *next=NULL;
    while(*head!=NULL)
    {
        next=(*head)->link;
        free(*head);
        *head=next;
    }
    printf("\nALL THE DATA SUCCESSFULY REMOVED FROM THE LINKED LIST");
    return;
}

struct Node* delete(struct Node *head)
{
    int ch,pos;
    printf("\n\t\tdelete Menu");
    printf("\n\t\t--------");
    printf("\n\n1. delete at beginning\n2. delete at end\n3. delete at specific-position\n4. delete-all\n\nEnter your Option\t: ");
    scanf("%d",&ch);
    
    switch(ch)
    {
        case 1: delete_beg(&head); break;
        case 2: delete_end(&head); break;
        case 3: 
            printf("\nEnter the position of element:\t");
            scanf("%d",&pos);
            delete_pos(&head,pos); 
            break;
        case 4: delete_all(&head);  break;
    }
    return head;
}
