#include <stdio.h>
#include <string.h>
bool EsPalindrome(char* frase){
    int largo = strlen(frase);
    //printf("%s", frase);
    for (int i = 0; i < largo / 2; i++)
        if (frase[i] != frase[largo - 1 - i])
            return false;
    return true;
}

int main() {
    /*int valor = 7/2;
    printf("%d", valor);*/
    printf("Ingresa una frase: ");
    char *frase;
    frase = new char;
    scanf("%[^\n]s", frase);

    if (EsPalindrome(frase))
        printf("\nSí es :)");
    else
        printf("\nNo es :(");

    return 0;
}