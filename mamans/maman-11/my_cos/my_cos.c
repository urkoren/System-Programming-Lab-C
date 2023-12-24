#include <stdio.h>
#include <math.h>
#define PI 3.14159

/* Function to calculate factorial of n */
unsigned long factorial(int n) {
    int i;
    unsigned long fact = 1;

    if (n < 0)
	;
    else {
        for (i = 1; i <= n; ++i) {
            fact *= i;
        }
    }
    return fact;
}

/* Function to calculate cos of x radians */
double my_cos(double x) {
    int i               = 1; 
    double result       = 1;
    double formula_res  = 1; 
    double fact_num     = 1;
    double sign, x2i;

/* Calculate cos till accuracy hits 1.0e-6 */
    while ( fabs(formula_res) >= 0.000001) {
        sign        = pow(-1, i);
        x2i         = pow(x, (2 * i));
        fact_num    = fact_num * (2*i-1) * 2*i;

        formula_res = sign * x2i / fact_num;
        result      += formula_res;
        i++;
    }
    return result;
}

/* Radians convertor */
double angle_to_radians(int angle) {
    double radian;

    radian = angle * PI / 180.0;
    radian = fmod(angle, 2 * PI);
    return radian;
}


int main() {
    int angle_input;
    double radian, cos_res, real_cos_res;

    printf("Enter angles in degrees (not radians): \n");

    while ( scanf("%d", &angle_input) != EOF) {
        radian          = angle_to_radians( angle_input );

        /* cos calls */   
        cos_res         = my_cos(radian);
        real_cos_res    = cos(radian);

        /* Res prints */
        printf("My cos of %f Radians: %.6f\n", radian, cos_res);
        printf("Bltin cos of %f Radians: %.6f\n", radian, real_cos_res);
    }
    return 0;
}
