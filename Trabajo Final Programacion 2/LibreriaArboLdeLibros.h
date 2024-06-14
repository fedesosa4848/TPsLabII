#ifndef LIBRERIAARBOLDELIBROS_H_INCLUDED
#define LIBRERIAARBOLDELIBROS_H_INCLUDED

//copias de libros
typedef struct
{
    int cantCopias;
    float precioAlquiler;
} stcopias;


//libros
typedef struct
{
    char titulo[30];
    char autor[30];
    int cantPag;
    char genero[30];
    int anioLanzamiento;
    int  idInterno;
    stcopias Copias;

} stlibros;

//Arbol de libros
typedef struct nodoArbolLibro
{
    stlibros dato;
    struct nodoArbolLibro * izq;
    struct nodoArbolLibro * der;
} nodoArbolLibro;

//lista de arboles --> lista de generos - arbol de libros
typedef struct nodoGenero {
    char genero[30];
    nodoArbolLibro *arbolDeLibros;
    struct nodoGenero *siguiente;
} nodoGenero;

//Lista de generos
typedef struct listaGeneros {
    nodoGenero *primero;
} listaGeneros;

nodoArbolLibro *buscarLibroEnArbol(nodoArbolLibro *arbol, const char * titulo);
stlibros crearLibro(char nombreLibro[]);
int libroExisteEnArchivo(const char *nombreLibro, const char *archivo);
void cargarLibroEnArchivo(const char *archivo);
nodoArbolLibro *inicializarArbol();
listaGeneros *inicializarListaGeneros();
nodoArbolLibro *crearNodoArbolLibro(stlibros libro);
void agregarGenero(listaGeneros *lista, const char genero[]);
nodoArbolLibro* buscarLibroPorTituloEnLista(listaGeneros *listaLibros, char const * libroBuscado);
nodoArbolLibro *insertarPorCopias(nodoArbolLibro *arbol, nodoArbolLibro *nuevo);
void inorder(nodoArbolLibro *arbol);
nodoGenero *buscarGenero(listaGeneros *lista, const char genero[]);
listaGeneros *cargarListaDeGenerosDesdeArchivo(const char *nombreArchivo, listaGeneros *listaGeneros);
void mostrarArchivoDeLibros(const char *archivo);
void recorrerListaDeGeneros(listaGeneros *lista);
void agregarLibroAListaYArchivo(listaGeneros *lista, const char *nombreArchivo);
void mostrarLibro(stlibros libro);
void mostrarLibrosPorGenero(listaGeneros *lista, const char *genero);

#endif // LIBRERIAARBOLDELIBROS_H_INCLUDED
