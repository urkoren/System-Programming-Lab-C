#ifndef __INDEX_H__
#define __INDEX_H__

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100

struct line_node {
    int line_number;
    struct line_node *next;
};

struct tnode {
    char *word;
    struct line_node *lines;
    struct tnode *left;
    struct tnode *right;
};


struct index {
    struct tnode *root;
};

extern void 
fparse_to_findex(FILE *file, struct index *findex);

extern struct line_node 
*create_new_line_node(int line_count);

extern int 
check_line(struct tnode *p, int line_count);

extern void 
append_line_count(struct tnode *p, int line_count);

extern void 
treeprint(struct tnode *p);

extern struct tnode 
*addtree(struct tnode *p, char *w, int line_count);

extern struct tnode 
*talloc(void);

extern char 
*mystrdup(char *s);

extern void 
reset_findex(struct index *findex);

extern void 
free_tree(struct tnode *p);

extern void 
free_line_list(struct line_node *lines);

extern void 
finalize(struct index *findex);

#endif /*!__INDEX__H__*/
