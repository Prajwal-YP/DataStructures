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
        struct Node *beg=(*tail)->next;
        (*tail)->next=beg->next;
        free(beg);
        if(beg==*tail)
            *tail=NULL;
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
        printf("\nEmpty singlyCircular Linked List!!");
    }
    else
    {
        struct Node *prev=*tail;
        struct Node *cur=(*tail)->next;
        for(i=1;i<pos;i++)
        {
            prev=cur;
            cur=cur->next;
            if(cur==(*tail)->next)
            {
                printf("\n\nInvalid Position!!");
                return;
            }
        }
        prev->next=cur->next;
        free(cur);
        if(cur==*tail)
        {
            if(cur==prev)
                *tail=NULL;
            else
                *tail=prev;
        }
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
        struct Node *end=(*tail)->next;
        while(end->next!=*tail)
            end=end->next;
        end->next=(*tail)->next;
        free(*tail);
        if(end==*tail)
            end=NULL;
        *tail=end;
    }
    printf("\n\nThe last element is deleted successfully!!");
    return;
}

void delete_all(struct Node **tail)
{
    if(tail==NULL)
    {
        printf("\nEmpty Circular Linked List!!");
        return;
    }
    else
    {
        struct Node *temp1=(*tail)->next;
        struct Node *temp2=(*tail)->next->next;
        while(temp2!=(*tail)->next)
        {
            free(temp1);
            temp1=temp2;
            temp2=temp2->next;
        }
        free(*tail);
        *tail=NULL;
    }

    printf("\n\nAll the elements are deleted successfully!!");
    mssgClear();
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
