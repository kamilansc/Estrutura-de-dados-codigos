#include <stdio.h>
#include <stdlib.h> 
#include <iostream>
using namespace std;

// Definindo a estrutura do nó
typedef struct Node {
    int data;
    struct Node *next;
} Node;


void append (Node** head_ref, int new_data) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    Node *p = *head_ref;

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = new_node;
    return;
}


void PrintList(Node *node) {
    while (node != NULL) {
        cout << node->data;
        node = node->next;
    }
}


void appendStartList(Node **head_ref, int new_data) {
    Node *new_node = (Node*) malloc(sizeof(Node));

    new_node->data = new_data;
    new_node->next = NULL;

    if (*head_ref != NULL) {
        new_node->next = *head_ref;
    }

    *head_ref = new_node;
}


int main() {
    Node *head = NULL;

    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    cout << "Lista encadeada: ";
    PrintList(head);

    appendStartList(&head, 5);
    appendStartList(&head, 10);
    cout << endl << "Lista encadeada: ";
    PrintList(head);

}

/*
10.1. O que será impresso ao final do programa?
    Lista encadeada: 1234

10.2. Se o algoritmo está incluindo no final da lista, Faça uma função
que inclua no início da lista.


10.3. Se o algoritmo está incluindo no inicio da lista, Faça uma
função que inclua no final da lista.

*/