#include <iostream>
using namespace std;

int compararStrings(char nome1[20], char nome2[20]) {
    for (int i = 0; nome1[i] != '\0' || nome2[i] != '\0'; i++) {
        if (nome1[i] != nome2[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char nome1[20], nome2[20];

    cout << "Digite o 1º nome: ";
    cin.getline(nome1, 20);

    cout << "Digite o 2º nome: ";
    cin.getline(nome2, 20);

    int resultado = compararStrings(nome1, nome2);
    if (resultado == 0) 
        cout << "São iguais";
    else
        cout << "São diferentes";

    return 0;
}