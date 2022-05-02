#include "p_tools.h"
#include <stdio.h>


int main() {
	int * a = malloc(sizeof * a);
	int * b = malloc(sizeof * b);
	int * c = malloc(sizeof * c);
	int * d = malloc(sizeof * d);
	int * e = malloc(sizeof * e);
	int * f = malloc(sizeof * f);
	free(a);
	free(b);
	free(c);
	free(d);
	free(e);
	free(f);
	check_allocs();
	return 0;
}

