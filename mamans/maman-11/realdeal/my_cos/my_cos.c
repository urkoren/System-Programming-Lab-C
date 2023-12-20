#include <stdio.h>
#include <math.h>

unsigned long factorial(int n) {
    int i;
    unsigned long res = 1;

    for (i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

double my_cos(double x, int terms) {
    int sign, i;
    double result = 1.0;
    unsigned long factorial_res;
    double formula_res, xpow_res;

    for (i = 1; i <= terms; i++) { 
        xpow_res                = pow(x, 2 * i);
        factorial_res           = factorial(2 * i);
        sign                    = (i % 2 == 0) ? 1 : -1;
        formula_res             = sign * xpow_res / factorial_res;

        result += formula_res;
/*        printf("sign: %d, xpow res: %lu, factorial res: %lu\n", sign, xpow_res, factorial_res);*/
/*        printf("added %lu to res: %.4f, i: %d\n", formula_res, result, i); */
    }
    return result;
}

int main() {
    float PI = 3.14159;
    double angle, cosine;
    int angle_input, num_terms = 10;

    while (scanf("%d", &angle_input) != EOF);{
        angle = angle_input * PI / 180.0;
        angle = fmod(angle, 2 * PI);
        cosine = my_cos(angle, num_terms);

        printf("My cos of %f Radians: %.6f\n", angle, cosine);
        printf("Bltin cos of %f Radians: %.6f\n", angle, cos(angle));
    }
    return 0;
}
