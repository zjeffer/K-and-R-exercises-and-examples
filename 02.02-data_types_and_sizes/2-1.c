/* Exercise 2-1. Write a program to determine the ranges of char, short, int, and long
variables, both signed and unsigned, by printing appropriate values from standard headers
and by direct computation. Harder if you compute them: determine the ranges of the various
floating-point types. */

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	
	// unsigned
	printf("Unsigned char: %u\n", UCHAR_MAX);
	printf("Unsigned short: %u\n", USHRT_MAX);
	printf("Unsigned int: %u\n", UINT_MAX);
	printf("Unsigned long: %lu\n", ULONG_MAX);

	// signed
	printf("Signed char: %d to %d\n", SCHAR_MIN, SCHAR_MAX);
	printf("Signed short: %d to %d\n", SHRT_MIN, SHRT_MAX);
	printf("Signed int: %d to %d\n", INT_MIN, INT_MAX);
	printf("Signed long: %li to %li\n", LONG_MIN, LONG_MAX);

	return 0;
}