#include <iostream>
using namespace std;

int x(char *str) {
    int y = 0;
    while (*str) {
        y++;
        str++;
    }

    return y;
}

int main() {
    char str[] = "Hello World";
    int w = x(str);
    cout << w;

    return 0;
}

/*
9.1. O que será impresso ao final do programa?
    11
9.2. O que a função X está fazendo?
    A função x percorre todo o vetor str, caractere por caractere, utilizando um ponteiro, e armazena na 
    variável local y a quantidade de caracteres no vetor até encontrar o caractere nulo "\0", que marca o fim
    da string.
*/