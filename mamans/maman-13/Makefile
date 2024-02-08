# Flags
CC = gcc
CFLAGS = -ansi -pedantic -Wall -std=c99 -g 
INCLUDES = -I./src

#Files and Directories
SOURCES = $(wildcard ./src/*.c)
OBJECTS = $(SOURCES:.c=.o)
BIN = mainmat

# Rules
all: $(BIN)

$(BIN): $(OBJECTS)
	@echo Building
	$(CC) $(CFLAGS) $^ -o $@
	@echo Cleaning up
	rm $(OBJECTS)
	@echo Done.

src/%.o: src/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

clean:
	rm ./src/*.o
	rm $(BIN)
