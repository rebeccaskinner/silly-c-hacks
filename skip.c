#include <stdio.h>

void function() {
    char buffer1[2];
    int *ret;
    ret = buffer1 + 24;
    (*ret) += 8;
}

void main() {
    int x;
    x = 0;
    function();
    asm("nop");
    x = 1;
    printf("%d\n",x);
}
