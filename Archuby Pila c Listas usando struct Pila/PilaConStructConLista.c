#include "PilaConStructConLista.h"


            /// utilizamos la libreria de Lista,modificada para almacenar solo un N° entero
            /// QUEDA A CARGO DE LOS ALUMNOS HACERLA



void inicPila (Pila* pila)
{
    pila->lista = inicLista();
}


void apilar (Pila* pila, int dato)
{
    nodo* aux = crearNodo(dato);
    pila->lista = agregarPpio(pila->lista, aux);
}


void leer (Pila* pila)
{
    int dato;
    printf("\nIngrese un numero entero:  ");
    scanf("%d", &dato);

    apilar(pila, dato);
}


int desapilar (Pila* pila)
{
    int rta= -1;
    if( (pila->lista) != NULL )
    {
        rta = retornarPrimerDato(pila->lista);
        pila->lista = borrarPrimerNodo(pila->lista);
    }
    else
    {
        printf("\n La pila está vacía, se retornará -1\n");
    }
    return rta;
}



void mostrar(Pila* A)
{
    Pila aux;
    inicPila(&aux);

    while(!pilavacia(A)){
        apilar(&aux, desapilar(A));
    }

    printf("\n Base...........................Tope\n");
    recorrerYmostrar(aux.lista);
    printf("\n Base...........................Tope\n");

    while(!pilavacia(&aux)){
        apilar(A, desapilar(&aux)); /// si no la pila A queda apuntado al 1ro (no se modifica eso),
                                     /// pero si queda con nodos desvinculados (eso se modifica por trabajar los enlaces de
                                    /// los nodos con punteros, aún si no usara puntero en la Pila)
    }
}


int pilavacia (Pila* pila)
{
    int rta=0;
    if ( (pila->lista) == NULL )
    {
        rta = 1;
    }
    return rta;  //PODRIA DECIR DIRECTAMENTE solo return (pila->lista)==NULL (es como si preguntara: "if (pilavacia)...
}



int tope (Pila* pila)
{
    int rta= -1;
    if ((pila->lista) != NULL)
    {
        rta = retornarPrimerDato(pila->lista); //mostramos el 1ro en vez del ultimo porque en la lista agregamos al ppio
    }                                          // entonces el 1° de la lista fue el ult en entrar y es el tope
    else
    {
        printf("\n La pila está vacía, se retornará -1\n");
    }
    return rta;
}
