#include <stdio.h>
#include <stdlib.h>

int factorialRecursiva (int num);
void mostrarArrayRecursivaNormal ( int a[], int valid, int i);
int sumaArrayRecursiva ( int a[], int valid, int i);
double potenciaRecursiva(double base, int exponente);
void mostrarArrayRecursivaInvertido ( int a[], int valid, int i);
int encontrarMinimoRecursivo(int arr[], int n);
void mostrarCaracteresInverso();
int elementoEnArreglo(const int arreglo[], int elemento, int longitud, int indice);

int main()
{
    //ej1()
    int x = 4;

    int factorialX = factorialRecursiva(x);

    printf("%d",factorialX);
    puts("\n");

    //ej2()
    double base;
    int exponente;

    printf("Ingrese la base: ");
    scanf("%lf", &base);

    printf("Ingrese el exponente: ");
    scanf("%d", &exponente);

    double resultado = potenciaRecursiva(base, exponente);

    printf("El resultado de %.2lf ^ %d es %.2lf\n", base, exponente, resultado);
    puts("\n");

    //ej3()
    int Z[5]={1,2,3,4,5};
    mostrarArrayRecursivaNormal(Z,5,0);
    puts("\n");

    //ej4()
    int A[5]={5,6,7,8,9};
    mostrarArrayRecursivaInvertido(A,5,0);
    puts("\n");

    //ej5()
    int n;
    printf("Ingrese el tamaño del arreglo: ");
    scanf("%d", &n);

    int arr[n];
    printf("Ingrese los elementos del arreglo:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    if (esCapicuaRecursiva(arr, 0, n - 1)) {
        printf("El arreglo es capicúa.\n");
    } else {
        printf("El arreglo no es capicúa.\n");
    }

    puts("\n");

    //ej6()
    int suma = sumaArrayRecursiva(Z,5,0);
    printf("%d",suma);
    puts("\n");

    //ej7()

    int arreglo[] = {12, 5, 9, 20, 7};
    int p = sizeof(arreglo) / sizeof(arreglo[0]);

    int minimo = encontrarMinimoRecursivo(arreglo, p);

    printf("El elemento mínimo en el arreglo es: %d\n", minimo);

    printf("Ingresa caracteres (termina con '*'):\n");
    mostrarCaracteresInverso();

    int arreglo2[] = {2, 4, 6, 8, 10};
    int longitud = sizeof(arreglo2) / sizeof(arreglo2[0]);
    int elementoBuscado = 6;

    if (elementoEnArreglo(arreglo2, elementoBuscado, longitud, 0)) {
        printf("\nEl elemento %d está en el arreglo.\n", elementoBuscado);
    } else {
        printf("\nEl elemento %d no está en el arreglo.\n", elementoBuscado);
    }


    return 0;
}

//ej1()
int factorialRecursiva (int num)
{
    int result;

    if( num == 0){
        result = 1;
    }else{
        result = num * factorialRecursiva (num - 1);
    }

    return result;
}

int factorialRecursivaIMplicita (int num)
{
    int result=1;

    if( num != 0){
        result = num * factorialRecursiva (num - 1);
    }
    return result;
}
//ej2()
double potenciaRecursiva(double base, int exponente) {
    if (exponente == 0) {
        return 1;
    } else if (exponente > 0) {
        return base * potenciaRecursiva(base, exponente - 1);
    } else {
        return 1 / (base * potenciaRecursiva(base, -exponente - 1));
    }
}

//ej3()
void mostrarArrayRecursivaNormal ( int a[], int valid, int i)
{
    if( i == valid ){
        printf("Fin Arreglo");
    }else{
        printf(" |%d| ", a[i]);
        mostrarArrayRecursivaNormal (a,valid,i+1);
    }
}

//ej4()
void mostrarArrayRecursivaInvertido ( int a[], int valid, int i)
{
    if( i == valid ){
        printf("Fin Arreglo");
    }else{

        mostrarArrayRecursivaInvertido (a,valid,i+1);
        printf(" |%d| ", a[i]); ///solo hay que dar vuelta el printf

    }
}

//ej5()
int esCapicuaRecursiva(int arr[], int inicio, int fin) {
    if (inicio >= fin) {
        return 1; // Si llega al centro del arreglo, es capicúa
    } else if (arr[inicio] != arr[fin]) {
        return 0; // Si los elementos no coinciden, no es capicúa
    } else {
        return esCapicuaRecursiva(arr, inicio + 1, fin - 1); // Comparamos los siguientes elementos
    }
}

//ej6()
int sumaArrayRecursiva ( int a[], int valid, int i)
{
    int result;

    if(i == valid){ //Puedo pasarme del ultimo y retornar 0 ó podria llegar justo a la ultima posicion y retornarla y chaupinela
        result = 0;
    }else{
        result = a[i] + sumaArrayRecursiva(a,valid,i);
    }

    return result;
}

//ej7()
int encontrarMinimoRecursivo(int arr[], int n)
{
    // Caso 1: Si el arreglo tiene solo un elemento, ese es el mínimo
    if (n == 1) {
        return arr[0];
    }

    // Llamada recursiva para encontrar el minimo en el subarreglo que excluye el primer elemento
    int subMinimo = encontrarMinimoRecursivo(arr + 1, n - 1);

    // Comparar el minimo encontrado en el subarreglo con el primer elemento y devolver el mínimo de ambos
    if (arr[0] < subMinimo) {
        return arr[0];
    } else {
        return subMinimo;
    }
}

//ej11()

void mostrarCaracteresInverso() {
    char caracter;
    scanf("%c",&caracter); // Leer un carácter (ignorar espacios en blanco)

    if (caracter != '*') {
        mostrarCaracteresInverso(); // Llamar recursivamente antes de mostrar el carácter
        printf("%c", caracter);    // Mostrar el carácter después de la llamada recursiva
    }
}

//ej12
// Función recursiva para verificar si un elemento está presente en el arreglo
int elementoEnArreglo(const int arreglo[], int elemento, int longitud, int indice) {
    // Caso base: si hemos recorrido todo el arreglo y no encontramos el elemento, devolvemos 0 (falso)
    if (indice == longitud) {
        return 0;
    }

    // Si el elemento actual es igual al elemento buscado, devolvemos 1 (verdadero)
    if (arreglo[indice] == elemento) {
        return 1;
    }

    // Llamada recursiva para verificar el resto del arreglo
    return elementoEnArreglo(arreglo, elemento, longitud, indice + 1);
}

