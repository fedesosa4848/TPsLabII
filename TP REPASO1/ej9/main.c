#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_PERSONS 10

void cargarArreglosParalelos(char nombres[][50], int edades[], int numPersonas) ;

int main()
{
    char nombres[MAX_PERSONS][50];
    int edades[MAX_PERSONS];
    int numPersonas;

    printf("Ingrese el n�mero de personas (m�ximo %d): ", MAX_PERSONS); //PONGO UN LIMITE PERPO TMB VOY A SABER LOS VALIDOS
    scanf("%d", &numPersonas);

    if (numPersonas > MAX_PERSONS) {
        printf("N�mero de personas excede el m�ximo permitido.\n");
        return 1; // C�digo de error
    }

    cargarArreglosParalelos(nombres, edades, numPersonas);

    printf("\nPersonas ingresadas:\n");
    for (int i = 0; i < numPersonas; i++) {
        printf("Nombre: %s, Edad: %d\n", nombres[i], edades[i]);
    }

    mostrarMayoresDeEdad(nombres, edades, numPersonas);

    return 0;
}

void cargarArreglosParalelos(char nombres[][50], int edades[], int numPersonas)
{
    for (int i = 0; i < numPersonas; i++) {
        printf("Ingrese el nombre de la persona %d: ", i + 1);
        scanf("%s", nombres[i]);

        printf("Ingrese la edad de %s: ", nombres[i]);
        scanf("%d", &edades[i]);
    }
}

void mostrarMayoresDeEdad(char nombres[][50], int edades[], int numPersonas) {
    printf("\nPersonas mayores de edad:\n");
    for (int i = 0; i < numPersonas; i++) {
        if (edades[i] >= 18) {
            printf("%s\n", nombres[i]);
        }
    }
}
