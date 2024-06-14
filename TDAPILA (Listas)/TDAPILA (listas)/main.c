#include <stdio.h>
#include <stdlib.h>
#include "TDAPilaListaSimp.h"


int main()
{
    Pila* pila = crearPila(); // Crea una nueva pila

    empujar(pila, 10); // Agrega elementos a la pila
    empujar(pila, 20);
    empujar(pila, 30);

    mostrarPila(pila);

    char mander = 's';

    do{
        int num;
        printf("Ingrese un dato :");
        scanf("%d",&num);
        empujar(pila,num);

        puts("Presione 'S' para cargar mas datos.");
        fflush(stdin);
        scanf("%c",&mander);
        system("cls");

    }while(mander == 's');

    printf("Elemento superior de la pila: %d\n", consultarTope(pila)); // Consulta el tope de la pila

    printf("Elementos de la pila: ");


    /* Para probar el "estaVacia recorro la pila con el while o modularizo la funcion"

    while (!estaVacia(pila)) { // Mientras la pila no esté vacía
        printf("%d ", sacar(pila)); // Saca elementos de la pila y los imprime
    }*/

    mostrarPila(pila);
    printf("\n");

    Pila* pila_Pares = crearPila();
    Pila* aux = crearPila();
    Pila* auxB = crearPila();


     while (!estaVacia(pila)) {
        int numero = sacar(pila);
        if (numero % 2 == 0) { // Verificar si el número es par
            empujar(pila_Pares,numero);
        }
    }

    mostrarPila(pila_Pares);


    while(!estaVacia(pila_Pares)){
        int num = 10;
        int aComparar = consultarTope(pila_Pares);
        printf("Valor a comparar : %d\n",aComparar);
        if(aComparar < num) {
            int dato = sacar(pila_Pares);
            empujar(aux,dato);
        }else{
            empujar(auxB,aComparar);
            sacar_v2(pila_Pares);
        }
    }

    while(!estaVacia(auxB))
    {
        empujar(pila_Pares,consultarTope(auxB));
        sacar_v2(auxB);
    }

    puts("Pila Menores");
    mostrarPila(aux);
    puts("Pila Mayores");
    mostrarPila(pila_Pares);

    return 0;
}

