#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int dato;
    struct nodo * siguiente;
} nodo;

typedef struct{
    int dato;
    struct nodoDoble* anterior;
    struct nodoDoble* siguiente;
}nodoDoble;

nodo * crearNodo (int dato);
nodo * buscarUltimo (nodo * lista);
nodo * agregarUltimo (nodo * lista,nodo * nuevo);
void mostrarListaInversa (nodo * lista);
nodo * agregarPpio(nodo * lista, nodo * nuevo);
int contadorDeNodos ( nodo * lista);
nodo * borrarNodo(nodo * lista, int pos);
nodo * borrarNodoEspecifico (nodo * lista , int dato);
nodo* borrarNodosMayores(nodo* lista, int dato);
nodoDoble * crearNodoDoble(nodo * lista);
nodoDoble* transferirYOrdenarLista(nodoDoble * listaDoble, nodo* lista) ;



int main()
{
    nodo * lista = NULL;

    int dato ;
    char mander = 's';
    nodo * aux = NULL;

    while ( mander == 's')
    {
        printf("Ingrese un numero : ");
        fflush(stdin);
        scanf("%d",&dato);

        aux = crearNodo(dato);
        lista = agregarPpio(lista,aux);

        printf("Desea cargar mas datos en la lista : (S/N)");
        fflush(stdin);
        scanf("%c",&mander);
    }

    mostrarListaInversa(lista);

    printf("\nEn la lista hay : %d cantidad de nodos, ",contadorDeNodos(lista));

    int pos;

    printf("Pos del nodo a eliminar : ");
    scanf("%d",&pos);

    lista = borrarNodo(lista,pos);

    printf("Ingresar el dato a eliminar de la lista:");
    scanf("%d",&pos);

    lista= borrarNodosMayores(lista,pos);


     nodoDoble * listaDoble = NULL;

    listaDoble = transferirYOrdenarLista(listaDoble,lista);





    return 0;
}

nodo * crearNodo (int dato)
{
    nodo * aux = (nodo*) malloc(sizeof(nodo));
    aux->dato = dato;
    aux->siguiente = NULL;

    return aux;
}

nodo * buscarUltimo (nodo * lista)
{

    if(lista ==NULL)
    {
        return lista;

    }
    else
    {
        nodo * ultimo = lista;
        while(ultimo->siguiente != NULL)
        {
            ultimo = ultimo->siguiente;
        }

        return ultimo;
    }
}

nodo * agregarUltimo (nodo * lista, nodo * nuevo)
{
    if (lista == NULL)
    {
        lista = nuevo; // Actualiza la variable 'lista'
    }
    else
    {
        nodo * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
    }
    return lista;
}

nodo * agregarPpio(nodo * lista, nodo * nuevo)
{

    if(lista == NULL)
    {
        lista= nuevo;
    }
    else
    {
        nuevo->siguiente = lista;
        lista = nuevo;
    }

    return lista;
}

void mostrarListaInversa (nodo * lista)
{

    if(lista != NULL)
    {

        mostrarListaInversa(lista->siguiente);
        printf("  |%d| ",lista->dato);
    }

}


int contadorDeNodos ( nodo * lista)
{

    int cont =0;

    if(lista ==NULL)
    {
        return cont;
    }
    else
    {
        nodo * seg = lista;
        while(seg!=NULL)
        {
            cont ++;
            seg= seg->siguiente;
        }
        return cont;
    }
}

nodo * borrarNodo(nodo * lista, int pos)
{
    int cont = contadorDeNodos(lista);


    if(lista == NULL)
    {
        puts("No hay nodos en la lista\n");
        return lista;
    }

    if(pos < 1 || pos > cont)
    {
        puts("Pos invalida\n");
        return lista;
    }

    if(pos == 1)
    {
        nodo * aBorrar = lista->siguiente;
        free(lista);
        return aBorrar;
    }

    int index = 2;
    nodo * seg = lista;
    nodo * ante = NULL;
    while(index != pos)
    {
        ante=lista;
        seg=seg->siguiente;
        index++;
    }
    ante->siguiente = seg->siguiente;
    free(seg);

    return lista;
}

nodo * borrarNodoEspecifico (nodo * lista , int dato)
{
    if(lista== NULL)
    {
        puts("Lista vacia\n");
    }else{
        if(lista->dato == dato)
        {
            nodo * aborrar = lista;
            lista = lista ->siguiente;
            free(aborrar);
        }else{
            nodo * ante= lista;
            nodo * seg = lista->siguiente;
            while((seg!= NULL) && (seg->dato != dato)){
                ante=seg;
                seg=seg->siguiente;
            }
                if(seg!= NULL)
                {
                    ante->siguiente=seg->siguiente;
                    free(seg);
                }
        }
    }
    return lista;
}

nodo* borrarNodosMayores(nodo* lista, int dato) {
    while (lista != NULL && lista->dato > dato) {
        nodo* aborrar = lista;
        lista = lista->siguiente;
        free(aborrar);
    }

    if (lista == NULL) {
        return NULL; // Todos los nodos eran mayores o la lista estaba vacía
    }

    nodo* ante = lista;
    nodo* seg = lista->siguiente;

    while (seg != NULL) {
        if (seg->dato > dato) {
            nodo* aborrar = seg;
            seg = seg->siguiente;
            ante->siguiente = seg;
            free(aborrar);
        } else {
            ante = seg;
            seg = seg->siguiente;
        }
    }

    return lista;
}

nodoDoble * crearNodoDoble(nodo * lista)
{
    nodoDoble* nuevoNodo = (nodoDoble*)malloc(sizeof(nodoDoble));
    nuevoNodo->dato = lista->dato;
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = NULL;

    return nuevoNodo;
}

nodoDoble* transferirYOrdenarLista(nodoDoble * listaDoble, nodo* lista) {

    // Recorrer la lista original y transferir los valores
    while (lista != NULL) {
        //  Crear un nuevo nodo para la lista doble
        nodoDoble * nuevoNodo = crearNodo(lista);
        // Insertar el nuevo nodo en la lista doble de manera ordenada
        if (listaDoble == NULL) {
            // Si la lista doble está vacía, simplemente asigna el nuevo nodo
            listaDoble = nuevoNodo;
        } else {
            // Buscar la posición adecuada para el nuevo nodo
            nodoDoble* actual = listaDoble;
            nodoDoble* anterior = NULL;

            while (actual != NULL && actual->dato < nuevoNodo->dato) {
                anterior = actual;
                actual = actual->siguiente;
            }

            if (anterior == NULL) {
                // Insertar el nuevo nodo al principio de la lista
                nuevoNodo->siguiente = listaDoble;
                listaDoble->anterior = nuevoNodo;
                listaDoble = nuevoNodo;
            } else {
                // Insertar el nuevo nodo después del nodo anterior
                anterior->siguiente = nuevoNodo;
                nuevoNodo->anterior = anterior;
                nuevoNodo->siguiente = actual;
                if (actual != NULL) {
                    actual->anterior = nuevoNodo;
                }
            }
        }
        // Mover al siguiente nodo en la lista original y liberar su memoria
        nodo* nodoAEliminar = lista;
        lista = lista->siguiente;
        free(nodoAEliminar);
    }

    // Devolver la lista doblemente enlazada ordenada
    return listaDoble;
}

