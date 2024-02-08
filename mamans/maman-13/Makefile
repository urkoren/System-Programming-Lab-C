# Flags
CC = gcc
CFLAGS = -ansi -pedantic -Wall -std=c99 -g 
INCLUDES = -I.

#Files and Directories
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

# Rules
all: mainmat

mainmat: $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

clean:
	rm ./*.o
	rm mymat
