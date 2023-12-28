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

unsigned int setbits(unsigned int x, int p, int n, int y)
{
    return ((~(~0 << n) & y) << (p + 1 - n)) | (~(~(~0 << n) << (p + 1 - n)) & x);
}

int main(void) 
{
    int p, n, y;
    unsigned int x = 3851;
    n = 2;
    p = 5;
    y = 3899;
    printf("x = %d\nBinary:", x);
    binary_print(x);
    printf("\nres:%d\nBinary:",setbits(x, p, n, y));
    binary_print(setbits(x, p, n, y));
}
