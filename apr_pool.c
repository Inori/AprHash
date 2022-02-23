#include "apr_pool.h"

void* apr_palloc(apr_pool_t* p, size_t size)
{
	return p->malloc(size);
}

void* apr_pcalloc(apr_pool_t* p, size_t size)
{
	return p->calloc(1, size);
}

void apr_pfree(apr_pool_t* p, void* mem)
{
	return p->free(mem);
}
