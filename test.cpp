#include <stdio.h>
#include <stdlib.h>
#include "apr_hash.h"

int hash_callback(void* rec, const void* key,
	apr_ssize_t klen,
	const void* value)
{

	return 1;
}

int main()
{
	apr_pool_t pool;
	pool.malloc = malloc;
	pool.calloc = calloc;
	pool.realloc = realloc;
	pool.free = free;

	apr_hash_t* table = apr_hash_make(&pool);

	apr_hash_do(hash_callback, nullptr, table);

	apr_hash_insert(table, "abc", 3, main);

	// need to manually delete, or the memory will be leaked
	// after hash table destroy
	apr_hash_insert(table, "abcd", 4, new int[3]);

	void* p = apr_hash_get(table, "abc", 3);

	apr_hash_do(hash_callback, nullptr, table);

	apr_hash_erase(table, "abc", 3);

	apr_hash_insert(table, "abc", 3, main);

	apr_hash_destroy(table);
	
	
	return 0;
}