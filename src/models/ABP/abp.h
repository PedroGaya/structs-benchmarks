struct TNodoA{
        int info;
        struct TNodoA *esq;
        struct TNodoA *dir;
};

typedef struct TNodoA pNodoA;

pNodoA* InsereArvore(pNodoA* a, int ch);
pNodoA* consultaABP(pNodoA* a, int chave);

void benchmark_ABP(pNodoA* input, int* data, int data_size);