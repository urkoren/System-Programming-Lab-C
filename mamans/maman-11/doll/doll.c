#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void dollar_to_is(void)
{
    float f_dollar, res, dollar_sum, res_sum, dollar_value = 0.0;
    char s1[100];
    while ((scanf("%s", s1)) != EOF) {
        if (dollar_value != 0.0) {
	    /* Calculate and prints result */
            f_dollar 	= atof(s1);
            res 	    = f_dollar * dollar_value;
            res_sum 	+= res;
            dollar_sum 	+= f_dollar;
            printf("%-12.2f %-24.2f\n", f_dollar, res);
        }
        else {
	    /* Sets dollar value */
            dollar_value = atof(s1);
            printf("%-12c %s\n",'$', "IS");
        }
	}
    /* Prints the sum of results */
    printf("%-12.2f %-24.2f\n", dollar_sum, res_sum);
}

int main(void) {
    dollar_to_is();
    return 0;
}
