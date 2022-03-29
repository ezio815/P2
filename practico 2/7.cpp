#include "general.h"

float horner ( float * P , uint n , float x ) {
    if (n == 0)
        return P[n];
    return horner(P, n - 1, x) * x + P[n];
}

float * insertar(float * P, uint n, uint t) {
    float a;
    printf("Ingrese el coeficiente: ");
    scanf("%f", &a);
    P[t - n] = a;
    if (n > 0) {
        return insertar(P, n - 1, t);
    }
    return P;
}

int main() {
    uint n;
    float x;
    printf("Ingrese la mayor potencia polinomio: ");
    scanf("%d", &n);
    printf("Ingrese el valor de x: ");
    scanf("%f", &x);
    float * P = insertar(P, n, n);
    printf("El resultado es: %f\n", horner(P, n, x));
    return 0;
}