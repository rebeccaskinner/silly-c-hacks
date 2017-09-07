#include "hello.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LEN(x) (sizeof(x)/sizeof(*x))

const char* genMsg(const char* (*cb)(const char** strings, size_t len))
{
    static const char* msgs [] = {"STL Polyglots", "World", "Friends"};
    return cb(msgs, 3);
}

const char* world() {
    int x;
    const char* cb(const char** strings, size_t len) {
        return strings[x % len];
    }
    return genMsg(cb);
}

void _lolwut() {
    const char* h = hello();
    const char* w = world();

    write(1, h, strlen(h));
    write(1, "\n", 1);
    write(1, w, strlen(w));
    write(1, "\n", 1);
    exit(0);
}
