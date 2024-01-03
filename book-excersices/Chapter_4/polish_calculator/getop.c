#include "calc.h"

char buf[BUFSIZE];  // buffer for ungetch
int bufp = 0;       // next free position in buffer

/* getop: get next operator or numeric operand */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c;  
    i = 0;
    if (isdigit(c))  
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')   
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}


/* getch: get a (possibly pushed back) character */
static int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}


/* push char back on input */
static void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
