#include <stdio.h>
#include <stdlib.h>
#include "abp.h"

pNodoA* InsereArvore(pNodoA *a, int ch)
{
     if (a == NULL)
     {
         a =  (pNodoA*) malloc(sizeof(pNodoA));
         a->info = ch;
         a->esq = NULL;
         a->dir = NULL;
         return a;
     }
     else
          if (ch < a->info)
              a->esq = InsereArvore(a->esq,ch);
          else if (ch > a->info)
              a->dir = InsereArvore(a->dir,ch);
     return a;
}

pNodoA* consultaABP(pNodoA *a, int chave) {
    if (a!=NULL) {
       if (a->info == chave)
         return a;
       else
           if (a->info > chave)
                return consultaABP(a->esq,chave);
            if (a->info < chave)
                return consultaABP(a->dir,chave);

            else return a;
       }
       else return NULL;
}