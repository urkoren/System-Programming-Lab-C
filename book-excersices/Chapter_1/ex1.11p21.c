#include <stdio.h>
#define IN 1
#define OUT 0
 
/* Take a string and divide it to words and print 1 by 1 in new lines */

int main()
{
    int c,state; 
    state = OUT;
    while ((c=getchar()) != EOF) {
	if (c == ' ' || c == '\n' || c == '\t'){
		if (state == IN){
			putchar('\n');
			state = OUT;
		}
	}
	else{
		putchar(c);
		state = IN;
	}
    }    
    return 0;
}
