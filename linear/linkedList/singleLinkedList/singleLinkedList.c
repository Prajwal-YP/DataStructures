#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include "node.h"
#include "tools.h"
#include "delete.h"
#include "add.h"
#include "view.h"
#include "search.h"

int main()
{
    struct Node *head = NULL;
    while(1)
    {
        printf("\n\t\tSingle Linked List Program");
        printf("\n\t\t-------------------");
        printf("\n\n1.View\n2. Add\n3. Delete\n4. Search\n5. Exit\n\nEnter your Option\t: ");
        int ch;
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                justClear();
                view(head);
                clearScreen();
                break;
            case 2: 
                justClear();
                head=add(head);
                clearScreen();
                break; 
            case 3: 
                justClear();
                head=delete(head);
                clearScreen();
                break; 
            case 4: 
                justClear();
                search(head);
                clearScreen();
                break; 
            case 5: 
                terminate();
                break;
            default:
                printf("\n\nInvalid choice!!");
                clearScreen();
                break;
        }
    }

    return 0;
}