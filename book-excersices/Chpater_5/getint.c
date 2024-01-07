#include <ctype.h>
#include <stdio.h>
#define BUFSIZE 100  
#define SIZE 100

char buf[BUFSIZE];  
int bufp = 0;      

/* getch: get a (possibly pushed back) character */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}


/* push char back on input */
void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))
    ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;        
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + ( c - '0');
    *pn *= sign;
    if (c!=EOF)
        ungetch(c);
    return c;
}

int main(void)
{
    int test;
    int status;

    status = getint(&test);
    printf("status: %d\n", status);
    printf("value: %d\n\n", test);

    return 0;
}

