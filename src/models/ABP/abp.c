#include <stdio.h>
#include <stdlib.h>

#include "abp.h"
#include "../../log/log.c/src/log.h"
#include "../../data_gen/mtwister/mtwister.h"

pNodoA* InsereArvore(pNodoA *a, int ch, long* insert_ops)
{
     if (a == NULL)
     { 
         *insert_ops += 1;
         a =  (pNodoA*) malloc(sizeof(pNodoA));
         a->info = ch;
         a->esq = NULL;
         a->dir = NULL;
         return a;
     }
     else
          if (ch < a->info) {
              *insert_ops += 1;
              a->esq = InsereArvore(a->esq,ch, insert_ops);
          }
          else if (ch > a->info) {
              *insert_ops += 1;
              a->dir = InsereArvore(a->dir,ch, insert_ops);
          }
     return a;
}

pNodoA* consultaABP(pNodoA *a, int chave, long* consult_ops) {
    if (a!=NULL) {
       if (a->info == chave) {
         *consult_ops += 1;
         return a;
       }
       else {
           if (a->info > chave) {
                *consult_ops += 1;
                return consultaABP(a->esq,chave,consult_ops);
           }
            if (a->info < chave) {
                *consult_ops += 1;
                return consultaABP(a->dir,chave,consult_ops);
            }

            else return a;
       }
    }
       else return NULL;
}

void benchmark_ABP(int* data, int data_size, int is_random) {
  pNodoA* root = NULL;

  // Start by inserting into the list.

  long insert_ops = 0;
  clock_t insert_start = clock();

  printf("Inserting into tree...\n");
  for (int i = 0; i < data_size; i++) {
    printf("\r%d of %d done.", i+1, data_size);
    fflush(stdout);
    root = InsereArvore(root, data[i], &insert_ops);
  };
  printf("\n");

  long insert_time = (long)(clock() - insert_start) / (CLOCKS_PER_SEC / 1000);

  log_info("INSERT ABP|%s|%li|%lims|%liops\n", 
   (is_random ? "randomized" : "ordered"), data_size, insert_time, insert_ops);

  if (is_random) {
    FILE* insert_output = fopen("../logs/abp_benchmarks/insert/random.txt", "a");
    fprintf(insert_output, "%d|%li|%d\n", data_size, insert_time, insert_ops);
    fclose(insert_output);
  } else {
    FILE* insert_output = fopen("../logs/abp_benchmarks/insert/ordered.txt", "a");
    fprintf(insert_output, "%d|%li|%d\n", data_size, insert_time, insert_ops);
    fclose(insert_output);
  }

  

  // Now we consult according to specification.
  

  long consult_ops = 0;
  long consult_array[5] = {0,0,0,0,0};

  if (!is_random) {
    consult_array[0] = 1;
    consult_array[1] = data_size - 1;
    consult_array[2] = data_size / 2;
  } else {
    MTRand r = seedRand(clock());
    for (int i = 0; i < 5; i++) {
      long to_consult = (long)(genRand(&r) * data_size) + 1;
      consult_array[i] = to_consult;
    }
  }

  for (int i = 0; i < 5; i++) {
    long val = consult_array[i];
    if (val != 0) {
      clock_t consult_start = clock();
      pNodoA* result = consultaABP(root, val, &consult_ops); 
      if (result == NULL) { log_error("Something went wrong while consulting.\n");}
      long consult_time_curr = (long)(clock() - consult_start) / (CLOCKS_PER_SEC / 1000);
      consult_array[i] = consult_time_curr;
    }
  }

  long consult_time = 0;
  if (is_random) {
    for (int i = 0; i < 5; i++) {
      consult_time += consult_array[i];
    }
    consult_time = consult_time / 5;

    log_info("CONSULT ABP|%s|%d|%lims(mean)|%dops\n", "randomized", data_size, consult_time, consult_ops);

    FILE* consult_output = fopen("../logs/abp_benchmarks/consult/random.txt", "a");
    fprintf(consult_output, "%d|%li|%d\n", data_size, consult_time, consult_ops);
    fclose(consult_output);

  } else {
    log_info("CONSULT ABP|%s|%d|%lims|%lims|%lims|%liops\n", 
      "ordered", data_size, consult_array[0], 
      consult_array[1], consult_array[2], consult_ops);

    FILE* consult_output = fopen("../logs/abp_benchmarks/consult/ordered.txt", "a");
    fprintf(consult_output, "%d|%li|%li|%li|%d\n", data_size, 
      consult_array[0], consult_array[1], consult_array[2], consult_ops);
    fclose(consult_output);
  }

};
