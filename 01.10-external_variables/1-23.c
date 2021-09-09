// Exercise 1-23. Write a program to remove all comments from a C program. Don't forget to
// handle quoted strings and character constants properly. C comments don't nest. 

#include <stdbool.h>
#include <stdio.h>

#define MAXPROGRAMLENGTH 1000

int readline(char s[], int lim);

int main() {
	int len;
	char line[MAXPROGRAMLENGTH];

	bool inQuotedString = false;
	bool inCharConst = false;
	bool inMultilineComment = false;

	printf("Enter a program: \n");

	while ((len = readline(line, MAXPROGRAMLENGTH)) > 0) {
		int i = 0;
		while (i < len) {
			// check for quotes
			if (line[i] == '\"') {
				inQuotedString = !inQuotedString;
			} else if (line[i] == '\'') {
				inCharConst = !inCharConst;
			}

			// if not in quotes, check for comments
			if (!inQuotedString && !inCharConst){
				// if already in multiline comment, check for end of comment
				if (inMultilineComment){
					// go through the whole line
					while (i < len) {
						// if newline found, keep inMultilineComment true
						if (line[i] == '\n') {
							break;
						} else {
							if (line[i] == '*' && line[i + 1] == '/') {
								inMultilineComment = false;
								line[i] = '\0';
								line[i + 1] = '\0';
								i += 1;
							}
						}
						
						i += 1;
					}
				// if not in multiline comment, check if single line comment starts
				} else if (line[i] == '/' && line[i + 1] == '/') {
					// if comment, empty the whole line
					while (i < len-1 && line[i] != '\n') {
						// printf("debug");
						line[i] = '\0';
						i++;
					}
					line[i] = '\n';
				// or if multiline comment starts
				} else if (line[i] == '/' && line[i + 1] == '*') {
					// if multi-line comment, find ending
					inMultilineComment = true;
					line[i] = '\0';
					line[i + 1] = '\0';
					i += 2;
				}
			}

			// if in quotes or char const, skip	character
			i++;
		}

		printf("%s", line);
		// empty string
		for (int index = 0; index < MAXPROGRAMLENGTH; index++) {
			line[index] = '\0';
		}
	}

	return 0;
}

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