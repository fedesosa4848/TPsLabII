#ifndef LISTASDOBLEENLAZADALIB_H_INCLUDED
#define LISTASDOBLEENLAZADALIB_H_INCLUDED

typedef struct {
     char nombre[20];
     int edad;
} persona;


typedef struct {
     persona dato;
     struct nodoDoble * anterior;
     struct nodoDoble * siguiente;
} nodoDoble;

nodoDoble * inicListaDoble();
nodoDoble * crearNodoDoble (persona dato);
persona cargarPersona();
nodoDoble * agregarPpioDoble (nodoDoble * lista, nodoDoble * nuevo);
nodoDoble * buscarUltimoDobleRecursivo (nodoDoble  * lista);
void mostrarNodo ( nodoDoble * nodo);
void mostrarLista ( nodoDoble * lista);
 void mostrarListaInversa ( nodoDoble * lista);
nodoDoble * buscarUltimo(nodoDoble * lista) ;
nodoDoble * agregarFinalDoble(nodoDoble  * lista, nodoDoble * nuevo);
nodoDoble * buscarNodo(nodoDoble * lista, char nombre[20]);
nodoDoble * borrarNodo(nodoDoble * lista, char nombre[20]) ;
nodoDoble * agregarEnOrdenDoble (nodoDoble  * lista, nodoDoble * nuevo);
nodoDoble * cargarlista (nodoDoble * lista);

#endif // LISTASDOBLEENLAZADALIB_H_INCLUDED
