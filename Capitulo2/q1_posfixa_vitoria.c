#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "Pilha.h"


int prio(char op) {
    switch (op) {
        case '(' : return 0;
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
    }
    return-1;
}

char *posfixa(char *e) {
    static char s[256];
    int j = 0;
    Pilha P = pilha(256);

    for (int i = 0; e[i]; i++)
        if (e[i] == '(' ) empilha(e[i], P);
        else if (isdigit(e[i])) s[j++] = e[i];
        else if (strchr("+-*/", e[i])){
            while (!vaziap(P) && prio(topo(P)) >= prio(e[i]))
                s[j++] = desempilha(P);
            empilha(e[i], P);
        }
        else if (e[i] == ')' ){
            while (topo(P) != '(')
                s[j++] = desempilha(P);
            desempilha(P);
        }

    while (!vaziap(P))
        s[j++] = desempilha(P);

    s[j] = '\0';
    destroip(&P);
    return s;    
}

float valor(char *e){
    Pilha P = pilha(256);
    for(int i = 0; e[i]; i++){
        if(isdigit(e[i])){
            empilha(e[i] - '0', P);
        } 
        else{
            float b = desempilha(P);
            float a = desempilha(P);
            switch(e[i]){
                case '+': empilha(a + b, P); break;
                case '-': empilha(a - b, P); break;
                case '*': empilha(a * b, P); break;
                case '/': empilha(a / b, P); break;
            }
        }
    }
    float resultado = desempilha(P);
    destroip(&P);
    return resultado;
}

int main(void) {
    char e[256];
    printf("Infixa?");
    gets(e);
    char *pf = posfixa(e);
    printf("Posfixa: %s\n\n", pf);
    printf("Resultado: %.1f\n", valor(pf));

    return 0;
}