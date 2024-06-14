#ifndef LIBRERIATP4_H_INCLUDED
#define LIBRERIATP4_H_INCLUDED


typedef struct nodo
{
    int *dato;
    struct nodo * siguiente;
} nodo;


void mostrarArchivo(const char *nombreArchivo);
nodo * crearNodo (int dato);
nodo * cargarlista (const char * nombreArchivo, nodo * lista);
void llenarArchivoRecursivo(FILE * archivo,int i,int cantidad);
void llenarArchivo(const char *nombreArchivo);
nodo * inicLista();
nodo * agregarPpio (nodo * lista, nodo * nuevoNodo);
void mostrarNum(int  num);
void mostrarNodo ( nodo * nodo);
void mostrarLista ( nodo * lista);
nodo * buscarNodo(nodo * lista, int dato);
void insertarOrdenado(nodo** lista, int nuevoValor);
nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo);
nodo* intercalarListasOrdenadas(nodo* lista1, nodo* lista2);
nodo * borrarNodo(nodo * lista, int dato);
void invertirLista(nodo** lista);

#endif // LIBRERIATP4_H_INCLUDED
