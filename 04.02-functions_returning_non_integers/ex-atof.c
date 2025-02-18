#include <ctype.h>
#include <stdio.h>

double atof(char s[]);

int main(void) {
    char s[] = "3.13";
    double n;

    n = atof(s);
    printf("%.3lf\n", n);
    return 0;
}

/* atof: convert string s to double */
double atof(char s[]) {
    double val, power;
    int i, sign;

    for (i = 0; s[i] == ' '; i++)  // skip white space
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if ((s[i] == '+') || (s[i] == '-'))
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = val * 10.0 + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return (sign * val / power);
}
