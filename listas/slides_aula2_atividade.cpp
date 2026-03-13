#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class No{
	public: 
		int mat;
		string nome;
		No *prox;

		No(int m, string n) {
			mat = m;
			nome = n;
			prox = NULL;
		}
};


class Lista{
	No *inicio,*fim;
	public:
		Lista(){
			inicio=NULL;
			fim=NULL;
		}

		
		// Questão 1
		void add_inicio(int mat, string nome){
		No *novo = new No(mat, nome);
		if (inicio == NULL){
			inicio = novo;
			fim = novo;
		} else {
			novo->prox = inicio;
			inicio = novo;
		}
		};


		// Questão 2
		void consultar (int mat) {
			No *atual = inicio;
			while (atual != NULL)
			{
				if (atual->mat == mat)
				{
					cout << "Aluno encontrado!" << endl;
					cout << "|Matrícula: " << atual->mat << endl;
					cout << "|Nome: " << atual->nome << endl;
					return;
				}
				{
				atual = atual->prox;
				}
			}
			cout << "\nAluno não encontrado!";	
		};
	

		// Questão 3
		void remover(int mat){
			No *atual = inicio;
			No *anterior = NULL;
				while (atual != NULL){
					if (atual->mat == mat){

						if (atual == inicio){
							inicio = inicio->prox;
						}
						else if (atual == fim){
							fim = anterior;
							fim->prox = NULL;
							}
						else {
							anterior->prox = atual->prox;
						}
						delete(atual);
						return;
					}
					anterior = atual;
					atual = atual->prox;
				}
				cout << "Aluno não encontrado!" << endl;
		}


		// Questão 4
		void listar(){
			No *atual = inicio;
			while (atual!=NULL){
				cout << "|Matrícula:" << atual->mat <<endl;
				cout << "|Nome: " << atual->nome <<endl;
				cout << "---------------------" <<endl;
				atual = atual->prox;
			}
		}


		// Questão 5
		Lista* copia_invertida_lista(){
			Lista *copia = new Lista();
			No *atual = this->inicio;

			while (atual != NULL)
			{
				copia->add_inicio(atual->mat, atual->nome);
				atual = atual->prox;
			}
			return copia;
		}


		// Questão 6
		void inverter_lista(){
			No *anterior = NULL;
			No *atual = this->inicio;
			No *proximo = NULL;
			
			this->fim = this->inicio;
			while (atual != NULL)
			{
				proximo = atual->prox;
				atual->prox = anterior;
				anterior = atual;
				atual = proximo;
			}
			this->inicio = anterior;
		}
};


int main(){
	Lista *turma=new Lista();
	
	turma->add_inicio(17, "Kamila");
	turma->add_inicio(25, "Maria Luiza");
	turma->add_inicio(27, "Mylena");
	turma->add_inicio(15, "Cecília");
	turma->add_inicio(10, "Mariane");
	turma->add_inicio(20, "Maria Caroline");
	turma->add_inicio(12, "Itallo");
	turma->add_inicio(5, "Mariana");
	turma->add_inicio(6, "Lívia");

	cout << "Turma: " << endl;
	turma->listar();
	
	cout << "\n\nConsultar aluno de matrícula 17: " << endl;
	turma->consultar(17);

	cout << "\n\nDepois da remocao de '15': " << endl;
	turma->remover(15);
	turma->listar();
	
	Lista *invertida = turma->copia_invertida_lista();
	cout << "\n\nCópia invertida da turma: " << endl;
	invertida->listar();

	cout << "\n\nPrópria turma invertida:" << endl;
	turma->inverter_lista();
	turma->listar();

	return 0;
}