#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "node.h"
#include "tool.h"
#include "delete.h"
#include "add.h"
#include "search.h"
#include "view.h"

int main()
{
    int ch;
    struct Node *head = NULL;

    while (1)
    { 
        printf("\n\t\tDoubly Linked List Program");
        printf("\n\t\t-------------------");
        printf("\n\n1.View\n2. Add\n3. Delete\n4. Search\n5. Exit\n\nEnter your Option\t: ");
        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                justClear();
                view(head);
                break;
            case 2:
                justClear();
                head=addMenu(head);
                break;
            case 3:
                justClear();
                head=deleteMenu(head);
                break;
            case 4:
                justClear();
                search(head);
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice !!");
                break;
        }
        mssgClear();
    }
        

    return 0;
}
