#include "stack.h"

int main () {
    struct stack* list0 = stackInit();

    int dec = 114514;
    while(dec>0) {
        stackPush(list0,dec&15);
        dec>>=4;
    }

    stackReverse(list0);

    while(!stackIsEmpty(list0)) {
        int num = stackPop(list0);
        if (num<=9) 
            printf("%d",num);
        else printf("%c",(char)(num+55));
    }
    printf("\n");

    stackDestroy(list0);
}