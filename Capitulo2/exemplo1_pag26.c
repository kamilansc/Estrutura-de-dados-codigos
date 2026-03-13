#include <stdio.h>
#include "Pilha.h"

int main(void) {
    int n;
    Pilha P = pilha(32);

    printf("Digite o decimal: ");
    scanf("%d", &n);

    do {empilha(n%2, P); n /= 2;} while (n != 0);

    printf("Binário: ");
    while (!vaziap(P)) printf("%d", desempilha(P));

    destroip(&P);
    return 0;
}