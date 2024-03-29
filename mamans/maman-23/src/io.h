#ifndef IO_H_
#define IO_H_

#include "includes.h"
#include "index.h"


#define MAXWORD 100

char *get_word(char *line, char *delimiters);
/* Extracts a word from a line. */

char *get_line(char *line, FILE *file);
/* Reads a line from a file. */

extern void treeprint(struct tnode *p);
/* Prints the index tree. */

void lineprint(struct line_node *p);
/* Prints the lines list */

extern char *mystrdup(char *s);
/* Duplicates a string. */

#endif /* IO_H_ */
