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

struct stack {
    struct stack_node* top;
};

struct stack* stackInit ();

bool stackIsEmpty (struct stack* top);

bool stackPush (struct stack* stack,STACK_ELEM_TYPE data);

STACK_ELEM_TYPE stackTop (struct stack* stack);

STACK_ELEM_TYPE stackPop (struct stack* stack);

bool stackDestroy (struct stack* stack);

void stackReverse (struct stack* stack);

#endif /*STACK_H*/