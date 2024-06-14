#ifndef LIBRERIATP4_H_INCLUDED
#define LIBRERIATP4_H_INCLUDED


typedef struct nodo
{
    int dato;
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
void invertirLista(nodo** lista);
void mostrarListaRecursiva (nodo * lista);
void mostrarListaRecursivaImplicita (nodo * lista);
int sumaListaRecursiva (nodo* lista);
int sumaListaRecursivaImplicita (nodo* lista);
int contadorRecursiva (nodo * lista);
void mostrarListaRecursivaInversa (nodo * lista);
void mostrarElementosPosicionesParesRecursiva(nodo* nodo, int indice);
//nodo * borrarNodoV1(nodo * lista, char nombre[20]);
nodo* borrarNodoV2(nodo* lista, int valor,int * flag);
nodo* borrarNodoRecursivo(nodo* lista, int valor);
nodo* insertarEnOrdenRecursivo(nodo* lista, int valor);
nodo* invertirListaRecursiva(nodo* lista);


#endif // LIBRERIATP4_H_INCLUDED
