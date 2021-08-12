/* Exercise 1-16. Revise the main routine of the longest-line program so it will correctly print
the length of arbitrary long input lines, and as much as possible of the text. */

/* Reads a set of text lines and prints the longest one. */
#include <stdio.h>

#define MAXLINE 10

int readline(char s[], int lim);
void copy(char to[], char from[]);

int main(void) {
    int len;                // current line length
    int max;                // maximum lenght seen so far
    char line[MAXLINE];     // current input line
    char longest[MAXLINE];  // longest line saved here

	int c;

    max = 0;
    while ((len = readline(line, MAXLINE)) > 0) {
		if (line[len] != '\n'){
			while (((c = getchar()) != EOF) && (c != '\n')){
				++len;
			}
		}
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0) {  // there was a line
		if (max > MAXLINE){
			printf("%d: %s...\n", max, longest);
		} else {
			printf("%d: %s\n", max, longest);
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

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}
