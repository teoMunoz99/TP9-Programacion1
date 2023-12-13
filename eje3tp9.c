// Sembrando Aire

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

//________________ Declaracion de estructuras _________________

typedef struct {
    char nombreCientifico[15];
    char categoria[15];
    char nombreVulgar[15];
} DatosEspecie;

typedef struct {
    char razonSocial[15];
    long int telefono;
} DatosCliente;

typedef struct {
    char apellidoEmpleado[15];
    char nombreEmpleado[15];
} DatosEmpleado;

typedef struct {
    DatosCliente datosCliente;
    DatosEmpleado datosEmpleado;
    int cantidad;
} DatosPedido;

typedef struct {
    DatosEspecie especie;
    int stock;
    float precio;
    int cantPedidos;
    DatosPedido *pedido;
} DatosArbol;

//_____________________________________________________________

//_______________ Declaracion de funciones ____________________

void mostrarMenu();
void mostrarMenu() {
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
void mostrarTodosLosArboles(DatosArbol *arbolito, int cant) {
    printf("______ Lista de arboles ______\n");
    printf("\n");
    for (int i = 0; i < cant; i++) {
        printf("__ Arbol: %d __\n", i + 1);
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

void mostrarSegunStock(DatosArbol *arbolito, int stock, int cant);
void mostrarSegunStock(DatosArbol *arbolito, int stock, int cant) {
    for (int i = 0; i < cant; i++) {
        if (arbolito[i].stock < stock) {
            mostrarTodosLosArboles(arbolito, 1);
        }
    }
}

void mostrarTodosLosPedidos(DatosArbol *arbolito, int cant);
void mostrarTodosLosPedidos(DatosArbol *arbolito, int cant) {
    for (int i = 0; i < cant; i++) {
        for (int j = 0; j < arbolito[i].cantPedidos; j++) {
            float montoTotal = arbolito[i].cantPedidos * arbolito[i].precio;
            printf("_______________\n");
            printf("\n");
            printf("Razon social: %s\n", arbolito[i].pedido[j].datosCliente.razonSocial);
            printf("Telefono: %d\n", arbolito[i].pedido[j].datosCliente.telefono);
            printf("Cantidad de pedidos: %ld\n", arbolito[i].cantPedidos);
            printf("Total a pagar: $%2.f\n", montoTotal);
            printf("_______________\n");
        }
    }
}

//_____________________________________________________________

//_________________ Funcion principal _________________________

int main() {
    // mostrarMenu();
    DatosArbol arboles[] = {
        {{"Catalpa", "Caduca", "Arce Rojo"},
         8,
         65000,
         0,
         NULL},
        {{"Betula", "Perenne", "Olivo"},
         9,
         80000,
         0,
         NULL},
        {{"Tilia", "Conifera", "Abeto"},
         3,
         45000,
         0,
         NULL}};
    DatosArbol *listaArboles;
    listaArboles = arboles;
    mostrarTodosLosPedidos(listaArboles, 3);
    // Asigno el tamaño en funcion de la cant de clientes que hayan realizado pedidos.
    /*for (int i = 0; i < 3; i++) {
        listaArboles[i].pedido = (DatosPedido *)malloc(sizeof(DatosPedido) * listaArboles[i].cantPedidos);

        for (int j = 0; j < listaArboles[i].cantPedidos; j++)
        {


        }

    }*/

    // mostrarTodosLosArboles(listaArboles, 3);
    // mostrarSegunStock(listaArboles,5,3);
    return 0;
}