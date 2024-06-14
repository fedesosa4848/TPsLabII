#include "libreriaArbolesBin.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "libreriaArbolesBin.h"
#include <string.h>

nodoArbol * inicializarArbol()
{
    return NULL;
}

nodoArbol * crearNodoArbol(int dato)
{
    nodoArbol  * aux = (nodoArbol*)malloc(sizeof(nodoArbol));

    aux->dato = dato;
    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

//Funcion Buscar
nodoArbol * buscar(nodoArbol * arbol, int dato)
{
    nodoArbol * rta = NULL;
    if(arbol !=NULL)
    {
        if(dato == arbol->dato)   //primer caso el dato es el primero
        {
            rta=arbol;
        }
        else
        {
            if(dato>arbol->dato)
            {
                rta=buscar(arbol->der,dato); //mayores a la derecha
            }
            else
            {
                rta=buscar(arbol->izq,dato); //menores a la izquierda
            }
        }
    }
    return rta;   //si no encuentra el dato , retorna NULL
}

//Funcion InsertarOrdenado
nodoArbol * insertar (nodoArbol* arbol, int dato)
{
    if(arbol == NULL)
    {
        arbol = crearNodoArbol(dato);
    }
    else
    {
        if(dato > arbol -> dato)
        {
            arbol->der = insertar(arbol->der,dato);     //puede ser que nos pidan cargar un arbol que no haya elmentos repetidos
        }
        else                                           //en ese caso deberiamos poner un else if con la conficion que si es menor se guarde ne la izquiera
        {
            //entonces los iguales no se guardan
            arbol->izq = insertar(arbol->izq,dato);
        }
    }
    return arbol;
}

//Funciones p/ mostrar Arbol
/**
Algoritmos Clasicos

La diferencia es cuando se recorre la raiz. EN los 3 se recorre primero el subarbol
izquierdo y luego el derecho

    *) Preorden : la raiz se recorre antes que los recorridos de los subarboles izq y derecho
    *) Inorden : la raiz se recorre entre los recorridos de los arboles izquierdo y derecho
    *) Postorden : la raiz se recorre despues de los recorridos por el subarbarbol izq y derecho
*/

void preOrder (nodoArbol * arbol)   //raiz ( izq, derecho)
{
    if(arbol!=NULL)
    {
        printf(" -%d- ",arbol->dato);
        preOrder(arbol->izq);
        preOrder(arbol->der);
    }
}

void inorder (nodoArbol * arbol)  //conveniente para mostrar en orden ( alfabetico o numerico )
{
    if(arbol!=NULL)
    {
        inorder(arbol->izq);    //atraviesa el subarbol izq
        printf(" -%d- ",arbol->dato);   //visita la raiz
        inorder(arbol->der);         //atravieza el subarbol derecho
    }
}

void postOrder (nodoArbol * arbol)
{
    if(arbol!=NULL)
    {
        postOrder(arbol->izq);
        postOrder(arbol->der);
        printf(" -%d- ",arbol->dato);
    }
}


int contarHojas(nodoArbol* arbol, int contador)
{
    if (arbol == NULL)
    {
        return contador;  // Si el árbol está vacío, retornar el contador actual.
    }

    if (arbol->izq == NULL && arbol->der == NULL)
    {
        contador++;  // El nodo actual es una hoja, así que incrementamos el contador.
    }

    // Llamada recursiva para los subárboles izquierdo y derecho.
    contador = contarHojas(arbol->izq, contador);
    contador = contarHojas(arbol->der, contador);

    return contador;  // Retornar el contador actual después de explorar ambos subárboles.
}

int contarNodosGrado1(nodoArbol* arbol, int contador) {
    if (arbol != NULL) {
        if ((arbol->izq != NULL && arbol->der == NULL) || (arbol->izq == NULL && arbol->der != NULL)) {  //tiene un hijo del lado izquiero o tiene un hijo de lado derecho. si la condicion fuera los 2 != NULL es que es de grado 2, es decir tiene 2 hijos
            contador++;  // El nodo actual es de grado 1.
        }

        // Llamadas recursivas para explorar los hijos izquierdo y derecho.
        contador = contarNodosGrado1(arbol->izq, contador);
        contador = contarNodosGrado1(arbol->der, contador);
    }
    return contador;
}

int sumaValores(nodoArbol * arbol)
{
    int rta = 0;
    if(arbol)
    {
        rta = arbol->dato + sumaValores(arbol->izq) + sumaValores(arbol->der);
    }

    return rta;
}

persona cargarPersona()
{
    persona aux;

    printf("Ingrese el legajo de la persona: ");
    fflush(stdin);
    scanf("%d",&aux.legajo);

    printf("Ingrese el nombre : ");
    fflush(stdin);
    scanf("%s",aux.nombre);

    printf("Ingrese la edad de la persona: ");
    fflush(stdin);
    scanf("%d",&aux.edad);

    return aux;
}

void mostrarPersona (persona aux)
{
    printf("\n---------------\n");
    printf("Nombre : %s\n",aux.nombre);
    printf("Edad: %d\n",aux.edad);
    printf("Legajo : %d",aux.legajo);
    printf("\n---------------\n");
}

nodoArbolPersona * inicializarArbolPersona ()
{
    return NULL;
}

nodoArbolPersona * crearNodoArbolPersona(persona nueva)
{
    nodoArbolPersona  * aux = (nodoArbolPersona*)malloc(sizeof(nodoArbolPersona));

    aux->dato = nueva;
    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

nodoArbolPersona * insertarPersonas (nodoArbolPersona* arbol, persona nueva)
{
    if(arbol == NULL)
    {
        arbol = crearNodoArbolPersona(nueva);
    }
    else
    {
        if( nueva.legajo > arbol->dato.legajo )
        {
            arbol->der = insertarPersonas(arbol->der,nueva);     //puede ser que nos pidan cargar un arbol que no haya elmentos repetidos
        }
        else                                                     //en ese caso deberiamos poner un else if con la conficion que si es menor se guarde ne la izquiera
        {
                                                                 //entonces los iguales no se guardan
            arbol->izq = insertarPersonas(arbol->izq,nueva);
        }
    }
    return arbol;
}

void cargarMuchasPersonas(nodoArbolPersona ** arbol)
{
    char mander = 's';
    persona nueva;

    while(mander == 's')
    {
        nueva = cargarPersona();
        *arbol = insertarPersonas(*arbol,nueva);

        printf("Desea cargar mas personas en el arbol ? (S/N): ");
        fflush(stdin);
        scanf(" %c", &mander); // Añade el espacio antes del formato para evitar que el '\n' se quede en el búfer.
        getchar(); //
    }
}

void inorderPersonas (nodoArbolPersona * arbol)  //conveniente para mostrar en orden ( alfabetico o numerico )
{
    if(arbol!=NULL)
    {
        inorderPersonas(arbol->izq);    //atraviesa el subarbol izq
        mostrarPersona(arbol->dato);         //visita la raiz
        inorderPersonas(arbol->der);         //atravieza el subarbol derecho
    }
}

nodo * inicializarLista ()
{
    return NULL;
}


// Función para insertar un nuevo nodo al principio de la lista.
void insertarEnLista(nodo** lista, persona nueva)
{
    nodo* nuevoNodo = (nodo*)malloc(sizeof(nodo)); // Asigna memoria para el nuevo nodo.
    nuevoNodo->dato = nueva;     // Asigna los datos de la persona al nuevo nodo.
    nuevoNodo->sig = *lista; // El nuevo nodo apunta al nodo anterior como siguiente.
    *lista = nuevoNodo;           // Actualiza el puntero de la lista para que apunte al nuevo nodo.
}

// Función recursiva para copiar los datos de un árbol a una lista.
void copiarArbolALista(nodoArbolPersona* arbol, nodo** lista)   //Dato : al estar recorriendo en orden sea donde sea que tenga que insertar los datos va a quedar ordenado sea, una lista, un archivo, un arreglo o una pila
{
    if (arbol != NULL)
    {
        copiarArbolALista(arbol->izq, lista);   // Recorre el subárbol izquierdo.
        insertarEnLista(lista, arbol->dato);     // Agrega la persona al inicio de la lista.
        copiarArbolALista(arbol->der, lista);   // Recorre el subárbol derecho.
    }
}

nodoArbolPersona * buscarLegajo(nodoArbolPersona * arbol, int Legajo)
{
    nodoArbol * rta = NULL;
    if(arbol !=NULL)
    {
        if(Legajo == arbol->dato.legajo)   //primer caso el dato es el primero
        {
            rta=arbol;
        }
        else
        {
            if(Legajo > arbol->dato.legajo)
            {
                rta=buscar(arbol->der,Legajo); //mayores a la derecha
            }
            else
            {
                rta=buscar(arbol->izq,Legajo); //menores a la izquierda
            }
        }
    }
    return rta;   //si no encuentra el dato , retorna NULL
}


int buscarPersonaPorNombre(nodoArbolPersona* arbol, char nombreBuscado[])
{
    if (arbol == NULL)
    {
        return 0; // El árbol está vacío o no se encontró el nombre.
    }

    int comparacion = strcasecmp(nombreBuscado, arbol->dato.nombre);

    if (comparacion == 0)
    {
        return comparacion; // Se encontró el nombre en este nodo.
    }
    else if (comparacion < 0)
    {
        return buscarPersonaPorNombre(arbol->izq, nombreBuscado); // Buscar en el subárbol izquierdo.
    }
    else
    {
        return buscarPersonaPorNombre(arbol->der, nombreBuscado); // Buscar en el subárbol derecho.
    }
}


int altura_del_arbol(nodoArbol* arbol) {
    if (arbol == NULL) {
        return 0;
    } else {
        int altura_izquierda = altura_del_arbol(arbol->izq);
        int altura_derecha = altura_del_arbol(arbol->der);

        int max_altura;
        if (altura_izquierda > altura_derecha) {
            max_altura = altura_izquierda;
        } else {
            max_altura = altura_derecha;
        }

        return max_altura + 1;
    }
}

int contarBuscador (nodoArbol * arbol, int valor)
{
    int rta = 0;
    if(arbol!=NULL)
    {
        if(arbol->dato == valor)
        {
            rta = 1 + contarBuscador(arbol->der,valor);
        }else
        {
            rta = 1 + contarBuscador(arbol->izq,valor);
        }
    }

    return rta;
}

nodoArbolPersona* nodoMasIzquierda(nodoArbolPersona* arbol) //Esta funcion va a permitir buscar el nodo "menor"
{
    if(arbol)
    {
        if(arbol->izq != NULL)
        {
            arbol = nodoMasIzquierda(arbol->izq);
        }
    }
    return arbol;//si el arbol esta vacio retorna NULL
}


nodoArbolPersona* nodoMasDerecha(nodoArbolPersona* arbol) //Esta funcion va a permitir buscar el nodo "mayor"
{
    if(arbol)
    {
        if(arbol->der != NULL)
        {
            arbol = nodoMasDerecha(arbol->der);
        }
    }
    return arbol;
}


int esHoja(nodoArbolPersona * arbol)
{
    int rta=0;

    if(arbol)
    {
        if(arbol->izq==NULL && arbol->der==NULL)
        {
            rta=1;
        }
    }
    return rta;
}

int esGrado1(nodoArbolPersona * arbol)
{
    int rta=0;

    if(arbol)
    {
        if( (arbol->izq==NULL && arbol->der!=NULL) || (arbol->izq!=NULL && arbol->der==NULL) )
        {
            rta=1;
        }
    }
    return rta;
}

nodoArbolPersona* borrarNodoArbolBis(nodoArbolPersona* arbol, int legajo){
    if(arbol!=NULL){ // cond corte y sol triv implicita: no hace nada y retorna arbol, que va a ser NULL)
        if(legajo > arbol->dato.legajo){
            arbol->der = borrarNodoArbolBis(arbol->der, legajo); // si el dato buscado es mayor, busca por la dcha
        }
        else if (legajo < arbol->dato.legajo){
            arbol->izq = borrarNodoArbolBis(arbol->izq, legajo); //si el dato buscado es menor, busca por la izq
        }
        else if (legajo == arbol->dato.legajo){  // si lo encontró (si no es < ni > ni llego al final es pq lo encontró)
            if(esHoja(arbol)){
                free(arbol);// puede ser q la hoja a borrar fuera el nodo q buscaba originariamente, o q fuera el nodo que "subi" y ahora necesito borrarlo para q no quede duplicado
                arbol = NULL; //como estamos en funcion recursiva, el otro llamado espera 1 nodo y si solo hago el free habra error
            }else if(esGrado1(arbol)){
                nodoArbol* aux;
                if (arbol->der){   /// si los hijos son del lado izquierdo
                    aux = arbol;
                    arbol = arbol->der;
                    free(aux);
                }
                else{             /// si los hijos son del lado derecho
                    aux = arbol;
                    arbol = arbol->izq;
                    free(aux);
                }
            }else{             /// tiene 2 hijos
                nodoArbolPersona* masDer = nodoMasDerecha(arbol->izq);
                arbol->dato = masDer->dato;  //al nodo a borrar le asigno como nuevo dato el del nodo mas derecho de la rama izquierda (el mas grande de los menores)
                arbol->izq = borrarNodoArbolBis(arbol->izq, arbol->dato.legajo); //y ahora busco y borro del lado izq el nodo que "subí"
            }
        }
    }
    return arbol;
}





