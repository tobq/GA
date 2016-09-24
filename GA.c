#ifdef WIN32

#include <windows.h>
double get_time()
{
    LARGE_INTEGER t, f;
    QueryPerformanceCounter(&t);
    QueryPerformanceFrequency(&f);
    return (double)t.QuadPart/(double)f.QuadPart;
}

#else

#include <sys/time.h>
#include <sys/resource.h>

double get_time()
{
    struct timeval t;
    struct timezone tzp;
    gettimeofday(&t, &tzp);
    return t.tv_sec + t.tv_usec*1e-6;
}

#endif

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct  {
	char string[17];
    int fitness;
} gen;

char randchar(){
	return rand()%27 ? 'a'+(random() % 26):' ';
}

char *randstr(int len) {
	char randStr[17]; 
	while (len--) randStr[len] = randchar();
	return (char*) &randStr;
}

int main() {
	srand(get_time()*10000);
	int noMatch = 1;
	gen top[2];
	gen generated[] = {
		{ randstr(16), 0 },
		{ randstr(16), 0 },
		{ randstr(16), 0 },
		{ randstr(16), 0 }
	};
	char *sentence = "generated string";
	double start = get_time();
	while (noMatch) {
		for (int i = 4; i--;) {
			gen *GEN = &generated[i];
			GEN->fitness=0;
			for (int j = 16; j--;) if (GEN->string[j]==sentence[j]) GEN->fitness++;
			for (int x=0; x < 16; ++x) printf("%c",generated[i].string[x]);
			printf(" %d\n",GEN->fitness);
			if (GEN->fitness>15) goto end;
		}
		for (int j = 4; j--;) if (generated[j].fitness > top[1].fitness || !top[1].fitness) {
			gen *GEN = &generated[j];
			if (GEN->fitness > top[0].fitness) top[0] = *GEN;
			else top[1] = *GEN;
		}
		for (int j = 4; j--;) for (int z = 16; z--;) {
			gen *GEN = &generated[j];
			if (!(rand()%50)) GEN->string[z] = randchar();
			else GEN->string[z] = top[rand()%2].string[z];
		}
	}
	end:
	printf("\nMatched \"%s\" in %f seconds\n",sentence,get_time()-start);
	return 0;
}










