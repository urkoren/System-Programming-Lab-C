# Flags
CC = gcc
CFLAGS = -ansi -pedantic -Wall -std=c90
INCLUDES = -I.

#Files and Directories
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

# Rules
all: mainmat

mainmat: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

mainmat.o: mainmat.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

mymat.o: mymat.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

io.o: io.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

clean:
	rm ./*.o
	rm mymat
