#include <stdio.h>
#include <stdlib.h>

/**

Implementar las siguientes funciones:
void apilar(Pila * p, int valor);
int desapilar(Pila * p);
int tope(Pila * p);
int pilavacia(Pila * p);
void mostrar(Pila * p);
void leer (Pila * p);
void inicPila(Pila * p);

*/


typedef struct{
     int valores[100];
     int posTope; //posición de nuevo tope, lugar en donde se almacenará el nuevo valor
} Pila;

void apilar(Pila *p, int valor);
int desapilar(Pila *p);
int tope(Pila *p);
int pilavacia(Pila *p);
void mostrar(Pila *p);
void leer(Pila *p);
void inicPila(Pila *p);
void combinarPilasOrdenadas(Pila *pila1, Pila *pila2, Pila *pilaResultado) ;

int main() {
    Pila miPila;
    inicPila(&miPila);

    apilar(&miPila, 5);
    apilar(&miPila, 10);
    apilar(&miPila, 3);

    mostrar(&miPila);

    printf("\nTope de la pila: %d\n", tope(&miPila));

    desapilar(&miPila);

    printf("\nTope de la pila despues de desapilar: %d\n", tope(&miPila));

    leer(&miPila);

    mostrar(&miPila);

    ///

    Pila pila1, pila2, pilaResultado;
    inicPila(&pila1);
    inicPila(&pila2);
    inicPila(&pilaResultado);

    apilar(&pila1, 1);
    apilar(&pila1, 3);
    apilar(&pila1, 5);


    apilar(&pila2, 2);
    apilar(&pila2, 4);
    apilar(&pila2, 6);

    // Combina las pilas ordenadas en pilaResultado
    combinarPilasOrdenadas(&pila1, &pila2, &pilaResultado);

    printf("Contenido de la pila combinada:\n");
    mostrar(&pilaResultado);

    return 0;
}

void apilar(Pila *p, int valor)
{
    if (p->posTope < 100) {
        p->valores[p->posTope] = valor;
        p->posTope++;
    } else {
        printf("La pila esta llena, no se puede apilar mas elementos.\n");
    }
}

int desapilar(Pila *p)
{
    if (p->posTope > 0)
    {
        p->posTope--;
        return p->valores[p->posTope];
    } else
    {
        printf("La pila esta vacia, no se puede desapilar mas elementos.\n");
        return -1; // Para indicar error
    }
}

int tope(Pila *p)
{
    if (p->posTope > 0)
    {
        return p->valores[p->posTope - 1];
    } else
    {
        printf("La pila está vacia, no hay elementos en el tope.\n");
        return -1; // Para indicar error
    }
}

int pilavacia(Pila *p)
{
    return p->posTope == 0;
}

void mostrar(Pila *p)
{
    printf("Contenido de la pila:\n");
    for (int i = p->posTope - 1; i >= 0; i--)
    {
        printf("%d\n", p->valores[i]);
    }
}

void leer(Pila *p)
{
    int valor;
    printf("Introduce un valor para apilar: ");
    scanf("%d", &valor);
    apilar(p, valor);
}

void inicPila(Pila *p)
{
    p->posTope = 0;
}

void combinarPilasOrdenadas(Pila *pila1, Pila *pila2, Pila *pilaResultado)
{
    inicPila(pilaResultado);

    while (!pilavacia(pila1) && !pilavacia(pila2)) {
        if (tope(pila1) > tope(pila2)) {
            apilar(pilaResultado, desapilar(pila1));
        } else {
            apilar(pilaResultado, desapilar(pila2));
        }
    }

    while (!pilavacia(pila1)) {
        apilar(pilaResultado, desapilar(pila1));
    }

    while (!pilavacia(pila2)) {
        apilar(pilaResultado, desapilar(pila2));
    }
}
