#include <stdio.h>

int main(void) {
    char s[3] = "um";
    char t[3] = "um";

    if(s == t) puts ("iguais");
    else puts ("diferentes");

    return 0;
}
/* O resultado dá "diferentes" pq ele compara o endereço de mémoria das variáveis.
Se quisésemos comparar o conteúdo das varíáveis teríamos que usar a função strcmp da lib <string.h> */