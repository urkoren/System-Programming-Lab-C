#include <stdio.h>

/* Use a function that convert fahrenheit to Celsius*/
float celsius;
int lower,upper,step;

float fahr_to_cels(int fahr){
	return((5.0/9.0) * (fahr-32));
	}

main(){
	
	float celsius, fahr;
	int lower,upper,step;
	lower = 0;
	upper = 300;
	step = 20;
	fahr = lower;
	while(fahr <= upper){
		celsius = fahr_to_cels(fahr);
		printf("%3.0f %6.1f\n",fahr,celsius);
		fahr += step;
	}
	return 0;
}

