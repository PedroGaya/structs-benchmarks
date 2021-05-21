#include <stdio.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "../log/log.c/src/log.h"
#include "mtwister/mtwister.h"

void shuffle(int *array, size_t n);

int* generate_DB(int size, int is_random) {
    int *integer_array = (int*)malloc(size * sizeof(int));

    printf("Writing to array...\n");

    for (int i = 0; i < size; i++) {
        integer_array[i] = i+1;
        printf("\r%d of %d done.", i+1, size);
        fflush(stdout);
    };
    printf("\n");

    // Not really the most efficient way, but it works well an the code is readable.
    if (is_random) {
        shuffle(integer_array, size);
    };

    // Note: this file is never read from in the program.
    // This, however, is used for debugging.
    FILE* db = fopen("../logs/database.txt", "w");
    for (int i = 0; i < size; i++) {
        fprintf(db, "%d\n", integer_array[i]);
    };
    fclose(db);


    return integer_array;
};  

void shuffle(int *array, size_t n) { 
    // RNG for genRand() used later.   
    MTRand r = seedRand(clock());

    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          // Generate a random number j such that i < j < n.
          // genRand() comes from mtwister.h. Generates a random float between 0 and 1.
          size_t j = i + (int)(genRand(&r) * (n - i));
          // Swap them using a temp variable.
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}