#include <stdio.h>

float celsiusToFahrenheit(float celsius){
	return (celsius * 9.0 / 5.0) + 32.0;
}

float fahrenheitToCelsius(float fahrenheit){
	return (fahrenheit - 32.0) * 5.0 / 9.0;
}


int main(){
	float celsius;

	printf("Celsius \tFahrenheit\n");
	for(celsius = 0.0; celsius <= 100.0; celsius += 5.0){
		printf("%6.2f\t\t%6.2f\n", celsius, celsiusToFahrenheit(celsius));
	}

	return 0;
}

