#include <iostream>
#include <string>
using namespace std;

int main() {
    string nome1, nome2;

    cout << "Digite o 1º nome: ";
    getline(cin, nome1);

    cout << "Digite o 2º nome: ";
    getline(cin, nome2);

    if (nome1 == nome2) {
        cout << "São iguais";
    } 
    else
        cout << "São diferentes"; 

    return 0;
}