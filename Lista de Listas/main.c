#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int nota;
    int legajo;
    char nombreApe[40];
} notaAlumno;

typedef struct _nodoNota {
    notaAlumno dato;
    struct _nodoNota *siguiente;
} nodoNota;

typedef struct {
    int idMateria;
    char materia[40];
    nodoNota *listaDeNotas; // Lista enlazada de notas para cada materia
} celda;

typedef struct _nodoMateria {
    celda dato;
    struct _nodoMateria *siguiente;
} nodoMateria;

nodoMateria *agregarMateria(nodoMateria *lista, celda nueva);
nodoNota *crearNodoNota(notaAlumno nuevo);
nodoMateria *buscarMateria(nodoMateria *lista, char materia[]);
void alta(nodoMateria **lista, notaAlumno nuevo, char materia[], int idMateria);
void cargarRegistroArchivo(nodoMateria *listaMaterias, const char *nombreArchi);

int ingresarNotas(nodoMateria **listaMaterias);
int notaValida();

// Otras funciones siguen siendo las mismas

int main() {
    nodoMateria *listaMaterias = NULL;
    const char *nombreArchi = "notasEstudiantes.bin";

    int validos = ingresarNotas(&listaMaterias);

    // Mostrar las materias y sus respectivas listas de notas
    nodoMateria *currentMateria = listaMaterias;
    while (currentMateria != NULL) {
        printf("\nMateria: %s\n", currentMateria->dato.materia);
        nodoNota *currentNota = currentMateria->dato.listaDeNotas;
        while (currentNota != NULL) {
            mostrarPersona(currentNota->dato);
            currentNota = currentNota->siguiente;
        }
        currentMateria = currentMateria->siguiente;
    }

    puts("\nCargando Archivo");
    cargarRegistroArchivo(listaMaterias, nombreArchi);

    // Liberar memoria al finalizar
    while (listaMaterias != NULL) {
        nodoMateria *temp = listaMaterias;
        listaMaterias = listaMaterias->siguiente;
        free(temp);
    }

    return 0;
}

int ingresarNotas(nodoMateria **listaMaterias) {
    notaAlumno nuevo;
    char materia[40];
    int idMateria;
    char mander = 's';
    int valid = 0;

    while (mander == 's') {
        printf("Ingresar la materia: ");
        fflush(stdin);
        scanf("%s", materia);
        printf("Ingrese el id de la materia: ");
        fflush(stdin);
        scanf("%d", &idMateria);

        nuevo = cargarDatos();

        alta(listaMaterias, nuevo, materia, idMateria);
        printf("Presione 's' para cargar más notas\n");
        mander = getch(mander);
    }

    return valid;
}

nodoNota *crearNodoNota(notaAlumno nuevo) {
    nodoNota *aux = (nodoNota *)malloc(sizeof(nodoNota));
    aux->dato = nuevo;
    aux->siguiente = NULL;
    return aux;
}

nodoMateria *agregarMateria(nodoMateria *lista, celda nueva) {
    nodoMateria *nuevoNodoMateria = (nodoMateria *)malloc(sizeof(nodoMateria));
    nuevoNodoMateria->dato = nueva;
    nuevoNodoMateria->siguiente = lista;
    return nuevoNodoMateria;
}

nodoMateria *buscarMateria(nodoMateria *lista, char materia[]) {
    nodoMateria *current = lista;
    while (current != NULL) {
        if (strcmp(current->dato.materia, materia) == 0) {
            return current;
        }
        current = current->siguiente;
    }
    return NULL;
}

void alta(nodoMateria **lista, notaAlumno nuevo, char materia[], int idMateria) {
    nodoMateria *materiaEncontrada = buscarMateria(*lista, materia);

    if (materiaEncontrada == NULL) {
        celda nuevaMateria;
        nuevaMateria.idMateria = idMateria;
        strcpy(nuevaMateria.materia, materia);
        nuevaMateria.listaDeNotas = NULL;
        materiaEncontrada = agregarMateria(*lista, nuevaMateria);
        *lista = materiaEncontrada;
    }

    nodoNota *nuevoNodoNota = crearNodoNota(nuevo);
    nuevoNodoNota->siguiente = materiaEncontrada->dato.listaDeNotas;
    materiaEncontrada->dato.listaDeNotas = nuevoNodoNota;
}

void cargarRegistroArchivo(nodoMateria *listaMaterias, const char *nombreArchi) {
    FILE *archi = fopen(nombreArchi, "wb");
    if (archi) {
        nodoMateria *currentMateria = listaMaterias;
        while (currentMateria != NULL) {
            nodoNota *currentNota = currentMateria->dato.listaDeNotas;
            while (currentNota != NULL) {
                registroArchivo nuevo;
                strcpy(nuevo.nombreApe, currentNota->dato.nombreApe);
                nuevo.legajo = currentNota->dato.legajo;
                nuevo.nota = currentNota->dato.nota;
                strcpy(nuevo.materia, currentMateria->dato.materia);
                nuevo.idMateria = currentMateria->dato.idMateria;
                fwrite(&nuevo, sizeof(registroArchivo), 1, archi);
                currentNota = currentNota->siguiente;
            }
            currentMateria = currentMateria->siguiente;
        }
        fclose(archi);
    } else {
        printf("Error al abrir el archivo.\n");
    }
}
