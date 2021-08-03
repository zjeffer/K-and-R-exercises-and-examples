/* Write a program to print a histogram of the frequencies of different characters
in its input. */

#include <stdio.h>

// for tolower function
#include <ctype.h>

char* alphabet = "abcdefghijklmnopqrstuvwxyz";

void printHistogram(int array[], int size) {
    printf("\n###########################################\n");
	printf("Histogram of the lengts of words in its input\n");

	for (int i = 0; i < size; i++) {
		printf("%c: \t", alphabet[i] - 32);
		for (int j = 0; j < array[i]; j++) {
			printf("#");
		}
		printf("\n");
	}
}

int main() {
    // max size of array
    int n = 26;

    // array of lengths
    int lengths[n];

    // initialize array
    for (int j = 0; j < n; j++)
        lengths[j] = 0;

    // c == current char
    int c;
    c = 0;

    while ((c = getchar()) != EOF) {
        if (c != ' ' && c != '\n') {
			lengths[tolower(c) - 'a']++;
		}
    }
    printHistogram(lengths, n);
}