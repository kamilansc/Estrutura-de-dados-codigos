#include <stdio.h>

int main(void) {
    char s[3] = "um";
    char t[3] = "um";

    printf("%c", s[0]);
    printf("%c\n", *(s+1));
    if (s == t) puts ("iguais");
    else puts ("diferentes");

    return 0;
}