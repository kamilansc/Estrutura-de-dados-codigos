// palindroma.cpp - verifica se uma cadeia é palíndroma (ordem original da frase = ordem inversa)

#include <stdio.h>
#include <ctype.h>
#include "fila.h"
#include "../Capitulo2/Pilha.h"

#define avanca(i) (i = (i+1) % F->max)

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


int main(){
    char s[256];
    Fila F = fila(256);
    Pilha P = pilha(256);
    printf("\nDigite a frase: ");
    gets(s);
    for (int i=0; s[i]; i++)
        if (isalpha(s[i]))
        {
            enfileira(s[i], F);
            empilha(s[i], P);
        }
    
    while (!vaziaf(F) && desenfileira(F) == desempilha(P));
    if (vaziaf(F)) puts ("A frase é palíndroma");
    else puts ("A frase não é palíndroma");
    destroif(&F);
    destroip(&P);
    return 0;
}