#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>

#include "lse.h"
#include "../../log/log.c/src/log.h"
#include "../../data_gen/mtwister/mtwister.h"

LSE* init_LSE(void)
{
  LSE* list = NULL;
  list = (LSE*) malloc(sizeof(LSE));

  list->size = 0;
  list->start = NULL;

  return list;
};

ptLSE* insert_ptLSE(int input, LSE* list, int* ops_counter)
{
       ptLSE* novo;
       novo = (ptLSE*) malloc(sizeof(ptLSE));

       novo->numero = input;

       int curr_ops = 0;
      
       curr_ops += 1;
       if (input == 0) return NULL;
       
       curr_ops += 1;
       if (list->start == NULL) {
         list->start = novo;
         novo->prox = novo;
         novo->ant = novo;
         list->size++;
         return list->start;
       }
       
       novo->prox = list->start;
       novo->ant = list->start->ant;
       list->start->ant->prox = novo;
       list->start->ant = novo;

       list->size++;

       *ops_counter += curr_ops;
       return list->start;
}

int show_LSE(LSE* list)
{
  if (list == NULL) { printf("List is NULL\n"); return -1; };
  if (list->start == NULL) { printf("Empty list\n"); return -1; };

  ptLSE* head = list->start;

  do {
    printf("%d ", head->numero);
    head = head->prox;
  } while(head != list->start);

  printf("\n");

  return 0;
}

int destroy_LSE(LSE* list)
{
  if (list != NULL) {
    do {
      ptLSE* curr = list->start;
      list->start = list->start->prox;
      free(curr);
    } while (list->start != NULL);
    return 0;
  free(list);
  } else {
    return -1;
  }
}

int find_LSE(int input, LSE* list, int* ops_counter) {
  if (list == NULL) { printf("List is NULL\n"); return 0; };
  if (list->start == NULL) { printf("Empty list\n"); return 0; };

  ptLSE* head = list->start;
  int curr_ops = 1;

  while(head->numero != input) {
    head = head->prox;

    curr_ops++;
    if (head == list->start) {
      return 0;
    }

    curr_ops++;
  };
  return 1;
}

void benchmark_LSE(int* data, int data_size, int is_random) {
  // Setup for storing benchmarks.

  FILE* output = fopen("../logs/lse_benchmark.txt", "a");
  log_add_fp(output, LOG_TRACE);

  LSE* list = init_LSE();


  // Start by inserting into the list.

  int insert_ops;
  clock_t insert_start = clock();

  printf("Inserting into list...\n");
  for (int i = 0; i < data_size; i++) {
    printf("\r%d of %d done.", i+1, data_size);
    fflush(stdout);
    insert_ptLSE(data[i], list, &insert_ops);
  };
  printf("\n");

  long insert_time = (long)(clock() - insert_start) / (CLOCKS_PER_SEC / 1000);

  log_info("INSERT LSEC|%s|%li|%lims|%dops\n", 
   (is_random ? "randomized" : "ordered"), data_size, insert_time, insert_ops);

  // Now we consult according to specification.

  int consult_ops;
  int consult_array[5] = {0,0,0,0,0};

  if (is_random) {
    consult_array[0] = 1;
    consult_array[1] = data_size;
    consult_array[2] = data_size / 2;
  } else {
    MTRand r = seedRand(clock());
    for (int i = 0; i < 5; i++) {
      consult_array[i] = (int)(genRand(&r) * data_size) + 1;
    }
  }

  for (int i = 0; i < 5; i++) {
    int val = consult_array[i];

    if (val != 0) {
      clock_t consult_start = clock();
      find_LSE(val, list, &consult_ops);
      consult_array[i] = (int)(clock() - consult_start) / (CLOCKS_PER_SEC / 1000);
    }
  }

  int consult_time;
  if (is_random) {
    for (int i = 0; i < 5; i++) {
      consult_time += consult_array[i] / 5;
    }

    log_info("CONSULT LSEC|%s|%li|%lims|%dops\n", 
      (is_random ? "randomized" : "ordered"), data_size, consult_time, consult_ops);
  } else {
    log_info("CONSULT LSEC|%s|%li|%lims|%lims|%lims|%dops\n", 
      (is_random ? "randomized" : "ordered"), data_size, consult_array[0], 
      consult_array[1], consult_array[2], consult_ops);
  }

};
