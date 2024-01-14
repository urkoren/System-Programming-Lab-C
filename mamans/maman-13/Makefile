CC = gcc
CFLAGS = -ansi -pedantic -Wall -std=c89
INCLUDES = -I.

all: mymat

mymat: mymat.o
	$(CC) $(CFLAGS) mymat.o -o mymat

mymat.o: mymat.c
	$(CC) $(CFLAGS) $(INCLUDES) -c mymat.c -o mymat.o

clean:
	rm ./*.o
	rm mymat