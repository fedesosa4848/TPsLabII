#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *valores;
    int posTope;
} Pila;

void apilar(Pila *p, int valor);
int desapilar(Pila *p);
int tope(Pila *p);
int pilavacia(Pila *p);
void mostrar(Pila *p);
void leer(Pila *p);
void inicPila(Pila *p);
void combinarPilasOrdenadas(Pila *pila1, Pila *pila2, Pila *pilaResultado);

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

    printf("\nContenido de la pila combinada:");
    mostrar(&pilaResultado);

    // Liberar memoria asignada dinámicamente
    free(miPila.valores);
    free(pila1.valores);
    free(pila2.valores);
    free(pilaResultado.valores);

    return 0;
}

void apilar(Pila *p, int valor)  ///recibe por parametros la "Pila" y el dato a apilar
{
    if (p->posTope < 100) { ///va a pilar mientras los "validos" sean menores a 100
        p->valores[p->posTope] = valor; ///como es un arreglo accedo a valores[postope] que son los validos
        p->posTope++; /// y modifico los validos
    } else {
        printf("La pila esta llena, no se puede apilar mas elementos.\n");
    }
}

int desapilar(Pila *p)
{
    if (p->posTope > 0) ///aca ocurre lo mismo que apilar, tengo que verificar que la pila no este vacia y en caso
    {                       ///que no este llena quitamos el ultimo valido y por ende borramos el ultimo dato apilado
        p->posTope--;
        return p->valores[p->posTope];
    }
    else
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
    }
    else
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
    /** Opcion 1 */
    ///creamos un arreglo dinamico
    int * arrDinam = (int * ) malloc (sizeof(int)*100);  //basicamente la ventaja de crear un arreglo dinamico es que la dimension
    ///y decimos que valores va a ser el arreglo dinamico
    p->valores= arrDinam;                               //la podemos ir manejando en tiempo de ejecucion. en este caso el irrelevante pero en caso
                                                        //de contar elementos e ir ubicandolo en un arreglo nuevo ahi si sirve pq nos "olvidamos"
                                                        //de ir controlando la dimension de ese nuevo arreglo
    /** Opcion 2 /

    p->valores= (int * ) malloc (sizeof(int)*100); */
    ///son los validos
    p->posTope = 0;
}

void combinarPilasOrdenadas(Pila *pila1, Pila *pila2, Pila *pilaResultado)
{
    inicPila(pilaResultado);

    while (!pilavacia(pila1) && !pilavacia(pila2))
    {
        if (tope(pila1) > tope(pila2))
        {
            apilar(pilaResultado, desapilar(pila1));
        }
        else
        {
            apilar(pilaResultado, desapilar(pila2));
        }
    }

    while (!pilavacia(pila1))
    {
        apilar(pilaResultado, desapilar(pila1));
    }

    while (!pilavacia(pila2))
    {
        apilar(pilaResultado, desapilar(pila2));
    }
}
