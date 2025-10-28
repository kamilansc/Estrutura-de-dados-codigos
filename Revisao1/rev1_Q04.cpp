#include <string.h>
#include <iostream>
using namespace std;

typedef struct {
    char valor[10];
} Str;

main() {
    char valor[3] = "um";

    Str v = {"123"};

    size_t i = 0;
    while (i <= strlen(v.valor)) {
        cout << i << "--" << v.valor[i] << endl;
        i++;
    }

    cout << "---------\n";

    int j = 0;
    while (valor[j] != '\0') {
        cout << "j = " << j << " - " << valor[j] << endl;
        j++;
    }

    cout << j;
}

// Resposta da 4.1) Ao final do programa, o valor de i é 4 e o valor de j é 2.