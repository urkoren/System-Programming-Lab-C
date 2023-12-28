#include <stdio.h>

char lower(char c)
{
    c = c >= 65 && c <= 90 ? c + 32 : c;
    return c;
}

int main(void)
{
    char c = getchar();
    printf("%c", lower(c));
    return 0;
}
