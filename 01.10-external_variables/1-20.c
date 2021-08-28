/* Exercise 1-20. Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
Should n be a variable or a symbolic parameter? */

#include <stdio.h>

#define TABSTOP 8
#define MAXLINE 1000

int readline(char s[], int lim);
void detab(char line[], int len, char detabbed[]);


int main(){
	int len;
	char line[MAXLINE];
	char detabbed[MAXLINE];

	while ((len = readline(line, MAXLINE)) > 0){
		detab(line, len, detabbed);
		printf("%s", detabbed);
	}

	return 0;
}


void detab(char line[], int len, char detabbed[]){
	int i, j;
	i = j = 0;
	while (i < len){
		if (line[i] == '\t'){	
			// **\t 			=> **000000 (8 - (2 % 8)) 	= 6
			// ****\t 			=> ****OOOO (8 - (4 % 8)) 	= 4
			// ******** **\t 	=> ******** **000000 (8 - (10 % 8))	= 6
			int amountOfSpaces = TABSTOP - (j % TABSTOP);
			for (int c = 0; c < amountOfSpaces; c++){
				detabbed[j] = ' ';
				j++;
			}
		} else {
			detabbed[j] = line[i];
			++j;
		}
		++i;
	}
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