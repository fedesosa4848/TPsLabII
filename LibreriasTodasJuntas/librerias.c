//FUNCIONES LISTAS DOBLEMENTE ENLAZADAS

typedef struct {
     char nombre[20];
     int edad;
} persona;


typedef struct {
     persona dato;
     struct nodoDoble * anterior;
     struct nodoDoble * siguiente;
} nodoDoble;

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



//FUNCIONES LISTAS CON PUNTERO DOBLE
typedef struct{
    int dato;
    struct nodo * siguiente;
}nodo;


nodo* crearNodo(int dato) {
    nodo* aux = (nodo*)malloc(sizeof(nodo));
    aux->dato = dato;
    aux->siguiente = NULL;
    return aux;
}

void cargarLista(nodo** lista) {
    char mander = 's';
    int num;
    nodo* nuevo;

    while (mander == 's') {
        printf("Ingrese un número: ");
        scanf("%d", &num);
        nuevo = crearNodo(num);
        agregarPpio(lista, nuevo);

        printf("Elemento cargado. ¿Desea cargar más números a la lista? (S/N): ");
        fflush(stdin);
        scanf(" %c", &mander);
    }

}

void inicLista(nodo** lista) {
    *lista=NULL;
}


void mostrarLista(nodo* lista) {
    if (lista == NULL) {
        printf("La lista está vacía.\n");
    } else {
        nodo* seg = lista;
        while (seg != NULL) {
            printf("Número en la lista: %d\n", seg->dato);
            seg = seg->siguiente;
        }
    }
}


void mostrarListaRecursiva(nodo** lista) { //NO ES NECESARIA UNA SEGUIDORA PQ LA LISTA NO SE MODIFICA. Se puede trabajar con punt doble o punt Simple
    if ( * lista == NULL) {
        printf("Fin de la lista.\n");
    } else {
            printf("%d ",(*lista)->dato);
            mostrarListaRecursiva(&(*lista)->dato);
        }
}


void agregarPpio(nodo** lista, nodo* nuevoNodo) {
    if ((*lista) == NULL) {
        *lista = nuevoNodo;
    } else {
        nuevoNodo->siguiente = *lista;
        *lista = nuevoNodo;
    }
}

void agregarFinal(nodo** lista, nodo* nuevoNodo) {
    if (*lista == NULL) {
        *lista = nuevoNodo;
    } else {
        nodo* ultimo = buscarUltimo(*lista);
        ultimo->siguiente = nuevoNodo;
    }
}

void agregarEnOrden(nodo** lista, nodo* nuevoNodo) {
    if (*lista == NULL || nuevoNodo->dato < (*lista)->dato) {
        nuevoNodo->siguiente = *lista;
        *lista = nuevoNodo;
    } else {
        nodo* actual = *lista;
        while (actual->siguiente != NULL && actual->siguiente->dato < nuevoNodo->dato) {
            actual = actual->siguiente;
        }
        nuevoNodo->siguiente = actual->siguiente;
        actual->siguiente = nuevoNodo;
    }
}


nodo* buscarUltimo(nodo* lista) {
    if (lista == NULL) {
        return NULL;
    }
    while (lista->siguiente != NULL) {
        lista = lista->siguiente;
    }
    return lista;
}

void borrarNodo(nodo** lista, int dato) {
    nodo* seg = *lista;
    nodo* ante = NULL;

    while (seg != NULL && seg->dato != dato) {
        ante = seg;
        seg = seg->siguiente;
    }

    if (seg != NULL) {
        if (ante == NULL) {
            *lista = seg->siguiente;
        } else {
            ante->siguiente = seg->siguiente;
        }
        free(seg);
    }
}

nodo* buscarNodo(nodo* lista, int dato) {
    nodo* actual = lista;
    while (actual != NULL) {
        if (actual->dato == dato) {
            return actual; // Se encontró el nodo con el valor deseado
        }
        actual = actual->siguiente;
    }
    return NULL; // El nodo no se encontró en la lista
}


//FUNCIONES LISTAS SIMPLES
typedef struct{
    int dato;
    struct nodo * siguiente;
}nodo;


nodo * inicLista()
{
    return NULL;
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

    char mander = 's';
    int num;
    nodo * nuevo;

    while(mander == 's')
    {
        nuevo = crearNodo(num);
        lista = agregarPpio(lista, nuevo);


        printf("Elemento cargado, Desea cargar mas Numeros a la lista ?(S/N)");
        fflush(stdin);
        scanf("%c",&mander);
    }

    return lista;
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

nodo * buscarUltimo ( nodo * lista){

    nodo * ultimo;
    if(lista == NULL)
    {
        return NULL;
    }else{
        ultimo=lista;
        while(ultimo->siguiente !=NULL)
        {
            ultimo = ultimo->siguiente;
        }
        return ultimo;
    }
}

nodo * agregarFinal(nodo * lista, nodo * nuevoNodo) {


   if(lista == NULL) {
      lista = nuevoNodo;
   } else {
      nodo * ultimo = buscarUltimo(lista);
      ultimo->siguiente = nuevoNodo;
   }
   return lista;
}

nodo * borrarNodo(nodo * lista, char nombre[20]) {
   nodo * seg;
   nodo * ante; //apunta al nodo anterior que seg.
   if((lista != NULL) && (strcmp(nombre, lista->dato.nombre)==0 )) {

      nodo * aux = lista;
      lista = lista->siguiente; //salteo el primer nodo.
      free(aux);                //elimino el primer nodo.
   }else {
      seg = lista;
      while((seg != NULL) && (strcmp(nombre, seg->dato.nombre)!=0 )) {
         ante = seg;           //adelanto una posición la variable ante.
         seg = seg->siguiente; //avanzo al siguiente nodo.
      }
      //en este punto tengo en la variable ante la dirección de
      //memoria del nodo anterior al buscado, y en la variable seg,
      //la dirección de memoria del nodo que quiero borrar.
      if(seg!=NULL) {
         ante->siguiente = seg->siguiente;
         //salteo el nodo que quiero eliminar.
         free(seg);
         //elimino el nodo.
      }
   }
   return lista;
}

// Función para insertar un nodo en la lista ordenadamente
void insertarOrdenado(nodo** lista, int nuevoValor) {
    nodo* nuevoNodo = crearNodo(nuevoValor); // Creo un nuevo nodo y le asigno el nuevo valor

    if (*lista == NULL || nuevoValor < (*lista)->dato) { // Verifico si la lista está vacía o si el nuevo valor es el menor en la lista
        // Si es el caso, el nuevo nodo se convierte en la nueva cabeza
        nuevoNodo->siguiente = *lista; // El siguiente del nuevo nodo apunta a la antigua cabeza
        *lista= nuevoNodo; // Actualizamos el puntero de cabeza para que apunte al nuevo nodo

    } else {
            // Si no es el caso, recorremos la lista para encontrar la ubicación correcta
        nodo* actual = *lista;
        while (actual->siguiente != NULL && actual->siguiente->dato < nuevoValor) { // Avanzamos en la lista mientras el siguiente nodo no sea nulo y su valor sea menor que el nuevo valor
            actual = actual->siguiente;
        }

        // Insertamos el nuevo nodo entre 'actual' y 'actual->siguiente'
        nuevoNodo->siguiente = actual->siguiente; // El siguiente del nuevo nodo apunta al siguiente del 'actual'
        actual->siguiente = nuevoNodo; // El siguiente del 'actual' apunta al nuevo nodo
    }
}


// Función para imprimir la lista
void imprimirLista(nodo* lista) {
    nodo* actual = lista;
    while (actual != NULL) {
        printf("%d ", actual->dato);
        actual = actual->siguiente;
    }
    printf("\n");
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


nodo * agregarEnOrden(nodo * lista, nodo * nuevoNodo) {
   // agrega un nuevo nodo a la lista manteniendo el orden.

   //si la lista está vacía agrego el primer elemento.
   if(lista == NULL) {
      lista = nuevoNodo;
   }else {
      //si el nuevo elemento es menor que el primero de la lista,
      //agrego al principio

      if(nuevoNodo->dato < lista->dato){
         lista = agregarPpio(lista, nuevoNodo);
      } else {
         //busco el lugar en donde insertar el nuevo elemento.
         //necesito mantener la dirección de memoria del nodo anterior
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
    nodo* lista_resultado = inicLista(); // Creamos una lista vacía para almacenar el resultado intercalado
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

    *lista = anterior; // Actualizamos el puntero de la lista para que apunte al último nodo (nuevo inicio)
}

//ARREGLO DINAMICO
int dim;

    printf("Ingrese la dimension del arreglo: ");
    scanf("%d", &dim);

    int *arregloDinamico = (int *)malloc(dim * sizeof(int));
    cargarArregloDinamico(arregloDinamico, dim);
    mostrarArr(arregloDinamico, dim);
    free(arregloDinamico);
    puts("\n");

    arregloDinamico = redimensionarArreglo(arregloDinamico, 20);
    printf("Nuevo tamaño del arreglo: %d\n", 20);

    free(arregloDinamico);


void cargarArregloDinamico(int *puntArr, int dim)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        puntArr[i] = i;
    }
}

void mostrarArr(int puntArr[], int dim)
{
    int i;
    for (i = 0; i < dim; i++)
    {
        printf("%d, ", puntArr[i]);
    }
}

int *redimensionarArreglo(int *arr, int dim)
{
    arr = realloc(arr, dim * sizeof(int));

    if (arr == NULL)
    {
        printf("Error al redimensionar el arreglo dinámico\n");
        exit(1);
    }

    return arr;
}


//TDA PILA ARREGLO DINAMICO
typedef struct {
    int *valores;
    int posTope;
} Pila;


void inicPila(Pila *p)
{
    /** Opcion 1 */
    ///creamos un arreglo dinamico
    int * arrDinam = (int * ) malloc (sizeof(int)*100);  //basicamente la ventaja de crear un arreglo dinamico es que la dimension
    ///y decimos que valores va a ser el arreglo dinamico
    p->valores= arrDinam;                               //la podemos ir manejando en tiempo de ejecucion. en este caso el irrelevante pero en caso
                                                        //de contar elementos e ir ubicandolo en un arreglo nuevo ahi si sirve pq nos "olvidamos"
                                                        //de ir controlando la dimension de ese nuevo arreglo
    /** Opcion 2 /

    p->valores= (int * ) malloc (sizeof(int)*100); */
    ///son los validos
    p->posTope = 0;
}

void apilar(Pila *p, int valor)  ///recibe por parametros la "Pila" y el dato a apilar
{
    if (p->posTope < 100) { ///va a pilar mientras los "validos" sean menores a 100
        p->valores[p->posTope] = valor; ///como es un arreglo accedo a valores[postope] que son los validos
        p->posTope++; /// y modifico los validos
    } else {
        printf("La pila esta llena, no se puede apilar mas elementos.\n");
    }
}

int desapilar(Pila *p)
{
    if (p->posTope > 0) ///aca ocurre lo mismo que apilar, tengo que verificar que la pila no este vacia y en caso
    {                       ///que no este llena quitamos el ultimo valido y por ende borramos el ultimo dato apilado
        p->posTope--;
        return p->valores[p->posTope];
    }
    else
    {
        printf("La pila esta vacia, no se puede desapilar mas elementos.\n");
        return -1; // Para indicar error
    }
}

int tope(Pila *p)
{
    if (p->posTope > 0)
    {
        return p->valores[p->posTope - 1];
    }
    else
    {
        printf("La pila está vacia, no hay elementos en el tope.\n");
        return -1; // Para indicar error
    }
}

int pilavacia(Pila *p)
{
    return p->posTope == 0;
}

void mostrar(Pila *p)
{
    printf("Contenido de la pila:\n");
    for (int i = p->posTope - 1; i >= 0; i--)
    {
        printf("%d\n", p->valores[i]);
    }
}

void leer(Pila *p)
{
    int valor;
    printf("Introduce un valor para apilar: ");
    scanf("%d", &valor);
    apilar(p, valor);
}

void combinarPilasOrdenadas(Pila *pila1, Pila *pila2, Pila *pilaResultado)
{
    inicPila(pilaResultado);

    while (!pilavacia(pila1) && !pilavacia(pila2))
    {
        if (tope(pila1) > tope(pila2))
        {
            apilar(pilaResultado, desapilar(pila1));
        }
        else
        {
            apilar(pilaResultado, desapilar(pila2));
        }
    }

    while (!pilavacia(pila1))
    {
        apilar(pilaResultado, desapilar(pila1));
    }

    while (!pilavacia(pila2))
    {
        apilar(pilaResultado, desapilar(pila2));
    }
}

/**recordar hacer el free luego de usar la pila*/




//TDA PILAS ARREGLO ESTATICO
typedef struct{
     int valores[100];
     int posTope; //posición de nuevo tope, lugar en donde se almacenará el nuevo valor
} Pila;

void apilar(Pila *p, int valor)
{
    if (p->posTope < 100) {
        p->valores[p->posTope] = valor;
        p->posTope++;
    } else {
        printf("La pila esta llena, no se puede apilar mas elementos.\n");
    }
}

int desapilar(Pila *p)
{
    if (p->posTope > 0)
    {
        p->posTope--;
        return p->valores[p->posTope];
    } else
    {
        printf("La pila esta vacia, no se puede desapilar mas elementos.\n");
        return -1; // Para indicar error
    }
}

int tope(Pila *p)
{
    if (p->posTope > 0)
    {
        return p->valores[p->posTope - 1];
    } else
    {
        printf("La pila está vacia, no hay elementos en el tope.\n");
        return -1; // Para indicar error
    }
}

int pilavacia(Pila *p)
{
    return p->posTope == 0;
}

void mostrar(Pila *p)
{
    printf("Contenido de la pila:\n");
    for (int i = p->posTope - 1; i >= 0; i--)
    {
        printf("%d\n", p->valores[i]);
    }
}

void leer(Pila *p)
{
    int valor;
    printf("Introduce un valor para apilar: ");
    scanf("%d", &valor);
    apilar(p, valor);
}

void inicPila(Pila *p)
{
    p->posTope = 0;
}

void combinarPilasOrdenadas(Pila *pila1, Pila *pila2, Pila *pilaResultado)
{
    inicPila(pilaResultado);

    while (!pilavacia(pila1) && !pilavacia(pila2)) {
        if (tope(pila1) > tope(pila2)) {
            apilar(pilaResultado, desapilar(pila1));
        } else {
            apilar(pilaResultado, desapilar(pila2));
        }
    }

    while (!pilavacia(pila1)) {
        apilar(pilaResultado, desapilar(pila1));
    }

    while (!pilavacia(pila2)) {
        apilar(pilaResultado, desapilar(pila2));
    }
}




//TDA PILAS ( LISTAS SIMPLES)

// Definición de la estructura del nodo de la lista enlazada simple
typedef struct Nodo {
    int dato;           // El dato almacenado en el nodo
    struct Nodo* siguiente; // Puntero al siguiente nodo
}Nodo;

// Definición de la estructura de la pila
typedef struct Pila {
    struct Nodo* tope; // Puntero al nodo en la parte superior de la pila
}Pila;

// Función para crear una nueva pila vacía
Pila* crearPila() {
    struct Pila* pila = (Pila*)malloc(sizeof(Pila)); // Asigna memoria para la pila
    if (!pila) { // Verifica si la asignación de memoria fue exitosa
        perror("Error al crear la pila"); // Imprime un mensaje de error en caso de falla
        exit(EXIT_FAILURE); // Termina el programa con un estado de error
    }
    pila->tope = NULL; // Inicializa el tope de la pila como NULL (pila vacía)
    return pila; // Retorna un puntero a la pila creada
}

// Función para verificar si la pila está vacía
int estaVacia(Pila* pila) {
    return pila->tope == NULL; // Comprueba si el puntero al tope de la pila es NULL
}

// Función para apilar un elemento en la pila
void empujar(Pila* pila, int dato) {
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo)); // Crea un nuevo nodo
    if (!nuevoNodo) { // Verifica si la asignación de memoria fue exitosa
        perror("Error al empujar un elemento en la pila"); // Imprime un mensaje de error en caso de falla
        exit(EXIT_FAILURE); // Termina el programa con un estado de error
    }
    nuevoNodo->dato = dato; // Almacena el dato en el nuevo nodo
    nuevoNodo->siguiente = pila->tope; // El nuevo nodo apunta al antiguo tope de la pila
    pila->tope = nuevoNodo; // Actualiza el tope de la pila al nuevo nodo
}

// Función para sacar un elemento de la pila
int sacar(Pila* pila) {
    if (estaVacia(pila)) { // Verifica si la pila está vacía
        printf("La pila está vacía\n"); // Imprime un mensaje de error
        exit(EXIT_FAILURE); // Termina el programa con un estado de error
    }
    Nodo* temp = pila->tope; // Almacena el puntero al nodo en el tope de la pila en una variable temporal
    int dato = temp->dato; // Almacena el dato del nodo en una variable
    pila->tope = temp->siguiente; // Actualiza el tope de la pila al siguiente nodo
    free(temp); // Libera la memoria del nodo eliminado
    return dato; // Retorna el dato eliminado de la pila
}

// Función para obtener el elemento superior de la pila sin eliminarlo
int consultarTope(Pila* pila) {
    if (estaVacia(pila)) { // Verifica si la pila está vacía
        printf("La pila está vacía\n"); // Imprime un mensaje de error
        exit(EXIT_FAILURE); // Termina el programa con un estado de error
    }
    return pila->tope->dato; // Retorna el dato en el tope de la pila sin eliminarlo
}

void mostrarPila(Pila* pila) {
    Pila aux; // Crear una pila auxiliar para invertir temporalmente los elementos
    aux.tope = NULL; // Inicializar la pila auxiliar

    // Invertir los elementos de la pila original en la pila auxiliar
    while (!estaVacia(pila)) {
        int elemento = sacar(pila); // Sacar de la pila original
        empujar(&aux, elemento); // Empujar en la pila auxiliar
    }

    printf("\n Base....");

    // Mostrar los elementos de la pila auxiliar (que originalmente estaban en la pila)
    while (!estaVacia(&aux)) {
        int elemento = sacar(&aux); // Sacar de la pila auxiliar
        printf(" |%d| ", elemento); // Mostrar el elemento
        empujar(pila, elemento); // Empujar el elemento nuevamente en la pila original
    }

    printf(".....Tope\n");
}

void sacar_v2(Pila* pila) {
    if (estaVacia(pila)) { // Verifica si la pila está vacía
        printf("La pila está vacía\n"); // Imprime un mensaje de error
        exit(EXIT_FAILURE); // Termina el programa con un estado de error
    }
    Nodo* temp = pila->tope; // Almacena el puntero al nodo en el tope de la pila en una variable temporal
    pila->tope = temp->siguiente; // Actualiza el tope de la pila al siguiente nodo
    free(temp); // Libera la memoria del nodo eliminado
}



