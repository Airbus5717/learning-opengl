#include "inc/other.h"

i32 getRandNum()
{
    i32 result = rand();
    return result;
}

vec(i32) randomNumbers(const usize size)
{
    srand(0); // seed for rand
    vec(i32) v = vec_new(i32, size);

    for (usize i = 0; i < size; i++)
        vec_push(v, getRandNum() % getRandNum());
    return v;
}
