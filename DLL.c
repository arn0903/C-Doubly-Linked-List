#include "DLL.h"


/*
function to create a node
*/
t_node *create()
{
    t_node *head = NULL;
    head = (t_node*)malloc (sizeof(t_node));
    if (head == NULL)
    {
        printf("memory alloc problem\n");
    }
    else
    {
        printf("Input a letter: ");
        fflush(stdin);
        scanf("%c", &(head->letter));
        printf("\n");
        head->prev = NULL ;
        head->next = NULL;
    }
    return head;
}


/*
recursive function to print a linked list
    parameter: list
*/
void print(t_node *list)
{
    //base case
    if (list== NULL)
    {
        //noting to do
    }

    //recursion
    else
    {
        printf("Letter : %c\n", list->letter);
        print(list->next);
    }

}


/*
recursive function to reversely print a linked list
    parameter: list
*/
void printReverse(t_node *list)
{
    //base case
    if (list== NULL)
    {
        //noting to do
    }

    //recursion
    else
    {
        print(list->next);
        printf("Letter : %c\n", list->letter);

    }

}


/*
function to add a new node before a know n in a linked list
    parameters: list, new node and value of n
*/
t_node *insertBefore(t_node *list, t_node *new_node, char temp)
{

    t_node *current, *previous;

    if(list == NULL)
    {
        return new_node;
    }


    else				//list is not empty
    {
        current = list;
        previous = list;


        printf("Input link node: ");
        fflush(stdin);
        scanf("%c",&temp);
        printf("\n");

        while (current != NULL)     //traverse the list
        {
            if (current->letter == temp)    //find the right place
            {

                if (current == list)    //insert in head of list
                {
                    new_node->next = current;
                    return new_node;
                }
                else
                {



                    new_node->next = previous->next;    //update the pointers
                    new_node->prev = previous;

                    previous->next = new_node;      //double the link
                    previous=new_node->next;
                    previous->prev=new_node;

                    return list;
                }

            }
            else				 //traverse the list to find the right place
            {
                previous = current;
                current = current->next;
            }
        }
    }
    return list;
}


/*
function to add a new node after a know n in a linked list
    parameters: list, new node and value of n
*/
t_node *insertAfter(t_node *list, t_node *new_node, char temp)
{
    t_node *current;


    if(list == NULL)
    {
        return new_node;
    }


    else
    {
        current = list;


        printf("Input link node: ");
        fflush(stdin);
        scanf("%c",&temp);
        printf("\n");

        while (current != NULL)
        {
            if (current->letter == temp)
            {
                if (current->next == NULL)	//insert end of list
                {
                    current->next = new_node;
                }
                else
                {
                    new_node->next = current->next; //insert middle of list
                    new_node->prev = current;

                    current->next = new_node;
                    current=new_node->next;
                    current->prev=new_node;
                }
                return list;
            }
            else
            {
                current = current->next;
            }
        }
    }
    return list;
}


/*
function to delete a node of a linked list
    parameter: list
*/
t_node *Delete(t_node *list)
{
    char temp;
    t_node *current;
    t_node *previous;
    printf("Input a node to delete: ");
    fflush(stdin);
    scanf("%c",&temp);
    printf("\n");
    if(list == NULL)
    {
        return NULL;
    }

    else
    {
        current = list;
        while(current !=NULL)
        {
            if(current->letter == temp)
            {

                //node is in head
                if(current->prev== NULL)
                {

                    previous = current;
                    current = current->next;
                    free(previous);
                    current->prev = NULL;
                    return current;
                }
                //node is in the middle
                else if(current->next == NULL)
                {
                    previous = current->prev;
                    free(current);
                    previous->next = NULL;
                    return list;
                }
                //node is in tail
                else
                {
                    previous = current->prev;
                    previous ->next = current->next;
                    previous = current->next;
                    previous->prev= current->prev;
                    free(current);
                    return list;
                }

            }
            else
            {
                current = current->next;
            }
        }
    }
    return list;
}


/*
function to delete a node of a linked list
    parameter: list
*/
void freeMemory(t_node *list)
{
    t_node *current, *previous;
    if(list == NULL)
    {

    }
    else //if list is not empty
    {
        current = list;
        previous = current;
        while(previous != NULL)
        {
            current = current->next;
            free(previous);
            previous = current;
        }
    }
}


/*
menu function
*/
int menu()
{
    int choice;

    printf("\n1-insert Before\n");
    printf("2-insert After\n");
    printf("3-Display list\n");
    printf("4-Reverse Display list\n");
    printf("5-Delete\n");
    printf("6-Quit\n");
    do
    {
        printf("Your choice: ");
        scanf("%d",&choice);
    }
    while ((choice<1)||(choice>6));
    return choice;
}
