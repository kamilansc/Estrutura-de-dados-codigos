# include <stdio.h>
#include "fila.h"

int main() {
    Fila F = fila(5);
    for (int i=0; i<=3; i++) enfileira('A'+i, F);
    while (!vaziaf(F)) printf("%c\n", desenfileira(F));
    destroif(&F);
    return 0;
}

// Resultado da linha 6 >> F: A, B, C, D
// Resultado da linha 7 (a partir da linha abaixo) >>
// A+0 = A
// A+1 = B
// A+2 = C
// A+3 = D
