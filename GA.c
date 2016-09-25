#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GA.h"

int main() {
	srand(get_time()*10000);
	char sentence[256];
	int STRINGLENGTH=0;
	printf("Type a sentence to match: ");
	scanf("%s",sentence);
	for(;sentence[STRINGLENGTH]!='\0'; ++STRINGLENGTH); sentence[STRINGLENGTH] = tolower(sentence[STRINGLENGTH]);
	gen parents[PARENTS];
	gen children[CHILDREN];
	for(int x = CHILDREN; x--;) children[x].string = randstr(STRINGLENGTH);
	for(int x = PARENTS; x--;) parents[x].fitness=-1;
	int noMatch = 1;
	double start = get_time();
	while (noMatch) {
		for (int i = CHILDREN; i--;) {
			gen *child = &children[i];
			child->fitness=0;
			for (int j = STRINGLENGTH; j--;) if (child->string[j]==sentence[j]) child->fitness++;
			printf("%s | %d\%\n",child->string,child->fitness*100/STRINGLENGTH);
			if (child->fitness>=STRINGLENGTH) goto end;
		}
		for (int j = CHILDREN; j--;) if (children[j].fitness > parents[1].fitness) {
			gen *child = &children[j];
			if (child->fitness > parents[0].fitness) parents[0] = *child;
			else parents[1] = *child;
		}
		printf("\n  P1: %s | %d\%\n",parents[0].string,parents[0].fitness*100/STRINGLENGTH);
		printf("  P2: %s | %d\%\n\n",parents[1].string,parents[1].fitness*100/STRINGLENGTH);
		for (int j = CHILDREN; j--;) for (int z = STRINGLENGTH; z--;) {
			gen *child = &children[j];
			if (!(rand()%(6*STRINGLENGTH/MUTATIONRATE))) child->string[z] = randchar();
			else child->string[z] = parents[rand()%PARENTS].string[z];
		}
	}
	end:
	printf("\nMatched \"%s\" in %f seconds\n",sentence,get_time()-start);
	return 0;
}










