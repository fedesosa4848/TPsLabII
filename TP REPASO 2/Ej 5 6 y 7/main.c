#include <stdio.h>
#include <stdlib.h>

void insertarOrden(int arr[], int *tam, int valor);
void insercion(int arr[], int tam) ;

int main()
{
    int arreglo[100] = {5, 10, 15, 20};
    int tam = 4;

    insertarOrden(arreglo, &tam, 12);

    for (int i = 0; i < tam; i++) {
        printf("%d ", arreglo[i]);
    }

    puts("\n");

    ///

    int arreglo2[] = {12, 11, 13, 5, 6};
    int tam2 = sizeof(arreglo2) / sizeof(arreglo2[0]);

    insercion(arreglo2, tam);

    for (int i = 0; i < tam2; i++) {
        printf("%d ", arreglo2[i]);
    }

     puts("\n");

    ///

    int arreglo3[] = {5, 10, 15, 20, 25};
    int tam3 = sizeof(arreglo3) / sizeof(arreglo3[0]);

    eliminarElemento(arreglo3, &tam3, 15);

    for (int i = 0; i < tam3; i++) {
        printf("%d ", arreglo3[i]);
    }

    return 0;
}

//ej5()
void insertarOrden(int arr[], int *tam, int valor)
{
    int i = *tam - 1;

    while (i >= 0 && arr[i] > valor) {
        arr[i + 1] = arr[i];
        i--;
    }

    arr[i + 1] = valor;
    (*tam)++;
}

//ej6()

void insercion(int arr[], int tam)
{
    for (int i = 1; i < tam; i++) {
        int dato = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > dato) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = dato;
    }
}

//ej7()

void eliminarElemento(int arr[], int *tam, int valor) {
    int pos = -1;

    for (int i = 0; i < *tam; i++) {
        if (arr[i] == valor) {
            pos = i;
            break;
        }
    }

    if (pos != -1) {
        for (int i = pos; i < *tam - 1; i++) {
            arr[i] = arr[i + 1];
        }

        (*tam)--;
    } else {
        printf("El valor no se encuentra en el arreglo.\n");
    }
}




