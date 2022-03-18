#include "general.h"
#include <stdio.h>

int maxComDivRec(uint n, uint a, uint b) {
    if (a % n == 0 && b % n == 0)
        return n;
    return maxComDivRec(n - 1, a, b);
}

int maxComDiv(uint a, uint b) {
    uint min;
    if (a <= b)
        min = a;
    if (a > b)
        min = b;
    return maxComDivRec(min, a, b);
}

int main() {
    int a, b;
    printf("Ingrese 2 números enteros de la forma \"a b\": ");
    scanf("%d %d", &a, &b);
    printf("El máximo común divisor entre %d y %d es: %d\n", a, b, maxComDiv(a, b));
    return 0;
}