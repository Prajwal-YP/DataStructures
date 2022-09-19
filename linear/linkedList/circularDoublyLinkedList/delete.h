//delete
void delete_beg(struct Node **tail)
{
    if(*tail==NULL)
    {
        printf("\nEmpty Circular Linked List!!");
        return;
    }
    else
    {
        struct Node *ptr=(*tail)->next;
        if(ptr==*tail)
        {
            free(*tail);
            *tail=NULL;
        }
        else
        {
            ptr->next->prev=*tail;
            (*tail)->next=ptr->next;
            free(ptr);
        }
    }

    printf("\n\nThe begining element is deleted successfully!!");
    return;
}

void delete_pos(struct Node **tail)
{
    int pos,i;
    printf("\nEnter tthe position:\t");
    scanf("%d",&pos);

    if(*tail==NULL)
    {
        printf("\nEmpty Circular Linked List!!");
    }
    else
    {
        struct Node *ptr=(*tail)->next;
        for(i=1;i<pos;i++)
        {
            ptr=ptr->next;
            if(ptr==(*tail)->next)
            {
                printf("\n\nInvalid Position!!");
                return;
            }
        }
        if(ptr==*tail)
        {
            if(pos==1)
            {
                free(*tail);
                *tail=NULL;
            }
            else
                *tail=(*tail)->prev;
        }
        ptr->prev->next=ptr->next;
        ptr->next->prev=ptr->prev;
        free(ptr);
    }
    printf("\n\nThe element at position-%d is deleted successfully!!",pos);
    return;
}

void delete_end(struct Node **tail)
{
    if(*tail==NULL)
    {
        printf("\nEmpty Circular Linked List!!");
        return;
    }
    else
    {
        struct Node *ptr=(*tail)->prev;
        if(ptr==*tail)
        {
            free(*tail);
            *tail=NULL;
        }
        else
        {
            (*tail)->next->prev=ptr;
            ptr->next=(*tail)->next;
            free(*tail);
            *tail=ptr;
        }
    }
    printf("\n\nThe last element is deleted successfully!!");
    return;
}

void delete_all(struct Node **tail)
{
    if(*tail==NULL)
    {
        printf("\nEmpty Circular Linked List!!");
        return;
    }
    else
    {
        struct Node *temp=(*tail)->next;
        do
        {
            free(temp->prev);
            temp=temp->next;
        }while(temp!=(*tail)->next);
        *tail=NULL;
    }

    printf("\n\nAll the elements are deleted successfully!!");
    return;
}

struct Node* deleteMenu(struct Node *tail)
{
    int ch;
    printf("\n\t\tDelete Menu");
    printf("\n\t\t-------------------");
    printf("\n\n1. Delete at begining\n2. Delete at end\n3. Delete at specific-position\n4. Delete everything\n\nEnter your Option\t: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            delete_beg(&tail);
            break;
        case 2:
            delete_end(&tail);
            break;
        case 3:
            delete_pos(&tail);
            break;
        case 4:
            delete_all(&tail);
            break;
        default:
            printf("\nInvalid Option!!");
            break;
    }
    return tail;
}
