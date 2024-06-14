#ifndef LIBRERIADOBLE_H_INCLUDED
#define LIBRERIADOBLE_H_INCLUDED

typedef struct Nodo {
    int dato;
    struct Nodo* siguiente;
} nodo;

nodo* crearNodo(int dato);
void cargarLista(nodo** lista);
nodo* inicLista(nodo* lista);
void mostrarNum(int num);
void mostrarNodo(nodo* nodo);
void mostrarLista(nodo* lista);
void agregarPpio(nodo** lista, nodo* nuevoNodo);
nodo* agregarFinal(nodo* lista, nodo* nuevoNodo);
nodo* agregarEnOrden(nodo** lista, nodo* nuevoNodo);
nodo* buscarUltimo(nodo* lista);
nodo* borrarNodo(nodo** lista, int dato);
nodo* buscarNodo(nodo* lista, int dato);
void mostrarListaRecursiva(nodo** lista);



#endif // LIBRERIADOBLE_H_INCLUDED
