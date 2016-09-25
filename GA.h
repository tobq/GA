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

typedef struct  {
	char string[17];
    int fitness;
} gen;

char randchar(){
	return rand()%27 ? 'a'+(random() % 26):' ';
}

char *randstr(int len) {
	char *randStr; 
	while (len--) randStr[len] = randchar();
	return randStr;
}
#endif

typedef enum {MUTATIONRATE=1, CHILDREN=4, PARENTS=2} config;
