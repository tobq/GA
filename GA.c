#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GA.h"

int main() {
	srand(get_time()*10000);
	char *sentence;
	int STRINGLENGTH=0;
	printf("Type a sentence to match: ");
	scanf("%s",sentence);
	for(;sentence[STRINGLENGTH]!='\0'; ++STRINGLENGTH) sentence[STRINGLENGTH] = tolower(sentence[STRINGLENGTH]);
	gen parents[PARENTS];
	gen children[CHILDREN];
	for(int x = CHILDREN; x--;) {
		strcpy(children[x].string,randstr(STRINGLENGTH));
		children[x].fitness = 0;
	}
	double start = get_time();
	int noMatch = 1;

	while (noMatch) {
		for (int i = CHILDREN; i--;) {
			gen *GEN = &children[i];
			GEN->fitness=0;
			for (int j = STRINGLENGTH; j--;) if (GEN->string[j]==sentence[j]) GEN->fitness++;
			printf("%s | %d\n",GEN->string,GEN->fitness);
			if (GEN->fitness>=STRINGLENGTH) goto end;
		}
		for (int j = CHILDREN; j--;) if (children[j].fitness > parents[1].fitness || !parents[1].fitness) {
			gen *GEN = &children[j];
			if (GEN->fitness > parents[0].fitness) parents[0] = *GEN;
			else parents[1] = *GEN;
		}
		for (int j = CHILDREN; j--;) for (int z = STRINGLENGTH; z--;) {
			gen *GEN = &children[j];
			if (!(rand()%(100*STRINGLENGTH/MUTATIONRATE))) GEN->string[z] = randchar();
			else GEN->string[z] = parents[rand()%2].string[z];
		}
	}
	end:
	printf("\nMatched \"%s\" in %f seconds\n",sentence,get_time()-start);
	return 0;
}










