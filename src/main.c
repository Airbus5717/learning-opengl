#include "inc/def.h"

#include "inc/other.h"

i32 main(void /*i32 argc, i8 **argv*/)
{
    puts("Hello, Template");
    puts("printing a random 10 numbers");
    

    // vec(i32) type must be pre declared (see inc/other.h)
    vec(i32) d = randomNumbers(10);
    FOREACH(i, d->count) 
        printf("i: %d, el: %d\n", i, d->elements[i]);    
   
    // NOTE: free Vector
    vec_free(d);
    return 0;
}
