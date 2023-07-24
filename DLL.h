#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/*
node structure
*/
typedef struct node
{
    char letter;
    struct node *next;
    struct node *prev;
}t_node;

t_node *create();
t_node *insertBefore(t_node *list, t_node *new_node, char temp);
t_node *insertAfter(t_node *list, t_node *new_node, char temp);
void print(t_node *list);
void printReverse(t_node *list);
t_node *Delete(t_node *list);
void freeMemory(t_node *list);
int menu();

#endif // DLL_H_INCLUDED
