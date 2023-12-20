#include <stdio.h>
#define LIMITER 10

/* Fold long lines input into smaller lines*/

int main(void) {
    int c;
    int counter = 0;
    
    while ((c = getchar()) != EOF) {
        if (counter == LIMITER) {
            putchar('\n');
            counter = 0;
        }
        putchar(c);
        counter++;
    }
    return 0;
}
