#include <stdio.h>

/* Count newlines,blanks and tabs in input */
main()
{
	int c, nl,bl,tb;
	nl = bl = tb = 0;
	while((c = getchar()) != EOF){
		if(c=='\n')
			++nl;
		else if(c=='\t')
			++tb;
		else if(c==' ')
			++bl;}
	printf("nl:%d tb:%d bl:%d\n",nl,tb,bl);
	
}
