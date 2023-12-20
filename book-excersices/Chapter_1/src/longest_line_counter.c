#include <stdio.h>
#define MAXLINE 1000
/* Count input lines and return the length of the longest line */

int countline(int maxline);
int main()
{
  int len,max;
  max = 0;
  while ((len = countline(MAXLINE)) > 0)
    if (len > max) {
        max = len;
    }
    if (max>0)
        printf("max len line: %d", max);
    return 0;
}

int countline(int lim)
 {
         int c,i;
                 
         for (i=0; i<lim-1 && (c=getchar()) != EOF && c!='\n'; ++i)
         if (c == '\n'){
                 ++i;
         }
         return i;
}
