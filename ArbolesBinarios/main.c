#include <stdio.h>
#include <stdlib.h>

/**
Un arbol binario es un conjunto finito de elementos de nombre NODOS de forma que :

    .) El arbol binario esta vacio si no tiene ningun elemento.

    .) Se denomina arbol binario al tipo de arbol que contiene un nodo raiz y 2 nodos que
       parten de él, llamados nodo izquierdo y nodo derecho.

    .)Un arbol binario es un arbol en el que ningun nodo puede tener mas de 2 subarboles

    .)Cada nodo puede tener 0,1 o 2 hijos ( subarboles ) porque es un arbol BINARIO

    .)El arbol binario completo, es un arbol binario lleno completo y balanceado

    .)(arbol de busqueda) Los nodos estan insertados en orden.

    Nodo raiz : tiene hijos pero no padres
    Nodo rama : tiene padres e hijos
    Nodo hoja : tiene madre pero no hijos
*/

/**
El nivel aumenta a medidda que se aleja de la raiz o tmb podemos contar los "pasos" que hay
desde determinado nodo a la raiz

Altura: parte de la raiz y segun su descendencia asi es su altura

Grado: es la descendencia de cada Nodo

*/

typedef struct
{
    int dato;
    struct nodoArbol* izq;
    struct nodoArbol* der;

}nodoArbol;

nodoArbol * inicializarArbol();
nodoArbol * crearNodoArbol(int dato);
nodoArbol * buscar(nodoArbol * arbol , int dato);
nodoArbol * insetar (nodoArbol* arbol, int dato);
void preOrder (nodoArbol * arbol);
void inorder (nodoArbol * arbol);
void postOrder (nodoArbol * arbol);


int main()
{
    int a[10] = {10,2,45,9,1,15,46,33,25,20};
    nodoArbol * arbol = inicializarArbol();
    for(int i=0 ; i < 10 ; i++)
    {
        arbol = insetar(arbol,a[i]);
    }



    printf("Preorder\n");
    preOrder(arbol);

    printf("InOrder\n");
    inorder(arbol);

    return 0;
}


nodoArbol * inicializarArbol()
{
    return NULL;
}

nodoArbol * crearNodoArbol(int dato)
{
    nodoArbol  * aux = (nodoArbol*)malloc(sizeof(nodoArbol));

    aux->dato = dato;
    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

//Funcion Buscar
nodoArbol * buscar(nodoArbol * arbol , int dato)
{
    nodoArbol * rta = NULL;
    if(arbol !=NULL)
    {
        if(dato == arbol->dato)   //primer caso el dato es el primero
        {
            rta=arbol;
        }else
        {
            if(dato>arbol->dato)
            {
                rta=buscar(arbol->der,dato); //mayores a la derecha
            }else
            {
                rta=buscar(arbol->izq,dato); //menores a la izquierda
            }
        }
    }
    return rta;   //si no encuentra el dato , retorna NULL
}

//Funcion InsertarOrdenado
nodoArbol * insetar (nodoArbol* arbol, int dato)
{
    if(arbol == NULL)
    {
        arbol = crearNodoArbol(dato);
    }else
    {
        if(dato > arbol -> dato)
        {
            arbol->der = insetar(arbol->der,dato);     //puede ser que nos pidan cargar un arbol que no haya elmentos repetidos
        }else                                          //en ese caso deberiamos poner un else if con la conficion que si es menor se guarde ne la izquiera
        {                                              //entonces los iguales no se guardan
            arbol->izq = insetar(arbol->izq,dato);
        }
    }
    return arbol;
}

//Funciones p/ mostrar Arbol
/**
Algoritmos Clasicos

La diferencia es cuando se recorre la raiz. EN los 3 se recorre primero el subarbol
izquierdo y luego el derecho

    *) Preorden : la raiz se recorre antes que los recorridos de los subarboles izq y derecho
    *) Inorden : la raiz se recorre entre los recorridos de los arboles izquierdo y derecho
    *) Postorden : la raiz se recorre despues de los recorridos por el subarbarbol izq y derecho
*/

void preOrder (nodoArbol * arbol)   //raiz ( izq, derecho)
{
    if(arbol!=NULL)
    {
        printf(" -%d- ",arbol->dato);
        preOrder(arbol->izq);
        preOrder(arbol->der);
    }
}

void inorder (nodoArbol * arbol)  //conveniente para mostrar en orden ( alfabetico o numerico )
{
    if(arbol!=NULL)
    {
        inorder(arbol->izq);    //atraviesa el subarbol izq
        printf(" -%d- ",arbol->dato);   //visita la raiz
        inorder(arbol->der);         //atravieza el subarbol derecho
    }
}

void postOrder (nodoArbol * arbol)
{
    if(arbol!=NULL)
    {
        postOrder(arbol->izq);
        postOrder(arbol->der);
        printf(" -%d- ",arbol->dato);
    }
}


