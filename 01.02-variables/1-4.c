#include <stdio.h>

int main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = -40;   /* lower limit of temperature scale */
    upper = 120; /* upper limit */
    step = 20;   /* step size */

    printf("Celsius\tFahr\n");
    celsius = lower;
    while (celsius <= upper) {
        fahr = celsius / (5.0 / 9.0) + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius += step;
    }
}