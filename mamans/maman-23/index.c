#include "index.h"

int 
main(int argc, char *argv[])
{
    char *file_path;
    FILE *file;
    int file_count = 1;
    struct index findex;
    
    while(file_count < argc) {
        file_path = argv[file_count];
        file = fopen(argv[file_count], "r");
        if (file == NULL) {
            printf("Error opening file: %s\n", file_path);
            return -1;
        }

        fparse_to_findex(file, &findex);
        treeprint(findex.root);
        fclose(file);
        file_count++;
        reset_findex(&findex);
        } 

    return 0;

}

void 
reset_findex(struct index *findex) {
    if (findex->root != NULL) {
        free_tree(findex->root);
        findex->root = NULL;
    }
}

void 
free_tree(struct tnode *p) {
    if (p != NULL) {
        free_tree(p->left);
        free_tree(p->right);
        free_line_list(p->lines); 
        free(p->word);
        free(p);
    }
}

void 
free_line_list(struct line_node *lines) {
    struct line_node *current = lines;
    while (current != NULL) {
        struct line_node *temp = current;
        current = current->next;
        free(temp);
    }
}

void 
fparse_to_findex(FILE *file, struct index *findex) {
    int line_count = 1;
    char line[MAXWORD];
    char *key;
    
    while (fgets(line, MAXWORD, file) != NULL) {
        /* Add get_line + get_word */
        char *token = strtok(line, " \t\n");
        while (token != NULL) {
            key = token;
            if (findex->root != NULL) {
                findex->root = addtree(findex->root, key, line_count); 
            } else {
                findex->root = addtree(NULL, key, line_count);
            }
            token = strtok(NULL, " \t\n");
        }
        line_count++;
    }
}


struct tnode 
*addtree(struct tnode *p, char *w, int line_count) {
    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = mystrdup(w);
        p->lines = create_new_line_node(line_count);
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) {
        if (check_line(p, line_count) == 0)
            append_line_count(p, line_count);
    } else if (cond < 0)
        p->left = addtree(p->left, w, line_count);
    else
        p->right = addtree(p->right, w, line_count);
    
    return p;
}

struct line_node 
*create_new_line_node(int line_count)
{
        struct line_node *new_node;
        new_node = (struct line_node *)malloc(sizeof(struct line_node));
        if (new_node == NULL) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        new_node->line_number = line_count;
        new_node->next = NULL;
        return new_node;
}

int 
check_line(struct tnode *p, int line_count) {
    struct line_node *current;
    current = p->lines;
    while (current != NULL) {
        if (current->line_number == line_count)
            return 1; 
        current = current->next;
    }
    return 0; 
}


void 
append_line_count(struct tnode *p, int line_count) {
    struct line_node *new_node;
    new_node = (struct line_node *)malloc(sizeof(struct line_node));
    if (new_node == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->line_number = line_count;
    new_node->next = p->lines;
    p->lines = new_node;
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


struct tnode 
*talloc(void)
{
	return (struct tnode *) malloc(sizeof(struct tnode));
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

