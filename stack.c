#include "stack.h"

struct stack* stackInit () {
    struct stack* new_stack = (struct stack*)malloc(sizeof(struct stack));
    if (new_stack==NULL) {
        perror(__func__);
        return NULL;
    }

    new_stack->top = NULL;

    return new_stack;
}

bool stackIsEmpty (struct stack* stack) {
    if(stack==NULL) {
        printf("%s,%d,trying to empty a NULL\n",__func__,__LINE__);
        return true;
    }
    return stack->top==NULL;
}

bool stackPush (struct stack* stack,STACK_ELEM_TYPE data) {
    if(stack==NULL) {
        printf("invalid stack to push\n");
        return false;
    }

    struct stack_node* new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
    if(new_node==NULL){
        perror(__func__);
        return false;
    }
    new_node->data = data;

    new_node->next=stack->top;
    stack->top=new_node;

    return true;
}

STACK_ELEM_TYPE stackTop (struct stack* stack) {
    if(stackIsEmpty(stack)) {
        printf("invalid stack to top\n");
        return 0;
    }

    return stack->top->data;
}

STACK_ELEM_TYPE stackPop (struct stack* stack) {
    if(stackIsEmpty(stack)) {
        printf("invalid stack to pop\n");
        return 0;
    }

    struct stack_node* node = stack->top;
    STACK_ELEM_TYPE data = node->data;
    stack->top=node->next;
    free(node);

    return data;
}

bool stackDestroy (struct stack* stack) {
    if(stack==NULL){
        printf("trying to destory nothing\n");
        return false;
    }

    while(!stackIsEmpty(stack))
        stackPop(stack);

    free(stack);
    return true;
}

void stackReverse (struct stack* stack) {
    if (stackIsEmpty(stack)||stack->top->next==NULL)
        return;

    struct stack* tmp_stack = stackInit();
    while(!stackIsEmpty(stack))
        stackPush(tmp_stack,stackPop(stack));
    
    stack->top = tmp_stack->top;
    free(tmp_stack);
}