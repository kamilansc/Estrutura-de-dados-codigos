#include <stdio.h>

int main(void) {
    int a = 3, b= 5;
    int *p = &a, *q = &b;

    *p = *p + *q; // 3 + 5 = 8
    *q = *p - *q; // 8 - 5 = 3
    *p = *p - *q; // 8 - 3 = 5

    printf("%d, %d\n", a, b);

    return 0;
}