
CC=gcc

bstr.o: bstr.c bstr.h
	$(CC) -c bstr.c  

bstrtest.o: bstrtest.c bstr.h
	$(CC) -c bstrtest.c 

all:  bstr.o bstrtest.o
	$(CC) bstr.o bstrtest.o -obstrtest

test: all
	./bstrtest

