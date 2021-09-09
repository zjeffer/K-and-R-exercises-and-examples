/* Exercise 1-22. Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column. */

#include <stdio.h>

#define TABSTOP 8
#define LINELENGTH 80
#define MAXLINE 1000

int getLastBlank(const char arr[], int len);

int main() {
    int c;          // character variable
    int i, j;       // indexing variable(s)
    int pos;        // current position in array
    int col;        // current column of output
    int lbc;        // last blank character position
    char line[LINELENGTH + 1];  // fold array
    
    pos = col = 0;
    while ((c = getchar()) != EOF) {
        // process line array, keep track of line length by columns
        line[pos++] = c;
		if (c == '\t'){
			col += TABSTOP - (col % TABSTOP);
		} else {
			col++;
		}

        // create fold
        if (col >= LINELENGTH || c == '\n') {
            line[pos] = '\0';
            
            if ((lbc = getLastBlank(line, pos)) == -1) {
                // split word if no blank characters 
                for (i = 0; i < pos; ++i)
                    putchar(line[i]);
                // reset column value and array position
                col = pos = 0;
            }
            else {
                // print array up until last blank character
                for (i = 0; i < lbc; ++i)
                    putchar(line[i]);
                // feed remaining characters into buffer
                for (i = 0, j = lbc + 1, col = 0; j < pos; ++i, ++j) {
                    line[i] = line[j];
                    // set new column value
                    if (c == '\t'){
						col += TABSTOP - (col % TABSTOP);
					} else {
						col++;
					}
                }
                // set array position after remaining characters
                pos = i;
            }
            // finish folded line with newline character
            putchar('\n');
        }
    }
    
    return 0;
}

int getLastBlank(const char arr[], int len) {
    int i, lbc;

    lbc = -1;
    for (i = 0; i < len; ++i)
        if (arr[i] == ' ' || arr[i] == '\t' || arr[i] == '\n')
            lbc = i;

    return lbc;
}