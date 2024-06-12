#include "stack.h"

struct stack_node* stackInit () {
    struct stack_node* new_head = (struct stack_node*)malloc(sizeof(struct stack_node));
    if(new_head==NULL) {
        perror(__func__);
        return NULL;
    }

    new_head->next=NULL;
    return new_head;
}

bool stackIsEmpty (struct stack_node* head) {
    if(head==NULL) {
        printf("%s,%d,trying to empty a NULL\n",__func__,__LINE__);
        return true;
    }
    return head->next==NULL;
}

bool stackPush (struct stack_node* head,STACK_ELEM_TYPE data) {
    if(head==NULL) {
        printf("invalid stack to push\n");
        return false;
    }

    struct stack_node* new_node = (struct stack_node*)malloc(sizeof(struct stack_node));
    if(new_node==NULL){
        perror(__func__);
        return false;
    }

    new_node->next=head->next;
    head->next=new_node;
    new_node->data = data;

    return true;
}

STACK_ELEM_TYPE stackTop (struct stack_node* head) {
    if(stackIsEmpty(head)) {
        printf("invalid stack to top\n");
        return 0;
    }

    return head->next->data;
}

STACK_ELEM_TYPE stackPop (struct stack_node* head) {
    if(stackIsEmpty(head)) {
        printf("invalid stack to pop\n");
        return 0;
    }

    struct stack_node* node = head->next;
    STACK_ELEM_TYPE data = node->data;
    head->next=node->next;
    free(node);

    return data;
}

bool stackDestroy (struct stack_node* head) {
    if(stackIsEmpty(head)){
        if(head==NULL){
            printf("trying to destory nothing\n");
            return false;
        }
        free(head);
        return true;
    }

    struct stack_node* current = head;
    struct stack_node* next = head->next;

    while(current!=NULL) {
        free(current);
        current=next;
        next=next->next;
    }

    return true;
}