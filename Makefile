%.o:%.c
	gcc -fPIC -c $(<) -o $(@)

all: libhello.so main libborkwrite.so

libhello.so:hello.o
	gcc -shared -fPIC -pie -o libhello.so hello.o -Wl,-E

libborkwrite.so:borkwrite.o
	gcc -shared -fPIC -pie -o libborkwrite.so borkwrite.o -Wl,-E -ldl

main:main.o libhello.so
	ld $(<) -o $(@) -dynamic-linker /lib64/ld-linux-x86-64.so.2 -L. -lhello -lc -rpath=$(shell pwd) -e _lolwut

clean:
	rm -fr libhello.so
	rm -fr *.o
	rm -fr main
	rm -fr libborkwrite.so

.PHONY: all clean
