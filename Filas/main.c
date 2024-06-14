#include <stdio.h>
#include <stdlib.h>

//al incluir las 2 variables dentro de la estructura puedo devolver el retorno de la fila modificada

typedef struct
{
    int dato;
    struct nodo2* ante;
    struct nodo2* sig;
}nodo2;

typedef struct
{
    struct nodo2 * inicio;
    struct nodo2 * fin;
}Fila;



int main()
{
    printf("Hello world!\n");
    return 0;
}

nodo2 * inicLista()
{
    return NULL;
}



void inicFila (Fila * fila)
{
    fila->inicio = inicLista();
    fila->fin = inicLista ();
}

void leer(Fila * fila)
{
    int dato;
    printf("Ingrese un dato : ");
    fflush(stdin);
    scanf("%d",&dato);
    agregarAlaFila(fila,dato);
}

void mostrarLista ( nodo2 * lista)
{
    if(lista == NULL)
    {
        printf("La lista esta vacia");
    }
    else
    {
        nodo2 * seg = lista;
        while (seg != NULL)
        {
            printf("Dato : %d",seg->dato);
            seg = seg->sig;
        }
    }
}

void mostrar(Fila fila)
{
    printf("Inicio de la fila : ");

    mostrarLista (fila.inicio);

    printf("Fin de la lista");
}

nodo2 * crearNodo(int dato)
{
    nodo2 * nuevo = (nodo2*)malloc (sizeof(nodo2));
    nuevo ->dato = dato;
    nuevo ->ante = NULL;
    nuevo ->sig = NULL;

    return nuevo;
}

nodo2 * buscarUltimo(nodo2 * lista) {
   nodo2 * seg = lista;
   if(seg != NULL)
      while(seg->sig != NULL) {
         seg = seg->sig;
      }
    return seg;
 }


nodo2 * agregarFinal(nodo2 * lista,nodo2 * nuevo)
{
    if(lista== NULL)     //esta opcion se podria quitar ya que en el if ya se evalua si la fila es distinto de null
    {
        lista = nuevo;
    }else
    {
        nodo2 * ultimo = buscarUltimo(lista);
        ultimo->sig = nuevo;
        nuevo->ante = ultimo;
    }

    return lista;
}

void agregarAlaFila (Fila * fila , int dato)
{
    nodo2 * nuevo = crearNodo (dato);
    if(fila->inicio = NULL)
    {
        fila->inicio=nuevo;
        fila->fin=nuevo;
    }else
    {
        fila->inicio = agregarFinal (fila->inicio, nuevo);
        fila->fin = nuevo;
    }
}

int verPrimero (nodo2 * lista)   // si fuera una persona seria persona verprimero y retornar la persona
{
    int rta = 0;
    if (lista)   //si la lista tiene datos
    {
        rta = lista ->dato;
    }

    return rta;
}

int verPrimeroFila (Fila fila) //como vamos a mostrar y no vamos a modificar le pasamos la fila por copia
{
    int resp = -9999999;

    if(fila.inicio!=NULL)
    {
        resp = verPrimero(fila.inicio); //ver primero recibe por parametro la lista. y la lista donde esta ? en fila . inicio
    }else
    {
        puts("Fila vacia");
    }

    return resp;
}

int filaVacia (Fila fila)
{
    int resp = 0 ;

    if(fila.inicio == NULL)
    {
        resp = 1 ;
    }
    return resp;
}

nodo2 * borrarPrimero (nodo2 * lista)
{
    nodo2 * aBorrar = lista;
    if(lista!=NULL)
    {
        lista = lista->sig;
        if(lista!=NULL)
        {
            lista->ante = NULL;
        }
        free(aBorrar);
    }

    return lista;
}

int extraerElemento (Fila * fila)
{
    int resp;
    if(fila->inicio != NULL) //si la fila tiene algo ...
    {
        resp = verPrimero(fila->inicio);   //cual es ese algo ? y se guarda en respuesta .

        fila->inicio = borrarPrimero(fila->inicio);

        if(fila->inicio == NULL) //cuando sale de la funcion puede que haya eliminado el unico elemento
        {
            fila->fin=inicLista();   //el fin es null
        }
    }

    return resp;
}
