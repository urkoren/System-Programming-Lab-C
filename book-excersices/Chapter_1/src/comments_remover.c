#include <stdio.h>
#define SLASH '/'
#define STAR '*'

int main(void) {
    int c;
    char temp = '\0';
    int on = 1;
    int counter = 0;
    while ((c = getchar()) != EOF) {
        if (c == SLASH) {
            if (counter == 0) {
                temp = c;
                counter++;
                continue;
            }
            else if (counter == 1 && temp == STAR) {
                on = 1;
                counter = 0;
                temp = 0;
                continue;
            }

        }
        else if (c == STAR) {
            if (counter == 1 && temp == SLASH) {
                on = 0;
                counter = 0;
                temp = 0;
                continue;
            }
            else if (counter == 0) {
                temp = c;
                counter++;
                continue;
            }
        }
        if (temp) {
            putchar(temp);
            temp = 0;
            counter = 0;
        }
        if (on) {
            putchar(c);
            counter = 0;
        }
    }

    return 0;
}
