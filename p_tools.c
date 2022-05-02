#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

extern void * t_debug_mem_malloc(uint size, char * file, uint line) {	
	return 
}
extern void t_debug_mem_free(void * ptr, char * file, uint line) {
	printf("free at file: %s, line: %d, ptr: %p\n", __FILE__, __LINE__, (void*)ptr);
	free(ptr);
	ALLOC_COUNT--;
}
