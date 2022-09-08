void search(struct Node *head)
{
    int ele,count=0,pos=1;
    printf("\nEnter the element you want to search\t:");
    scanf("%d",&ele);
    if(head==NULL)
    {
        printf("\nLinked List is empty!!");
    }
    else
    {
        while(head!=NULL)
        {
            if(head->data==ele)
            {
                count++;
                printf("\nPosition-%d has %d ",pos,ele);
            }
            head=head->link;
            pos++;
        }
        if(count)
        {
            printf("\n\tElement \"%d\" have appeared %d times !!",ele,count);
        }
        else
        {
            printf("\n\tElement \"%d\" was not found in the linked list!!",ele);
        }
    }
    return;
}
