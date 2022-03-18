#include "general.h"

uint factAcum ( uint n , int acum ) {
    if (n == 0)
        return acum;
    return factAcum(n - 1, n * acum);
}

int main() {
    uint n;
    printf("Ingrese un número entero no negativo: ");
    scanf("%d", &n);
    printf("El factorial de %d es %d\n", n, factAcum(n, 1));
    return 0;
}