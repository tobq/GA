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

int main() {
	int noMatch = 1;
	gen top[2];
	gen generated[] = {
		{ "sjfdaospfjapofja", 0 },
		{ "iqweuqwioruiqwor", 0 },
		{ "zxnmcrznxmnvxmcc", 0 },
		{ "wqcnioenfgjnlwoz", 0 }
	};
	double start = get_time();
	srand(get_time()*10000);

	while (noMatch) {
		for (int i = 4; i--;) {
			gen* GEN = &generated[i];
			GEN->fitness=0;
	
			for (int j = 16; j--;) if (GEN->string[j]=="generated string"[j]) {
				GEN->fitness++;
			}
			if (GEN->string == "generated string") {
				noMatch = 0;
				break;
			}
		}
		for (int j = 4; j--;) {
			if (generated[j].fitness > top[1].fitness || !top[1].fitness) {
				if (generated[j].fitness > top[0].fitness) top[0] = generated[j];
				else top[1] = generated[j];
			}
		}
		for (int j = 4; j--;) {
			int IND = rand()%16;	
			for (int z = 16; z--;) generated[j].string[z] = top[rand()%2].string[z];
			printf("%s : %d\n",generated[j].string,generated[j].fitness);
			if (!(rand()%100)) generated[j].string[IND] = rand()%27 ? 'a'+(random() % 26):' ';
		}
	}
	printf("\nMatched \"generated sentence\" in %f seconds\n",get_time()-start);
	return 0;
}










