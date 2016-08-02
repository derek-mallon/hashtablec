all:
	clang -Ofast -Wall -c hashtable.c 
	clang -Ofast -Wall -dynamiclib -o libhashtable.dylib hashtable.o -llinkedlist
install: 
	mv libhashtable.dylib /usr/lib
	cp hashtable.h /usr/include
	rm hashtable.o
