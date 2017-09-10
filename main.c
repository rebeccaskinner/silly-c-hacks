#include "hello.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LEN(x) (sizeof(x)/sizeof(*x))

const char* genMsg(const char* (*cb)(const char** strings, size_t len))
{
    static const char* msgs [] = {"STL Polyglots", "World", "Friends"};
    return cb(msgs, LEN(msgs));
}

const char* world() {
    int x;

    return genMsg(({
                const char* cb(const char** strings, size_t len) {
                    return strings[x % len];
                };
                cb;
            }));
}

void writeWorld() {
    const char* w = world();
    write(1, w, strlen(w));
}

void _lolwut() {
    const char* h = hello();

    size_t h_len = strlen(h);
    write(1, h, h_len);
    write(1, "\n", 1);
    writeWorld();
    write(1, "\n", 1);
    exit(0);
}
