#include "../inc/platform.h"


void *mem_alloc(usize size) 
{
    return malloc(size);
}

void *mem_realloc(void *mem_blk, usize size) 
{
    return realloc(mem_blk, size);
}

void mem_free(void *mem_blk) 
{
    free(mem_blk);
}