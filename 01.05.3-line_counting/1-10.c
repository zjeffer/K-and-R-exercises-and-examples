#include <stdio.h>

int main(){
    /* Write a program to copy its input to its output, replacing each tab by \t, each
    backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an
    unambiguous way. */

    int c;
    while ((c = getchar()) != EOF){
        switch (c){
            case '\t':
                printf("\\t");
                break;
            case '\b':
                printf("\\b");
                break;
            case '\\':
                printf("\\\\");
                break;
            default:
                printf("%c", c);
                break;
        }
    }
    return 0;
}