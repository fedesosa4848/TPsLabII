#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//pila estatica dinamica y listas
//[punt dobles a cualqueir cosa
//recursividad
//lista simple simple con punt doble , lista doblemente enlazada

typedef struct
{
    char patente[6];
    int valor;
    char marca[10];
} automovil;

typedef struct
{
    automovil dato;
    struct nodoAuto * siguiente;
} nodoAuto;


nodoAuto * inicList();
automovil cargarAuto();
nodoAuto * crearNodo (automovil nuevo);
nodoAuto * buscarUltimo (nodoAuto * lista);
nodoAuto * agregarFinal (nodoAuto * lista, nodoAuto * nuevo);
void agregarMuchos(nodoAuto ** lista);
void mostrarYrecorrerLista (nodoAuto * lista);
int insertarCelda(automovil A[], int dim, automovil dato, int validos);
int pasar(nodoAuto *lista, automovil A[], int dim);
void mostrarArregloRecursivo(automovil A[ ], int i, int pos);
int esNumeroPar(char * patente);
int sumaRecursiva (nodoAuto * lista);

int main()
{
    int dim = 10;
    automovil arreglo[dim];

    nodoAuto * lista = inicList();
    agregarMuchos(&lista);

    mostrarYrecorrerLista(lista);

    int validos = pasar(lista, arreglo,dim);

    mostrarArregloRecursivo(arreglo,validos,0);

    int suma = sumaRecursiva(lista);

    printf("\nEl valor total de los coches que terminan con patente par es de : %d ",suma);

    return 0;
}

nodoAuto * inicList()
{
    return NULL;
}

automovil cargarAuto()
{
    automovil aux;

    printf("Patente:");
    fflush(stdin);
    gets(aux.patente);

    printf("Ingrese un valor para el automovil:");
    scanf("%d",&aux.valor);

    printf("Marca:");
    fflush(stdin);
    gets(aux.marca);

    return aux;
}

nodoAuto * crearNodo (automovil nuevo)
{
    nodoAuto* aux = (nodoAuto*) malloc (sizeof(nodoAuto));
    aux->dato = nuevo;
    aux->siguiente= NULL;

    return aux;
}

nodoAuto * buscarUltimo (nodoAuto * lista)
{
    nodoAuto* ultimo;

    if(lista == NULL)
    {
        return NULL;         //si la lista esta vacia retorna NULL
    }
    else
    {
        ultimo = lista;
        while(ultimo->siguiente != NULL)
        {
            ultimo = ultimo->siguiente;    //buscamos el ultimo nodo y lo retornamos
        }
        return ultimo;
    }

}

nodoAuto * agregarFinal (nodoAuto * lista, nodoAuto * nuevo)
{
    if(lista == NULL)
    {
        return nuevo;   //si la lista esta vacia, el nuevo es el unico nodo
    }
    else
    {
        nodoAuto * ultimo = buscarUltimo(lista);  //buscamos el ultimo
        ultimo->siguiente=nuevo;        //enlazamos el ultimo nodo al nuevo en vez de que apunte a null y nuevo ya va a estar apuntando a null
        return lista;
    }
}

void agregarMuchos(nodoAuto ** lista)
{
    char mander = 's';
    automovil nuevo;
    nodoAuto * aux;

    while (mander == 's' || mander == 'S')
    {
        nuevo= cargarAuto();
        aux = crearNodo(nuevo);
        *lista = agregarFinal(*lista,aux);

        printf("Presione S para cargar mas datos en la lista: ");
        fflush(stdin);
        scanf("%c", &mander);
    }
}



void mostrarYrecorrerLista (nodoAuto * lista)
{
    nodoAuto * seg;
    if(lista == NULL)
    {
        printf("Lista Vacia");
    }
    else
        seg=lista;
    {
        while(seg!= NULL)
        {
            printf("\n-------------------------\n");
            printf("Patente : %s\n",seg->dato.patente);
            printf("Marca : %s\n",seg->dato.marca);
            printf("Valor:%d",seg->dato.valor);
            printf("\n-------------------------\n");

            seg=seg->siguiente;
        }
    }
}


int insertarCelda(automovil A[], int dim, automovil dato, int validos)
{
    // Si el arreglo está lleno, no se puede insertar más elementos
    if (validos >= dim)
    {
        printf("El arreglo está lleno. No se puede insertar más elementos.\n");
        return validos;
    }

    int i;

    // Encontrar la posición donde se debe insertar el nuevo automóvil
    for (i = validos - 1; i >= 0 && A[i].valor > dato.valor; i--)
    {
        A[i + 1] = A[i]; // Desplazar elementos mayores hacia la derecha
    }

    // Insertar el nuevo automóvil en la posición correcta
    A[i + 1] = dato;

    // Incrementar la cantidad de elementos válidos en el arreglo
    return validos + 1;
}


int pasar(nodoAuto *lista, automovil A[], int dim) {
    int validos = 0; // Inicializamos la cantidad de elementos válidos en el arreglo

    // Recorremos la lista y transferimos los datos al arreglo
    nodoAuto *seg = lista;
    while (seg != NULL && validos < dim) {
        automovil dato = seg->dato;
        validos = insertarCelda(A, dim, dato, validos);
        seg = seg->siguiente;
    }

    return validos;
}

void mostrarArregloRecursivo(automovil A[ ], int i, int pos)
{
    if(pos!=i)
    {
            printf("\n-------------------------\n");
            printf("Patente : %s\n",A[pos].patente);
            printf("Marca : %s\n",A[pos].marca);
            printf("Valor:%d",A[pos].valor);
            printf("\n-------------------------\n");

            mostrarArregloRecursivo(A,i,pos+1);
    }
}

int esNumeroPar(char * patente) {
    // Obtén el último dígito numérico de la patente
    char ultimoDigito = patente[3];

    // Verifica si el último dígito numérico es par
    if ((ultimoDigito - '0') % 2 == 0) {
        return 1; // Verdadero, el número es par
    } else {
        return 0; // Falso, el número no es par
    }
}

int sumaRecursiva (nodoAuto * lista)
{
    int suma = 0;

    if(lista!=NULL)
    {
        int par = esNumeroPar(lista->dato.patente);
        if(par == 1)
        {
            suma = lista->dato.valor;

        }
        suma = suma + sumaRecursiva(lista->siguiente);
    }
    return suma;
}
