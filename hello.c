#include <stdio.h>

__attribute__((weak))
const char* hello() {
    static const char* hello = "hello";
    return hello;
}

__attribute__((weak))
const char* world() {
    static const char* hello[] = {"mercury","venus","earth","mars"};
    return 1[hello];
}

int main()
{
    printf("library %s, %s\n", hello(), world());
    return 0;
}
