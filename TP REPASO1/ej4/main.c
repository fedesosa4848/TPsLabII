#include <stdio.h>
#include <stdlib.h>
#include "time.h"

int maxPosicion (int a[],int dim);

int main()
{
    srand(time(NULL));

    int arreglo[10];
    int valid=cargarArreglo(arreglo,10);

    for(int i=0; i < valid; i ++)
    {
        printf(" |%d| ",arreglo[i]);
    }

    int pos = maxPosicion(arreglo,valid);

    printf("\nEl mayor numero se encuentra en la pos : %d ", pos+1);


    return 0;
}

int cargarArreglo (int a[],int dim)
{
    srand(time(NULL));
    int i;
    for(i=0; i < dim; i++)
    {
        a[i]= rand ()% 20+1;

    }

    return i;
}

int maxPosicion (int a[],int dim)
{
    int maxPos=0;
    int maxVal=a[0];
    srand(time(NULL));

    for(int i=1; i < dim; i++)
    {
        if(a[i]>maxVal)
        {
            maxVal=a[i];
            maxPos=i;
        }
    }

    return maxPos;
}
