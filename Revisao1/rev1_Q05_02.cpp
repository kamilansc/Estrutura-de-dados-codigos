/*
#include <iostream>
using namespace std;

typedef struct no {
    int item;
    struct no *prox;
} *Lst;

Lst no (int x, Lst p){
    Lst n = (struct no*) malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
}

main() {
    Lst p = (no(1, no(2, no(3, no(4, NULL)))));

    while (p) {
        cout << p->item << endl;
        p = p->prox; 
    }
}


Respostas:
    7.1) 1
         2
         3
         4

    7.2) (Código a seguir)
*/

#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct no {
    int item;
    struct no *prox;
} *Lst;

Lst no (int x, Lst p){
    Lst n = (struct no*) malloc(sizeof(struct no));
    n->item = x;
    n->prox = p;
    return n;
}

main() {
    Lst p;
    int i = 0;
    int valorItem;
    int j;
    Lst ponteiroAtual;
    while (1) {
        cout << "Digite o valor "<< i+1 << ":";
        cin >> valorItem;

        cout << "Digite -1 para encerrar: ";
        cin >> j;

        if (i == 0) {
            p = no(valorItem, NULL);
            ponteiroAtual = p;
        }

        if (i > 0) {
            ponteiroAtual->prox = no(valorItem, NULL);
            ponteiroAtual = ponteiroAtual->prox;
        }

        if (j == -1) {
            break;
        }

        i++;
    }

    while (p) {
        cout << p->item << endl;
        p = p->prox; 
    }

    Lst temp;
    while (p) {
        temp = p;
        p = p->prox;
        free(temp);
    }

}