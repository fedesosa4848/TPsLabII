#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int ingresarNotas(celda ArrDeList[], int dim);
int notaValida ();
nodo * crearNodo (notaAlumno nuevo);
int alta (celda ArrDeLista [],notaAlumno nuevo,char materia[],int idMateria,int validos);
nodo * inicLista ();
int agregarMateria (celda ArrDeLis[],char materia[],int idMateria, int validos);
int buscarPosMateria (celda ArrDeLista [],char materia [],int validos);
nodo * agregarPpio (nodo * lista, nodo * nuevo);
void cargarRegistroArchivo (celda ArrDeList [],int valid,const char * nombreArchi);
void cargarNotasAprobadas(celda ArrDeList[], int valid, const char *nombreArchi, const char *nombreArchiAprobadas);
void mostrarPersona(notaAlumno aux);
void mostrarLista(nodo * lista);

const char * nombreArchi = "notasEstudiantes.bin";
const char * nombreArchi2 = "notas.Aprobadas";

int main()
{
    celda ArregloDeNotas [20];

    int validos = ingresarNotas(ArregloDeNotas,20);

    for(int i = 0 ; i < validos; i++)
    {
        printf("\nMateria : %s\n ",ArregloDeNotas[i].materia);
        printf("ID Materia : %d ",ArregloDeNotas[i].idMateria);

        mostrarLista(ArregloDeNotas[i].listaDeNotas);

    }

    puts("\nCargando Archivo");

    cargarRegistroArchivo(ArregloDeNotas,validos,nombreArchi);

    return 0;
}

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

