#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
class No{
	public: 
		int mat;
		char nome[23];
		No *prox; 
		No(int m, const char* n) {
			mat=m;
			strcpy(nome, n);
			prox=NULL;
		}
};


class Lista{
	No *inicio,*fim;
	public:
		Lista(){
			inicio=NULL;
			fim=NULL;
		}


		void add_fim(int mat, const char nome[23]){
			No *novo = new No(mat, nome);
			if (inicio == NULL){
				inicio = novo;
				fim = novo;
			}
			else {
				fim->prox = novo;
				fim = novo;
			}
			
		};
		

		void add_inicio(int mat, const char nome[23]){
		No *novo = new No(mat, nome);
		if (inicio == NULL){
			inicio = novo;
			fim = novo;
		} else {
			novo->prox = inicio;
			inicio = novo;
		}
		};

	
		void adicionar_ordenado(int mat, const char nome[23]){
			No *novo = new No(mat, nome);
			if (inicio == NULL || novo->mat < inicio->mat)
			{
				novo->prox = inicio;
				inicio = novo;
				if (fim == NULL) fim = novo;
				return;
			}

			No *anterior = inicio;
			No *atual = inicio->prox;
			
			while (atual != NULL && novo->mat > atual->mat)
			{
				anterior = atual;
				atual = atual->prox;
			}
			anterior->prox = novo;
			novo->prox = atual;

			if (atual == NULL)
			{
				fim = novo;
			}
			
		};
		
		// Questão 4
		void mostrar(){
			No *atual = inicio;
			while (atual!=NULL){
				printf("\n Mat: %d Nome: %s", atual->mat, atual->nome);
				atual = atual->prox;
			}
		};
	
		// Questão 3
		int remover(int cod){
			No *atual = inicio;
			No *anterior = NULL;
				while (atual != NULL){
					if (atual->mat == cod){

						if (atual == inicio){
							inicio = inicio->prox;
						}
						else{
							if (atual == fim){
								fim = anterior;
								fim->prox = NULL;
							}
							else{
								anterior->prox = atual->prox;
							}
						}
						delete(atual);
						return 1;
					}
					anterior = atual;
					atual = atual->prox;
				}
				return 0;
		};

		// Questão 2
		int consultar (int mat) {
			No *atual = inicio;
			while (atual != NULL)
			{
				if (atual->mat == mat)
				{
					printf("\nAluno encontrado! \nMatrícula: %d Nome: %s", atual->mat, atual->nome);
					return 1;
				}
				else
				{
					atual = atual->prox;
				}
			}
			cout << "\nAluno não encontrado!";
			return 0;	
		};


		// Questão 5
		Lista* copia_invertida_lista(Lista *original){
			Lista *copia = new Lista();
			No *atual = original->inicio;

			while (atual != NULL)
			{
				copia->add_inicio(atual->mat, atual->nome);
				atual = atual->prox;
			}
			return copia;
		}


		// Questão 6
		void inverter_lista(Lista *lista){
			No *anterior = NULL;
			No *atual = lista->inicio;
			No *proximo = NULL;
			
			lista->fim = lista->inicio;
			while (atual != NULL)
			{
				proximo = atual->prox;
				atual->prox = anterior;
				anterior = atual;
				atual = proximo;
			}
			lista->inicio = anterior;
		}
};


int main(){
	Lista *turma=new Lista();
	
	turma->add_fim(17, "Kamila");
	turma->mostrar();
	
	printf("\n");
	turma->add_inicio(25, "Maria Luiza");
	turma->add_fim(27, "Mylena");
	turma->add_inicio(15, "Cecília");
	turma->mostrar();
	
	turma->remover(15);
	printf("\n\nDepois da remocao de '15':");
	turma->mostrar();
	
	turma->consultar(17);
	
	Lista *invertida = turma->copia_invertida_lista(turma);
	printf("\n\nCópia invertida da turma: ");
	invertida->mostrar();
	printf("\n\n");

	Lista *turma2 = new Lista();
	turma2->adicionar_ordenado(10, "Mariane");
	turma2->adicionar_ordenado(20, "Maria Caroline");
	turma2->adicionar_ordenado(13, "Kamila");
	turma2->adicionar_ordenado(12, "Itallo");
	turma2->adicionar_ordenado(17, "Mariana");
	turma2->adicionar_ordenado(5, "Mariana");
	turma2->mostrar();

	turma2->inverter_lista(turma2);
	printf("\n");
	turma2->mostrar();

	//turma->inv_lista2();
}
