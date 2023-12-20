#include <stdio.h>
#define N_SPACES 5

int main(void) {
    int i, c;
    int space_counter = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') { 
            space_counter++;
            if (space_counter == N_SPACES) {
                putchar('\t');
                space_counter = 0;
                }
            continue;
        }
        else if (c == '\n') {
            putchar('\n');
            space_counter = 0;
            continue;
        }
        for (i = 0; space_counter != 0; space_counter--) {
            putchar('s');
        }
        putchar(c);
        }
    return 0;
    }

