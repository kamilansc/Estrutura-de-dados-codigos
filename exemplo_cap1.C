#include <stdio.h>

typedef struct {int a; char b; float c;} Reg;

int main(){
    int v[3] = {9, 6, 7};
    int *pInt = v;
        
    printf("%d\n",*(pInt));    


    Reg r = {18, 'a', 2.5};
    Reg *pReg = &r;

    printf("%f\n", pReg->c);
    return 0;
}