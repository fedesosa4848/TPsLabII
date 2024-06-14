#ifndef TDAPILALISTASIMP_H_INCLUDED
#define TDAPILALISTASIMP_H_INCLUDED

// Definición de la estructura del nodo de la lista enlazada simple
typedef struct Nodo {
    int dato;           // El dato almacenado en el nodo
    struct Nodo* siguiente; // Puntero al siguiente nodo
}Nodo;

// Definición de la estructura de la pila
typedef struct Pila {
    struct Nodo* tope; // Puntero al nodo en la parte superior de la pila
}Pila;

struct Pila* crearPila();
int estaVacia(struct Pila* pila);
void empujar(struct Pila* pila, int dato);
int sacar(struct Pila* pila);
int consultarTope(struct Pila* pila);
void mostrarPila(struct Pila* pila);
void sacar_v2(struct Pila* pila);

#endif // TDAPILALISTASIMP_H_INCLUDED
