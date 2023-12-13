//Sembrando Aire

#include <stdio.h>
#include <ctype.h>


//________________ Declaracion de estructuras _________________

typedef struct{
    char nombreCientifico[15];
    char categoria[15];
    char nombreVulgar[15];
}DatosEspecie;

typedef struct{
    char razonSocial[15];
    long int telefono;
}DatosCliente;

typedef struct{
    char apellidoEmpleado[15];
    char nombreEmpleado[15];
}DatosEmpleado;

typedef struct{
    DatosCliente datosCliente;
    DatosEmpleado datosEmpleado;
    int cantidad;
}DatosPedido;

typedef struct{
    DatosEspecie especie;
    int stock;
    float precio;
    int cantPedidos;
    DatosPedido *pedido;
}DatosArbol;

//_____________________________________________________________

//_______________ Declaracion de funciones ____________________

void mostrarMenu();
void mostrarMenu(){
    printf("______ Menu ______\n");
    printf("\n");
    printf("01. Mostrar todos los arboles/especies disponibles\n");
    printf("02. Mostrar arboles/especies segun stock\n");
    printf("03. Mostrar todos los pedidos\n");
    printf("04. Agregar pedidos a una especie\n");
    printf("05. Actualizar stock de una especie\n");
    printf("06. Actualizar el precio de una especie\n");
    printf("07. Salir\n"); 
    printf("_____________________\n");
}

void mostrarTodosLosArboles(DatosArbol *arbolito, int cant);
void mostrarTodosLosArboles(DatosArbol *arbolito, int cant){    
    printf("______ Lista de arboles ______\n");
    printf("\n");
    for (int i = 0; i < cant; i++)
    {
        printf("__ Arbol: %d __\n", i+1);
        printf("\n");
        printf("Nombre cientifico: %s\n", arbolito[i].especie.nombreCientifico);
        printf("Categoria: %s\n", arbolito[i].especie.categoria);
        printf("Nombre vulgar: %s\n", arbolito[i].especie.nombreVulgar);
        printf("Stock: %d\n", arbolito[i].stock);
        printf("Precio: %2.f\n", arbolito[i].precio);
        printf("____________________________\n");
        printf("\n");
    }
    printf("____________________________\n");
}

//_____________________________________________________________

//_________________ Funcion principal _________________________

int main(){
    //mostrarMenu();
    DatosArbol arboles[] = {
        {
            {"Catalpa", "Caduca", "Arce Rojo"},
            8,
            65000,
            3,
            NULL
        },
        {
            {"Betula", "Perenne", "Olivo"},
            9,
            80000,
            7,
            NULL
        },
        {
            {"Tilia", "Conifera", "Abeto"},
            3,
            45000,
            6,
            NULL
        }
    };
    DatosArbol *listaArboles;
    listaArboles = arboles;
    mostrarTodosLosArboles(listaArboles, 3);
    return 0;
}