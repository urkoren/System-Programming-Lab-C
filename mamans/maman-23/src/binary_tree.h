#ifndef BINARY_TREE_H_
#define BINARY_TREE_H_ 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <assert.h>

#include "io.h"
#include "index.h"

extern void 
fparse_to_findex(FILE *file, struct index *findex);
/* Parses a file and adds words to the index. */

extern struct tnode 
*addtree(struct tnode *p, char *w, int line_count);
/* Adds a word to the index tree. */

struct tnode
*create_new_tnode(struct tnode *p, char *w, int line_count);
/* Creates a new tree node. */

extern struct line_node 
*create_new_line_node(int line_count);
/* Creates a new line node. */

extern int 
check_line(struct tnode *p, int line_count);
/* Checks if a line number is already present in the node. */

extern void 
append_line_count(struct tnode *p, int line_count);
/* Appends a line number to the node. */

extern struct tnode 
*talloc(void);
/* Allocates memory for a tree node. */

extern void 
reset_findex(struct index *findex);
/* Resets the index structure. */

extern void 
free_tree(struct tnode *p);
/* Frees memory allocated for the tree. */

extern void 
free_line_list(struct line_node *lines);
/* Frees memory allocated for the line list. */

#endif /* BINARY_TREE_H_ */
