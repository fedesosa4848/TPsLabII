#include <stdio.h>
#include <stdlib.h>
#include "ListasDobleEnlazadaLib.h"

int main()
{
    printf("Agregar persona al principio de la lista\n");

    nodoDoble *miLista = inicListaDoble();
    persona nuevaPersona = cargarPersona();
    nodoDoble *nuevoNodo = crearNodoDoble(nuevaPersona);
    miLista = agregarPpioDoble(miLista, nuevoNodo);

    mostrarLista(miLista);

    printf("Agregar otra persona al principio de la lista\n");

    persona nuevaPersonaX = cargarPersona();
    nodoDoble *nuevoNodoX = crearNodoDoble(nuevaPersonaX);
    miLista = agregarPpioDoble(miLista, nuevoNodoX);

    mostrarLista(miLista);

    printf("Cargando tercer persona\n");

    persona nuevaPersona2 = cargarPersona();
    nodoDoble *nuevoNodo2 = crearNodoDoble(nuevaPersona2);
    miLista = agregarFinalDoble(miLista, nuevoNodo2);

    mostrarLista(miLista);

    char nombreBuscado[20];
    printf("Ingrese el nombre a buscar: ");
    scanf("%s", nombreBuscado);
    nodoDoble *nodoEncontrado = buscarNodo(miLista, nombreBuscado);
    if (nodoEncontrado != NULL)
    {
        printf("Nodo encontrado:\n");
        mostrarNodo(nodoEncontrado);
    }
    else
    {
        printf("Nodo no encontrado.\n");
    }


    char nombreABorrar[20];
    printf("Ingrese el nombre a borrar: ");
    scanf("%s", nombreABorrar);
    miLista = borrarNodo(miLista, nombreABorrar);

    persona nuevaPersona3 = cargarPersona();
    nodoDoble *nuevoNodo3 = crearNodoDoble(nuevaPersona3);
    miLista = agregarEnOrdenDoble(miLista, nuevoNodo3);


    miLista = cargarlista(miLista);

    mostrarLista(miLista);

    return 0;
}
