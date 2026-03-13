#include <stdio.h>
// #include <conio.h> --> armazena a função _textcolor
#include "../Capitulo4 - filas/fila.h"

#define dim 9 // dimensão da matriz
#define cor(i, j) (i>=0 && i<dim && j>=0 && j<dim ? I[i][j] : -1)
#define par(i, j) ((i)*100+(j))
#define lin(p) ((p)/100)
#define col(p) ((p)%100)

int I[dim][dim] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 0, 0, 1, 0, 0, 0, 0},
                   {0, 0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 0, 1, 1, 1, 1, 1, 0, 0},
                   {0, 1, 1, 1, 1, 1, 1, 1, 0},
                   {0, 0, 2, 0, 0, 0, 2, 0, 0},
                   {0, 0, 2, 0, 0, 0, 2, 0, 0},
                   {0, 0, 2, 2, 2, 2, 2, 0, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0}};

int K[dim][dim] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},  // Solução da questão 2 (decidi não substituir a matriz I
                   {0, 1, 0, 0, 1, 0, 0, 1, 0},  // e adicionar a K que é o desenho recomendado pela questão)
                   {0, 0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 1, 1, 1, 1, 1, 1, 0},
                   {0, 0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 1, 0, 0, 1, 0, 0, 1, 0},
                   {0, 0, 0, 0, 0, 0, 0, 0, 0}};


void textcolor(int color) { // a função _textcolor de <conio.h> não existe no compilador GCC moderno
    // usa cores ANSI (0-7 = preto a branco)
    printf("\033[3%dm", color);
}


void resetcolor() {
    printf("\033[0m");
}


int colorir (int I[dim][dim], int i, int j, int novaCor) {
    Fila F = fila(dim*dim);
    int corOriginal = I[i][j];
    if (corOriginal == novaCor) return 1; // solução da Questão 1
    I[i][j] = novaCor;
    enfileira(par(i, j), F);
    while (!vaziaf(F)) {
        int ponto = desenfileira(F);
        i = lin(ponto);
        j = col(ponto);
        if (cor(i-1, j) == corOriginal) {
            I[i-1][j] = novaCor;
            enfileira(par(i-1, j), F);
        }
        if (cor(i+1, j) == corOriginal) {
            I[i+1][j] = novaCor;
            enfileira(par(i+1, j), F);
        }
        if (cor(i, j-1) == corOriginal) {
            I[i][j-1] = novaCor;
            enfileira(par(i, j-1), F);}
        if (cor(i, j+1) == corOriginal) {
            I[i][j+1] = novaCor;
            enfileira(par(i, j+1), F);}
    }
    destroif(&F);
    return 0;
}


void exiba(int I[dim][dim]) {
    for (int i = -1; i<dim; i++) {
        textcolor(7);
        for (int j = -1; j<dim; j++){
            if (i<0 && j<0) 
                printf(" ");
            else if (i<0) 
                printf("%2d", j);
            else if (j<0) 
                printf("\n%2d", i);
            else {
                textcolor(I[i][j]); 
                printf("%c%c", 219, 219);}
        }
    }
    resetcolor();
}


void inicia (int I[dim][dim], char *s) {
    FILE *a = fopen(s, "rt");
    if (!a) {
        puts("Arquivo não encontrado!");
        abort();
    }

    for (int i = 0; i < dim; i++)
        for (int j = 0; j < dim; j++)
            fscanf(a, "%d", &I[i][j]);
    fclose(a);
}


int escolheMatriz () {
    int opcaoMatriz = 0;
    while (1) {
        puts("(1) - CASA \n(2) - ESTRELA \n(3) - Passar dados de um ARQUIVO DE TEXTO");
        printf("Qual desenho você deseja visualizar? ");
        if (scanf("%d", &opcaoMatriz) != 1) {
            printf("Entrada inválida!\n");
            while (getchar() != '\n');
            continue;
        }

        if (opcaoMatriz == 1) return 1;
        else if (opcaoMatriz == 2) return 2;
        else if (opcaoMatriz == 3) return 3;
        else puts("Opção inválida!");
        }
    }


int main() {
    int i = 0, j = 0, novaCor = 0, matriz[dim][dim] = {0};
    int opcaoMatriz = escolheMatriz();
    if (opcaoMatriz == 1) exiba(I);
    else if (opcaoMatriz == 2) exiba(K);
    else if (opcaoMatriz == 3) {
        char nomeArquivo[100];
        printf("Digite o nome do arquivo (sem aspas): ");
        scanf("%s", nomeArquivo);
        inicia(matriz, nomeArquivo);
        exiba(matriz);
    }
        
    while (1) {
        printf("\n\nNova cor (ou -1 para sair): ");
        if (scanf("%d", &novaCor) != 1) {
            printf("Entrada inválida!\n");
            while (getchar() != '\n');
            continue;
        }
        if (novaCor<0) break;
        
        do {
            printf("Posição? (informe i e j respectivamente separados por espaço) ");
            scanf("%d %d", &i, &j);
        } while (i<0 || i>=dim || j<0 || j>=dim);
        
        if (opcaoMatriz == 1) {
            if (colorir(I, i, j, novaCor) == 1) { //solução da Questão 1
                printf("A área desejada já possui a cor escolhida. Tente novamente.\n");
                continue;
            }
            exiba(I); 
        }
        if (opcaoMatriz == 2) {
            if (colorir(K, i, j, novaCor) == 1) { //solução da Questão 1
                printf("A área desejada já possui a cor escolhida. Tente novamente.\n");
                continue;
            }
            exiba(K);
        }
        if (opcaoMatriz == 3) {
            if (colorir(matriz, i, j, novaCor) == 1) { //solução da Questão 1
                printf("A área desejada já possui a cor escolhida. Tente novamente.\n");
                continue;
            }
            exiba(matriz);
        }
    }
    return 0;
}