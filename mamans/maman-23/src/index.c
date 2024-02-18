/*
 * Builds an index of words and their line numbers from text files.
 */

#include "index.h"
#include "binary_tree.h"
#include "io.h"

int main(int argc, char *argv[]) {
  char *file_path;
  FILE *file;
  int file_count = 1;
  struct index findex;
  findex.root = NULL;

  while (file_count < argc) {
    file_path = argv[file_count++];
    file = fopen(file_path, "r");
    if (file == NULL) {
      fprintf(stderr, "Error opening file %s: ", file_path);
      perror("");  
      continue;
    }

    fparse_to_findex(file, &findex);
    treeprint(findex.root);
    fclose(file);
    reset_findex(&findex);
  }

  return 0;
}
