#include <stdio.h>
#include <stdlib.h>
#include "time.h"



int cargarArreglo(int a[], int dim);
int arrayToDecimal(int arr[], int dim);

int main() {
    srand(time(NULL));

    int arreglo[10];
    int valid = cargarArreglo(arreglo, 10);

    for (int i = 0; i < valid; i++) {
        printf(" |%d| ", arreglo[i]);
    }

    int decimalValue = arrayToDecimal(arreglo, valid);

    printf("\nEl valor decimal del arreglo es: %d\n", decimalValue);

    return 0;
}

int cargarArreglo(int a[], int dim) {
    int i;

    for (i = 0; i < dim; i++) {
        a[i] = rand() % 9 + 1;
    }

    return i;
}

int arrayToDecimal(int arr[], int dim) {
    int decimalValue = 0;

    for (int i = 0; i < dim; i++) {
        // Multiplicar el valor actual por 10 y sumar
        decimalValue = decimalValue * 10 + arr[i];
        printf("\n%d",decimalValue);
    }

    return decimalValue;
}
