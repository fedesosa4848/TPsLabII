#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 30

typedef struct {
      char nombre[30];
      char genero;
      int edad;
}persona;

int cargaArregloStruc(persona L[],int dim);
int contarPorGenero (persona L[],int valid, char genero[]);
persona* copiarPorGenero(persona L[], int valid, char genero, int* nuevoValid);

int main()
{
    persona alumnos [MAX_SIZE];
    int valid2=cargaArregloStruc(alumnos,MAX_SIZE);

    char genero;

    printf("\nIngrese un genero : (M/F)");
    fflush(stdin);
    scanf("%c",&genero);

    int contador=contarPorGenero(alumnos,valid2,genero);

    printf("Cantidad de alumnos %c : %d",genero,contador);

    ordenarPorEdad(alumnos, valid2);

    printf("Arreglo ordenado por edad:\n");
    mostrarArreglo(alumnos, valid2);

    int nuevoValid;
    persona* nuevosAlumnos = copiarPorGenero(alumnos, valid2, genero, &nuevoValid);

    if (nuevosAlumnos != NULL) {
        printf("Arreglo de alumnos de genero %c:\n", genero);
        mostrarArreglo(nuevosAlumnos, nuevoValid);
        free(nuevosAlumnos); // Liberar memoria asignada por malloc
    } else {
        printf("No hay alumnos del genero %c.\n", genero);
    }

    return 0;
}

int cargaArregloStruc(persona L[],int dim)
{
    int i=0;
    char mander = 's';

    for(i=0; i < dim && mander == 's'; i++)
    {
        printf("Ingrese nombre  : \n");
        fflush(stdin);
        gets(L[i].nombre);

        printf("Ingrese el genero : \n");
        fflush(stdin);
        scanf("%c",&L[i].genero);

        printf("Ingrese la edad : \n");
        fflush(stdin);
        scanf("%d",&L[i].edad);

        puts("Presione 'S'para cargar mas datos al registro \n");
        fflush(stdin);
        scanf("%c",&mander);

    }

    return i;
}

int contarPorGenero (persona L[],int valid, char genero[])
{
    int cont=0;

    for(int i=0; i < valid; i++)
    {
        if(L[i].genero==genero)
        {
            cont++;
        }
    }

    return cont;
}


void ordenarPorEdad(persona L[], int valid)
{
    for (int i = 0; i < valid - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < valid; j++) {
            if (L[j].edad < L[minIndex].edad) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            intercambiar(&L[i], &L[minIndex]);
        }
    }
}

void intercambiar(persona *a, persona *b)
{
    persona temp = *a;
    *a = *b;
    *b = temp;
}

void mostrarArreglo(persona L[], int valid)
{
    for (int i = 0; i < valid; i++) {
        printf("Nombre: %s, Genero: %c, Edad: %d\n", L[i].nombre, L[i].genero, L[i].edad);
    }
}

persona* copiarPorGenero(persona L[], int valid, char genero, int* nuevoValid)
{
    int cont = contarPorGenero(L, valid, genero);

    if (cont == 0) {
        *nuevoValid = 0;
        return NULL;
    }

    persona* nuevoArreglo = (persona*)malloc(cont * sizeof(persona));
    if (nuevoArreglo == NULL) {
        *nuevoValid = 0;
        return NULL;
    }

    int nuevoIndice = 0;
    for (int i = 0; i < valid; i++) {
        if (L[i].genero == genero) {
            nuevoArreglo[nuevoIndice] = L[i];
            nuevoIndice++;
        }
    }

    *nuevoValid = cont;
    return nuevoArreglo;
}


