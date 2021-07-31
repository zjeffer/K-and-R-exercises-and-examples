#include <stdio.h>

int main() {
    /* Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank. */
    int i = 0;
    int c;
    while ((c = getchar()) != EOF) {
        if (c != ' ') {
            putchar(c);
            i = 0;
        } else {
            if (i == 0) {
                putchar(' ');
                i++;
            }
        }
    }
    return 0;
}