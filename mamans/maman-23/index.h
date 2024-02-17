#ifndef __INDEX_H__
#define __INDEX_H__

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*
* structs
*/

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

#endif /*!__INDEX__H__*/
