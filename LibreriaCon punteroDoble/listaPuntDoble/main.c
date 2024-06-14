#include <stdio.h>
#include <stdlib.h>
#include "libreriaDoble.h"


int main() {
    nodo* lista;
    inicLista(lista);
    cargarLista(&lista);
    printf("Lista cargada:\n");
    mostrarLista(lista);

    int datoAEliminar;
    printf("Ingrese el número que desea eliminar de la lista: ");
    scanf("%d", &datoAEliminar);
    lista = borrarNodo(&lista, datoAEliminar);
    printf("Lista después de eliminar el número %d:\n", datoAEliminar);
    mostrarLista(lista);

    int datoABuscar;
    printf("Ingrese el número que desea buscar en la lista: ");
    scanf("%d", &datoABuscar);
    nodo* nodoEncontrado = buscarNodo(lista, datoABuscar);

    if (nodoEncontrado != NULL) {
        printf("Nodo encontrado: %d\n", nodoEncontrado->dato);
    } else {
        printf("El nodo con el valor %d no se encontró en la lista.\n", datoABuscar);
    }


    // Crear algunos nodos y agregarlos en orden
    nodo* nodo1 = crearNodo(5);
    nodo* nodo2 = crearNodo(3);
    nodo* nodo3 = crearNodo(8);

    lista = agregarEnOrden(&lista, nodo1);
    lista = agregarEnOrden(&lista, nodo2);
    lista = agregarEnOrden(&lista, nodo3);

    // Mostrar la lista resultante
    printf("Lista con nodos agregados en orden:\n");
    mostrarLista(lista);

    return 0;
}
