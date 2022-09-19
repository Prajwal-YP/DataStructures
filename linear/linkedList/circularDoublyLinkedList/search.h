//search
void search(struct Node *tail)
{
    int i=0,pos=1,ele;
    printf("\nEnter the element:\t");
    scanf("%d",&ele);
    if(tail==NULL)
    {
        printf("\nEmpty Circular Linked List!!");
        return;
    }
    struct Node *ptr=tail->next;
    do{
        if(ele==ptr->data)
        {
            i++;
            printf("\nElement-%d found at Position-%d",ele,pos);
        }
        pos++;
        ptr=ptr->next;
    }while(ptr!=tail->next);
    if(i)
    {
        printf("\n\n\tElement \"%d\" found %d-times",ele,i);
    }
}
