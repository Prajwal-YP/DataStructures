//search
void search(struct Node *head)
{
    int ele,count=0,pos=1;
    printf("\nEnter the element:\t");
    scanf("%d",&ele);

    while(head!=NULL)
    {
        if(head->data==ele)
        {
            count++;
            printf("\nElement found at Position-%d",pos);
        }
        pos++;
        head=head->next;
    }
    if(count)
        printf("\n\n\tElement \"%d\" found %d-times",ele,count);
    else
        printf("\n\n\tElement not found !!");
}
