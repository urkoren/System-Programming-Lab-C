#include <stdio.h>


int main(void) {
    int i, c, lim = 10;
    char s[10];

    for (i = 0; i < lim - 1; i++) {
        if ((c=getchar()) != '\n') {
            if (c != EOF) {
                s[i] = c;
            } else {break;}
        } else {break;}
    }
    s[i] = '\0';
    printf("result: %s", s); 
    return 0;
}
