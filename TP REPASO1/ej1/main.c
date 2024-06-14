#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 30
#include "time.h"
#include <string.h>

void initializeArray(int arr[], int size);
int getValues(int arr[], int size);
int sumArray(int arr[], int size);
int countValues(int arr[], int size);
float calculateAverage(int arr[], int size);

int main() {
    int arr[MAX_SIZE];
    int size = sizeof(arr) / sizeof(arr[0]);

    initializeArray(arr, size);
    int count = getValues(arr, size);

    if (count == 0) {
        printf("No se ingresaron valores.\n");
        return 0;
    }

    float avg = calculateAverage(arr, size);

    printf("El promedio de los valores ingresados es: %.2f\n", avg);

    return 0;
}

void initializeArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = -1;
    }
}

int getValues(int arr[], int size) {
    int count = 0;
    int value;

    printf("Ingrese los valores del arreglo (ingrese un número negativo para terminar):\n");

    for (int i = 0; i < size; i++) {
        scanf("%d", &value);
        if (value < 0) {
            break;
        }
        arr[i] = value;
        count++;
    }

    return count;
}

int sumArray(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != -1) {
            total += arr[i];
        }
    }
    return total;
}

int countValues(int arr[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != -1) {
            count++;
        }
    }
    return count;
}

float calculateAverage(int arr[], int size) {
    int total = sumArray(arr, size);
    int count = countValues(arr, size);
    if (count == 0) {
        return 0;
    }
    return (float)total / count;
}
