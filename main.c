#include "DLL.h"

int main()
{
    t_node *list = NULL;
    t_node *new_node= NULL;
    //t_node *n= NULL;
    char letter ='a';
    int choose;
    do
    {
        //menu
        choose = menu();
        switch(choose)
        {

        //menu 1: insert before
        case 1:
            new_node = create();
            list = insertBefore(list, new_node, letter);
            break;

        //menu 2: insert after
        case 2:
            new_node = create();
            list = insertAfter(list, new_node, letter);
            break;

        //menu 3: print
        case 3:
            printf("\n");
            print(list);
            break;

        //menu 4: reverse print
        case 4:
            printf("\n");
            printReverse(list);
            break;

        //menu 5: delete
        case 5:
            list = Delete(list);
            break;

        //menu 6: quit
        case 6:
            printf("Goodbye\n");
            break;

        default:
            printf("ERREUR INPUT VALUEn");
        }


    }
    while(choose!=6);

    freeMemory(list);   //free allocated memory
    return 0;

}
