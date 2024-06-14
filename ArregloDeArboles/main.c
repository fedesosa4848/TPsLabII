#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LibreriaArregloDeArboles.h"

const char * nombreArchivo = "animales.dat";

int main()
{
    int cantidad = mostrarArchivoAnimales(nombreArchivo);

    printf("Cantidad de registros : %d",cantidad);

    celdaEspecie ADA [cantidad];
    int validos = ingresarAnimales(nombreArchivo,ADA,cantidad);

    puts("\n");

    for (int i = 0; i < validos; i++)
{
    printf("Especie : %s\n", ADA[i].especie);
    inorder(ADA[i].arbolDeAnimales);

    puts("\n-----------\n");
}


    return 0;
}
