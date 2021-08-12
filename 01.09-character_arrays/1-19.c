/* Exercise 1-19. Write a function reverse(s) that reverses the character string s. Use it to
write a program that reverses its input a line at a time. */

#include <stdio.h>

#define MAXLINE 1000

int readline(char s[], int lim);
void reverse(char s[], char reversed[], int len);


int main(){
	int c;
	char s[MAXLINE];
	char reversed[MAXLINE];

	int len;

	while ((len = readline(s, MAXLINE)) > 0) {
		reverse(s, reversed, len);
		printf("%s\n", reversed);
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

void reverse(char s[], char reversed[], int len){
	for(int i = 0; i < len; i++){
		reversed[(len - 1) - i] = s[i];
	}
}