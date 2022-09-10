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
    printf("\nEnter element-1:\t");
    scanf("%d",&val);
    struct Node* list=createNode(val);
    struct Node* ptr=NULL;
    list->prev=list;
    list->next=list;
    for(i=1;i<size;i++)
    {
        printf("Enter element-%d:\t",i+1);
        scanf("%d",&val);
        ptr=createNode(val);
        list->next->prev=ptr;
        ptr->prev=list;
        ptr->next=list->next;
        list->next=ptr;
        list=list->next;
    }
    ptr=NULL;
    return list;
}

void add_beg(struct Node **tail,struct Node *list)
{
    if(*tail==NULL)
    {
        *tail=list;
    }
    else
    {
        struct Node *listBeg=list->next;
        struct Node *tailBeg=(*tail)->next;
        list->next=tailBeg;
        listBeg->prev=*tail;
        (*tail)->next=listBeg;
        tailBeg->prev=list;
    }
    printf("\n\nElements are added successfully at the begining!!");
    return;
}

void add_pos(struct Node **tail,struct Node *list)
{
    int pos,i;
    printf("\nEnter the position:\t");
    scanf("%d",&pos);
    if(*tail==NULL)
    {
        if(pos==1)
            *tail=list;
        else
        {
            printf("\n\nInvalid Position!!");
            return;
        }
    }
    else if(pos==1)
    {
        add_beg(tail,list);
    }
    else
    {
        struct Node *cur = (*tail)->next;
        for(i=1;i<pos-1;i++)
        {
            cur=cur->next;
            if(cur==(*tail)->next)
            {
            printf("\n\nInvalid Position!!");
            return;
            }
        }
        struct Node *listBeg=list->next;
        cur->next->prev=list;
        list->next=cur->next;
        cur->next=listBeg;
        listBeg->prev=cur;
        if(cur==*tail)
            *tail=list;
    }
    printf("\n\nElements are added successfully at the Position-%d !!",pos);
    return;
}

void add_end(struct Node **tail,struct Node *list)
{
    if(*tail==NULL)
    {
        *tail=list;
    }
    else
    {
        struct Node *listBeg=list->next;
        struct Node *tailBeg=(*tail)->next;
        list->next=tailBeg;
        listBeg->prev=*tail;
        (*tail)->next=listBeg;
        tailBeg->prev=list;
        *tail=list;
    }
    printf("\n\nElements are added successfully at the end!!");
    return;
}

struct Node* addMenu(struct Node *tail)
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
            add_beg(&tail,list);
            break;
        case 2:
            add_end(&tail,list);
            break;
        case 3:
            add_pos(&tail,list);
            break;
        default:
            printf("\nInvalid Option!!");
            break;
    }
    return tail;
}
