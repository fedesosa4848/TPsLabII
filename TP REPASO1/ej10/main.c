#include <stdio.h>
#include <stdlib.h>

void calcularEstadisticas(const int arreglo[], int dim, int *maximo, int *minimo, float *promedio);

int main() {
    int numeros[] = {12, 5, 23, 8, 17};
    int dimension = sizeof(numeros) / sizeof(numeros[0]);

    int maximo, minimo;
    float promedio;

    calcularEstadisticas(numeros, dimension, &maximo, &minimo, &promedio);

    printf("Valor máximo: %d\n", maximo);
    printf("Valor mínimo: %d\n", minimo);
    printf("Promedio: %.2f\n", promedio);

    return 0;
}



void calcularEstadisticas(const int arreglo[], int dim, int *maximo, int *minimo, float *promedio) {
    if (dim <= 0) {
        printf("Error: La dimensión debe ser mayor que cero.\n");
        return;
    }

    *maximo = arreglo[0];
    *minimo = arreglo[0];
    *promedio = 0.0;

    for (int i = 0; i < dim; i++) {
        if (arreglo[i] > *maximo) {
            *maximo = arreglo[i];
        }
        if (arreglo[i] < *minimo) {
            *minimo = arreglo[i];
        }
        *promedio += arreglo[i];
    }

    *promedio /= dim;
}


