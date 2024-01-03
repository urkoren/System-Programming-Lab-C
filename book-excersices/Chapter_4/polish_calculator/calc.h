#include <stdio.h>
#include <stdlib.h>  // for atof()
#include <ctype.h>
#include <math.h>

#define MAXOP   100  // max size of operand or operator
#define NUMBER  '0'  // signal that a number was found

#define MAXVAL  100  // max depth of val stack
#define BUFSIZE 100  //

int getop(char []);
void push(double);
double pop(void);
static int getch(void);
static void ungetch(int);




