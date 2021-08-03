#include <stdio.h>

int main(){
	int c, state;


	while((c = getchar()) != EOF){
		if (c == ' ' || c == '\n'){
			printf("\n");
		} else {
			printf(c);
		}
	}

	return 0;
}