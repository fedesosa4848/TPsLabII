#ifndef LIBRERIAARREGLODEARBOLES_H_INCLUDED
#define LIBRERIAARREGLODEARBOLES_H_INCLUDED

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

int mostrarArchivoAnimales ( const char * nombreArchivo);
nodoArbol * inicializarArbol();
nodoArbol * crearNodoArbol(registroArchivo dato);
nodoArbol * insertar (nodoArbol* arbol, nodoArbol * nuevo);
void inorder (nodoArbol * arbol);
void mostrarAnimal (nodoArbol * dato);
int ingresarAnimales(const char * nombreArchivo ,celdaEspecie ADA[], int dim);
int cargarEspecie(celdaEspecie ADA[], registroArchivo nuevo,int validos);
int buscarPosEspecie (celdaEspecie ADA [],char especie [],int validos);
int agregarEspecie (celdaEspecie ADA[],char especie[],int idEspecie, int validos);




#endif // LIBRERIAARREGLODEARBOLES_H_INCLUDED
