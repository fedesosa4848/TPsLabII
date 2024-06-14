#include <stdio.h>
#include <stdlib.h>
#include "libreriaArbolesBin.h"
#include <string.h>



int main()
{

    /**
                8
               /  \
              3    10
       		 / \     \
            1   6	 14
               / \	   \
              4   7     13


    Contenido de los nodos en diferentes recorridos:

    Recorrido Preorden: 8, 3, 1, 4, 6, 7, 10, 14, 13
    Recorrido Inorden: 1, 3, 4, 6, 7, 8, 10, 13, 14
    Recorrido Posorden: 4, 1, 7, 6, 3, 13, 14, 10, 8
    Niveles y altura del árbol:

    Nivel 0: 8
    Nivel 1: 3, 10
    Nivel 2: 1, 6, 14
    Nivel 3: 4, 7, 13
    La altura del árbol es 3, ya que la ruta más larga desde la raíz (8) hasta una hoja (4, 7 o 13) atraviesa 3 niveles.
    */

    int a[9] = {8,3,10,1,6,14,4,7,13};
    nodoArbol * arbol = inicializarArbol();
    for(int i=0 ; i < 9 ; i++)
    {
        arbol = insetar(arbol,a[i]);
    }

    //ej2(d)
    printf("Preorder\n");
    preOrder(arbol);

    printf("\nPostOrder\n");
    postOrder(arbol);

    printf("\nInOrder\n");
    inorder(arbol);



    //ej2(a)

    int sumatoria = sumaValores(arbol);

    printf("\nLa suma de todos los elementos del arbol es de : %d",sumatoria);

    int cantidad = contarHojas(arbol,0);

    printf("\nCantidad de hojas: %d ",cantidad);

    //ej2(b)

    int contador = contarNodosGrado1(arbol,0);

    printf("\nCantidad de nodos grado 1 : %d ",contador);

    //ej2(c)

    int dato = buscar(arbol, 44);   //yo ya se que tengo en el arbol por eso paso un dato que no esta o que esta eso depende de mi

    if(dato != NULL)
    {
        printf("\nSe encontraba el dato");
    }else
    {
        printf("\nNo se encontro el dato");
    }
    int altura = altura_del_arbol(arbol);
    printf("\nLa altura del arbol es: %d\n",altura);


    ///B

    nodoArbolPersona * arbolBinPersonas = inicializarArbolPersona();

    //2

    cargarMuchasPersonas(&arbolBinPersonas);

    nodo * listaPersonas= inicializarLista();

    //3
    copiarArbolALista(arbolBinPersonas,&listaPersonas);

    nodo* actual = listaPersonas;
    while (actual != NULL)
    {
        mostrarPersona(actual->dato);
        actual = actual->sig;
    }

    //4
    int legajoABuscar = 123; // El legajo que deseas buscar

    nodoArbolPersona* rta = buscarLegajo(arbolBinPersonas, legajoABuscar);

    if (rta != NULL) {
        mostrarPersona(rta->dato);
    } else {
        printf("Legajo %d no encontrado.\n", legajoABuscar);
    }

    //5
    char nombre [20];
    puts("Ingrese el nombre a buscar :");
    fflush(stdin);
    gets(nombre);

    int resultado = buscarPersonaPorNombre(arbolBinPersonas, nombre);
    if (resultado == 0)
    {
        printf("El nombre se encontró en el árbol.\n");
    }else
    {
        printf("El nombre buscado no se encontraba en el árbol.\n");
    }

    arbolBinPersonas = borrarNodoArbolBis(arbolBinPersonas,456);
    puts("\n");
    inorderPersonas(arbolBinPersonas);

    return 0;
}


