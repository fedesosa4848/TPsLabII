#ifndef LIBRERIAARBOLESBIN_H_INCLUDED
#define LIBRERIAARBOLESBIN_H_INCLUDED

typedef struct
{
    int dato;
    struct nodoArbol* izq;
    struct nodoArbol* der;

}nodoArbol;


typedef struct
{
    int legajo;
    char nombre[20];
    int edad;
} persona;


typedef struct nodoArbolPersona
{
    persona dato;
    struct nodoArbolPersona * izq;
    struct nodoArbolPersona * der;
} nodoArbolPersona;

typedef struct nodo
{
    persona dato;
    struct nodo * sig;
} nodo;

persona cargarPersona();
void mostrarPersona (persona aux);
nodoArbolPersona * inicializarArbolPersona ();
nodoArbolPersona * crearNodoArbolPersona(persona nueva);
nodoArbolPersona * insertarPersonas (nodoArbolPersona* arbol, persona nueva);
void cargarMuchasPersonas(nodoArbolPersona ** arbol);
void inorderPersonas (nodoArbolPersona * arbol);
nodo * inicializarLista ();
void insertarEnLista(nodo** lista, persona nueva);
void copiarArbolALista(nodoArbolPersona* arbol, nodo** lista) ;
nodoArbolPersona * buscarLegajo(nodoArbolPersona * arbol, int Legajo);
int buscarPersonaPorNombre(nodoArbolPersona* arbol, char nombre []);
int altura_del_arbol(nodoArbol* arbol);

nodoArbol * inicializarArbol();
nodoArbol * crearNodoArbol(int dato);
nodoArbol * buscar(nodoArbol * arbol , int dato);
nodoArbol * insetar (nodoArbol* arbol, int dato);
void preOrder (nodoArbol * arbol);
void inorder (nodoArbol * arbol);
void postOrder (nodoArbol * arbol);
int contarHojas(nodoArbol* arbol, int contador);
int contarNodosGrado1(nodoArbol* arbol, int contador);
int sumaValores(nodoArbol * arbol);
int contarBuscador (nodoArbol * arbol, int valor);
nodoArbolPersona* nodoMasIzquierda(nodoArbolPersona* arbol);
nodoArbolPersona* nodoMasDerecha(nodoArbolPersona* arbol);
int esHoja(nodoArbolPersona * arbol);
int esGrado1(nodoArbolPersona * arbol);
nodoArbolPersona* borrarNodoArbolBis(nodoArbolPersona* arbol, int legajo);

#endif // LIBRERIAARBOLESBIN_H_INCLUDED
