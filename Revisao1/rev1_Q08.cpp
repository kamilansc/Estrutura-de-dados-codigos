//#include <stdio.h>
#include <iostream>
using namespace std;

void x (char *str1, char *str2) {
    while (*str1) {
        str1++;
    }

    while (*str2) {
        *str1 = *str2;
        str1++;
        str2++;
    }

    *str1 = '\0';
}


int main() {
    char str1[100] = "Hello ";
    char str2[] = "World!";
    x(str1, str2);
    cout << str1 << endl;
//    printf(" %s\n", str1);

    return 0;
}


/*
8.1. O que será impresso ao final do programa? Será impresso Hello World!

8.2. O que a função X está fazendo? 
    No primeiro while, ela percorre até o caracter nulo do vetor str1 (que é "\0") depois, com o segundo 
    while, ela percorre o vetor de char str2 e adiciona cada caractere válido ao vetor str1 até chegar no
    caractere nulo "\0". Ou seja, ela concatena str2 ao final de str1 usando manipulação de ponteiros.
*/