#include "my_cos.h"

#define FORMULA_PRINT_FORMAT\
	"formula: (-1)^%d * ( %d ^ 2 * %d ) / (2 * %d)!\n"
#define FORMULA_PRINT_ARGS(i, x)\
	(i), (x), (i), (i)

#define POGCHAMP_PRINT(i, x)\
    fprintf( stdout, FORMULA_PRINT_FORMAT, FORMULA_PRINT_ARGS((i), (x)) )


double single_formula(unsigned int i, unsigned int x);

int main(void) 
{
   	double single_formula_res;
	unsigned int i, x;

    i = 1;
    x = 150;
    
	for (i = 1; i < 20; i++) {
		single_formula_res = single_formula(
			i, x		
		);
		fprintf( stdout, "res: %.10f\n", single_formula_res);
	}
	

    return 0;
}

double single_formula(unsigned int i, unsigned int x)
{
    /* Variable Declarations */
    unsigned long   factorial_res;
    int             final_multiplier;
    unsigned long   xpow_base, xpow_exponent;
    double          complicated_formula_res, xpow_res;
    
    /* Variable Definitions */
    final_multiplier    = (i % 2 == 0) ? 1: -1;
    xpow_base           = x;
    xpow_exponent       = 2 * i;
    xpow_res            = pow(xpow_base, xpow_exponent);
    factorial_res       = factorial(2 * i);
    complicated_formula_res = final_multiplier * xpow_res / factorial_res;

	
	POGCHAMP_PRINT(i, x);
	fprintf(stdout, "single_form_res: %.4f\n", complicated_formula_res);
    return factorial_res;
}
