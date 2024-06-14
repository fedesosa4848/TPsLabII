#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
#include "libreriaTp4.h"

void mostrarArchivo(const char *nombreArchivo)
{
    FILE *archi = fopen(nombreArchivo, "rb");
    if (archi == NULL)
    {
        puts("Error\n");
        return;
    }

    printf("Contenido del archivo:\n");

    int num;

    // Leer y mostrar los n�meros desde el principio del archivo
    fseek(archi, 0, SEEK_SET);

    while (fread(&num, sizeof(int), 1, archi) == 1)
    {
        printf(" |%d| ", num);
    }

    fclose(archi);
}

nodo * crearNodo (int dato)
{
    nodo * aux = (nodo*) malloc(sizeof(nodo));
    aux->dato = dato;
    aux->siguiente = NULL;

    return aux;
}

nodo * cargarlista (const char * nombreArchivo, nodo * lista)
{
    FILE * archi = fopen(nombreArchivo, "rb");
    if(archi == NULL)
    {
        puts("Error\n");
        return;
    }

    char mander = 's';
    int num;
    nodo * nuevo;

    while(fread(&num, sizeof(int), 1, archi) == 1 && mander == 's')
    {
        nuevo = crearNodo(num);
        lista = agregarPpio(lista, nuevo);


        printf("Elemento cargado, Desea cargar mas Numeros a la lista ?(S/N)");
        fflush(stdin);
        scanf("%c",&mander);
    }

    return lista;
}

void llenarArchivoRecursivo(FILE * archivo,int i,int cantidad)
{
    int num = rand() % 120+1;
    if(i == cantidad)
    {
        return;
    }else
    {
        fwrite(&num,sizeof(int),1,archivo);
        llenarArchivoRecursivo(archivo,i+1,cantidad);
    }


}
void llenarArchivo(const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo");
        return;
    }
    int cantidadNumeros = 5; // Cantidad de n�meros a generar y almacenar en el archivo
    int i=0;
    llenarArchivoRecursivo(archivo,i,cantidadNumeros);


    fclose(archivo);
}

nodo * inicLista()
{
    return NULL;
}


void mostrarNum(int num)
{
    printf("Num en la lista : %d \n ",num);
}

void mostrarNodo ( nodo * nodo)
{
    mostrarNum(nodo->dato);
}

void mostrarLista ( nodo * lista)
{
    if(lista == NULL)
    {
        printf("La lista esta vacia");
    }
    else
    {
        nodo * seg = lista;
        while (seg != NULL)
        {
            mostrarNodo(seg);
            seg = seg->siguiente;
        }
    }
}

nodo * agregarPpio (nodo * lista, nodo * nuevoNodo)
{
    if(lista == NULL)
    {
        lista = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista;
        lista = nuevoNodo;
    }
    return lista;
}


// Funci�n para insertar un nodo en la lista ordenadamente
void insertarOrdenado(nodo** lista, int nuevoValor) {
    nodo* nuevoNodo = crearNodo(nuevoValor); // Creo un nuevo nodo y le asigno el nuevo valor

    if (*lista == NULL || nuevoValor < (*lista)->dato) { // Verifico si la lista est� vac�a o si el nuevo valor es el menor en la lista
        // Si es el caso, el nuevo nodo se convierte en la nueva cabeza
        nuevoNodo->siguiente = *lista; // El siguiente del nuevo nodo apunta a la antigua cabeza
        *lista= nuevoNodo; // Actualizamos el puntero de cabeza para que apunte al nuevo nodo

    } else {
            // Si no es el caso, recorremos la lista para encontrar la ubicaci�n correcta
        nodo* actual = *lista;
        while (actual->siguiente != NULL && actual->siguiente->dato < nuevoValor) { // Avanzamos en la lista mientras el siguiente nodo no sea nulo y su valor sea menor que el nuevo valor
            actual = actual->siguiente;
        }

        // Insertamos el nuevo nodo entre 'actual' y 'actual->siguiente'
        nuevoNodo->siguiente = actual->siguiente; // El siguiente del nuevo nodo apunta al siguiente del 'actual'
        actual->siguiente = nuevoNodo; // El siguiente del 'actual' apunta al nuevo nodo
    }
}


// Funci�n para imprimir la lista
void imprimirLista(nodo* lista) {  //iterativa
    nodo* actual = lista;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
}

void mostrarListaRecursiva (nodo * lista) //recursivaExplicita
{
    if(lista == NULL)
    {
        printf("Fin de la lista");
    }else{
        printf(" - %d - ",lista ->dato );
        mostrarListaRecursiva(lista->siguiente);
    }
}

void mostrarListaRecursivaInversa (nodo * lista) //recursivaExplicita
{
    if(lista == NULL)
    {
        printf("Fin de la lista");
    }else{
        mostrarListaRecursivaInversa(lista->siguiente);
        printf(" - %d - ",lista ->dato );
    }
}

void mostrarListaRecursivaImplicita (nodo * lista) //recursivaImplicita
{
    if(lista != NULL)
    {
        printf(" %d ",lista ->dato );
        mostrarListaRecursiva(lista->siguiente);   //si quisiera imprimir la lista al revez debo dar vuelta el printF por debajo de la funcion recursiva
    }
}

nodo * buscarNodo(nodo * lista, int dato) {
   nodo * seg;
   seg = lista;
   while ((seg != NULL) && (seg->dato != dato )) {
//busco mientras me quede lista por recorrer y no haya encontrado el dato
      seg=seg->siguiente; //avanzo hacia el siguiente nodo.
   }
   return seg;
}

/*
nodo * borrarNodoV1(nodo * lista, char nombre[20]) { ///Con string
   nodo * seg;
   nodo * ante; //apunta al nodo anterior que seg.
   if((lista != NULL) && (strcmp(nombre, lista->dato.nombre)==0 )) {

      nodo * aux = lista;
      lista = lista->siguiente; //salteo el primer nodo.
      free(aux);                //elimino el primer nodo.
   }else {
      seg = lista;
      while((seg != NULL) && (strcmp(nombre, seg->dato.nombre)!=0 )) {
         ante = seg;           //adelanto una posici�n la variable ante.
         seg = seg->siguiente; //avanzo al siguiente nodo.
      }
      //en este punto tengo en la variable ante la direcci�n de
      //memoria del nodo anterior al buscado, y en la variable seg,
      //la direcci�n de memoria del nodo que quiero borrar.
      if(seg!=NULL) {
         ante->siguiente = seg->siguiente;
         //salteo el nodo que quiero eliminar.
         free(seg);
         //elimino el nodo.
      }
   }
   return lista;
}
*/
nodo* borrarNodoV2(nodo* lista, int valor, int  * flag) { ///Con un entero
    nodo* seg;
    nodo* ante = NULL;

    if (lista == NULL) {
        return lista; // La lista est� vac�a, no hay nada que borrar.
    }

    if (lista->dato == valor) {
        nodo* aux = lista;          //lista apunta al principio. por eso con aux aseguramos que apunte el primer nodo tmb
        lista = lista->siguiente;   //ahora lista apunta al segundo nodo
        free(aux);                  //aux que se quedo apuntando al primero lo borramos con el free
        *flag = 1;
        return lista;
    }

    seg = lista;
    while (seg != NULL && seg->dato != valor) {
        ante = seg;
        seg = seg->siguiente;
    }

    if (seg != NULL) {
        ante->siguiente = seg->siguiente;
        free(seg);
        *flag = 1;
    }

    return lista;
}

nodo* borrarNodoRecursivo(nodo* lista, int valor) {
    if (lista == NULL) {
        return lista; // La lista est� vac�a, no hay nada que borrar.
    }

    if (lista->dato == valor) {      //esta es la funcion para borrar el primer nodo sin embargo sirve para borrar cualquier nodo en cualquier posicion
        nodo* aux = lista;
        lista = lista->siguiente;
        free(aux);
        return lista; // Devolvemos la nueva cabeza de la lista
    }

    lista->siguiente = borrarNodoRecursivo(lista->siguiente, valor);

    return lista; // Devolvemos la cabeza de la lista actualizada
}



nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo) {
   // agrega un nuevo nodo a la lista manteniendo el orden.

   //si la lista est� vac�a agrego el primer elemento.
   if(lista == NULL) {
      lista = nuevoNodo;
   }else {
      //si el nuevo elemento es menor que el primero de la lista,
      //agrego al principio

      if(nuevoNodo->dato < lista->dato){
         lista = agregarPpio(lista, nuevoNodo);
      } else {
         //busco el lugar en donde insertar el nuevo elemento.
         //necesito mantener la direcci�n de memoria del nodo anterior
         //al nodo que tiene un nombre mayor al del nuevo nodo.
         nodo * ante = lista;
         nodo * seg = lista->siguiente;
         while((seg != NULL)
                  &&(nuevoNodo->dato > seg->dato)) {
            ante = seg;
            seg = seg->siguiente;
         }
         // inserto el nuevo nodo en el lugar indicado.
         nuevoNodo->siguiente = seg;
         ante->siguiente = nuevoNodo;
      }
   }

   return lista;
}

nodo* intercalarListasOrdenadas(nodo* lista1, nodo* lista2) {
    nodo* lista_resultado = inicLista(); // Creamos una lista vac�a para almacenar el resultado intercalado
    nodo** puntero_lista_resultado = &lista_resultado; // Creamos un puntero al puntero de lista_resultado
    nodo* actual_lista1 = lista1; // Puntero para recorrer lista1
    nodo* actual_lista2 = lista2; // Puntero para recorrer lista2

    while (actual_lista1 != NULL || actual_lista2 != NULL) {
        if (actual_lista1 != NULL && (actual_lista2 == NULL || actual_lista1->dato <= actual_lista2->dato)) {
            *puntero_lista_resultado = actual_lista1; // Enlazamos el nodo de lista1 en la lista intercalada
            actual_lista1 = actual_lista1->siguiente; // Avanzamos en lista1
        } else {
            *puntero_lista_resultado = actual_lista2; // Enlazamos el nodo de lista2 en la lista intercalada
            actual_lista2 = actual_lista2->siguiente; // Avanzamos en lista2
        }

        puntero_lista_resultado = &((*puntero_lista_resultado)->siguiente); // Actualizamos el puntero al puntero de lista_resultado para que apunte al siguiente nodo
    }

    return lista_resultado; // Devolvemos la lista intercalada
}

///1.nodo* intercalarListasOrdenadas(nodo* lista1, nodo* lista2) {:
/* Esta es la declaraci�n de la funci�n intercalarListasOrdenadas que toma dos listas
ordenadas como entrada y devuelve la lista intercalada.*/

///2.nodo* lista_resultado = inicLista();:
/*Se crea una lista vac�a lista_resultado para almacenar la lista intercalada.
Esto se hace llamando a la funci�n inicLista, que inicializa una lista vac�a.*/

///3.nodo** puntero_lista_resultado = &lista_resultado;:
/*Se crea un puntero puntero_lista_resultado que apunta al puntero de lista_resultado.
Esto se utilizar� para redireccionar los punteros mientras se construye la lista intercalada.*/

///4.nodo* actual_lista1 = lista1; y nodo* actual_lista2 = lista2;:
/*Se crean punteros actual_lista1 y actual_lista2 para recorrer las listas lista1 y lista2 respectivamente.*/

///5.while (actual_lista1 != NULL || actual_lista2 != NULL) {:
/*Inicia un bucle while que se ejecuta mientras al menos una de las listas no haya llegado al final.*/

///6.if (actual_lista1 != NULL && (actual_lista2 == NULL || actual_lista1->dato <= actual_lista2->dato)) {:
/*Se verifica si el nodo actual de lista1 debe ser enlazado en la lista intercalada.
Esto se hace comparando el valor de los nodos actuales y asegur�ndose de que lista2 no haya llegado al final.*/

///7.*puntero_lista_resultado = actual_lista1;:
/*Se enlaza el nodo actual de lista1 en la lista intercalada a trav�s del puntero puntero_lista_resultado.*/

///8.actual_lista1 = actual_lista1->siguiente;:
/*Avanza al siguiente nodo en lista1.*/

///9.} else {:
/*En caso contrario (cuando el nodo actual de lista2 debe ser enlazado en la lista intercalada).*/

///10.*puntero_lista_resultado = actual_lista2;:
/* Se enlaza el nodo actual de lista2 en la lista intercalada a trav�s del puntero puntero_lista_resultado.*/

///11.actual_lista2 = actual_lista2->siguiente;:
/*Avanza al siguiente nodo en lista2.*/

///12.puntero_lista_resultado = &((*puntero_lista_resultado)->siguiente);:
/*Se actualiza el puntero al puntero de lista_resultado para que apunte al siguiente nodo.
Esto asegura que los nodos se enlacen correctamente en la lista intercalada.*/

///13.return lista_resultado;:
/*Finalmente, se devuelve la lista intercalada.*/

void invertirLista(nodo** lista) {
    nodo* anterior = NULL;
    nodo* actual = *lista;
    nodo* siguiente = NULL;

    while (actual != NULL) {
        siguiente = actual->siguiente; // Guardamos el siguiente nodo
        actual->siguiente = anterior; // Invertimos el puntero siguiente del nodo actual
        anterior = actual; // Movemos los punteros hacia adelante
        actual = siguiente;
    }

    *lista = anterior; // Actualizamos el puntero de la lista para que apunte al �ltimo nodo (nuevo inicio)
}


int sumaListaRecursiva (nodo* lista) //recursivaExplisita
{
    int suma = 0;

    if(lista == NULL)
    {
        suma=0;
    }else{
        suma = lista->dato + sumaListaRecursiva(lista->siguiente); //suma es igual a lo que esta en lista->dato + lo que retorne la funcion ( que es una incognita)
    }

    return suma;
}

int sumaListaRecursivaImplicita (nodo* lista) //recursivaImplisita
{
    int suma=0;

    if(lista != NULL)
    {

        suma = lista->dato + sumaListaRecursivaImplicita(lista->siguiente);
        printf(" suma = - %d - \n",lista->dato);
    }

    return suma;
}

int contadorRecursiva (nodo * lista){

    int contador = 0;
    if(lista != NULL){
        if(lista -> dato > 6){
        contador = 1 + contadorRecursiva(lista->siguiente);  //es importante que haya un else porque puede la lista no continuar avanzando si el primero ya no es mayor
        }else{
            contador = contadorRecursiva(lista->siguiente);  //puedo obviar el 0 y que contador no retorne nada. queda a gusto personal.
        }
    }

    return contador;
}


/**No tiene sentido crear una funcion recursiva para agregar al principio
en cambio si quiero agregar al final o en orden si */

void mostrarElementosPosicionesParesRecursiva(nodo* nodo, int indice) {
    if (nodo == NULL) {
        return; // Caso base: llegamos al final de la lista
    }

    // Verificar si el �ndice es par y mostrar el elemento
    if (indice % 2 == 0) {
        printf(" -%d- ", nodo->dato);
    }

    // Llamar recursivamente con el siguiente nodo y un �ndice incrementado
    mostrarElementosPosicionesParesRecursiva(nodo->siguiente, indice + 1);
}

nodo* insertarEnOrdenRecursivo(nodo* lista, int valor) {
    if (lista == NULL || valor < lista->dato) {
        nodo* nuevoNodo = crearNodo(valor);
        nuevoNodo->siguiente = lista;
        return nuevoNodo; // Devolvemos el nuevo nodo como la nueva cabeza de la lista
    }

    lista->siguiente = insertarEnOrdenRecursivo(lista->siguiente, valor);
    return lista; // Devolvemos la cabeza de la lista actualizada
}

nodo* invertirListaRecursiva(nodo* lista) {
    if (lista == NULL || lista->siguiente == NULL) {
        return lista; // La lista est� vac�a o tiene un solo nodo, no es necesario invertirla
    }

    // Obtener el segundo nodo
    nodo* segundoNodo = lista->siguiente;

    // Invertir el resto de la lista de forma recursiva
    nodo* listaInvertida = invertirListaRecursiva(segundoNodo);

    // Cambiar el v�nculo del segundo nodo para que apunte al primero
    segundoNodo->siguiente = lista;

    // Establecer el v�nculo del primer nodo como NULL para que sea el �ltimo
    lista->siguiente = NULL;

    return listaInvertida; // Devolver la nueva cabeza de la lista invertida
}

