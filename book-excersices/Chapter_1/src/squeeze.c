#include <stdio.h>

void squezze(char s[], char c[])
{
    int i, j, k;

    for (i = j = 0; s[i] != '\0'; i++){
        for (k = 0; c[k] != '\0'; k++){
            if (s[i] == c[k]){
                break;
            }
        }
        if (c[k] == '\0')
            s[j++] = s[i];
    }
    s[j] = '\0';
}

int main(void) {
    char s[] = "Hello";
    char c[] = "le";
    squezze(s,c);
    printf("%s", s);
    return 0;


}
