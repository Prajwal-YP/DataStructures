//view
void view(struct Node *tail)
{
    int i=1;
    if(tail==NULL)
    {
        printf("\nEmpty Circular Linked List!!");
        return;
    }
    struct Node *ptr=tail->next;
    do{
        printf("\nElement-%d:\t%d",i++,ptr->data);
        ptr=ptr->next;
    }while(ptr!=tail->next);
}
