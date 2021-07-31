#include <stdio.h>

int main() {
    int c, nl, tabs, blanks;
    nl = 0;
    tabs = 0;
    blanks = 0;

    while ((c = getchar()) != EOF)
        switch (c) {
            case '\n':
                ++nl;
                break;
            case '\t':
                ++tabs;
                break;
            case ' ':
                ++blanks;
                break;
            default:    
                /* ignore other characters */
                break;
        }

    printf("Blanks: %d\n", blanks);
    printf("Tabs: %d\n", tabs);
    printf("Newlines: %d\n", nl);
    return 0;
}