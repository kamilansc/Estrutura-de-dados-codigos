#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct{
    int x, y;
} Ponto;


typedef struct {
    Ponto dados[MAX * MAX];
    int inicio, final;
} Fila;


void Inicializar_fila(Fila *f) {
    f->inicio = f->final = 0;
}


int fila_vazia(Fila *f) {
    return f->inicio == f->final;
}


void enfileirar (Fila *f, int x, int y) {
    f->dados[f->final].x = x;
    f->dados[f->final].y = y;
    f->final++;
}


Ponto desenfileirar(Fila *f) {
    return f->dados[f->inicio++];
}


void floodFill(int imagem[MAX][MAX], int linhas, int colunas, int x, int y, int nova_cor) {
    int cor_original = imagem[x][y];
    if (cor_original == nova_cor) return;

    Fila fila;
    Inicializar_fila(&fila);
    enfileirar(&fila, x,y);

    while(!fila_vazia(&fila)) {
        Ponto p = desenfileirar(&fila);
        int i = p.x; // índice na linha
        int j = p.y; // índice na coluna

        if (i<0 || i>=linhas || j<0 || j>=colunas) continue;
        if (imagem[i][j] != cor_original) continue;

        imagem[i][j] = nova_cor;
        enfileirar(&fila, i+1, j);
        enfileirar(&fila, i-1, j);
        enfileirar(&fila, i, j+1);
        enfileirar(&fila, i, j-1);
    }
}


int main(){
    return 0;
}