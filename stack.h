#ifndef _STACK_H
#define _STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned char STACK_ELEM_TYPE;

struct stack_node {
    STACK_ELEM_TYPE data;
    struct stack_node* next;
};

struct stack_node* stackInit ();

bool stackIsEmpty (struct stack_node* head);

bool stackPush (struct stack_node* head,STACK_ELEM_TYPE data);

STACK_ELEM_TYPE stackPop (struct stack_node* head);

STACK_ELEM_TYPE stackTop (struct stack_node* head);

bool stackDestroy (struct stack_node* head);

#endif /*STACK_H*/