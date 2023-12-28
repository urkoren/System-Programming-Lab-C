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

unsigned rightrot(unsigned x, unsigned n)
{
    while (n > 0) 
    {
        if ((x & 1) == 1)
        {
            x = (x >> 1) | ~(~0U >> 1);
        }
        else
        {
            x = ( x >> 1);
        }
        n--;
    }
    return x;
}

int main(void)
{
    unsigned x, n;
    x = 1500;
    n = 3;

    printf("%d\n", x);
    binary_print(x);
    printf("%u\n", rightrot(x,n));
    binary_print(rightrot(x,n));
    return 0;
}
