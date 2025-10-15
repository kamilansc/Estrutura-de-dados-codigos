#include <stdlib.h>
#include <stdio.h>

typedef char Itemf;                 // tipo de item: nesse caso item é char
#define avanca(i) (i = (i+1) % F->max)

typedef struct fila {
    int max;                        // tamanho de fila
    int total;                      // quantidade atual de itens da fila
    int inicio;                     // indice da posição inicial
    int final;                      // indice da posição final
    Itemf *item;
} *Fila;


Fila fila (int m) {
    Fila F = malloc(sizeof(struct fila));
    F->max = m;
    F->total = 0;
    F->inicio = 0;
    F->final = 0;
    F->item = malloc(m*sizeof(Itemf));
    return F;
}


int vaziaf(Fila F) {
    return (F->total == 0);
}


int cheiaf (Fila F){
    return (F->total == F->max);
}


void enfileira (Itemf item, Fila F) {
    if (cheiaf(F)) {
        puts ("Fila cheia!"); 
        abort();
    }
    F->item[F->final] = item;
    avanca(F->final);
    F->total++;
}


Itemf desenfileira (Fila F) {
    if (vaziaf(F)) {
        puts ("Fila vazia!");
        abort();
    }
    Itemf x = F->item[F->inicio];
    avanca(F->inicio);
    F->total--;
    return x;
}


void destroif (Fila *G) {
    free ((*G)->item);
    free (*G);
    *G = NULL;
}