#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "node.h"
#include "tools.h"
#include "delete.h"
#include "add.h"
#include "view.h"
#include "search.h"

int main()
{
    int ch;
    struct Node *tail = NULL;

    while (1)
    {
        printf("\n\t\tCircular Doubly Linked List Program");
        printf("\n\t\t-------------------");
        printf("\n\n1.View\n2. Add\n3. Delete\n4. Search\n5. Exit\n\nEnter your Option\t: ");
        int ch;
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                justClear();
                view(tail);
                break;
            case 2: 
                justClear();
                tail=addMenu(tail);
                break; 
            case 3: 
                justClear();
                tail=deleteMenu(tail);
                break; 
            case 4: 
                justClear();
                search(tail);
                break; 
            case 5: 
                delete_all(&tail);
                terminate();
                break;
            default:
                printf("\n\nInvalid choice!!");
                break;
        }

        mssgClear();
    }
    
    // delete_all(&tail);
    return 0;
}