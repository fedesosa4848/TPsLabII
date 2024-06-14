#include <stdio.h>
#include <stdlib.h>

void cargarArregloDinamico(int *puntArr, int dim);
void mostrarArr(int puntArr[], int dim);
int *redimensionarArreglo(int *arr, int dim);

int main()
{
    int dim;

    printf("Ingrese la dimension del arreglo: ");
    scanf("%d", &dim);

    int *arregloDinamico = (int *)malloc(dim * sizeof(int));
    cargarArregloDinamico(arregloDinamico, dim);
    mostrarArr(arregloDinamico, dim);
    free(arregloDinamico);
    puts("\n");

    arregloDinamico = redimensionarArreglo(arregloDinamico, 20);
    printf("Nuevo tamaño del arreglo: %d\n", 20);

    free(arregloDinamico);

    return 0;
}

void cargarArregloDinamico(int *puntArr, int dim)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        puntArr[i] = i;
    }
}

void mostrarArr(int puntArr[], int dim)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        printf("%d, ", puntArr[i]);
    }
}

int *redimensionarArreglo(int *arr, int dim)
{
    arr = realloc(arr, dim * sizeof(int));

    if (arr == NULL)
    {
        printf("Error al redimensionar el arreglo dinámico\n");
        exit(1);
    }

    return arr;
}
