//add
struct Node* createNode(int val)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

struct Node* createList(int size)
{
    int i,val;
    printf("Enter element-1:\t");
    scanf("%d",&val);
    struct Node *newNode=createNode(val);
    struct Node *ptr=newNode;
    for(i=1;i<size;i++)
    {
        printf("Enter element-%d:\t",i+1);
        scanf("%d",&val);
        ptr->next=createNode(val);
        ptr->next->prev=ptr;
        ptr=ptr->next;
    }
    ptr=NULL;
    return newNode;
}

void add_beg(struct Node **head,struct Node *list)
{
    if(*head==NULL)
    {
        *head=list;
    }
    else
    {
        struct Node *ptr=list;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=*head;
        (*head)->prev=ptr;
        *head=list;
    }
    printf("\nSuccessfully added the element at the beginning of doubly linked list!!");
}

void add_pos(struct Node **head,struct Node *list)
{
    int pos;
    printf("\nEnter the position : ");
    scanf("%d",&pos);
    if(*head==NULL)
    {
        *head=list;
    }
    else if(pos==1)
    {
        add_beg(head,list);
        return;
    }
    else
    {
        struct Node *ptr1=*head;
        struct Node *ptr2=list;
        while(pos!=2)
        {
            if(ptr1->next==NULL)
            {
                printf("Invalid Position!!");
                return;
            }
            ptr1=ptr1->next;
            pos--;
        }
        while(ptr2->next!=NULL)
            ptr2=ptr2->next;
        if(ptr1->next==NULL)
        {
            ptr1->next=list;
            list->prev=ptr1;
        }
        else
        {
            ptr2->next=ptr1->next;
            ptr1->next->prev=ptr2;
            ptr1->next=list;
            list->prev=ptr1;
        }
    }
    printf("\nSuccessfully added the element at the position-%d of doubly linked list!!",pos);
}

void add_end(struct Node **head,struct Node *list)
{
    if(*head==NULL)
    {
        *head=list;
    }
    else
    {
        struct Node *ptr=*head;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=list;
        list->prev=ptr;
    }
    printf("\nSuccessfully added the element at the end of doubly linked list!!");
}

struct Node* addMenu(struct Node *head)
{
    int ch,n;
    printf("How many elements do you want to add\t: ");
    scanf("%d",&n);
    struct Node *list=createList(n);
    printf("\n\t\tAdd Menu");
    printf("\n\t\t-------------------");
    printf("\n\n1.Add at begining\n2. Add at end\n3. Add at specific-position\n\nEnter your Option\t: ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            add_beg(&head,list);
            break;
        case 2:
            add_end(&head,list);
            break;
        case 3:
            add_pos(&head,list);
            break;
        default:
            printf("\nInvalid Option!!");
            break;
    }
    return head;
}
