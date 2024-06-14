#include <stdio.h>
#include <stdlib.h>
#include "time.h"

const int fil = 12;
const int col = 31;
void cargarMatriz ( int m[fil][col]);
void mostrarMatriz( int m[fil][col]);
int pedirMesValido();
int encontrarDiaMaximaPrecipitacion(int matriz[fil][col], int mes);
void cargarArregloMaxPrecip(int matriz[fil][col], int arreglo[fil]);

int main()
{
    srand(time(NULL));

    int matriz[fil][col];
    cargarMatriz(matriz);
    mostrarMatriz(matriz);

    int mes = pedirMesValido();

    int dia = encontrarDiaMaximaPrecipitacion(matriz,mes);

    printf("\nEl dia mas lluvioso del mes num %d fue el dia : %d",mes, dia);

    int arregloMensual [fil];
    cargarArregloMaxPrecip(matriz,arregloMensual);

    puts("\n");

    for(int i=0; i < fil; i++)
    {
        printf("Mes %d: |%d| \n",i+1,arregloMensual[i]);
    }


    return 0;
}

void cargarMatriz ( int m[fil][col])
{
    srand(time(NULL));
    int i;
    for(i=0; i < fil; i++)
    {
        for(int j=0; j < col; j++)
        {
            m[i][j]= rand()% 20+1;
        }
    }
}

void mostrarMatriz( int m[fil][col])
{
    int cont=0;
    for(int i=0; i < fil; i ++)
    {
        for(int j=0; j < col; j++)
        {
            printf(" |%dmm| ",m[i][j]);
        }
        puts("\n\n");
    }
}

int pedirMesValido()
{
    int mes;
    do {
        printf("\nIngresa un número de mes (1-12): ");
        scanf("%d", &mes);
    } while (mes < 1 || mes > 12);

    return mes;
}

int encontrarDiaMaximaPrecipitacion(int matriz[fil][col], int mes)
{
    int diaMaximaPrecipitacion = 1;
    int maximaPrecipitacion = matriz[mes - 1][0]; // suponemos que el primer dia es el max lluvioso

    for (int dia = 2; dia <= col; dia++) { //arrancamos analizando el segundo dia
        if (matriz[mes - 1][dia - 1] > maximaPrecipitacion) {
            maximaPrecipitacion = matriz[mes - 1][dia - 1]; //actualizamos valores
            diaMaximaPrecipitacion = dia;
        }
    }

    return diaMaximaPrecipitacion;
}

void cargarArregloMaxPrecip(int matriz[fil][col], int arreglo[fil])
{
    for (int mes = 1; mes <= fil; mes++) {
        arreglo[mes - 1] = encontrarDiaMaximaPrecipitacion(matriz, mes);
    }
}



