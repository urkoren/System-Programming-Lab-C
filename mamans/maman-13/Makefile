# Flags
CC = gcc
CFLAGS = -ansi -pedantic -Wall -std=c99 -g 
<<<<<<< HEAD
INCLUDES = -I./src/.
=======
INCLUDES = -I.
>>>>>>> f9d46f9 (compiling - requires debug)

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

<<<<<<< HEAD
src/%.o: src/%.c
=======
%.o: %.c
>>>>>>> f9d46f9 (compiling - requires debug)
	$(CC) $(CFLAGS) $(INCLUDES) -c $^ -o $@

clean:
	rm ./src/*.o
	rm $(BIN)
