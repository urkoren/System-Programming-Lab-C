#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
    float f_dollar, res, dollar_sum, res_sum, dollar_value = 0.0;
    char s1[100];
    while ((scanf("%s", s1)) != EOF) {
        if (dollar_value != 0.0) {
            f_dollar = atof(s1);
            res = f_dollar * dollar_value;
            res_sum += res;
            dollar_sum += f_dollar;
            printf("%-8.2f %-18.2f\n", f_dollar, res);
        }
        else {
            dollar_value = atof(s1);
            printf("%-8c %s\n",'$', "IS");
        }
	}
    printf("%-8.2f %-18.2f\n", dollar_sum, res_sum);
	return 0;
}
