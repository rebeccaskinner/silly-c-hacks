#include <stdio.h>
#include <trampoline.h>

void* var;
int data;

typedef void* (*func)();

func new_adder(int x) {
    func f;
    int addr(int y) { return x + y; }
    data = x;
    f = alloc_trampoline(&addr, &var, data)
}

int main() {
    add_nums f = new_adder(1);
    printf("%d\n", f(1));
}
