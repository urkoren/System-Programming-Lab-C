#include <stdio.h>

/* Return the first location in the string s where any character from the string c occurs, or -1 if s contains no characters from c.*/

int any(char s[], char c[])
{
    int i, j;

    for (i = 0; s[i] != '\0'; i++) {
        for (j = 0; c[j] != '\0'; j++) {
            if (s[i] == c[j]) {
                return i;
            }
        }
    }
    return -1;
}

int main(void) {
    char s[] = "Hello";
    char c[] = "lo";
    printf("%d", any(s,c));
    return 0;
}