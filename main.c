#include "hello.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

const char* world() {
    static const char* who = "STL Polyglots";
    return who;
}

void _lolwut() {
    write(1, hello(), strlen(hello()));
    exit(0);
}
