//delete

void delete_beg(struct Node **head)
{
    if(*head==NULL)
    {
        printf("\nIts an empty linked list!!");
        return;
    }
    else if((*head)->next==NULL)
    {
        free(*head);
        *head=NULL;
    }
    else
    {
        *head=(*head)->next;
        free((*head)->prev);
        (*head)->prev=NULL;
    }    
    printf("\nSuccessfully deleted the first element from the doubly linked list!!");
}

void delete_pos(struct Node **head)
{
    int pos;
    printf("\nEnter the position : ");
    scanf("%d",&pos);
    if(*head==NULL)
    {
        printf("\nIts an empty linked list!!");
        return;
    }
    else if(pos==1)
    {
        delete_beg(head);
        return;
    }
    else
    {
        struct Node *ptr=*head;
        while(pos!=1)
        {
            ptr=ptr->next;
            pos--;
        }
        ptr->prev->next=ptr->next;
        if(ptr->next!=NULL)
            ptr->next->prev=ptr->prev;
        free(ptr);
    }
    printf("\nSuccessfully deleted the element-%d from the doubly linked list!!",pos);
}

void delete_end(struct Node **head)
{
    if(*head==NULL)
    {
        printf("\nIts an empty linked list!!");
        return;
    }
    else if((*head)->next==NULL)
    {
        free(*head);
        *head=NULL;
    }
    else
    {
        struct Node *ptr=*head;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->prev->next=NULL;
        free(ptr);
    }   
    printf("\nSuccessfully deleted the last element from the doubly linked list!!");
}

void delete_all(struct Node **head)
{
    if(*head==NULL)
    {
        printf("\nIts an empty linked list!!");
        return;
    }
    else
    {
        struct Node *ptr=*head;
        while(*head!=NULL)
        {
            *head=(*head)->next;
            free(ptr);
            ptr=ptr->next;
        }
    }
    printf("\nSuccessfully deleted all the elements from the doubly linked list!!");
}

struct Node* deleteMenu(struct Node *head)
{
    int ch;
    printf("\n\t\tDelete Menu");
    printf("\n\t\t-------------------");
    printf("\n\n1.Delete at begining\n2. Delete at end\n3. Delete at specific-position\n4.Delete everything\n\nEnter your Option\t: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            delete_beg(&head);
            break;
        case 2:
            delete_end(&head);
            break;
        case 3:
            delete_pos(&head);
            break;
        case 4:
            delete_all(&head);
            break;
        default:
            printf("\nInvalid Option!!");
            break;
    }
    return head;
}
