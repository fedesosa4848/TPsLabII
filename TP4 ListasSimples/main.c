#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
#include "libreriaTp4.h"

const char * nombreArchivo = "archivo.bin";

int main()
{

    srand(time(NULL));

    /*
    puts("cargando archivo :");

    llenarArchivo(nombreArchivo);
    mostrarArchivo(nombreArchivo);

    FILE* archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL)
    {
        perror("Error al abrir el archivo");
        return 1;
    }

    nodo * lista;
    lista = inicLista();
    int valorLeido;

    // Lee los datos del archivo y los inserta en la lista ordenadamente
    while (fread(&valorLeido, sizeof(int), 1, archivo) == 1)
    {
        insertarOrdenado(&lista, valorLeido);
    }

    fclose(archivo);

    // Imprime la lista ordenada
    printf("Lista ordenada:\n");
    imprimirLista(lista);

    int dato;

    printf("\nIngrese un numero a buscar en la lista :");
    scanf("%d",&dato);

    nodo * encontrado = buscarNodo(lista,dato);

    if( encontrado == NULL)
    {
        char mander = 's';
        puts("\nNo se encontro el dato.Desea agregarlo a la lista ? (S/N)");
        fflush(stdin);
        scanf("%c",&mander);
        if(mander == 's')
        {
            lista = agregarEnOrden(lista,crearNodo(dato));
            imprimirLista(lista);
        }
    }
    else
    {
        puts("\nSe encontro el dato");
    }

    printf("\nIntercalar listas");

    */

    nodo* lista1 = inicLista();
    nodo* lista2 = inicLista();

    // Llena las listas con valores ordenados
    lista1 = agregarEnOrden(lista1, crearNodo(1));
    lista1 = agregarEnOrden(lista1, crearNodo(3));
    lista1 = agregarEnOrden(lista1, crearNodo(5));
    lista1 = agregarEnOrden(lista1, crearNodo(7));

    mostrarListaRecursiva(lista1); //ej1 () TP Lista Recursiva
    int flag = 0;
    lista1= borrarNodoV2(lista1,6,&flag);
    puts("\n");
    printf("Flag = %d\n", flag);
    if(flag == 0 )
    {
        puts("No se encontraba el dato en la lista\n");
    }else
    {
        puts("Se modifico la lista ");
    }

    mostrarListaRecursiva(lista1);

    mostrarListaRecursivaInversa(lista1);

    puts("\n");

    int suma = sumaListaRecursivaImplicita(lista1);  ///ej2() nose porque el error del resultado

    printf("El resultado de la suma de los elementos de la lista es de : %i ", suma);


    puts("\n");

    mostrarElementosPosicionesParesRecursiva(lista1,0); //ej3 () TP Lista Recursiva

    puts("\n\nBorrando dato (3)");

    lista1 = borrarNodoRecursivo(lista1,3);  //ej4 () TP Lista Recursiva

    puts("\n");

    mostrarListaRecursiva(lista1);

    puts("\n");

    for(int i = 8 ;  i < 12; i++)
    {
        lista1 = insertarEnOrdenRecursivo(lista1,i);   //ej5 () TP Lista Recursiva
    }

    puts("Lista Con mas datos\n");

    mostrarListaRecursiva(lista1);

    puts("\nInvirtiendo Lista ..");
    lista1=invertirListaRecursiva(lista1);   //ej6 () TP Lista Recursiva

    mostrarListaRecursiva(lista1);

    /*
    lista2 = agregarEnOrden(lista2, crearNodo(2));
    lista2 = agregarEnOrden(lista2, crearNodo(4));
    lista2 = agregarEnOrden(lista2, crearNodo(6));

    puts("\n");

    mostrarLista(lista2);


    puts("\n");

    // Llama a la función para intercalar las listas
    nodo* lista_intercalada = intercalarListasOrdenadas(lista1,lista2);

    // Muestra la lista intercalada
    printf("Lista intercalada: ");
    mostrarLista(lista_intercalada);

    puts("\n");

    printf("Lista invertida: ");
    invertirLista(&lista_intercalada);
    mostrarLista(lista_intercalada);
    */



    return 0;
}




