#include <stdio.h>
#include <stdlib.h>
#include "libreriaDoble.h"

nodo* crearNodo(int dato) {
    nodo* aux = (nodo*)malloc(sizeof(nodo));
    aux->dato = dato;
    aux->siguiente = NULL;
    return aux;
}

void cargarLista(nodo** lista) {
    char mander = 's';
    int num;
    nodo* nuevo;

    while (mander == 's') {
        printf("Ingrese un número: ");
        scanf("%d", &num);
        nuevo = crearNodo(num);
        agregarPpio(lista, nuevo);

        printf("Elemento cargado. ¿Desea cargar más números a la lista? (S/N): ");
        fflush(stdin);
        scanf(" %c", &mander);
    }

}

void inicLista(nodo** lista) {
    *lista=NULL;
}


void mostrarLista(nodo* lista) {
    if (lista == NULL) {
        printf("La lista está vacía.\n");
    } else {
        nodo* seg = lista;
        while (seg != NULL) {
            printf("Número en la lista: %d\n", seg->dato);
            seg = seg->siguiente;
        }
    }
}


void mostrarListaRecursiva(nodo** lista) { //NO ES NECESARIA UNA SEGUIDORA PQ LA LISTA NO SE MODIFICA. Se puede trabajar con punt doble o punt Simple
    if ( * lista == NULL) {
        printf("Fin de la lista.\n");
    } else {
            printf("%d ",(*lista)->dato);
            mostrarListaRecursiva(&(*lista)->dato);
        }
}


void agregarPpio(nodo** lista, nodo* nuevoNodo) {
    if ((*lista) == NULL) {
        *lista = nuevoNodo;
    } else {
        nuevoNodo->siguiente = *lista;
        *lista = nuevoNodo;
    }
}

void agregarFinal(nodo** lista, nodo* nuevoNodo) {
    if (*lista == NULL) {
        *lista = nuevoNodo;
    } else {
        nodo* ultimo = buscarUltimo(*lista);
        ultimo->siguiente = nuevoNodo;
    }
}

void agregarEnOrden(nodo** lista, nodo* nuevoNodo) {
    if (*lista == NULL || nuevoNodo->dato < (*lista)->dato) {
        nuevoNodo->siguiente = *lista;
        *lista = nuevoNodo;
    } else {
        nodo* actual = *lista;
        while (actual->siguiente != NULL && actual->siguiente->dato < nuevoNodo->dato) {
            actual = actual->siguiente;
        }
        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente = nuevoNodo;
    }
}


nodo* buscarUltimo(nodo* lista) {
    if (lista == NULL) {
        return NULL;
    }
    while (lista->siguiente != NULL) {
        lista = lista->siguiente;
    }
    return lista;
}

void borrarNodo(nodo** lista, int dato) {
    nodo* seg = *lista;
    nodo* ante = NULL;

    while (seg != NULL && seg->dato != dato) {
        ante = seg;
        seg = seg->siguiente;
    }

    if (seg != NULL) {
        if (ante == NULL) {
            *lista = seg->siguiente;
        } else {
            ante->siguiente = seg->siguiente;
        }
        free(seg);
    }
}

nodo* buscarNodo(nodo* lista, int dato) {
    nodo* actual = lista;
    while (actual != NULL) {
        if (actual->dato == dato) {
            return actual; // Se encontró el nodo con el valor deseado
        }
        actual = actual->siguiente;
    }
    return NULL; // El nodo no se encontró en la lista
}




