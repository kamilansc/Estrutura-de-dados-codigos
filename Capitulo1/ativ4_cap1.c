#include <stdio.h>

typedef struct {char valor[10];} Str;

int main(void) {
    Str x = {"um"};
    Str y = {"dois"};

    puts (x.valor);
    x = y;
    puts (x.valor);

    return 0;
}