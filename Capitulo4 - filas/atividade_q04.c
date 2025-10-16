#include <stdio.h>
#include "fila.h"
#define tempo 3 // define o tempo máximo da CPU como 3


int main() {
    Fila F = fila(5);
    enfileira(17, F);
    enfileira(25, F);
    enfileira(39, F);
    enfileira(46, F);

    while (!vaziaf(F))
    {
        int x = desenfileira(F);
        int num_processo = x/10;
        int tempo_processo = x%10;
        
        if (tempo_processo > 3) enfileira(num_processo*10 + (tempo_processo - tempo), F);
        else printf("Processo %d concluído!\n", num_processo);
    }
    destroif(&F);
    return 0;
}

/*
>> Ordem de conclusão dos processos:
17: 7 - 4; 14: 4 - 1; 11: 1 --> CONCLUÍDO 
25: 5 - 2; 22: 2 --> CONCLUÍDO
39: 9 - 6; 36: 6 - 3; 33: 3 --> CONCLUÍDO
46: 6 - 3; 43: 3 --> CONCLUÍDO

1º: Processo 2;
2º: Processo 4;
3º: Processo 1;
4ª: Processo 3
*/
