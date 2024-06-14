#include <stdio.h>
#include <stdlib.h>



typedef struct
{
    int num;
    struct nodoDoble * anterior;
    struct nodoDoble * siguiente;
} nodoDoble;

nodoDoble * inicListaDoble();
nodoDoble * crearNodoDoble (int num);
nodoDoble * agregarPpioDoble (nodoDoble * lista, nodoDoble * nuevo);
void mostrarNodo(nodoDoble *nodo) ;
void mostrarLista ( nodoDoble * lista);
nodoDoble * buscarUltimo(nodoDoble * lista);
nodoDoble * buscarUltimoDobleRecursivo (nodoDoble  * lista);
nodoDoble * agregarFinalDoble(nodoDoble  * lista, nodoDoble * nuevo);
nodoDoble * buscarNodo(nodoDoble * lista, int num) ;
nodoDoble * borrarNodo(nodoDoble * lista, int dato);
nodoDoble * agregarEnOrdenDoble (nodoDoble  * lista, nodoDoble * nuevo);
nodoDoble * cargarlista (nodoDoble * lista);
int contadora ( nodoDoble * lista);
nodoDoble *eliminarNodoDelMedio(nodoDoble *lista);

int main()
{
    nodoDoble *miLista = inicListaDoble();
    miLista = cargarlista(miLista);

    puts("Lista Original ... ");
    mostrarLista(miLista);

    miLista = eliminarNodoDelMedio(miLista);
    puts("Lista Modificada ... ");
    mostrarLista(miLista);


    return 0;
}


//Inicializa el puntero al primer nodo de la lista con el valor NULL.
nodoDoble * inicListaDoble()
{
    return NULL;
}

nodoDoble * crearNodoDoble (int num)
{

    nodoDoble* aux = (nodoDoble*) malloc(sizeof(nodoDoble));
    aux->num = num;
//asigna valor NULL a los campos que contienen la dirección de memoria  //de los nodos anterior y siguiente
    aux->anterior = NULL;
    aux->siguiente = NULL;


    return aux;
}


nodoDoble * agregarPpioDoble (nodoDoble * lista, nodoDoble * nuevo)
{
    nuevo->siguiente = lista;
    if(lista != NULL)
        lista->anterior=nuevo;
    return nuevo;
}

void mostrarNodo(nodoDoble *nodo)
{
    printf("\n-------------------------\n");
    printf("Numero : %d", nodo->num);
    printf("\n-------------------------\n");
}


void mostrarLista ( nodoDoble * lista)
{
    if(lista == NULL)
    {
        printf("La lista esta vacia");
    }
    else
    {
        nodoDoble * seg = lista;
        while (seg != NULL)
        {
            mostrarNodo(seg);
            seg = seg->siguiente;
        }
    }
}


nodoDoble * buscarUltimo(nodoDoble * lista)
{
    nodoDoble * seg = lista;
    if(seg != NULL)
        while(seg->siguiente != NULL)
        {
            seg = seg->siguiente;
        }
    return seg;
}

nodoDoble * buscarUltimoDobleRecursivo (nodoDoble  * lista)
{
    nodoDoble * rta;
    if (lista==NULL)
        rta=NULL;
    else if(lista->siguiente==NULL)
        rta=lista;
    else
        rta=buscarUltimoDobleRecursivo(lista->siguiente);
    return rta;
}

nodoDoble * agregarFinalDoble(nodoDoble  * lista, nodoDoble * nuevo)
{


    if(lista == NULL)
    {
        lista = nuevo;
    }
    else
    {
        nodoDoble * ultimo = buscarUltimo(lista);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
    }
    return lista;
}

nodoDoble * buscarNodo(nodoDoble * lista, int num)
{
    //busca un nodo por nombre y retorna su posición de memoria
    //si no lo encuentra retorna NULL.

    nodoDoble * seg;  //apunta al nodo de la lista que está siendo procesado
    seg = lista; //con esto evito cambiar el valor de la variable
    //lista, que contiene un puntero al primer nodo de la
    //lista vinculada

    while ((seg != NULL) && ( num != seg->num))
    {
        seg=seg->siguiente; //avanzo hacia el siguiente nodo.
    }
    return seg;
}

nodoDoble * borrarNodo(nodoDoble * lista, int dato)
{
    nodoDoble * seg;
    nodoDoble * ante; //apunta al nodo anterior que seg.
    if(lista != NULL)
    {

        if(lista->num == dato ) //si el buscado el primero o el unico
        {

            nodoDoble * aBorrar = lista;
            lista = lista->siguiente; //salteo el primer nodo.
            if(lista!=NULL)
            {
                lista->anterior = NULL;
            }
            free(aBorrar);                //elimino el primer nodo.
        }
        else
        {
            nodoDoble * seg;
            nodoDoble * ante; //apunta al nodo anterior que seg.
            seg = lista;
            while((seg != NULL) && (seg->num != dato))
            {
                ante = seg;           //adelanto una posición la variable ante.
                seg = seg->siguiente; //avanzo al siguiente nodo.
            }
            //en este punto tengo en la variable ante la dirección de
            //memoria del nodo anterior al buscado, y en la variable seg,
            //la dirección de memoria del nodo que quiero borrar.
            if(seg!=NULL)
            {

                ante->siguiente = seg->siguiente;
                nodoDoble * temp = seg->siguiente;

                if(temp != NULL)
                {
                    temp->anterior=ante;
                }
                free(seg);
                //elimino el nodo.
            }
        }
    }
    return lista;
}

nodoDoble * agregarEnOrdenDoble (nodoDoble  * lista, nodoDoble * nuevo)
{

    if(lista == NULL)
    {
        lista = nuevo;
    }else
    {
        if(nuevo->num < lista->num){
        lista = agregarPpioDoble(lista, nuevo);
        }else{
            // se puede recorrer la lista utilizando un solo puntero??
            nodoDoble * ante = lista;
            nodoDoble * seg = lista->siguiente;
            while((seg != NULL)&&(nuevo->num > seg->num)){
                ante = seg;
                seg = seg->siguiente;
            }
                ante->siguiente = nuevo;
                nuevo->anterior = ante;
                nuevo->siguiente = seg;
                if (seg!=NULL){
                    seg->anterior=nuevo;
                }
        }
    }
    return lista;
}

nodoDoble * cargarlista (nodoDoble * lista)
{
    char mander = 's';
    int numero;
    nodoDoble * nuevo;

    while(mander == 's')
    {
        printf("Ingrese un numero: ");
        fflush(stdin);
        scanf("%d",&numero);
        nuevo = crearNodoDoble(numero);
        lista = agregarEnOrdenDoble(lista, nuevo);


        printf("Elemento cargado, Desea cargar mas elementos en la lista ?(S/N)");
        fflush(stdin);
        scanf("%c",&mander);
    }

    return lista;
}

int contadora ( nodoDoble * lista){
    int cont=0;
    if(lista == NULL)
    {
        printf("La lista esta vacia");
    }
    else
    {
        nodoDoble * seg = lista;
        while (seg != NULL)
        {
            cont++;
            seg = seg->siguiente;
        }
    }
    return cont;
}

nodoDoble *eliminarNodoDelMedio(nodoDoble *lista)
{
    int longitud = contadora(lista); // Obtener la longitud de la lista utilizando la función "contadora"

    if (longitud < 2)// Comprobar si la longitud de la lista es menor que 2
    {
        // No hay nodo del medio para eliminar, así que simplemente regresar la lista original
        return lista;
    }


    int posicionDelMedio = longitud / 2; // Calcular la posición del nodo del medio


    if (longitud % 2 == 0) // Si la longitud es par, restar 1 a la posición del medio para eliminar el nodo inmediatamente superior
    {
        posicionDelMedio--;
    }

    nodoDoble *seg = lista; // Inicializar un puntero "seg" que apunta al inicio de la lista

    // Recorrer la lista hasta llegar al nodo del medio o al inmediatamente superior
    for (int i = 0; i < posicionDelMedio; i++)
    {
        seg = seg->siguiente;
    }

    // Llamar a la función "borrarNodo" para eliminar el nodo del medio o el inmediatamente superior
    // y devolver la lista actualizada
    return borrarNodo(lista, seg->num);
}


/**
    Explicación:

Se calcula la longitud de la lista utilizando la función contadora para determinar cuántos nodos hay en la lista.

Se verifica si la longitud es menor que 2. Si es así, no hay un nodo del medio para eliminar, por lo que la
función simplemente devuelve la lista original sin cambios.

Se calcula la posición del nodo del medio dividiendo la longitud por 2. Si la longitud es par, se resta 1 a la
posición del medio para eliminar el nodo inmediatamente superior.

Se inicializa un puntero seg que apunta al inicio de la lista.

Se utiliza un bucle for para recorrer la lista hasta llegar al nodo del medio o al nodo inmediatamente superior.

Finalmente, se llama a la función borrarNodo para eliminar el nodo del medio o el nodo inmediatamente
superior utilizando el valor del nodo seg, y se devuelve la lista actualizada después de la eliminación.

*/
