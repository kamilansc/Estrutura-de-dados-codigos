#include <stdio.h>
#include "Pilha.h"

int main(void) {
    char cadeia[80];

    Pilha P = pilha(256);

    printf("Digite a cadeia de caracteres: ");
    gets(cadeia);

    for (int i = 0; cadeia[i]; i++) 
        empilha(cadeia[i], P);

    printf("Inverso: ");
    while (!vaziap(P)) printf("%c", desempilha(P));

    destroip(&P);
    return 0;
}

    