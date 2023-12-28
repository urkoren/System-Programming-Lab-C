#include <stdio.h>

void expand(char s1[], char s2[])
{
    int i,j;

    for ( i=0, j=0; s1[i]!='\0'; i++)
    {
        if (s1[i] == '-')
        {
            i++;

            do{
                s2[j] = s2[j-1] + 1;
            }
            while(s1[i] != s2[j++]);
        }
        else 
            s2[j++] = s1[i];
    }
    s2[j] = 0;
}

int main(void)
{
    char s2[200] = {0};
    char s1[100] = {'a','-','z', 0};
    
    printf("s1: %s\n", s1);
    expand(s1,s2);
    printf("s2: %s\n", s2); 
    return 0;

}
