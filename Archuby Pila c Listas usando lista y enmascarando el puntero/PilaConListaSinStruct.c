#include "PilaConListaSinStruct.h"


            /// utilizamos la libreria de Lista,modificada para almacenar solo un N° entero
            /// QUEDA A CARGO DE LOS ALUMNOS HACERLA

///     void inicPila (nodo ** lista)
///     {
///         (*lista)= inicLista();
///     }

///     SE TRANSFORMA EN...


void inicPila (Pila* pila) // Pila*pila en realidad es nodo** pila
{                           // se trabaja con punt doble porque todas las funciones reciben &dada
    (*pila) = inicLista();   // *pila porq pila es punt doble (a donde apunta el punt doble)
}



int desapilar (Pila* pila)  // Pila*pila en realidad es nodo** pila
{
    int rta=-1;  // ninguna solucion es perfecta...
    if( (*pila) != NULL )
    {
        rta = retornarPrimerDato(*pila);
        *pila = borrarPrimerNodo(*pila);
    }
    else
    {
        printf("\n La pila está vacía, se retornará -1\n");
    }
    return rta;
}


void apilar (Pila* pila, int dato)
{
    nodo* aux = crearNodo(dato);
    *pila = agregarPpio(*pila, aux);
}


void leer (Pila* pila)
{
    int dato;
    nodo* nuevoNodo;
    printf("\nIngrese un numero:  ");
    scanf("%d", &dato);
    apilar(pila, dato);
}


void mostrar(Pila* pila)
{
    Pila aux;  // Pila aux en realidad es nodo* aux
    inicPila(&aux);

    while(!pilavacia(pila)){
        apilar(&aux, desapilar(pila));
    }

    printf("\n Base...........................Tope\n");
    recorrerYmostrar(aux); // esta funcione pide un puntero a lista, y aux es un punt a lista
    printf("\n Base...........................Tope\n");

    while(!pilavacia(&aux)){
        apilar(pila, desapilar(&aux));
    }
}


int pilavacia (Pila* pila)
{
    int rta=0;
    if ( (*pila) == NULL )
    {
        rta = 1;
    }
    return rta;  //PODRIA DECIR DIRECTAMENTE solo return (*pila)==NULL (es como si preguntara: "if (pilavacia)...
}


int tope (Pila* pila)
{
    int rta=-1;
    if ((*pila) != NULL)
    {
        rta = retornarPrimerDato(*pila); //mostramos el 1ro en vez del ultimo porque en la lista agregamos
    }
    else
    {
        printf("\n La pila está vacía, se retornará -1\n");
    }                        // al ppio, entonces el tope es el 1ro en vez del ultimo
    return rta;
}

