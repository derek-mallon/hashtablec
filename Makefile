all:
	clang -Ofast -Wall -c hashtable.c 
	clang -Ofast -Wall -c linkedlist.c
	clang -Ofast -Wall -dynamiclib -o libhashtable.dylib hashtable.o linkedlist.o
install: 
	mv libhashtable.dylib /usr/lib
	cp hashtable.h /usr/include
	rm hashtable.o
	rm linkedlist.o
