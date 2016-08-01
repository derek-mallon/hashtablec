all:
	clang -Ofast -Wall -c hashtable.c 
	clang -Ofast -Wall -c linkedlist.c
	clang -Ofast -Wall -shared -o libhashtable.so hashtable.o linkedlist.o
install: 
	mv libhashtable.so /usr/lib
	cp hashtable.h /usr/include
	rm hashtable.o
	rm linkedlist.o
