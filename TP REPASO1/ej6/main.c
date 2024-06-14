#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int esPalindromo(const char *cadena);

int main() {
    char cadena[100];
    printf("Ingrese una cadena: ");
    scanf("%s", cadena);

    if (esPalindromo(cadena)) {
        printf("La cadena es un pal�ndromo.\n");
    } else {
        printf("La cadena no es un pal�ndromo.\n");
    }

    return 0;
}


int esPalindromo(const char *cadena) {
    int longitud = strlen(cadena);
    int inicio = 0;
    int fin = longitud - 1;

    while (inicio < fin) {
        if (cadena[inicio] != cadena[fin]) {
            return 0; // No es un pal�ndromo
        }
        inicio++;
        fin--;
    }
    return 1; // Es un pal�ndromo
}

