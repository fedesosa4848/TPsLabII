#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cargarArregloCaracteres(char A[],int dimesion);
void mostrarArregloCaracteres(char A[],int validos);
void invertirArregloCaracteres(char A[], int validos);

int main()
{
    char arregloCaracteres[20];
    int validate=0;
    validate=cargarArregloCaracteres(arregloCaracteres,20);
    printf("\narreglo caracteres\n");
    mostrarArregloCaracteres(arregloCaracteres,validate);

    invertirArregloCaracteres(arregloCaracteres,validate);
    puts("\n");

    mostrarArregloCaracteres(arregloCaracteres,validate);

    return 0;
}

int cargarArregloCaracteres(char A[],int dimesion)
{
    int validos=0;
    char mander = 's';
    while(mander == 's')
    {
        printf("ingrese una letra : ");
        fflush(stdin);
        scanf("%c",&A[validos]);

        validos++;

        printf("\npresione S para seguir cargando letras : ");
        fflush(stdin);
        scanf("%c",&mander);
    }

    return validos;
}

void mostrarArregloCaracteres(char A[],int validos)
{
    int i =0;

    while (i < validos)
    {
        printf("%c ",A[i]);
        i++;
    }
}

void invertirArregloCaracteres(char A[], int validos)
{
    int inicio = 0;
    int fin = validos - 1;
    char temp;

    while (inicio < fin)
    {
        // Intercambiar los caracteres en las posiciones inicio y fin
        temp = A[inicio];
        A[inicio] = A[fin];
        A[fin] = temp;

        inicio++;
        fin--;
    }
}
