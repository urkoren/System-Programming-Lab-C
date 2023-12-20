#include <stdio.h>
#define MAXLINE 1000
/* Check line and if there is a space or tab then remove it*/

int main()
 {
    int c;
    while ((c=getchar()) != EOF){
        if (c == '\n'){
            putchar('\n');
         }
        else if (c != '\t' && c != ' '){
            putchar(c);
        }
    }
        return 0;
}


