#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct Node
{
    float coefficient;
    int exponent;
    struct Node *link;
};

struct Node* insert(struct Node *head,float co, int ex)
{
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    struct Node *ptr=head;
    newNode->coefficient=co;
    newNode->exponent=ex;
    newNode->link=NULL;

    if(head==NULL)
    {
        head=newNode;
        return head;
    }
    else
    {
        if(ex > (head->exponent) )
        {
            newNode->link=head;
            return newNode;   
        }
        else if(ex == (head->exponent) )
        {
            (head->coefficient) = (head->coefficient) + co;
            return head;   
        }
        else{
            while(ptr->link!=NULL)
            {
                if(ex == (ptr->link->exponent) )
                {
                    (ptr->link->coefficient) = (ptr->link->coefficient) + co;
                    free(newNode);
                    return head;
                }
                else if(ex > (ptr->link->exponent) )
                {
                    (newNode->link) = (ptr->link);
                    (ptr->link) = newNode;
                    return head;
                }
                else
                {
                    ptr=ptr->link;
                }
            }
            ptr->link=newNode;
            return head;
        }
    }

}

struct Node* createPoly(struct Node *head)
{
    int i,n,ex;
    float co;
    printf("\nEnter the number of terms in polynomial:\t");
    scanf("%d",&n);
    struct Node *ptr=NULL;
    for(i=1;i<=n;i++)
    {
        printf("\nEnter coefficient value of term-%d:\t",i);
        scanf("%f",&co);
        printf("Enter exponent value of term-%d:\t\t",i);
        scanf("%d",&ex);
        head=insert(head,co,ex);
    }
    return head;
}

void print(struct Node *head)
{
    while(head!=NULL)
    {
        if(head->exponent)
            printf("%.1f (X ^%d)",head->coefficient,head->exponent);
        else
            printf(" (%.1f) ",head->coefficient,head->exponent);
        if(head->link!=NULL)
        {
            if(head->coefficient>0)
                printf(" + ");
            else
                printf(" - ");
        }
        head=head->link;
    }
}

struct Node* terminate(struct Node *head)
{
    struct Node *p=NULL;
    while(head!=NULL)
    {
        p=head;
        head=head->link;
        free(p);
    }

}

void addPoly(struct Node *h1,struct Node *h2)
{
    while( h1!=NULL && h2!=NULL)
    {
        if(h1->exponent==h2->exponent)
        {
            printf("%.1f(X^%d)",(h1->coefficient+h2->coefficient),h1->exponent);
            if((h1->link!=NULL) || (h2->link!=NULL))
            {
                if((h1->coefficient+h2->coefficient)>0)
                    printf(" + ");
                else
                    printf(" - ");
            }
            h1=h1->link;
            h2=h2->link;
        }
        else if(h1->exponent>h2->exponent)
        {
            printf("%.1f (X^%d)",(h1->coefficient),h1->exponent);
            if((h1->link!=NULL) || (h2->link!=NULL))
            {
                if(h1->coefficient>0)
                    printf(" + ");
                else
                    printf(" - ");
            }
            h1=h1->link;
        }
        else
        {
            printf("%.1f (X^%d)",(h2->coefficient),h2->exponent);
            if((h1->link!=NULL) || (h2->link!=NULL))
            {
                if(h2->coefficient>0)
                    printf(" + ");
                else
                    printf(" - ");
            }
            h2=h2->link;
        }
    }
    print(h1);
    print(h2);
}

void mulPoly(struct Node *h1,struct Node *h2)
{
    struct Node *h2copy=h2;
    struct Node *ans=NULL;
    float co;
    int ex;
    while(h1!=NULL)
    {
        h2=h2copy;
        while(h2!=NULL)
        {
            co= (h1->coefficient)*(h2->coefficient); 
            ex=(h1->exponent)+(h2->exponent);
            ans=insert(ans,co,ex);
            h2=h2->link;
        }
        h1=h1->link;
    }
    print(ans);
    return;
}

int main()
{
    struct Node *head1=NULL;
    struct Node *head2=NULL;
    printf("\t\tEnter the polynomial-1");
    printf("\n\t\t----------------------");
    printf("\n\n");
    head1=createPoly(head1);
    printf("\t\tEnter the polynomial-2");
    printf("\n\t\t----------------------");
    printf("\n\n");
    head2=createPoly(head2);

    printf("\n\n");
    printf("\nPolynomial-1 Expression:\t");
    print(head1);
    printf("\nPolynomial-2 Expression:\t");
    print(head2);

    printf("\n\n");
    printf("\nAddition: ");
    addPoly(head1,head2);

    printf("\n\n");
    printf("\nMultiplication: ");
    mulPoly(head1,head2);

    head1=terminate(head1);
    head2=terminate(head2);
}
