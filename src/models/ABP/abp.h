struct TNodoA{
        int info;
        struct TNodoA *esq;
        struct TNodoA *dir;
};
typedef struct TNodoA pNodoA;

/*
This inserts a key into into the given tree.
insert_ops is a counter that will increment upon each comparison operation.

You can insert 0 into the tree with this function.

usage:
  pNodoA* root = NULL;
  int key = 0;
  long insert_ops = 0;

  root = BST_insert_iterative(root, key, &insert_ops)
*/
pNodoA* BST_insert_iterative(pNodoA* a, int ch, long* insert_ops);

/*
Deprecated but functional. This function inserts the key into the given tree.
Uses a recurisve algorithm, which causes stack overflow on trees whose height is around 43k.

This will return and not insert if ch == 0.
*/
pNodoA* InsereArvore(pNodoA *a, int ch, long* insert_ops); 

/*
Use this to search for a given key on the given tree. 

Returns 1 on success, 0 otherwise.

usage:
  pNodoA* root = NULL;
  int key = 10;
  long consult_ops = 0;

  ... Insert into the tree ...

  int is_success = consultaABP(root, key, &consult_ops)
*/
int consultaABP(pNodoA* a, int chave, long* consult_ops);

/*
Does all the benchmarking for any given data_set.

In this program's case, the input args are generated on startup from argv on main.

usage:
  int data[5] = {1, 2, 3, 4, 5};
  int data_size = 5;
  int is_random = 0;

  benchmark_ABP(data, data_size, is_random);

*/
void benchmark_ABP(int* data, int data_size, int is_random);