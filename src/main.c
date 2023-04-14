#include "inc/def.h"

#include "inc/other.h"

i32 main(void /*i32 argc, i8 **argv*/)
{
    puts("Hello, Template");
    puts("printing a random 10 numbers");
    
    
    vec(i32) d = randomNumbers(10);
    for (size_t i = 0; i < 10; i++)
        printf("%d\n", d->elements[i]);

    // NOTE: free Vector
    vec_free(d);
    return 0;
}
