#include <stdio.h>
#include <stdlib.h>

int main()
{

    return 0;
}

//Funciones Arboles
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





//Funciones ArregloDe Listas
typedef struct {
   int nota;
   int legajo;
   char nombreApe[40];
   char materia[40];
   int idMateria;
} registroArchivo;

typedef struct {
   int nota;
   int legajo;
   char nombreApe[40];
} notaAlumno;

typedef struct _nodo {
   notaAlumno dato;
   struct _nodo *siguiente;
} nodo;

typedef struct {
    int idMateria;
    char materia[40];
    nodo * listaDeNotas;
} celda;


notaAlumno cargarDatos()
{
    notaAlumno nuevo;
    int nota;

    printf("Igrese el nombre del alumno : ");
    fflush(stdin);
    scanf("%s",&nuevo.nombreApe);

    printf("Ingrese el legajo del alumno: ");
    fflush(stdin);
    scanf("%d",&nuevo.legajo);

    nota = notaValida();
    nuevo.nota = nota;

    return nuevo;

}

int ingresarNotas(celda ArrDeList[], int dim)
{
    notaAlumno nuevo;
    char materia[20];
    int idMateria;
    char mander = 's';
    int valid = 0;

    while(mander == 's' && valid<dim)
    {
        printf("Ingresar la materia : ");
        fflush(stdin);
        scanf("%s",&materia);
        printf("Ingrese el id de la materia :");
        fflush(stdin);
        scanf("%d",&idMateria);

        nuevo = cargarDatos();

        valid = alta(ArrDeList,nuevo,materia,idMateria,valid);
        printf("Presione 's' para cargar mas notas\n");
        mander = getch (mander);
    }

    return valid;
}



int notaValida ()
{
    int nota;

    while(nota < 1 || nota > 10)
    {
        printf("Ingrese la nota:");
        fflush(stdin);
        scanf("%d",&nota);
    }

    return nota;
}

nodo * crearNodo (notaAlumno nuevo)
{
    nodo * aux = (nodo*) malloc(sizeof(nodo));
    aux->dato = nuevo;
    aux->siguiente = NULL;

    return aux;
}

/*
int alta (celda ArrDeLista [],notaAlumno nuevo,char materia[],int idMateria,int validos)
{
    nodo * aux = crearNodo(nuevo);
    int pos = buscarPosMateria(ArrDeLista,materia,validos);
    if(pos == -1) //si la funcion devuelve -1 es porque recorrio el arreglo y no encontro la materia
    {
        validos = agregarMateria (ArrDeLista,materia,idMateria,validos);
        pos = validos - 1;
    }
    ArrDeLista[pos].listaDeNotas = agregarPpio(ArrDeLista[pos].listaDeNotas,aux);

    return validos;
}
*/

//OPCION MAS RECOMENDABLE PARA MI
int alta(celda ArrDeLista[], notaAlumno nuevo, char materia[], int idMateria, int validos)
{
    int pos = buscarPosMateria(ArrDeLista, materia, validos);

    if (pos == -1)
    {
        validos = agregarMateria(ArrDeLista, materia, idMateria, validos);
        pos = validos - 1;
    }

    // Verifica si el alumno ya tiene una nota en esta materia
    if (!existeAlumno(ArrDeLista[pos].listaDeNotas, nuevo.legajo))
    {
        nodo *aux = crearNodo(nuevo);
        ArrDeLista[pos].listaDeNotas = agregarPpio(ArrDeLista[pos].listaDeNotas, aux);
    }
    else
    {
        printf("El alumno con legajo %d ya tiene una nota en la materia %s.\n", nuevo.legajo, materia);
    }

    return validos;
}

int existeAlumno(nodo *lista, int legajo)
{
    while (lista)
    {
        if (lista->dato.legajo == legajo)
        {
            return 1; // El alumno ya tiene una nota en la lista
        }
        lista = lista->siguiente;
    }
    return 0; // El alumno no tiene una nota en la lista
}


nodo * inicLista ()
{
    return NULL;
}


int agregarMateria (celda ArrDeLis[],char materia[],int idMateria, int validos)
{
    strcpy(ArrDeLis[validos].materia,materia);
    ArrDeLis[validos].idMateria = idMateria;
    ArrDeLis[validos].listaDeNotas = inicLista();
    validos ++;

    return validos;
}


int buscarPosMateria (celda ArrDeLista [],char materia [],int validos)
{
    int rta = -1;
    int i=0;
    while(i< validos && rta == -1)
    {
        if(strcasecmp(ArrDeLista[i].materia,materia)==0)
        {
            rta = i;   //si encuentra coincidencia nos devuelve la posicion de la materia en el arreglo
        }              //sino devuelve -1
        i++;
    }

    return rta;
}

nodo * agregarPpio (nodo * lista, nodo * nuevo)
{
    if(lista == NULL)
    {
        lista = nuevo;
    }else
    {
        nuevo->siguiente = lista;
        lista = nuevo;
    }

    return lista;
}

void cargarRegistroArchivo(celda ArrDeList[], int valid, const char *nombreArchi)
{
    FILE *archi = fopen(nombreArchi, "wb"); // Usa "wb" para escritura binaria

    if (archi)
    {
        for (int i = 0; i < valid; i++)
        {
            nodo *actual = ArrDeList[i].listaDeNotas; // Apunta al primer nodo de la lista
            while (actual)
            {
                registroArchivo nuevo;

                strcpy(nuevo.nombreApe, actual->dato.nombreApe);
                nuevo.legajo = actual->dato.legajo;
                nuevo.nota = actual->dato.nota;
                strcpy(nuevo.materia, ArrDeList[i].materia);
                nuevo.idMateria = ArrDeList[i].idMateria;

                fwrite(&nuevo, sizeof(registroArchivo), 1, archi);

                actual = actual->siguiente; // Avanza al siguiente nodo en la lista
            }
        }
        fclose(archi);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}

void cargarNotasAprobadas(celda ArrDeList[], int valid, const char *nombreArchi, const char *nombreArchiAprobadas)
{
    FILE *archi = fopen(nombreArchi, "rb"); // Abre el archivo original para lectura binaria
    FILE *archiAprobadas = fopen(nombreArchiAprobadas, "wb"); // Crea un archivo para notas aprobadas

    if (archi && archiAprobadas)
    {
        registroArchivo nuevo;

        while (fread(&nuevo, sizeof(registroArchivo), 1, archi) == 1)
        {
            if (nuevo.nota >= 6) // Cambia 6 por el umbral de notas aprobadas que desees
            {
                fwrite(&nuevo, sizeof(registroArchivo), 1, archiAprobadas);
            }
        }

        fclose(archi);
        fclose(archiAprobadas);
    }
    else
    {
        printf("Error al abrir los archivos.\n");
    }
}

void mostrarPersona(notaAlumno aux)
{
    printf("\n----------------------\n");
    printf("Nombre : %s\n",aux.nombreApe);
    printf("Legajo : %d\n",aux.legajo);
    printf("Nota : %d",aux.nota);
    printf("\n----------------------\n");
}

void mostrarLista(nodo * lista)
{
    if(lista == NULL)
    {
        printf("Error al imprimir la lista\n");
    }else
    {
        nodo * seg;
        seg = lista;
        while(seg != NULL)
        {
            mostrarPersona(seg->dato);
            seg = seg->siguiente;
        }
    }
}


//Funciones Arreglo de Arboles

typedef struct {
   char animal[30];
   int cant;
   int habitat;
   int idEspecie;
   char especie[20];
} registroArchivo;

typedef struct {
    char nombreAnimal [30];
	int cantidad;
	int habitat;
// 1 - selva, 2- savana, 3-bosque, 4-mar
} animal;

typedef struct
{
   animal dato;
   struct nodoArbol * izq;
   struct nodoArbol * der;
} nodoArbol;

typedef struct
{
   int idEspecie;
   char especie [20];
 	 // "Mamiferos", "Aves"
       // "Reptiles", "Peces",”Anfibios”
   nodoArbol * arbolDeAnimales;
} celdaEspecie;

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


//Lista de Arboles
typedef struct
{
    int cantCopias;
    float precioAlquiler;
} stcopias;

typedef struct
{
    char titulo[20];
    char autor[20];
    int cantPag;
    char genero[20];
    int anioLanzamiento;
    int  idInterno;
    stcopias Copias;

} stlibros;

typedef struct nodoArbolLibro
{
    stlibros dato;
    struct nodoArbolLibro * izq;
    struct nodoArbolLibro * der;
} nodoArbolLibro;

typedef struct nodoGenero {
    char genero[20];
    nodoArbolLibro *arbolDeLibros;
    struct nodoGenero *siguiente;
} nodoGenero;

typedef struct listaGeneros {
    nodoGenero *primero;
} listaGeneros;


stlibros crearLibro(char nombreLibro[])
{
    stlibros libro;

    strcpy(libro.titulo,nombreLibro);

    printf("Ingrese el autor del libro : ");
    fflush(stdin);
    gets(libro.autor);

    printf("Ingrese la cantidad de páginas: ");
    scanf("%d", &libro.cantPag);

    printf("Ingrese el género del libro : ");
    fflush(stdin);
    gets(libro.genero);

    printf("Ingrese el año de lanzamiento: ");
    scanf("%d", &libro.anioLanzamiento);

    printf("Ingrese el ID interno del libro: ");
    scanf("%d", &libro.idInterno);

    printf("Ingrese la cantidad de copias: ");
    scanf("%d", &libro.Copias.cantCopias);

    printf("Ingrese el precio de alquiler por copia: ");
    scanf("%f", &libro.Copias.precioAlquiler);

    return libro;
}

// Función para verificar si un libro ya existe en el archivo
int libroExisteEnArchivo(const char *nombreLibro, const char *archivo) {
    FILE *file = fopen(archivo, "rb");
    if (file == NULL) {
        return 0; // El archivo no está disponible
    }

    stlibros libro;

    while (fread(&libro, sizeof(stlibros), 1, file) == 1) {
        // Comparar el nombre del libro en el archivo con el nombre proporcionado
        if (strcmp(libro.titulo, nombreLibro) == 0) {
            fclose(file);
            return 1; // El libro existe en el archivo
        }
    }

    fclose(file);
    return 0; // No se encontró el libro en el archivo
}

// Función para cargar un libro en el archivo
void cargarLibroEnArchivo(const char *archivo) {
    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        stlibros libro;
        FILE *file = fopen(archivo, "ab");

        if (file == NULL) {
            printf("Error al abrir el archivo de libros.\n");
            return;
        }

        printf("Ingrese el título del libro: ");
        fflush(stdin);
        gets(libro.titulo);

        if (libroExisteEnArchivo(libro.titulo, archivo)) {
            printf("El libro ya existe en el archivo. No se puede cargar nuevamente.\n");
            fclose(file);
        } else {
            libro = crearLibro(libro.titulo);

            fwrite(&libro, sizeof(stlibros), 1, file);
            fclose(file);

            printf("¿Desea cargar otro libro? (S/N): ");
            fflush(stdin);
            scanf(" %c", &continuar);
        }
    }
}


nodoArbolLibro *inicializarArbol()
{
    return NULL;
}

listaGeneros *inicializarListaGeneros() {
    listaGeneros *nuevaLista = (listaGeneros *)malloc(sizeof(listaGeneros));
    if (nuevaLista != NULL) {
        nuevaLista->primero = NULL; // Inicializa el puntero primero a NULL
    } else {
        printf("Error al asignar memoria para la lista de géneros.\n");
        // Manejo de errores si no se pudo asignar memoria
    }
    return nuevaLista;
}


nodoArbolLibro *crearNodoArbolLibro(stlibros libro)
{
    nodoArbolLibro *aux = (nodoArbolLibro *)malloc(sizeof(nodoArbolLibro));

    aux->dato = libro;
    aux->izq = NULL;
    aux->der = NULL;

    return aux;
}

void agregarGenero(listaGeneros *lista, const char genero[]) {
    nodoGenero *nuevoGenero = (nodoGenero *)malloc(sizeof(nodoGenero));
    strcpy(nuevoGenero->genero, genero);
    nuevoGenero->arbolDeLibros = inicializarArbol();
    nuevoGenero->siguiente = lista->primero;
    lista->primero = nuevoGenero;
}


nodoArbolLibro *buscarLibroEnArbol(nodoArbolLibro *arbol, const char titulo[]) {
    if (arbol == NULL) {
        return NULL; // El árbol está vacío, no se encontró el libro
    }

    int comparacion = strcmp(titulo, arbol->dato.titulo);

    if (comparacion == 0) {
        return arbol; // El libro fue encontrado en este nodo
    } else if (comparacion < 0) {
        return buscarLibroEnArbol(arbol->izq, titulo); // Buscar en el subárbol izquierdo
    } else {
        return buscarLibroEnArbol(arbol->der, titulo); // Buscar en el subárbol derecho
    }
}


// Función para insertar un libro en el árbol teniendo como criterio la cantidad de copias
nodoArbolLibro *insertarPorCopias(nodoArbolLibro *arbol, nodoArbolLibro *nuevo)
{
    if (arbol == NULL)
    {
        arbol = nuevo;
    }
    else
    {
        if (nuevo->dato.Copias.cantCopias > arbol->dato.Copias.cantCopias)
        {
            arbol->der = insertarPorCopias(arbol->der, nuevo);
        }
        else
        {
            arbol->izq = insertarPorCopias(arbol->izq, nuevo);
        }
    }
    return arbol;
}



// Función para mostrar los libros en orden (por identificador interno)
void inorder(nodoArbolLibro *arbol)
{
    if (arbol != NULL)
    {
        inorder(arbol->izq);
        printf("ID: %d - Título: %s - Autor: %s\n", arbol->dato.idInterno, arbol->dato.titulo, arbol->dato.autor);
        inorder(arbol->der);
    }
}

nodoGenero *buscarGenero(listaGeneros *lista, const char genero[]) {
    nodoGenero *actual = lista->primero;
    while (actual != NULL) {
        if (strcmp(actual->genero, genero) == 0) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL; // Género no encontrado
}


listaGeneros *cargarListaDeGenerosDesdeArchivo(const char *nombreArchivo, listaGeneros *listaGeneros) {
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de libros.\n");
        return listaGeneros; // Devolver la lista original
    }

    stlibros libro;

    while (fread(&libro, sizeof(stlibros), 1, archivo) == 1) {
        nodoGenero *genero = buscarGenero(listaGeneros, libro.genero);
        if (genero == NULL) {
            // Si el género no existe en la lista, agrégalo
            agregarGenero(listaGeneros, libro.genero);
            genero = listaGeneros->primero;
        }

        // Crea el nodo del árbol de libros para el libro y agrégalo al género correspondiente
        genero->arbolDeLibros = insertarPorCopias(genero->arbolDeLibros, crearNodoArbolLibro(libro));
    }

    fclose(archivo);

    return listaGeneros; // Devolver la lista modificada
}

void mostrarArchivoDeLibros(const char *archivo) {
    FILE *file = fopen(archivo, "rb");

    if (file == NULL) {
        printf("No se pudo abrir el archivo de libros.\n");
        return;
    }

    stlibros libro;

    printf("Libros en el archivo:\n");

    while (fread(&libro, sizeof(stlibros), 1, file) == 1) {
        printf("Título: %s\n", libro.titulo);
        printf("Autor: %s\n", libro.autor);
        printf("Cantidad de páginas: %d\n", libro.cantPag);
        printf("Género: %s\n", libro.genero);
        printf("Año de lanzamiento: %d\n", libro.anioLanzamiento);
        printf("ID interno: %d\n", libro.idInterno);
        printf("Cantidad de copias: %d\n", libro.Copias.cantCopias);
        printf("Precio de alquiler por copia: %.2f\n", libro.Copias.precioAlquiler);
        printf("\n");
    }

    fclose(file);
}

void recorrerListaDeGeneros(listaGeneros *lista) {
    nodoGenero *actual = lista->primero;

    while (actual != NULL) {
        printf("Género: %s\n", actual->genero);
        printf("Libros en este género (ordenados por ID interno):\n");

        inorder(actual->arbolDeLibros);

        printf("\n");

        actual = actual->siguiente;
    }
}

void agregarLibroAListaYArchivo(listaGeneros *lista, const char *nombreArchivo) {
    char nombreLibro[20];
    char genero[20];

    printf("Ingrese el título del libro: ");
    fflush(stdin);
    gets(nombreLibro);

    if (libroExisteEnLista(lista, nombreLibro)) {
        printf("El libro ya existe en la lista.\n");
        return;
    }

    printf("Ingrese el género del libro: ");
    fflush(stdin);
    gets(genero);

    stlibros libroAGuardar = crearLibro(nombreLibro);
    nodoArbolLibro *nuevoNodo = crearNodoArbolLibro(libroAGuardar);

    // Buscar el género en la lista
    nodoGenero *generoEncontrado = buscarGenero(lista, genero);

    if (generoEncontrado == NULL) {
        // Si el género no existe en la lista, agrégalo
        agregarGenero(lista, genero);
        generoEncontrado = lista->primero;
    }

    // Insertar el libro en el árbol correspondiente al género
    generoEncontrado->arbolDeLibros = insertarPorCopias(generoEncontrado->arbolDeLibros, nuevoNodo);

    FILE *archivo = fopen(nombreArchivo, "ab");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para escritura.\n");
        free(nuevoNodo); // Liberar memoria si no se pudo abrir el archivo
        return;
    }

    fwrite(&libroAGuardar, sizeof(libroAGuardar), 1, archivo); // Guardar en el archivo
    fclose(archivo);

    printf("Libro guardado en la lista y en el archivo.\n");
}

//Lista de listas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructuras para listas
typedef struct {
    int cantCopias;
    float precioAlquiler;
} stcopias;

typedef struct {
    char titulo[20];
    char autor[20];
    int cantPag;
    char genero[20];
    int anioLanzamiento;
    int idInterno;
    stcopias Copias;
} stlibros;

typedef struct nodoLibro {
    stlibros dato;
    struct nodoLibro *siguiente;
} nodoLibro;

typedef struct nodoGenero {
    char genero[20];
    nodoLibro *listaDeLibros;
    struct nodoGenero *siguiente;
} nodoGenero;

typedef struct listaGeneros {
    nodoGenero *primero;
} listaGeneros;

// Inicializar lista de géneros
listaGeneros *inicializarListaGeneros() {
    listaGeneros *nuevaLista = (listaGeneros *)malloc(sizeof(listaGeneros));
    if (nuevaLista != NULL) {
        nuevaLista->primero = NULL;
    } else {
        printf("Error al asignar memoria para la lista de géneros.\n");
    }
    return nuevaLista;
}

// Crear un nuevo nodo libro
nodoLibro *crearNodoLibro(stlibros libro) {
    nodoLibro *nuevo = (nodoLibro *)malloc(sizeof(nodoLibro));
    if (nuevo != NULL) {
        nuevo->dato = libro;
        nuevo->siguiente = NULL;
    } else {
        printf("Error al asignar memoria para el nodo libro.\n");
    }
    return nuevo;
}

// Agregar un género a la lista de géneros
void agregarGenero(listaGeneros *lista, const char genero[]) {
    nodoGenero *nuevoGenero = (nodoGenero *)malloc(sizeof(nodoGenero));
    if (nuevoGenero != NULL) {
        strcpy(nuevoGenero->genero, genero);
        nuevoGenero->listaDeLibros = NULL;
        nuevoGenero->siguiente = lista->primero;
        lista->primero = nuevoGenero;
    } else {
        printf("Error al asignar memoria para el nodo género.\n");
    }
}

// Buscar un género en la lista de géneros
nodoGenero *buscarGenero(listaGeneros *lista, const char genero[]) {
    nodoGenero *actual = lista->primero;
    while (actual != NULL) {
        if (strcmp(actual->genero, genero) == 0) {
            return actual;
        }
        actual = actual->siguiente;
    }
    return NULL; // Género no encontrado
}

// Agregar un libro a la lista de libros de un género
void agregarLibroAGenero(nodoGenero *genero, stlibros libro) {
    nodoLibro *nuevoLibro = crearNodoLibro(libro);
    if (nuevoLibro != NULL) {
        nuevoLibro->siguiente = genero->listaDeLibros;
        genero->listaDeLibros = nuevoLibro;
    }
}

// Crear un libro
stlibros crearLibro(char nombreLibro[]) {
    stlibros libro;

    strcpy(libro.titulo, nombreLibro);

    printf("Ingrese el autor del libro: ");
    fflush(stdin);
    gets(libro.autor);

    printf("Ingrese la cantidad de páginas: ");
    scanf("%d", &libro.cantPag);

    printf("Ingrese el género del libro: ");
    fflush(stdin);
    gets(libro.genero);

    printf("Ingrese el año de lanzamiento: ");
    scanf("%d", &libro.anioLanzamiento);

    printf("Ingrese el ID interno del libro: ");
    scanf("%d", &libro.idInterno);

    printf("Ingrese la cantidad de copias: ");
    scanf("%d", &libro.Copias.cantCopias);

    printf("Ingrese el precio de alquiler por copia: ");
    scanf("%f", &libro.Copias.precioAlquiler);

    return libro;
}

// Verificar si un libro ya existe en el archivo
int libroExisteEnArchivo(const char *nombreLibro, const char *archivo) {
    FILE *file = fopen(archivo, "rb");
    if (file == NULL) {
        return 0; // El archivo no está disponible
    }

    stlibros libro;

    while (fread(&libro, sizeof(stlibros), 1, file) == 1) {
        if (strcmp(libro.titulo, nombreLibro) == 0) {
            fclose(file);
            return 1; // El libro existe en el archivo
        }
    }

    fclose(file);
    return 0; // No se encontró el libro en el archivo
}

// Cargar un libro en el archivo
void cargarLibroEnArchivo(const char *archivo) {
    char continuar = 's';

    while (continuar == 's' || continuar == 'S') {
        stlibros libro;
        FILE *file = fopen(archivo, "ab");

        if (file == NULL) {
            printf("Error al abrir el archivo de libros.\n");
            return;
        }

        printf("Ingrese el título del libro: ");
        fflush(stdin);
        gets(libro.titulo);

        if (libroExisteEnArchivo(libro.titulo, archivo)) {
            printf("El libro ya existe en el archivo. No se puede cargar nuevamente.\n");
            fclose(file);
        } else {
            libro = crearLibro(libro.titulo);

            fwrite(&libro, sizeof(stlibros), 1, file);
            fclose(file);

            printf("¿Desea cargar otro libro? (S/N): ");
            fflush(stdin);
            scanf(" %c", &continuar);
        }
    }
}

// Cargar lista de géneros desde archivo
listaGeneros *cargarListaDeGenerosDesdeArchivo(const char *nombreArchivo, listaGeneros *listaGeneros) {
    FILE *archivo = fopen(nombreArchivo, "rb");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo de libros.\n");
        return listaGeneros; // Devolver la lista original
    }

    stlibros libro;

    while (fread(&libro, sizeof(stlibros), 1, archivo) == 1) {
        nodoGenero *genero = buscarGenero(listaGeneros, libro.genero);
        if (genero == NULL) {
            // Si el género no existe en la lista, agrégalo
            agregarGenero(listaGeneros, libro.genero);
            genero = listaGeneros->primero;
        }

        // Agregar el libro a la lista del género correspondiente
        agregarLibroAGenero(genero, libro);
    }

    fclose(archivo);

    return listaGeneros; // Devolver la lista modificada
}

// Mostrar el archivo de libros
void mostrarArchivoDeLibros(const char *archivo) {
    FILE *file = fopen(archivo, "rb");

    if (file == NULL) {
        printf("No se pudo abrir el archivo de libros.\n");
        return;
    }

    stlibros libro;

    printf("Libros en el archivo:\n");

    while (fread(&libro, sizeof(stlibros), 1, file) == 1) {
        printf("Título: %s\n", libro.titulo);
        printf("Autor: %s\n", libro.autor);
        printf("Cantidad de páginas: %d\n", libro.cantPag);
        printf("Género: %s\n", libro.genero);
        printf("Año de lanzamiento: %d\n", libro.anioLanzamiento);
        printf("ID interno: %d\n", libro.idInterno);
        printf("Cantidad de copias: %d\n", libro.Copias.cantCopias);
        printf("Precio de alquiler por copia: %.2f\n", libro.Copias.precioAlquiler);
        printf("\n");
    }

    fclose(file);
}

// Recorrer lista de géneros y mostrar libros
void recorrerListaDeGeneros(listaGeneros *lista) {
    nodoGenero *actual = lista->primero;

    while (actual != NULL) {
        printf("Género: %s\n", actual->genero);
        printf("Libros en este género:\n");

        nodoLibro *libroActual = actual->listaDeLibros;
        while (libroActual != NULL) {
            printf("ID: %d - Título: %s - Autor: %s\n", libroActual->dato.idInterno, libroActual->dato.titulo, libroActual->dato.autor);
            libroActual = libroActual->siguiente;
        }

        printf("\n");

        actual = actual->siguiente;
    }
}

// Agregar libro a lista y archivo
void agregarLibroAListaYArchivo(listaGeneros *lista, const char *nombreArchivo) {
    char nombreLibro[20];
    char genero[20];

    printf("Ingrese el título del libro: ");
    fflush(stdin);
    gets(nombreLibro);

    // Buscar si el libro ya existe en la lista
    nodoGenero *generoActual = lista->primero;
    while (generoActual != NULL) {
        nodoLibro *libroActual = generoActual->listaDeLibros;
        while (libroActual != NULL) {
            if (strcmp(libroActual->dato.titulo, nombreLibro) == 0) {
                printf("El libro ya existe en la lista.\n");
                return;
            }
            libroActual = libroActual->siguiente;
        }
        generoActual = generoActual->siguiente;
    }

    printf("Ingrese el género del libro: ");
    fflush(stdin);
    gets(genero);

    stlibros libroAGuardar = crearLibro(nombreLibro);
    nodoLibro *nuevoNodo = crearNodoLibro(libroAGuardar);

    // Buscar el género en la lista
    nodoGenero *generoEncontrado = buscarGenero(lista, genero);

    if (generoEncontrado == NULL) {
        // Si el género no existe en la lista, agrégalo
        agregarGenero(lista, genero);
        generoEncontrado = lista->primero;
    }

    // Insertar el libro en la lista correspondiente al género
    agregarLibroAGenero(generoEncontrado, libroAGuardar);

    FILE *archivo = fopen(nombreArchivo, "ab");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo para escritura.\n");
        free(nuevoNodo); // Liberar memoria si no se pudo abrir el archivo
        return;
    }

    fwrite(&libroAGuardar, sizeof(libroAGuardar), 1, archivo); // Guardar en el archivo
    fclose(archivo);

    printf("Libro guardado en la lista y en el archivo.\n");
}

// Programa principal para demostrar las funciones
int main() {
    listaGeneros *miLista = inicializarListaGeneros();

    // Cargar libros desde archivo
    cargarListaDeGenerosDesdeArchivo("libros.dat", miLista);

    // Agregar un libro nuevo a la lista y al archivo
    agregarLibroAListaYArchivo(miLista, "libros.dat");

    // Mostrar los libros desde el archivo
    mostrarArchivoDeLibros("libros.dat");

    // Recorrer la lista de géneros y mostrar los libros
    recorrerListaDeGeneros(miLista);

    return 0;
}


//TDA Fila


typedef struct
{
    int dato;
    struct nodo2* ante;
    struct nodo2* sig;
}nodo2;

typedef struct
{
    struct nodo2 * inicio;
    struct nodo2 * fin;
}Fila;


nodo2 * inicLista()
{
    return NULL;
}



void inicFila (Fila * fila)
{
    fila->inicio = inicLista();
    fila->fin = inicLista ();
}

void leer(Fila * fila)
{
    int dato;
    printf("Ingrese un dato : ");
    fflush(stdin);
    scanf("%d",&dato);
    agregarAlaFila(fila,dato);
}

void mostrarLista ( nodo2 * lista)
{
    if(lista == NULL)
    {
        printf("La lista esta vacia");
    }
    else
    {
        nodo2 * seg = lista;
        while (seg != NULL)
        {
            printf("Dato : %d",seg->dato);
            seg = seg->sig;
        }
    }
}

void mostrar(Fila fila)
{
    printf("Inicio de la fila : ");

    mostrarLista (fila.inicio);

    printf("Fin de la lista");
}

nodo2 * crearNodo(int dato)
{
    nodo2 * nuevo = (nodo2*)malloc (sizeof(nodo2));
    nuevo ->dato = dato;
    nuevo ->ante = NULL;
    nuevo ->sig = NULL;

    return nuevo;
}

nodo2 * buscarUltimo(nodo2 * lista) {
   nodo2 * seg = lista;
   if(seg != NULL)
      while(seg->sig != NULL) {
         seg = seg->sig;
      }
    return seg;
 }


nodo2 * agregarFinal(nodo2 * lista,nodo2 * nuevo)
{
    if(lista== NULL)     //esta opcion se podria quitar ya que en el if ya se evalua si la fila es distinto de null
    {
        lista = nuevo;
    }else
    {
        nodo2 * ultimo = buscarUltimo(lista);
        ultimo->sig = nuevo;
        nuevo->ante = ultimo;
    }

    return lista;
}

void agregarAlaFila (Fila * fila , int dato)
{
    nodo2 * nuevo = crearNodo (dato);
    if(fila->inicio = NULL)
    {
        fila->inicio=nuevo;
        fila->fin=nuevo;
    }else
    {
        fila->inicio = agregarFinal (fila->inicio, nuevo);
        fila->fin = nuevo;
    }
}

int verPrimero (nodo2 * lista)   // si fuera una persona seria persona verprimero y retornar la persona
{
    int rta = 0;
    if (lista)   //si la lista tiene datos
    {
        rta = lista ->dato;
    }

    return rta;
}

int verPrimeroFila (Fila fila) //como vamos a mostrar y no vamos a modificar le pasamos la fila por copia
{
    int resp = -9999999;

    if(fila.inicio!=NULL)
    {
        resp = verPrimero(fila.inicio); //ver primero recibe por parametro la lista. y la lista donde esta ? en fila . inicio
    }else
    {
        puts("Fila vacia");
    }

    return resp;
}

int filaVacia (Fila fila)
{
    int resp = 0 ;

    if(fila.inicio == NULL)
    {
        resp = 1 ;
    }
    return resp;
}

nodo2 * borrarPrimero (nodo2 * lista)
{
    nodo2 * aBorrar = lista;
    if(lista!=NULL)
    {
        lista = lista->sig;
        if(lista!=NULL)
        {
            lista->ante = NULL;
        }
        free(aBorrar);
    }

    return lista;
}

int extraerElemento (Fila * fila)
{
    int resp;
    if(fila->inicio != NULL) //si la fila tiene algo ...
    {
        resp = verPrimero(fila->inicio);   //cual es ese algo ? y se guarda en respuesta .

        fila->inicio = borrarPrimero(fila->inicio);

        if(fila->inicio == NULL) //cuando sale de la funcion puede que haya eliminado el unico elemento
        {
            fila->fin=inicLista();   //el fin es null
        }
    }

    return resp;
}


