#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "lista.h"  /// utilizamos la libreria de Lista,modificada para almacenar solo un N° entero
                    /// QUEDA A CARGO DE LOS ALUMNOS HACERLA

#define Pila nodo* /// definimos nuevo tipo de dato Pila
                   /// (para enmascarar el puntero a un nodo)


void inicPila (Pila * pila);

int pilavacia (Pila * pila);

int tope (Pila * pila);

int desapilar (Pila * pila);

void apilar (Pila * pila, int dato);

void leer (Pila * pila);

void mostrar (Pila * pila);

#endif // PILA_H_INCLUDED
