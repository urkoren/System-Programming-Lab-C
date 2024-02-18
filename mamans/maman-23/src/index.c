/*
 * Builds an index of words and their line numbers from text files.
 */

#include "io.h"
#include "index.h"
#include "binary_tree.h"

int 
main(int argc, char *argv[])
{
    char *file_path;
    FILE *file;
    int file_count = 1;
    struct index findex;
    findex.root = NULL;
    
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
