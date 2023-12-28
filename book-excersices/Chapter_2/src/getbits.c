#include <stdio.h>
// n = amount of bits
// p = position

int binary_print(unsigned int n)
{
    int i;
    for (i = 0; n > 0; i++) {
        printf("%d",(n % 2));
        n = n / 2;
    }
    printf("\n");
}

unsigned int getbits(unsigned int x, int p, int n)
{
    int temp;
    temp = (x >> (p + 1 - n)) & ~( ~0 << n);
    return temp;
}

int main(void) 
{
    int p, n;
    unsigned int x = 3899;
    n = 2;
    p = 5;
    printf("x = %d\nBinary:", x);
    binary_print(x);
    printf("\nres:%d\nBinary:",getbits(x, p, n));
    binary_print(getbits(x, p, n));
}
