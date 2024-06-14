#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    char nombre[200];
    char apellido[200];
    int dni;
    int edad;
    char genero; //m ó f
} stPersona;

typedef struct
{
    stPersona persona;
    struct nodo * sig;
} nodo;


typedef struct
{
    stPersona arreglo [5];
    int posTope;
} Pila;

//Prototipado Funciones


nodo * inicializarLista ();
nodo * crearNodo (stPersona nueva);
void archivoToLista (const char * nombreArchivo,nodo ** lista);
nodo* insertarEnOrdenRecursivo(nodo* lista, stPersona nueva);
void mostrarListaInversa (nodo * lista);
nodo * busquedaMenor (nodo * lista);
nodo * borrarNodo(nodo ** lista, int dato);
void inicPila(Pila *p);
void apilar(Pila *p, stPersona nueva);
void mostrar(Pila *p);
void mostrarListaInversa (nodo * lista);

//Funciones Auxiliares
void mostrarArchivo(const char *nombreArchivo);
void mostrarPersona (stPersona aux);



const char * nombreArchivo = "archivoPersonas.bin";

int main()
{

    mostrarArchivo(nombreArchivo);

    puts("\n");

    nodo * lista  = inicializarLista();
    //ej1()
    archivoToLista(nombreArchivo,&lista);
    //ej2()
    mostrarListaInversa(lista);
    //ej3(a)
    /*nodo * menor = NULL;
    menor = busquedaMenor(nodo * lista);

    if(menor != NULL)
    {
        mostrarPersona(menor->persona);
    }
*/
    //ej3(b)
    int idAborrar;
    printf("Ingrese el ID a borrar : ");
    scanf("%d",&idAborrar);

    nodo * aborrar = borrarNodo(&lista,idAborrar);
    if(aborrar != NULL)
    {
        mostrarPersona(aborrar->persona);
    }

    //ej3(c)
    Pila p;
    inicPila(&p);


    while(lista !=NULL )
    {
        nodo * menor = busquedaMenor(lista);
        apilar(&p, menor->persona);

    }

    mostrar (&p);

    return 0;
}

void mostrarArchivo(const char *nombreArchivo)
{
    FILE *archi = fopen(nombreArchivo, "rb");
    if (archi == NULL)
    {
        puts("Error\n");
        return;
    }

    printf("Contenido del archivo:\n");

    stPersona aux;

    while (fread(&aux, sizeof(stPersona), 1, archi) == 1)
    {
        printf("\n---------------------\n");
        printf("ID: %d\n",aux.id);
        printf("Nombre : %s\n",aux.nombre);
        printf("Apellido: %s\n",aux.apellido);
        printf("DNI: %d\n",aux.dni);
        printf("Edad: %d\n",aux.edad);
        printf("Genero : %c",aux.genero);
    }

    fclose(archi);
}

void mostrarPersona (stPersona aux)
{

    printf("\n---------------------\n");
    printf("ID: %d\n",aux.id);
    printf("Nombre : %s\n",aux.nombre);
    printf("Apellido: %s\n",aux.apellido);
    printf("DNI: %d\n",aux.dni);
    printf("Edad: %d\n",aux.edad);
    printf("Genero : %c",aux.genero);
}

nodo * inicializarLista ()
{
    return NULL;
}

nodo * crearNodo (stPersona nueva)
{
    nodo * aux = (nodo *)malloc (sizeof(nodo));
    aux->persona = nueva;
    aux->sig = NULL;

    return aux;
}

//ej1()
void archivoToLista (const char * nombreArchivo, nodo ** lista)
{
    FILE * archi = fopen(nombreArchivo, "r+b");
    if(archi ==NULL)
    {
        printf("Error al abrir el archivo\n");
    }
    else
    {
        stPersona nueva;
        while(fread(&nueva,sizeof(stPersona),1,archi)==1)
        {
            *lista = insertarEnOrdenRecursivo(*lista,nueva);
        }
    }

    fclose(archi);
}

//ej1()
nodo* insertarEnOrdenRecursivo(nodo* lista, stPersona nueva) {
    if (lista == NULL || nueva.dni < lista->persona.dni) {
        nodo* nuevoNodo = crearNodo(nueva);
        nuevoNodo->sig = lista;
        return nuevoNodo;
    }

    lista->sig = insertarEnOrdenRecursivo(lista->sig, nueva);
    return lista;
}

//ej2()

void mostrarListaInversa (nodo * lista)
{
    if(lista == NULL)
    {
        printf("Fin de la lista");
    }
    else
    {
        mostrarListaInversa(lista->sig);
        printf("\nID...................................: %d", lista->persona.id);
        printf("\nNombre y Apellido..........: %s %s",lista->persona.nombre,lista->persona.apellido);
        printf("\nDNI.................................: %d",lista->persona.dni);
        printf("\nEdad...............................: %d",lista->persona.edad);
        printf("\nGenero............................: %c \n",lista->persona.genero);
    }
}


//ej3(a)

nodo * busquedaMenor (nodo * lista)
{
    if(lista == NULL)
    {
        printf("La lista esta vacia\n");
        return NULL;
    }
    else
    {
         // Inicializar el nodo menor con el primer nodo de la lista
    nodo* nodoMenor = lista;

    // Iterar sobre la lista para encontrar el nodo con el menor elemento
    nodo* actual = lista->sig;
    while (actual != NULL) {
        if (actual->persona.edad < nodoMenor->persona.edad) {
            nodoMenor = actual;
        }
        actual = actual->sig;
    }
        return nodoMenor;
    }
}

//ej3(b)
nodo * borrarNodo(nodo ** lista, int dato)
{
    if((*lista) == NULL)
    {
        printf("Lista vacia\n");
        return NULL;
    }else
    {
        if((*lista)->persona.id == dato)
        {
            nodo * aborrar = (*lista);
            (*lista) = (*lista)->sig;
            nodo * aux = aborrar;
            free(aborrar);
            return aux;
        }else
        {
            nodo * ante = NULL;
            nodo * seg = (*lista);
            while(seg != NULL && seg->persona.id != dato)
            {
                ante = seg;
                seg = seg->sig;
            }

            if(seg != NULL){
            ante->sig = seg ->sig;
            nodo * aux = seg;
            free(seg);
            return aux;
            }else
            {
                puts("Nodo no encontrado\n");
                return NULL ;
            }
        }
    }

}


void apilar(Pila *p, stPersona nueva)
{
    if (p->posTope < 5)
    {
        p->arreglo[p->posTope] = nueva;
        p->posTope++;
    }
    else
    {
        printf("La pila esta llena, no se puede apilar mas personas.\n");
    }
}


void mostrar(Pila *p)
{
    printf("Pila de personas:\n");
    for (int i = p->posTope - 1; i >= 0; i--)
    {
        printf("\nID...................................: %d", p->arreglo[i].id);
        printf("\nNombre y Apellido..........: %s %s",p->arreglo[i].nombre,p->arreglo[i].apellido);
        printf("\nDNI.................................: %d",p->arreglo[i].dni);
        printf("\nEdad...............................: %d",p->arreglo[i].edad);
        printf("\nGenero............................: %c \n",p->arreglo[i].genero);
    }
}



void inicPila(Pila *p)
{
    p->posTope = 0;
}













