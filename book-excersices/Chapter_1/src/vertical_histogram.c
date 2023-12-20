#include <stdio.h>
#define IN 1
#define OUT 0

/* Function that take string and print their length in horizontal histogram */

int main()
{
/* Create verablies */
    int i,c,d,state,n_letters,n_words;
    n_letters = n_words = d = 0 ;
    int hor_list[10];
    for (i = 0;i < 10;++i)
	hor_list[i] = 0;
    state = OUT;


    while ((c=getchar()) != EOF) {
	if (c == ' ' || c == '\n' || c == '\t'){
		if (state == IN){
			state = OUT;
			d++;
			n_letters = 0;
		}
	}
	else{
		hor_list[d]++;
		n_letters++;
		state = IN;
	}
   } 

    for(i=10;i>0;--i){
    	for(d=0;hor_list[d] > 0;++d){
		if (hor_list[d] >= i){
			putchar('|');
			putchar(' ');
			}
			
		else{
			putchar('*');
			putchar(' ');
		}
	}
	putchar('\n');
	}
		
	return 0;    
	
}
