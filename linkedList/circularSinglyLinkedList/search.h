//search
void search(struct Node *tail)
{
    int pos=1,count=0,ele;
    printf("Enter the element:\t");
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
            printf("\nElement-%d found at Position-%d",ele,pos);
            count++;
        }    
        pos++;
        ptr=ptr->next;
    }while(ptr!=tail->next);
    if(count)
    {
        printf("\n\nElement \"%d\" is found %d-times",ele,count);
    }
    else
    {
        printf("\n\nElement \"%d\" not found!!",ele);
    }
}
