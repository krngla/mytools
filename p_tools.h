#pragma once
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include <stdio.h>
#include <assert.h>
//Useful tools
#define ttostr(type) ((TypeId)&#type)
#define t_type_id_cstr(type_id) ((const char *)type_id)

#ifdef DEBUG
void * DANGERPOINTER;
int * ALLOC_COUNT = 0;
//malloc stuff
#define free(ptr) \
	do {
		printf("free at file: %s, line: %d, ptr: %p\n", __FILE__, __LINE__, (void*)ptr);
		free(ptr);
		ALLOC_COUNT--;
		ptr = NULL;
	}while(0)
#define malloc(size) DANGERPOINTER = malloc(size); printf("malloc at file: %s, line: %d, ptr: %p\n", __FILE__, __LINE__, DANGERPOINTER);ALLOC_COUNT++;
#define m_dprintf(...) printf(__VA_ARGS__)
#define check_allocs() assert(ALLOC_COUNT == 0);
#else
#define m_dprintf(...)
#define check_allocs()
#endif//DEBUG

