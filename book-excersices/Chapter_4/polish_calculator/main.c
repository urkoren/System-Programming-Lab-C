
#include "calc.h"

/* reverse Polish calculator */
int main(void)
{
    int type, i;
    double op2, op1;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {

        switch (type) {
            /*case 'c':
                for (; sp > 0; sp--, val[sp] = 0);
                break;
            case 'p':
                printf("top element: %f\n", val[sp]);
                for (i=0; i<=sp; i++)
                    printf("val %d : %f\n", i, val[i]);
                break;
            case 'd':
                val[sp+1] = val[sp++];
                break;*/
            case 's': 
               op1 = pop();
               op2 = pop();
               printf(" %f to %f", op1 , op2);
               push(op1);
               push(op2); 
               break;
            case 'n':
                push(sin(pop()));
                break;
            case 'x':
                push(exp(pop()));
                break;
            case '^': 
                op2 = pop();
                push(pow(pop(), op2));
                break;
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("Error: cannot divide by 0\n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            case '%':
                op1 = pop();
                op2 = pop();
                if (op1 >= 0 && op2 >= 0)
                    push((int) op2  % (int)op1);
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}



