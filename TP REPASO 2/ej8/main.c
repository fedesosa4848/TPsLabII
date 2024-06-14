#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct
{
    int matricula;
    char nombre[30];
} Alumno;

typedef struct
{
    int codigo;
    char nombreMat[20];
} Materia ;

typedef struct
{
    int matricula;
    int codigo;
    int nota;
} Nota;


int cargarMaterias (Materia m[],int dim);
int agregarAlumno(Alumno a[],int dim);
int pedirNotaValida();
int agregarNota(Nota nota[], Alumno a[], Materia m[], int dim, int dim2, int dim3);
void mostrarNotasPorAlumno(char nombreAlumno[], Alumno a[], Materia m[], Nota nota[], int dimAlumnos, int dimMaterias, int dimNotas);

int main()
{
    Alumno alus[2]; // para almacenar los datos de los 20 alumnos.
    Materia mats[2]; // para almacenar los códigos y nombres de las 5 materias.
    Nota notas[100]; // para almacenar todas las notas de los alumnos.

    int valid= cargarMaterias (mats,5);
    int valid2 = agregarAlumno(alus,20);

    int agregada = agregarNota(notas,alus,mats,valid2,valid,100);

    if(agregada == 1)
    {
        puts("Notas cargadas con exito");
    }else
    {
        puts("No se pudo cargar Notas");
    }

    char nombreAlumno[30];
    printf("Ingrese el nombre del alumno para mostrar sus notas: ");
    fflush(stdin);
    gets(nombreAlumno);

    mostrarNotasPorAlumno(nombreAlumno, alus, mats, notas, valid2, valid, agregada);

    return 0;
}

int cargarMaterias (Materia m[],int dim)
{
    char mander = 's';
    int i=0;

    while(mander == 's' && i<dim)
    {
        printf("Codigo de la materia: ");
        fflush(stdin);
        scanf("%d",&m[i].codigo);

        printf("\nNombre de la materia : ");
        fflush(stdin);
        gets(m[i].nombreMat);

        i++;

        printf("\nDesea ... MATERIAS ?");
        fflush(stdin);
        scanf("%c",&mander);

        puts("\n");
    }

    return i;
}

int agregarAlumno(Alumno a[], int dim)
{
    int i=0;
    char mander= 's';

    while(i<dim && mander == 's')
    {
        printf("Nombre del alumno:");
        fflush(stdin);
        gets(a[i].nombre);

        printf("\nMatricula:");
        scanf("%d",&a[i].matricula);

        i++;

        puts("\n");

        puts("Seguir ?");
        fflush(stdin);
        scanf("%c",&mander);

    }

    return i;
}

int pedirNotaValida()
{
    int nota;
    do {
        printf("\nIngresa una calificion valida (1-10): ");
        scanf("%d", &nota);
    } while (nota < 1 || nota > 10);

    return nota;
}

int agregarNota(Nota nota[], Alumno a[], Materia m[], int dim, int dim2, int dim3)
{
    int matricula, codigo;

    printf("Ingrese la matricula del alumno: ");
    scanf("%d", &matricula);

    printf("Ingrese el codigo de la materia: ");
    scanf("%d", &codigo);

    int alumnoEncontrado = 0, materiaEncontrada = 0;

    for (int i = 0; i < dim; i++)
    {
        if (a[i].matricula == matricula)
        {
            alumnoEncontrado = 1;
            break;
        }
    }

    for (int i = 0; i < dim2; i++)
    {
        if (m[i].codigo == codigo)
        {
            materiaEncontrada = 1;
            break;
        }
    }

    if (alumnoEncontrado && materiaEncontrada)
    {
        int calificacion = pedirNotaValida();

        for (int i = 0; i < dim3; i++)
        {
            if (nota[i].matricula == 0 && nota[i].codigo == 0)
            {
                nota[i].matricula = matricula;
                nota[i].codigo = codigo;
                nota[i].nota = calificacion;
                return 1; // Operación exitosa
            }
        }
    }

    return 0; // Operación fallida
}

void mostrarNotasPorAlumno(char nombreAlumno[], Alumno a[], Materia m[], Nota nota[], int dimAlumnos, int dimMaterias, int dimNotas)
{
    int matriculaAlumno = -1;

    // Buscar la matrícula del alumno por su nombre
    for (int i = 0; i < dimAlumnos; i++)
    {
        if (strcmp(nombreAlumno, a[i].nombre) == 0)
        {
            matriculaAlumno = a[i].matricula;
            break;
        }
    }

    if (matriculaAlumno != -1)
    {
        printf("Notas de %s:\n", nombreAlumno);

        for (int i = 0; i < dimNotas; i++)
        {
            if (nota[i].matricula == matriculaAlumno)
            {
                for (int j = 0; j < dimMaterias; j++)
                {
                    if (m[j].codigo == nota[i].codigo)
                    {
                        printf("Materia: %s\tNota: %d\n", m[j].nombreMat, nota[i].nota);
                        break;
                    }
                }
            }
        }
    }
    else
    {
        printf("Alumno no encontrado.\n");
    }
}


