#include "detab.h"
#define N_SPACES 4

int main(void) {
    int i, c;

    while ((c = getchar()) != EOF) {
        if (c == '\t'){
            for (i = 0; i < N_SPACES; ++i) {
                putchar(' ');
            }
            continue;
        }
        else if (c == '\n') {
            putchar('\n');
            continue;
            }
        putchar(c);
        }
    return 0;
    }

