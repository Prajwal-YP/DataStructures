//view
void view(struct Node *head)
{
    int i=1;
    if(head==NULL)
    {
        printf("It is an empty Doubly Linked List!!!");
    }
    else
    {
        printf("\nElements of Doubly Linked List:");
        printf("\n------------------------------");
        while(head!=NULL)
        {
            printf("\n\tElement-%d\t:%d",i++,head->data);
            head=head->next;
        }
    }
}
