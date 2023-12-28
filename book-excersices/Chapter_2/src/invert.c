#include <stdio.h>

int binary_print(unsigned int n)
{
    int i;
    for (i = 0; n > 0; i++) {
        printf("%d",(n % 2));
        n = n / 2;
    }
    printf("\n");
}

unsigned invert(unsigned x, int p, int n)
{
    return (x ^ (((1 << (n)) -1) << (p - n + 1)));
}

int main(void)
{
    int x, p, n;
    x = 1516; 
    p = 5;
    n = 2;
    printf("x : %d\n", x);
    binary_print(x);
    printf("res : %u\n", invert(x,p,n));
    binary_print(invert(x,p,n));
    return 0;
}
