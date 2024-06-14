#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ListasDobleEnlazadaLib.h"

//Inicializa el puntero al primer nodo de la lista con el valor NULL.
nodoDoble * inicListaDoble(){
   return NULL;
}

nodoDoble * crearNodoDoble (persona dato) {

nodoDoble* aux = (nodoDoble*) malloc(sizeof(nodoDoble));
aux->dato = dato;
//asigna valor NULL a los campos que contienen la dirección de memoria  //de los nodos anterior y siguiente
aux->anterior = NULL;
aux->siguiente = NULL;


return aux;
}

persona cargarPersona()
{
    persona aux;

    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(aux.nombre);
    printf("Edad: ");
    fflush(stdin);
    scanf("%d",&aux.edad);

    return aux;
}

nodoDoble * agregarPpioDoble (nodoDoble * lista, nodoDoble * nuevo) {
    nuevo->siguiente = lista;
    if(lista != NULL)
       lista->anterior=nuevo;
    return nuevo;
}

void mostrarNodo(nodoDoble *nodo) {
    printf("\n-------------------------\n");
    printf("Nombre : %s\n", nodo->dato.nombre);
    printf("Edad : %d", nodo->dato.edad);
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

nodoDoble * buscarUltimo(nodoDoble * lista) {
   nodoDoble * seg = lista;
   if(seg != NULL)
      while(seg->siguiente != NULL) {
         seg = seg->siguiente;
      }
    return seg;
 }

 void mostrarListaInversa ( nodoDoble * lista)
 {
     nodoDoble * ult = buscarUltimo(lista);
     if(ult != NULL)
     {
         while(ult!= NULL)
         {
             mostrarNodo(ult);
             ult=ult->anterior;
         }
     }
 }

 nodoDoble * buscarUltimoDobleRecursivo (nodoDoble  * lista) {
   nodoDoble * rta;
   if (lista==NULL)
      rta=NULL;
   else
      if(lista->siguiente==NULL)
         rta=lista;
      else
         rta=buscarUltimoDobleRecursivo(lista->siguiente);
   return rta;
 }

 nodoDoble * agregarFinalDoble(nodoDoble  * lista, nodoDoble * nuevo) {


   if(lista == NULL) {
      lista = nuevo;
   } else {
      nodoDoble * ultimo = buscarUltimo(lista);
      ultimo->siguiente = nuevo;
      nuevo->anterior = ultimo;
   }
   return lista;
}

nodoDoble * buscarNodo(nodoDoble * lista, char nombre[20]) {
   //busca un nodo por nombre y retorna su posición de memoria
   //si no lo encuentra retorna NULL.

   nodoDoble * seg;  //apunta al nodo de la lista que está siendo procesado
   seg = lista; //con esto evito cambiar el valor de la variable
                //lista, que contiene un puntero al primer nodo de la
                //lista vinculada

   while ((seg != NULL) && ( strcasecmp(nombre, seg->dato.nombre)!=0 )) {
      seg=seg->siguiente; //avanzo hacia el siguiente nodo.
   }
   return seg;
}

nodoDoble * borrarNodo(nodoDoble * lista, char nombre[20])
{
    nodoDoble * seg;
    nodoDoble * ante; //apunta al nodo anterior que seg.
    if(lista != NULL){

    if(strcasecmp(nombre, lista->dato.nombre)==0 ) //si el buscado el primero o el unico
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
            while((seg != NULL) && (strcasecmp(nombre, seg->dato.nombre)!=0 ))
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

nodoDoble * agregarEnOrdenDoble (nodoDoble  * lista, nodoDoble * nuevo) {

   if(lista == NULL) {
      lista = nuevo;
   }else {

      if(strcasecmp(nuevo->dato.nombre,lista->dato.nombre)<0){
         lista = agregarPpioDoble(lista, nuevo);
      } else {
         // se puede recorrer la lista utilizando un solo puntero??
         nodoDoble * ante = lista;
         nodoDoble * seg = lista->siguiente;
         while((seg != NULL)
                  &&(strcasecmp(nuevo->dato.nombre,seg->dato.nombre)>0)) {
            ante = seg;
            seg = seg->siguiente;
         }
         ante->siguiente = nuevo;
         nuevo->anterior = ante;
         nuevo->siguiente = seg;
         if (seg!=NULL)
             seg->anterior=nuevo;
      }
   }
   return lista;
}

nodoDoble * cargarlista (nodoDoble * lista)
{
    char mander = 's';
    persona aux;
    nodoDoble * nuevo;

    while(mander == 's')
    {
        aux=cargarPersona();
        nuevo = crearNodoDoble(aux);
        lista = agregarPpioDoble(lista, nuevo);


        printf("Elemento cargado, Desea cargar mas personas a la lista ?(S/N)");
        fflush(stdin);
        scanf("%c",&mander);
    }

    return lista;
}



