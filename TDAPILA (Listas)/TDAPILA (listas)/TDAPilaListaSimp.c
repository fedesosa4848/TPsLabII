#include <stdio.h>
#include <stdlib.h>
#include "TDAPilaListaSimp.h"

// Función para crear una nueva pila vacía
Pila* crearPila() {
    struct Pila* pila = (Pila*)malloc(sizeof(Pila)); // Asigna memoria para la pila
    if (!pila) { // Verifica si la asignación de memoria fue exitosa
        perror("Error al crear la pila"); // Imprime un mensaje de error en caso de falla
        exit(EXIT_FAILURE); // Termina el programa con un estado de error
    }
    pila->tope = NULL; // Inicializa el tope de la pila como NULL (pila vacía)
    return pila; // Retorna un puntero a la pila creada
}

// Función para verificar si la pila está vacía
int estaVacia(Pila* pila) {
    return pila->tope == NULL; // Comprueba si el puntero al tope de la pila es NULL
}

// Función para apilar un elemento en la pila
void empujar(Pila* pila, int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo)); // Crea un nuevo nodo
    if (!nuevoNodo) { // Verifica si la asignación de memoria fue exitosa
        perror("Error al empujar un elemento en la pila"); // Imprime un mensaje de error en caso de falla
        exit(EXIT_FAILURE); // Termina el programa con un estado de error
    }
    nuevoNodo->dato = dato; // Almacena el dato en el nuevo nodo
    nuevoNodo->siguiente = pila->tope; // El nuevo nodo apunta al antiguo tope de la pila
    pila->tope = nuevoNodo; // Actualiza el tope de la pila al nuevo nodo
}

// Función para sacar un elemento de la pila
int sacar(Pila* pila) {
    if (estaVacia(pila)) { // Verifica si la pila está vacía
        printf("La pila está vacía\n"); // Imprime un mensaje de error
        exit(EXIT_FAILURE); // Termina el programa con un estado de error
    }
    Nodo* temp = pila->tope; // Almacena el puntero al nodo en el tope de la pila en una variable temporal
    int dato = temp->dato; // Almacena el dato del nodo en una variable
    pila->tope = temp->siguiente; // Actualiza el tope de la pila al siguiente nodo
    free(temp); // Libera la memoria del nodo eliminado
    return dato; // Retorna el dato eliminado de la pila
}

// Función para obtener el elemento superior de la pila sin eliminarlo
int consultarTope(Pila* pila) {
    if (estaVacia(pila)) { // Verifica si la pila está vacía
        printf("La pila está vacía\n"); // Imprime un mensaje de error
        exit(EXIT_FAILURE); // Termina el programa con un estado de error
    }
    return pila->tope->dato; // Retorna el dato en el tope de la pila sin eliminarlo
}

void mostrarPila(Pila* pila) {
    Pila aux; // Crear una pila auxiliar para invertir temporalmente los elementos
    aux.tope = NULL; // Inicializar la pila auxiliar

    // Invertir los elementos de la pila original en la pila auxiliar
    while (!estaVacia(pila)) {
        int elemento = sacar(pila); // Sacar de la pila original
        empujar(&aux, elemento); // Empujar en la pila auxiliar
    }

    printf("\n Base....");

    // Mostrar los elementos de la pila auxiliar (que originalmente estaban en la pila)
    while (!estaVacia(&aux)) {
        int elemento = sacar(&aux); // Sacar de la pila auxiliar
        printf(" |%d| ", elemento); // Mostrar el elemento
        empujar(pila, elemento); // Empujar el elemento nuevamente en la pila original
    }

    printf(".....Tope\n");
}

void sacar_v2(Pila* pila) {
    if (estaVacia(pila)) { // Verifica si la pila está vacía
        printf("La pila está vacía\n"); // Imprime un mensaje de error
        exit(EXIT_FAILURE); // Termina el programa con un estado de error
    }
    Nodo* temp = pila->tope; // Almacena el puntero al nodo en el tope de la pila en una variable temporal
    pila->tope = temp->siguiente; // Actualiza el tope de la pila al siguiente nodo
    free(temp); // Libera la memoria del nodo eliminado
}



