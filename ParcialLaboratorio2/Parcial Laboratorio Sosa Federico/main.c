#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
 int idSucursal;
 char nombreSucursal[25];
 char nombreDisfraz[25];
 char generoDisfraz[25];
 int stockDisfraz;
}stRegistroDisfraz;

typedef struct{
 int idSucursal;
 char nombreSucursal[25];
}stSucursal;

 typedef struct{
 char nombreDisfraz[25];
 char generoDisfraz[25];
 int stockDisfraz;
}Disfraz;

typedef struct nodoArbolDisfraz{

    Disfraz dato;
    struct nodoArbolDisfraz * izq;
    struct nodoArbolDisfraz * der;

}nodoArbolDisfraz;

typedef struct celdaSucursal{

    stSucursal infoSucursal;
    nodoArbolDisfraz * raiz;

}celdaSucursal;


//Prototipado Funciones
nodoArbolDisfraz * inicializarArbol ();
nodoArbolDisfraz * crearNodoArbol (stRegistroDisfraz);
nodoArbolDisfraz * insertar(nodoArbolDisfraz * arbol, nodoArbolDisfraz * nuevo);
int ingresarDisfarces(const char * nombreArchivo ,celdaSucursal ADA[], int dim);
int cargarDisfraz(celdaSucursal ADA[], stRegistroDisfraz nuevo, int validos);
int buscarPosSucursal (celdaSucursal ADA [],char sucursal [],int validos);
//int agregarSucursal (celdaSucursal ADA[],char sucursal[],int idSucursal, int validos);
int agregarSucursal(celdaSucursal ADA[],stRegistroDisfraz dato,int validos);
void mostrarArchivoDisfraces ( const char * nombreArchivo);
void mostrarDisfraz(nodoArbolDisfraz *dato);
void inorder(nodoArbolDisfraz *arbol);
int contarBuscador (nodoArbolDisfraz * arbol, char genero[]);


const char * nombreArchivo = "archivoRegistrosDisfraces.bin";



int main()
{
    //Solo para corroborar que pude leer el archivo .
     mostrarArchivoDisfraces(nombreArchivo);

    puts("Arreglo de Arboles");

    //Sabiendo que cantidad de registros tengo en el archivo creo un arreglo de dicha cantidad

    celdaSucursal sucursales [100];

    int validos = ingresarDisfarces(nombreArchivo,sucursales,100);

    for(int i = 0; i < validos ; i++)
    {
        puts("\n--------------------\n");

        printf("Nombre de la Sucursal : %s\n",sucursales[i].infoSucursal.nombreSucursal);
        printf("ID sucursal : %d\n",sucursales[i].infoSucursal.idSucursal);

        inorder(sucursales[i].raiz);  //estimo que lo muestra en orden pero al estar cargados algunos en mayus y otros en minusculas los ordena diferente, creo

        puts("\n--------------------\n");
    }

    char genero [20];
    printf("Ingrese el genero a buscar ((los generos existentes en el archivo son: hombre, mujer, ninio, ninia)");
    fflush(stdin);
    scanf("%s",&genero);

    int cantidad_XGenero =0;

    for(int j=0; j < validos ; j ++ ) //recorro el arreglo
    {
        cantidad_XGenero += contarBuscador(sucursales[j].raiz,genero); //accedo al arbol de disfraces de cada sucursal y empiezo a acumular el resultado
    }

    printf("Cantidad de disfraces del genero : %s es de : %d",genero,cantidad_XGenero);



    return 0;
}


nodoArbolDisfraz * inicializarArbol ()
{
    return NULL;
}

nodoArbolDisfraz * crearNodoArbol (stRegistroDisfraz nuevo)
{
    nodoArbolDisfraz * aux = malloc(sizeof(nodoArbolDisfraz));
    strcpy(aux->dato.nombreDisfraz,nuevo.nombreDisfraz);
    strcpy(aux->dato.generoDisfraz,nuevo.generoDisfraz);
    aux->dato.stockDisfraz = nuevo.stockDisfraz;
    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

nodoArbolDisfraz * insertar(nodoArbolDisfraz * arbol, nodoArbolDisfraz * nuevo)
{

    if (arbol == NULL)
    {
        arbol = nuevo;
    }
    else
    {   //
        if (strcasecmp(nuevo->dato.nombreDisfraz,arbol->dato.nombreDisfraz)== -1) //si el dato nuevo es mayor va a la derecha sino a la izq de la raiz
        {
            arbol->der = insertar(arbol->der, nuevo);
        }
        else
        {
            arbol->izq = insertar(arbol->izq, nuevo);
        }
    }
    return arbol;
}

int ingresarDisfarces(const char * nombreArchivo ,celdaSucursal ADA[], int dim)
{
    FILE * archi = fopen(nombreArchivo,"rb");
    if(archi ==NULL)
    {
        printf("Error\n");
        return -1;
    }

    stRegistroDisfraz nuevo;
    int valid = 0;

    while(fread(&nuevo,sizeof(nuevo),1,archi) && valid < dim)
    {
        valid = cargarDisfraz(ADA,nuevo,valid);
    }

    fclose(archi);

    return valid;
}


int cargarDisfraz(celdaSucursal ADA[], stRegistroDisfraz nuevo, int validos)
{
    nodoArbolDisfraz *aux = crearNodoArbol(nuevo);
    int pos = buscarPosSucursal(ADA, nuevo.nombreSucursal, validos);
    if (pos == -1) {
        validos = agregarSucursal(ADA,nuevo,validos);
        ADA[validos - 1].raiz = insertar(ADA[validos - 1].raiz, aux);
    } else {
        ADA[pos].raiz = insertar(ADA[pos].raiz, aux);
    }

    return validos;
}


int buscarPosSucursal (celdaSucursal ADA [],char sucursal [],int validos)
{
    int rta = -1;
    int i=0;
    while(i< validos && rta == -1)
    {
        if(strcasecmp(ADA[i].infoSucursal.nombreSucursal,sucursal)==0)
        {
            rta = i;
        }
        i++;
    }

    return rta;
}

int agregarSucursal(celdaSucursal ADA[],stRegistroDisfraz dato,int validos)
{
    strcpy(ADA[validos].infoSucursal.nombreSucursal,dato.nombreSucursal);
    ADA[validos].infoSucursal.idSucursal = dato.idSucursal;
    ADA[validos].raiz = inicializarArbol();
    validos ++;

    return validos;
}




int contarBuscador (nodoArbolDisfraz * arbol, char genero[])
{
    int rta = 0;
    if(arbol!=NULL)
    {
        if(strcasecmp(arbol->dato.generoDisfraz,genero)==0)
        {
            rta += arbol->dato.stockDisfraz;
        }

        rta += contarBuscador(arbol->izq,genero);
        rta += contarBuscador(arbol->der,genero);
    }

    return rta;
}




void mostrarArchivoDisfraces ( const char * nombreArchivo)
{
    FILE *archivo;
    stRegistroDisfraz registro;

    // Abre el archivo en modo lectura binaria
    archivo = fopen(nombreArchivo, "rb");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
    }

    // Lee y muestra cada registro del archivo
    while (fread(&registro, sizeof(stRegistroDisfraz), 1, archivo) == 1) {

        printf("Nombre Sucursal: %s\n", registro.nombreSucursal);
        printf("IdSucursal: %d\n", registro.idSucursal);
        printf("Nombre Disfraz: %s\n", registro.nombreDisfraz);
        printf("Stock Disfraz: %d\n", registro.stockDisfraz);
        printf("Genero del disfraz : %s\n", registro.generoDisfraz);
        printf("\n");

    }

    // Cierra el archivo
    fclose(archivo);

}


void mostrarDisfraz(nodoArbolDisfraz *dato)
{
    printf("Nombre Disfraz: %s\n", dato->dato.nombreDisfraz);
    printf("Cantidad: %d\n", dato->dato.stockDisfraz);
    printf("Genero: %s\n", dato->dato.generoDisfraz);
}



void inorder(nodoArbolDisfraz *arbol) {
    if (arbol != NULL) {
        inorder(arbol->izq);    // atraviesa el subárbol izq
        mostrarDisfraz(arbol);   // visita la raíz
        puts("\n");
        inorder(arbol->der);    // atraviesa el subárbol derecho
    }
}



