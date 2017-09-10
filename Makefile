%.o:%.c
	gcc -std=gnu99 -Wall -Wextra -fPIC -c $(<) -o $(@)

all: libhello.so main libborkwrite.so skip skip.s

libhello.so:hello.o
	gcc -shared -fPIC -pie -o libhello.so hello.o -Wl,-E

libborkwrite.so:borkwrite.o
	gcc -shared -fPIC -pie -o libborkwrite.so borkwrite.o -Wl,-E -ldl

main:main.o libhello.so
	ld $(<) -o $(@) -dynamic-linker /lib64/ld-linux-x86-64.so.2 -L. -lhello -lc -rpath=$(shell pwd) -e _lolwut

skip:skip.c
	gcc -std=gnu99 -fno-stack-protector -O0 -g -ggdb skip.c -o skip

skip.s:skip.c
	gcc -std=gnu99 -fno-stack-protector -O0 -S skip.c -o skip.s

clean:
	rm -fr libhello.so
	rm -fr *.o
	rm -fr main
	rm -fr libborkwrite.so
	rm -fr skip
	rm -fr core
	rm -fr skip.s

.PHONY: all clean
