#include <string.h>

// Prova 2
struct livro {
    int cod;
    char nome[20];
};

typedef struct livro Tlivro;
Tlivro livros[5];
int ultimo = 0;

void inserirOrd(Tlivro novo) {
    int pos;
    if (ultimo < 5) {

        if (ultimo == 0) {
            livros[0] = novo;
            ultimo ++;
        }

        else {
            int comparacao = strcmp(novo.nome, livros[ultimo-1].nome);

            if (comparacao == 1 || comparacao == 0) {
                pos = ultimo;
            }

            else if (comparacao == -1) {
                if (ultimo == 0) {
                    livros[ultimo + 1] = livros[ultimo];
                }

                else {
                    pos = ultimo - 1;
                }
            }
        }

        livros[pos] = novo;
        ultimo++;
    }
}
