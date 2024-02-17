CC = gcc
OBJS = index.o
EXEC = index
DEBUG_FLAG = -g
COMP_FLAG = -Wall -ansi -pedantic $(DEBUG_FLAG)

$(EXEC): $(OBJS)
	$(CC) $(DEBUG_FLAG) $(OBJS) -o $@

index.o: index.c index.h
	$(CC) -c $(COMP_FLAG) $*.c

clean:
	rm -f $(OBJS)
