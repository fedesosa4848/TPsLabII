#include <stdio.h>
#include <stdlib.h>
#include "time.h"

void llenarArchivo(const char *nombreArchivo);
void llenarArchivoRecursivo(FILE * archivo,int i,int cantidad);
void mostrarArchivo(const char *nombreArchivo);
int encontrarMinimoRecursivo(FILE *archivo);
int encontrarMinimo(const char *nombreArchivo);
void invertirArchivoRecursivo(FILE *archivo, int *arreglo, int i);
void invertirArchivo(const char *nombreArchivo);

int main()
{

    srand(time(NULL));

    const char *nombreArchivo = "numeros.bin"; // Nombre del archivo
    llenarArchivo(nombreArchivo);
    mostrarArchivo(nombreArchivo);
    int minimo = encontrarMinimo(nombreArchivo);
    printf("\nEl minimo es : %d",minimo);
    puts("\n");
    invertirArchivo(nombreArchivo);
    mostrarArchivo(nombreArchivo);

    return 0;
}

void mostrarArchivo(const char *nombreArchivo)
{
    FILE *archi = fopen(nombreArchivo, "rb");
    if (archi == NULL)
    {
        puts("Error\n");
        return;
    }

    printf("Contenido del archivo:\n");

    int num;
    long tamanoArchivo = ftell(archi);

    // Leer y mostrar los n�meros desde el principio del archivo
    fseek(archi, 0, SEEK_SET);

    while (fread(&num, sizeof(int), 1, archi) == 1)
    {
        printf(" |%d| ", num);
    }

    fclose(archi);
}



void llenarArchivoRecursivo(FILE * archivo,int i,int cantidad)
{
    int num = rand() % 120+1;
    if(i == cantidad)
    {
        return;
    }else
    {
        fwrite(&num,sizeof(int),1,archivo);
        llenarArchivoRecursivo(archivo,i+1,cantidad);
    }


}
void llenarArchivo(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        return;
    }
    int cantidadNumeros = 10; // Cantidad de n�meros a generar y almacenar en el archivo
    int i=0;
    llenarArchivoRecursivo(archivo,i,cantidadNumeros);


    fclose(archivo);
}

int encontrarMinimo(const char *nombreArchivo) {

    int num;

    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        return;
    }

    num=encontrarMinimoRecursivo(archivo);


    fclose(archivo);

    return num;
}


int encontrarMinimoRecursivo(FILE *archivo)
{
    int numero;
    int minimo;

    // Leer el primer n�mero del archivo
    if (fread(&numero, sizeof(int), 1, archivo) != 1)
    {
        // Si no se pudo leer un n�mero, el archivo est� vac�o
        return -1; // Devuelve -1 para indicar un error o que el archivo est� vac�o
    }

    // Leer el m�nimo de los n�meros restantes en el archivo de forma recursiva
    minimo = encontrarMinimoRecursivo(archivo);

    // Comparo el n�mero actual con el m�nimo encontrado hasta ahora
    if (numero < minimo || minimo == -1)
    {
        return numero; // Si el n�mero actual es menor, lo devolvemos como el nuevo m�nimo
    }
    else
    {
        return minimo; // Si no, devolvemos el m�nimo encontrado hasta ahora
    }
}

void invertirArchivoRecursivo(FILE *archivo, int *arreglo, int i)
{
    int numero;

    // Leer el n�mero del archivo
    if (fread(&numero, sizeof(int), 1, archivo) != 1)
    {
        // Si no se pudo leer un n�mero, el archivo est� vac�o
        return;
    }

    // Llenar el arreglo recursivamente
    invertirArchivoRecursivo(archivo, arreglo, i + 1);

    // Colocar el n�mero le�do en el arreglo en la posici�n inversa
    arreglo[i] = numero;
}

void invertirArchivo(const char *nombreArchivo)
{
    FILE *archivo = fopen(nombreArchivo, "rb+");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo");
        return;
    }

    // Obtener el tama�o del archivo dividiendo el tama�o total por el tama�o de un entero
    fseek(archivo, 0, SEEK_END);
    long tamanoArchivo = ftell(archivo);
    fseek(archivo, 0, SEEK_SET);

    // Calcular la cantidad de elementos enteros en el archivo
    int cantidadElementos = tamanoArchivo / sizeof(int);

    // Crear un arreglo para almacenar los elementos
    int *arreglo = (int *)malloc(cantidadElementos * sizeof(int));
    if (arreglo == NULL)
    {
        printf("Error al asignar memoria para el arreglo");
        fclose(archivo);
        return;
    }

    // Llenar el arreglo de forma recursiva
    invertirArchivoRecursivo(archivo, arreglo, 0);

    // Volver al inicio del archivo para escribir los elementos invertidos
    fseek(archivo, 0, SEEK_SET);

    // Escribir los elementos invertidos en el archivo
    fwrite(arreglo, sizeof(int), cantidadElementos, archivo);

    // Liberar la memoria del arreglo
    free(arreglo);

    // Cerrar el archivo
    fclose(archivo);
}




