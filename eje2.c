#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nombre[15];
    char apellido[15];
} Datos;

typedef struct
{
    int dia;
    int mes;
    int anio;
} Fecha;

typedef struct
{
    char nombre[15];
    char destinatario[15]; // Alumnos,Docentes/Directivos
    char nivel[4];          // Inicial,Primario,Secundario,Superior
    char cursos[15];
    char area[15]; // Lengua, Matemática, Ciencias Naturales, Ciencias Sociales,Robótica, Teatro, Música, etc.
    char descripcion[15];
    Datos datosControl;
    Fecha fechaControl;
    char estado[15];
} Planilla;

void cargarPlanilla(Planilla *planilla);
void cargarPlanilla(Planilla *planilla)
{
    int aux;
    // Nombre articulo
    printf("Ingrese el nombre del articulo: ");
    gets(planilla->nombre);
    printf("\n");
    // Destinatarios
    printf("Ingrese el destinatario (Alumnos/Docentes/Directivos): ");
    gets(planilla->destinatario);
    printf("\n");
    // Nivel
    printf("Ingrese el nivel (1. Inicial/2. Primario/3. Secundario/4. Superior): ");
    gets(planilla->nivel);
    printf("\n");
    // Cursos
    printf("Elija un ciclo (1. Primer ciclo/2. Segundo ciclo)");
    scanf("%d", &aux);
    printf("\n");
    switch (aux)
    {
    case 1:
        strcpy(planilla->cursos, "1° 2° 3°");
        break;
    case 2:
        strcpy(planilla->cursos, "4° 5° 6°");
        break;
    default:
        strcpy(planilla->cursos, "No especificado");
        break;
    }
    //area
    printf("Ingrese el area del articulo (Lengua/ Matemática/ Ciencias Naturales/ etc): ");
    gets(planilla->area);
    printf("\n");
    //descripcion
    printf("Ingrese una descripcion del articulo: ");
    gets(planilla->descripcion);
    printf("\n");
    //datos control
    printf("Nombre de quien controla: ");
    gets(planilla->datosControl.nombre);
    printf("\n");
    printf("Apellido de quien controla: ");
    gets(planilla->datosControl.apellido);
    printf("\n");
    //fecha
    printf("Dia de control: ");
    scanf("%d", &planilla->fechaControl.dia);
    printf("\n");
    printf("Mes de control: ");
    scanf("%d", &planilla->fechaControl.mes);
    printf("\n");
    printf("Anio de control: ");
    scanf("%d", &planilla->fechaControl.anio);
    printf("\n");
    //Estado
    printf("Estado (Cargado/ controlado/ publicado): ");
    gets(planilla->estado);
    printf("\n");
}

void mostrarPlanilla(Planilla *planilla);
void mostrarPlanilla(Planilla *planilla){
    printf("=== DATOS PLANILLA ===\n");
    printf("Nombre: %s \n",planilla->nombre);
    printf("Destinatario: %s \n",planilla->destinatario);
    printf("Nivel: %s \n",planilla->nivel);
    printf("Cursos: %s \n",planilla->cursos);
    printf("Area: %s \n",planilla->area);
    printf("Descripcion: %s \n",planilla->descripcion);
    printf("Nombre Controlador: %s %s \n",planilla->datosControl.apellido, planilla->datosControl.nombre);
    printf("Fecha: %d/%d/%d \n", planilla->fechaControl.dia, planilla->fechaControl.mes, planilla->fechaControl.anio);
    printf("Estado: %s \n",planilla->estado);
}

int main(){
    Planilla planillita;
    cargarPlanilla(&planillita);
    mostrarPlanilla(&planillita);
    return 0;
}