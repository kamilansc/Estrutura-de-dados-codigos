#include <stdlib.h>

typedef char Itemp;

typedef struct pilha{
    int max;
    int topo;
    Itemp *item;
} *Pilha;

Pilha criarPilha(int tamanho) {
    Pilha P = malloc(sizeof(struct pilha));
    
}