#ifndef ARV_H
#define ARV_H

#define fmt "%d"

typedef int Item;

typedef struct arv{
    struct arv *esq;
    Item item;
    struct arv *dir; 
} *Arv;

Arv cria_no_arv(Arv esq, Item item, Arv dir);

// Percorre a esquerda da subávore, depois visita a raiz e,
// em seguida, a subárvore da direita.
void percorre_em_ordem (Arv no);


// Visita a raiz, depois percorre a esquerda da subávore e,
// em seguida, percorre a subárvore da direita.
void percorre_em_pre_ordem (Arv no);


// Percorre a esquerda da subávore, em seguida, 
// percorre a direita da subárvore, e depois visita a raiz.
void percorre_em_pos_ordem(Arv no);

void destroi_arv(Arv *no);

void insere_em_arv(Item item, Arv *no_arv);

Item busca_em_arv(Item item, Arv no_arv);

Item remove_item_max_em_arv(Arv *no_arv);

void remove_item(Item item, Arv *no_arv);

#endif