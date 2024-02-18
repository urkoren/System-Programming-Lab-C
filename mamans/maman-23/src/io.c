#include "io.h"

char
*get_word(char *line, char *delimiters)
{
    return strtok(line, delimiters);
}

char 
*get_line(char *line, FILE *file)
{
    return fgets(line, MAXWORD, file);
}

void 
treeprint(struct tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%-10s appears in line ", p->word);
	lineprint(p->lines);
        printf("\n");
        treeprint(p->right);
    }
}

void
lineprint(struct line_node *p)
{
    if (p != NULL) {
        lineprint(p->next);
	if ((p->next) != NULL)
	    printf(",");
        printf("%d", p->line_number);

    }
}

char 
*mystrdup(char *s)
{
	char *p;

	p = (char *) malloc(strlen(s)+1);
	if (p != NULL)
		strcpy(p, s);

	return p;
}
