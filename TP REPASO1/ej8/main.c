#include <stdio.h>
#include <stdlib.h>
#define max_dim 3

void cargarArregloIntercalado(int a[], int b[], int c[]) {
    int i = 0, j = 0, x = 0;

    while (i < max_dim && j < max_dim) {
        if (a[i] <= b[j]) {
            c[x] = a[i];
            i++;
        } else {
            c[x] = b[j];
            j++;
        }
        x++;
    }

    while (i < max_dim) {
        c[x] = a[i];
        i++;
        x++;
    }

    while (j < max_dim) {
        c[x] = b[j];
        j++;
        x++;
    }
}

int main() {
    int a[max_dim] = {1, 3, 5};
    int b[max_dim] = {2, 4, 6};
    int c[2 * max_dim];

    cargarArregloIntercalado(a, b, c);

    printf("Arreglo intercalado: ");
    for (int i = 0; i < 2 * max_dim; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");

    return 0;
}


