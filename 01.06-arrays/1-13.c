/* Write a program to print a histogram of the lengths of words in its input. It is
easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging. */

#include <stdio.h>

void printHistogram(int array[], int size) {
    printf("\n###########################################\n");
	printf("Histogram of the lengts of words in its input\n");

	for (int i = 0; i < size; i++) {
		printf("%d:\t", i);
		for (int j = 0; j < array[i]; j++) {
			printf("#");
		}
		printf("\n");
	}
}

int main() {
    // max size of array
    int n = 20;

    // array of lengths
    int lengths[n];

    // initialize array
    for (int j = 0; j < n; j++)
        lengths[j] = 0;

    // c == current char
    // i == length of current word
    int c, i;
    c = i = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n') {
            if (i >= n) {
                lengths[n-1] += 1;
            } else {
                lengths[i] += 1;
            }
            i = 0;
        } else {
            ++i;
        }
    }
    printHistogram(lengths, 20);
}