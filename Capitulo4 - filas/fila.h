typedef char Itemf;                 // tipo de item: nesse caso item é char

typedef struct fila {
    int max;                        // tamanho de fila
    int total;                      // quantidade atual de itens da fila
    int inicio;                     // indice da posição inicial
    int final;                      // indice da posição final
    Itemf *item;
} *Fila;