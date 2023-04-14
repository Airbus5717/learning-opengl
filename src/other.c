#include "inc/other.h"

i32 getRandNum()
{
    i32 result = rand();
    return result;
}

vec(i32) randomNumbers()
{
    srand(0); // seed for rand
    const u8 SIZE = 10;
    vec(i32) v = vec_new(i32, SIZE);

    for (size_t i = 0; i < SIZE; i++)
        vec_insert(v, getRandNum() % getRandNum());
    return v;
}
