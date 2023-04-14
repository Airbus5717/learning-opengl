#pragma once

/*
    Platform layer
*/

#include "def.h"

/* Log */
// TODO: Add logging functions here

/*
    Memory Allocation:
        override when needed for different platform
*/
local void *mem_alloc(usize size)
{
    return malloc(size);
}

local void *mem_realloc(void *mem_block, usize size)
{
    return realloc(mem_block, size);
}

local void mem_free(void *mem_block)
{
    free(mem_block);
}
