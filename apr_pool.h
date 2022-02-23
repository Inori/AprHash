#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif


struct apr_pool_s
{
	void* (*malloc)(size_t);        /* Function to allocate memory */
	void (*free)(void*);           /* Function to release it      */
	void* (*realloc)(void*, size_t);/* Function to resize a block of memory */
	void* (*calloc)(size_t, size_t);
};

typedef struct apr_pool_s apr_pool_t;


void* apr_palloc(apr_pool_t* p, size_t size);

void* apr_pcalloc(apr_pool_t* p, size_t size);

void apr_pfree(apr_pool_t* p, void* mem);

#ifdef __cplusplus
}
#endif