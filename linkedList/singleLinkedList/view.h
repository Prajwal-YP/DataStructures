
void view(struct Node *head)
{
    int i=1;
    if(head==NULL)
    {
        printf("Linked List is Empty !!!");
    }
    else
    {
        while(head!=NULL)
        {
            printf("\nData at position-%d:\t %d",i++,head->data);
            head =head->link;
        }
    }
    return;
}

