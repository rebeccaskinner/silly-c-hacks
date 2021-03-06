#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dlfcn.h>
#include <string.h>
#include <ctype.h>

void *handle = 0;
const char *libc_path = "/lib/x86_64-linux-gnu/libc-2.23.so";
ssize_t (*libc_write)(int,const void*,size_t);

ssize_t write(int fd, const char* buf, size_t count) {
    static const char* borkbuffer = "bork";
    static const size_t borksize = 4;
    static size_t offset = 0;

    if (NULL == libc_write) {
        return -1;
    }

    for (size_t i = 0; i < count; i++) {
        if (buf[i] == '\n') {
            libc_write(fd, buf + i, 1);
            continue;
        }
        libc_write(fd, borkbuffer + offset, 1);
        offset = (offset + 1) % borksize;
    }
    return count;
}

__attribute__((constructor))
void init() {
    if (NULL == (handle = dlopen(libc_path, RTLD_LAZY))) {
        return;
    }
    if (NULL == (libc_write = dlsym(handle, "write"))) {
        return;
    }
}

__attribute__((destructor))
void cleanup() {
    if (NULL != handle) {dlclose(handle);}
}

int main() {
    const char* out = "hello, world";
    write(fileno(stdout), out, strlen(out));
    return 0;
}
