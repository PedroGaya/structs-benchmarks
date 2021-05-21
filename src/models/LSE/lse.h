typedef struct tipoNo ptLSE;
typedef struct LSE LSE;

struct tipoNo {
       int numero;   
       ptLSE *prox;
       ptLSE *ant;
};

struct LSE {
       int size;
       ptLSE *start;
};


/*
Initiates a list with no values in it.

usage:
  LSE* list = init_LSE();
*/
LSE* init_LSE(void);

/*
This inserts a key into into the given list.
ops_counter is a counter that will increment upon each comparison operation.

usage:
  LSE* list = init_LSE();
  int key = 0;
  long insert_ops = 0;

  insert_ptLSE(list, key, &insert_ops);
*/
ptLSE* insert_ptLSE(int input, LSE* list, long* ops_counter);

/*
Use this to search for a given key on the given list. 

Returns 1 on success, 0 otherwise.

usage:
  LSE* list = init_LSE();
  int key = 0;
  long consult_ops = 0;

  ... Insert into the tree ...

  int is_success = find_LSE(list, key, &consult_ops);
*/
int find_LSE(int input, LSE* list, long* ops_counter);

/*
Does all the benchmarking for any given data_set.

In this program's case, the input args are generated on startup from argv on main.

usage:
  int data[5] = {1, 2, 3, 4, 5};
  int data_size = 5;
  int is_random = 0;

  benchmark_LSE(data, data_size, is_random);
*/
void benchmark_LSE(int* data, int data_size, int is_random);