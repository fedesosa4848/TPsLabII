#include <stdio.h>
#include <stdlib.h>
#include "PilaConListaSinStruct.h"
// #include "PilaConStructConLista.h"

                /// utilizamos la libreria de Lista,modificada para almacenar solo un N° entero
                /// QUEDA A CARGO DE LOS ALUMNOS HACERLA

int main ()
{
    Pila pilita;          // Pila equivale a nodo* lista
    inicPila (&pilita);
    apilar(&pilita, 10);
    apilar(&pilita, 20);
    apilar(&pilita, 30);
    printf("Apile por sistema un 10, un 20 y un 30 en Pilita y ahora pido al user que cargue 3 nros mas\n");
    leer(&pilita);
    leer(&pilita);
    leer(&pilita);
    printf("\n Muestro Pilita\n");
    if(pilavacia(&pilita))
        printf("La pila esta vacia");
    else
    {
        mostrar(&pilita);
        printf("\nEl tope de Pilita es %d", tope(&pilita));
    }


    Pila pilota;
    inicPila(&pilota);

    printf("\n Paso lo de Pilita a Pilota\n");
    while(!pilavacia(&pilita))
    {
        apilar(&pilota, desapilar(&pilita));
    }

    printf("\n Muestro Pilota\n");
    mostrar(&pilota);

    printf("\n Muestro Pilita\n");
    if(pilavacia(&pilita))
        printf("La pila esta vacia");
    else
    {
        mostrar(&pilita);
        printf("\nEl tope es %d\n\n\n\n\n\n", tope(&pilita));
    }

    return 0;
}
