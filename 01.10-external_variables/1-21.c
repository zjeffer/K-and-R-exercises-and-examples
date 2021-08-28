/* Exercise 1-21. Write a program entab that replaces strings of blanks by the minimum
number of tabs and blanks to achieve the same spacing. Use the same tab stops as for detab.
When either a tab or a single blank would suffice to reach a tab stop, which should be given
preference? */

#include <stdio.h>

#define TABSTOP 8
#define MAXLINE 1000

void detab(char line[], int len, char detabbed[]);
int readline(char s[], int lim);

int main(){
	int c, len;
	char line[MAXLINE];

	int tabs = 0;
	int blanks = 0;
	
	for(int i = 1; (c = getchar()) != EOF; i++){
		if (c == ' '){
			if ((i % TABSTOP) == 0){
				blanks = 0;
				tabs++;
			} else {
				blanks++;
			}
		} else {
			while (tabs > 0){
				putchar('\t');
				tabs--;
			}
			if (c == '\t'){
				blanks = 0;
			}
			while (blanks > 0){
				putchar(' ');
				blanks--;
			}
			putchar(c);

			if (c == '\n'){
				i = 0;
			} else if(c == '\t'){
				i = i + (TABSTOP - (i-1) % TABSTOP) - 1;
			}
		}
		i++;
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