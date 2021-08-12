/* Exercise 1-18. Write a program to remove trailing blanks and tabs from each line of input,
and to delete entirely blank lines. */

#include <stdio.h>

#define MAXLINE 1000

int readline(char s[], int lim);

int main(){
	int c;
	char s[MAXLINE];
	char reversed[MAXLINE];

	int len;

	while ((len = readline(s, MAXLINE)) > 0) {
		int i = len-1;
		while (i > 0 && (s[i - 1] == ' ' || s[i - 1] == '\t')) {
			--i;
		}
		s[i] = '\0';
		if (i != 0){
			printf("%d: %s\n", i, s);
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