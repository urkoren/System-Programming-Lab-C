# Flags
CC = gcc
CFLAGS = -ansi -pedantic -Wall -std=c99 -g 
INCLUDES = -I./src
HIDE = @

#Files and Directories
SOURCES = $(wildcard ./src/*.c)
OBJECTS = $(SOURCES:.c=.o)
BIN = mainmat

# -----
# Rules
# -----

.PHONY: all

all: $(BIN)

# -----
# Build
# -----

src/%.o: src/%.c
	@echo $(BIN): Building $@...
	@$(HIDE)$(CC) $(CFLAGS) -c $(INCLUDES) $^ -o $@

$(BIN): $(OBJECTS)
	@echo $(BIN): Linking...
	@$(HIDE)$(CC) $(CFLAGS) $(OBJECTS) -o $(BIN)
	@echo $(BIN): Done.


# -----
# Clean
# -----

clean: $(eval remove_obj := $(shell find ./ -type f -name "*.o"))
clean: $(eval remove_bin := $(shell find ./ -maxdepth 1 -executable -type f))
ifneq ($(remove_obj),)
	$(info Clean: Cleaning $(remove_obj)...)
	@rm $(remove_obj)
endif
ifneq ($(remove_bin),)
	$(info Clean: Cleaning $(remove_bin)...)
	@rm $(remove_bin)
endif
	$(info Clean: Done.)

