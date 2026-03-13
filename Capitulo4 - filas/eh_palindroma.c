// palindroma.cpp - verifica se uma cadeia é palíndroma (ordem original da frase = ordem inversa)

#include <stdio.h>
#include <ctype.h>
#include "fila.h"
#include "../Capitulo2/Pilha.h"


int main(){
    char s[256];
    Fila F = fila(256);
    Pilha P = pilha(256);
    printf("\nDigite a frase: ");
    gets(s);
    for (int i=0; s[i]; i++)
        if (isalpha(s[i]))
        {
            enfileira(toupper(s[i]), F);  // Questão 3 - aplicação de toupper() para converter maiúscula
            empilha(toupper(s[i]), P);    // pra minúscula
        }
    
    while (!vaziaf(F) && desenfileira(F) == desempilha(P));
    if (vaziaf(F)) puts ("A frase é palíndroma");
    else puts ("A frase não é palíndroma");
    destroif(&F);
    destroip(&P);
    return 0;
}