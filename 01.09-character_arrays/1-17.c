/* Exercise 1-17. Write a program to print all input lines that are longer than 80 characters. */

/* Reads a set of text lines and prints the longest one. */
#include <stdio.h>

#define MAXLINE 1000
#define LIMIT 80

int readline(char s[], int lim);

int main(void) {
    int len;                // current line length
    int max;                // maximum lenght seen so far
    char line[MAXLINE];     // current input line
    char longest[MAXLINE];  // longest line saved here

	int c;

    max = 0;
    while ((len = readline(line, MAXLINE)) > 0) {
		if (len > LIMIT){
			printf("%s", line);
		}
    }
    return 0;
}

/* readline: read a line into s, return length */
int readline(char s[], int lim) {
    int c, i;

    for (i = 0; (i < lim - 1) && ((c = getchar()) != EOF) && (c != '\n'); ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

