#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LibreriaArregloDeArboles.h"


int mostrarArchivoAnimales ( const char * nombreArchivo)
{
    FILE *archivo;
    registroArchivo registro;

    // Abre el archivo en modo lectura binaria
    archivo = fopen(nombreArchivo, "rb");

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo.\n");
    }

    int cantRegistros = 0;

    // Lee y muestra cada registro del archivo
    while (fread(&registro, sizeof(registroArchivo), 1, archivo) == 1) {
        printf("Animal: %s\n", registro.animal);
        printf("Cantidad: %d\n", registro.cant);
        printf("Habitat: %d\n", registro.habitat);
        printf("ID Especie: %d\n", registro.idEspecie);
        printf("Especie: %s\n", registro.especie);
        printf("\n");

        cantRegistros ++;
    }

    // Cierra el archivo
    fclose(archivo);

    return cantRegistros;
}

nodoArbol * inicializarArbol()
{
    return NULL;
}

nodoArbol * crearNodoArbol(registroArchivo dato)
{
    nodoArbol  * aux = (nodoArbol*)malloc(sizeof(nodoArbol));

    strcpy(aux->dato.nombreAnimal,dato.animal);
    aux->dato.cantidad=dato.cant;
    aux->dato.habitat=dato.habitat;
    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

nodoArbol * insertar(nodoArbol * arbol, nodoArbol * nuevo)
{
    if (arbol == NULL)
    {
        arbol = nuevo;
    }
    else
    {
        if (nuevo->dato.cantidad > arbol->dato.cantidad)
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

void mostrarAnimal(nodoArbol *dato)
{
    printf("Nombre: %s\n", dato->dato.nombreAnimal);
    printf("Cantidad: %d\n", dato->dato.cantidad);
    printf("Habitat: %d\n", dato->dato.habitat);
}



void inorder(nodoArbol *arbol) {
    if (arbol != NULL) {
        inorder(arbol->izq);    // atraviesa el subárbol izq
        mostrarAnimal(arbol);   // visita la raíz
        inorder(arbol->der);    // atraviesa el subárbol derecho
    }
}



int ingresarAnimales(const char * nombreArchivo ,celdaEspecie ADA[], int dim)
{
    FILE * archi = fopen(nombreArchivo,"rb");
    if(archi ==NULL)
    {
        printf("Error\n");
        return -1;
    }

    registroArchivo nuevo;
    int valid = 0;

    while(fread(&nuevo,sizeof(nuevo),1,archi) && valid < dim)
    {
        valid = cargarEspecie(ADA,nuevo,valid);
    }

    fclose(archi);

    return valid;
}


int cargarEspecie(celdaEspecie ADA[], registroArchivo nuevo, int validos)
{
    nodoArbol *aux = crearNodoArbol(nuevo);
    int pos = buscarPosEspecie(ADA, nuevo.especie, validos);
    if (pos == -1) {
        validos = agregarEspecie(ADA, nuevo.especie, nuevo.idEspecie, validos);
        ADA[validos - 1].arbolDeAnimales = insertar(ADA[validos - 1].arbolDeAnimales, aux);
    } else {
        ADA[pos].arbolDeAnimales = insertar(ADA[pos].arbolDeAnimales, aux);
    }

    return validos;
}


int buscarPosEspecie (celdaEspecie ADA [],char especie [],int validos)
{
    int rta = -1;
    int i=0;
    while(i< validos && rta == -1)
    {
        if(strcasecmp(ADA[i].especie,especie)==0)
        {
            rta = i;   //si encuentra coincidencia nos devuelve la posicion de la materia en el arreglo
        }              //sino devuelve -1
        i++;
    }

    return rta;
}

//podria modularizar 2 funciones que convierta de registro a Animal y otra a Especie. entonces no paso tantas cosas por parametro
int agregarEspecie (celdaEspecie ADA[],char especie[],int idEspecie, int validos)
{
    strcpy(ADA[validos].especie,especie);
    ADA[validos].idEspecie = idEspecie;
    ADA[validos].arbolDeAnimales = inicializarArbol();
    validos ++;

    return validos;
}
