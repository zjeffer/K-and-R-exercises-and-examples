/* 
for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i){
	s[i] = c;
}

Exercise 2-2. Write a loop equivalent to the for loop above without using && or ||. 
*/


#include <stdio.h>


int main(){
	int lim = 1000;
	char s[lim];
	char c;
	int i;

	// solution: use , instead of &&
	for (i=0, c=getchar(); i < lim-1, (c=getchar()) != '\n', c != EOF; ++i){
		s[i] = c;
	}


	printf("%s\n", s);
		

	return 0;
}