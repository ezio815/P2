#include "./general.h"
#include <string.h>

bool esPalindrome(uint n, char *texto) {
    bool resultado = texto[n] == texto[strlen(texto) - (n + 1)];
    if (n == 0)
        return resultado;
    return resultado && esPalindrome(n - 1, texto);
}

int main() {
    printf("Ingrese un texto: ");
    char *texto;
    texto = new char;
    scanf("%[^\n]", texto);
    if (esPalindrome(strlen(texto) / 2, texto))
        printf("\"%s\" sí es palíndrome\n", texto);
    else
        printf("\"%s\" no es palíndrome\n", texto);
    return 0;
}