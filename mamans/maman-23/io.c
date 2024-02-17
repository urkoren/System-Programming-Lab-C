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
        printf("%s: ", p->word);
        struct line_node *current;
        current = p->lines;
        while (current != NULL) {
            printf("%d ", current->line_number);
            current = current->next;
        }
        printf("\n");
        treeprint(p->right);
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
