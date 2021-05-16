struct TNodoA{
        int info;
        struct TNodoA *esq;
        struct TNodoA *dir;
};

typedef struct TNodoA pNodoA;

pNodoA* InsereArvore(pNodoA* a, int ch, long* insert_ops);
pNodoA* consultaABP(pNodoA* a, int chave, long* consult_ops);

void benchmark_ABP(int* data, int data_size, int is_random);