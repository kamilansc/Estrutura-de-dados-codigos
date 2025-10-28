/*
Questão 5)
#include <stdio.h>
#include <iostream>
using namespace std;
typedef struct no {
    int item;
    struct no *prox;
} No;

main(){
    No v[4]={{3,v+2},{1,v+3},{4,NULL},{2,v+0}};
    for (No *p=v+1;p!=NULL;p=p->prox)
        cout<<p->item;
}
*/


/*
Respostas:
6.1) Será impresso 1234.

6.2) (código a seguir)
*/

#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct no {
    int item;
    struct no *prox;
} No;

main() {
    No v[4];
    int tamanho = sizeof(v)/sizeof(v[0]);

    for (int i = 0; i < tamanho; i++) {
        cout << "Digite o valor: ";
        cin >> v[i].item;
        
        if (i < tamanho-1) {
            v[i].prox = &v[i + 1];
        }
        else {
            v[i].prox = NULL;
        }
    }
    
    No *p = &v[0];
    while (p != NULL) {
        cout << p->item << " ";
        p = p->prox;
    }
}