#include "../../../Estrutura de dados 25.2/ETDCodigos/Etapa1/Capitulo4-filas/fila.h"
#include "arvore_binaria.h"
#include <stdio.h>
#include <stdlib.h>

Arv cria_no_arv(Arv esq, Item item, Arv dir){
    Arv no = malloc(sizeof(struct arv));
    no->esq = esq;
    no->dir = dir;
    no->item = item;
    return no;
}

// void percorre_em_nivel(Arv arv){
//     if (arv == NULL) return;
//     Fila F = fila(MAX);
//     enfileira(arv, F);
//     while (!vaziaf(F)){
//         Arv arv = desenfileira(F);
//         printf(fmt, arv->item);
//         if (arv->esq != NULL) enfileira(arv->esq, F);
//         if (arv->dir != NULL) enfileira(arv->dir, F);
//     }
// }


// Percorre a esquerda da subávore, depois visita a raiz e,
// em seguida, a subárvore da direita.
void percorre_em_ordem (Arv no){
    if (no == NULL) return;

    if (no->esq != NULL){
        percorre_em_ordem(no->esq);
    }

    printf(fmt" ", no->item);

    if (no->dir != NULL) {
        percorre_em_ordem(no->dir);
    }
}


// Visita a raiz, depois percorre a esquerda da subávore e,
// em seguida, percorre a subárvore da direita.
void percorre_em_pre_ordem (Arv no){
    if (no == NULL) return;
    
    printf(fmt" ", no->item); // 1 2

    if (no->esq != NULL){
        percorre_em_pre_ordem(no->esq);
    }

    if (no->dir != NULL) {
        percorre_em_pre_ordem(no->dir);
    }
}


// Percorre a esquerda da subávore, em seguida, 
// percorre a direita da subárvore, e depois visita a raiz.
void percorre_em_pos_ordem(Arv no){
    if (no == NULL) return;
    
    if (no->esq != NULL){
        percorre_em_pos_ordem(no->esq);
    }
    
    if (no->dir != NULL) {
        percorre_em_pos_ordem(no->dir);
    }
    
    printf(fmt" ", no->item);
}


void destroi_arv(Arv *no){
    if (*no == NULL) return;
    
    if ((*no)->esq != NULL){
        destroi_arv(&(*no)->esq);
    }
    
    if ((*no)->dir != NULL) {
        destroi_arv(&(*no)->dir);
    }
    
    free(*no);
    *no = NULL;
}


void insere_em_arv(Item item, Arv *no_arv){
    if ((*no_arv) == NULL) {
        Arv no = cria_no_arv(NULL, item, NULL);
        *no_arv = no;
    }
    else {
        if (item <= (*no_arv)->item){
            insere_em_arv(item, &((*no_arv)->esq));
        }
        else if (item > (*no_arv)->item){
            insere_em_arv(item, &((*no_arv)->dir));
        }
    }
}


Item busca_em_arv(Item item, Arv no_arv){
    if (no_arv == NULL) return 0;
    if (item == no_arv->item) return 1;
    if (item < no_arv->item) return busca_em_arv(item, no_arv->esq);
    else return busca_em_arv(item, no_arv->dir);
}

Item remove_item_max_em_arv(Arv *no_arv) {
    if (*no_arv == NULL) abort();
    while ((*no_arv)->dir != NULL) no_arv = &(*no_arv)->dir;
    Arv achou = *no_arv;
    Item removido = (*no_arv)->item;
    *no_arv = achou->esq;
    free(achou);
    return removido;
}


void remove_item(Item item, Arv *no_arv){
    if ((*no_arv) == NULL) return;
    if (item == (*no_arv)->item){
        Arv no = *no_arv;
        if (no->esq == NULL) *no_arv = no->dir;
        else if (no->dir == NULL) *no_arv = no->esq;
        else (*no_arv)->item = remove_item_max_em_arv(&no->esq);
        if (no != *no_arv) free(no);
    }
    else if (item <= (*no_arv)->item) remove_item(item, &(*no_arv)->esq);
    else remove_item(item, &(*no_arv)->dir);
}


int main(){
    Arv no = 
    cria_no_arv(
        cria_no_arv(
            cria_no_arv(NULL, 4, NULL), 
            2, 
            cria_no_arv(NULL, 5, NULL)
        ),
        1, 
        cria_no_arv(
            NULL,
            3,
            cria_no_arv(NULL, 6, NULL)
        )
    );
    
    
    printf("-------- TIPOS DE PERCURSOS EM PROFUNDIDADE --------\n");
    printf("-> Em-ordem:\n");
    percorre_em_ordem(no);
    printf("\n\n");

    printf("-> Pré-ordem:\n");
    percorre_em_pre_ordem(no);
    printf("\n\n");
    
    printf("-> Pos-ordem:\n");
    percorre_em_pos_ordem(no);

    remove_item_max_em_arv(&no);
    printf("\nPercurso após a remoção do maior elemento: ");
    percorre_em_ordem(no);

    // destroi_arv(&no);
    // printf("\n");
    // printf(no == NULL ? "-> Árvore destruída!" : "-> Falha na destruição da árvore!");

    // Arv raiz = NULL;
    // insere_em_arv(5, &raiz);

    // insere_em_arv(7, &raiz);

    // insere_em_arv(3, &raiz);
    
    // insere_em_arv(4, &raiz);

    // percorre_em_pos_ordem(raiz);

    // int resposta_busca = busca_em_arv(3, raiz);
    // printf("\nResposta da busca do ITEM 3 na árvore: "fmt, resposta_busca);

    // Arv testa_remocao = cria_no_arv(cria_no_arv(NULL, 0, NULL), 1, cria_no_arv(NULL, 3, NULL));
    // remove_item_max_em_arv(&testa_remocao);
    // percorre_em_ordem(testa_remocao);
    return 0;
}