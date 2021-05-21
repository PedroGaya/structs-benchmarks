#include <stdio.h>

/*
Generates an array of the given size. if is_random is true, then it will shuffle said array.
The array contains numbers from 1 to size-1.

In this program, size comes from argv in main().

usage:
  int size = 1000;
  bool is_random = true;

  int* data = generate_db(size, is_random);
*/
int* generate_DB(int size, int is_random);

/*
Shuffles the given array with the given size.

Is used only inside generate_db(), but can be used outside.
*/
void shuffle (int* array, size_t size);