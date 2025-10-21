#include <iostream>
using namespace std;

void procurarElementoPorIndice(int *indice, int *p, int tamanho) {
    for (int i=0; i<tamanho; i++){
        if ((p+i) == indice) {
            cout << "Elemento: " << *(p+i) << endl;
            cout << "Deslocamento: " << i << endl;
            return;
        }
    }
}


int main() {
    int matriz[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int *p = &matriz[0][0];

    for (int i=0; i < 6; i++) {
        int linha = i/3;
        int coluna = i%3;
        cout << "Elemento matriz[" << linha <<"][" << coluna << "] = " << (p+i) << endl;
    }
    cout << "Endereço do ponteiro: " << matriz << endl;
    procurarElementoPorIndice(&matriz[1][0], p, 6);
    return 0;
}