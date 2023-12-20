# Variables
CC=gcc
CFLAGS=-ansi -pedantic -Wall -g

# Binaries
DETAB=bin/detab

# Rules
all: detab

detab: src/detab.c src/detab.h
    $(CC) $(CFLAGS) src/detab.c -o $(DETAB)

clean: 
    $(shell rm ./bin/*)
