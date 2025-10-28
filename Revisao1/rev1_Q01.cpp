#include <iostream>
#include <string.h>
using namespace std;

int main() {
    char nome1[20];
    char nome2[20];

    cout << "Digite o 1º nome: ";
    cin.getline(nome1, 20);

    cout << "Digite o 2º nome: ";
    cin.getline(nome2, 20);

    int resultado = _stricmp(nome1, nome2);

    if (resultado == 0) {
        cout << "São iguais!";
    }
    else cout << "São diferentes!";

    return 0;
}