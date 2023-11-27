#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// Declaro estrucutras
typedef struct
{
    int dia;
    int mes;
    int anio;
} fecha;

typedef struct
{
    char nombre[30];
    long int telefono;
} proveedor;

typedef struct
{
    char nombreProducto[30];
    float precioUnitario;
    int ventasMensuales[12];
    proveedor proveedorProd;
    fecha fechaProd;
} producto;

void modificarPrecio(producto prod, float *precio);
void modificarPrecio(producto prod, float *precio)
{
    float nuevoP;
    printf("Cambiar precio de: %s \n", prod.nombreProducto);
    printf("PRECIO ACTUAL: $%2.f \n", prod.precioUnitario);
    printf("Ingrese el nuevo precio: $");
    scanf("%f", &nuevoP);
    *precio = nuevoP;
    printf("PRECIO NUEVO: $%2.f \n", *precio);
}

void cargarDatos(int cantProd, producto *prod[]);
void cargarDatos(int cantProd, producto *prod[])
{
    for (int i = 0; i < cantProd; i++)
    {
        int opcion = 0;
        printf("Ingrese el nombre del %d producto:\n", i+1);
        fflush(stdin);
        gets(prod[i]->nombreProducto);
        printf("Ingrese el precio del producto: %s \n", prod[i]->nombreProducto);
        scanf("%f", &prod[i]->precioUnitario);
        printf("Desea modificar el precio?\n");
        printf("1. SI\n2. NO\n");
        scanf("%d", &opcion);
        if (opcion == 1)
        {
            modificarPrecio(*prod[i], &prod[i]->precioUnitario);
        }
        printf("Dia de inicio de ventas del producto: \n");
        scanf("%d", &prod[i]->fechaProd.dia);
        printf("Mes de inicio de ventas del producto: \n");
        scanf("%d", &prod[i]->fechaProd.mes);
        printf("Año de inicio de ventas del producto: \n");
        scanf("%d", &prod[i]->fechaProd.anio);
        for (int i = 0; i < 12 - prod[i]->fechaProd.mes; i++)
        {
            printf("Ingrese la cantidad de ventas del %i mes:\n", i + 1);
            scanf("%d", &prod[i]->ventasMensuales[i]);
        }
        printf("Ingrese el nombre del proveedor: \n");
        fflush(stdin);
        gets(prod[i]->proveedorProd.nombre);
        printf("Ingrese el telefono del proveedor: \n");
        scanf("%ld", &prod[i]->proveedorProd.telefono);
    }
}

float montoTotalVentas(producto prod);
float montoTotalVentas(producto prod)
{
    float total = 0;
    for (int i = 0; i < 12 - prod.fechaProd.mes; i++)
    {
        total = total + prod.ventasMensuales[i] * prod.precioUnitario;
    }
    return total;
}

void mostrarProd(producto prod);
void mostrarProd(producto prod)
{
    float total;
    printf("\n === MUESTRA DEL PRODUCTO === \n");
    printf("NOMBRE PRODUCTO: %s \n", prod.nombreProducto);
    printf("PRECIO UNITARIO: $%2.f \n", prod.precioUnitario);
    printf("CANT.VENTAS MENSUALES: ");
    for (int i = 0; i < 12 - prod.fechaProd.mes; i++)
    {
        printf("%d-", prod.ventasMensuales[i]);
    }
    printf("\nNOMBRE DEL PROVEEDOR: %s \n", prod.proveedorProd.nombre);
    printf("TEL. DEL PROVEEDOR: %ld \n", prod.proveedorProd.telefono);
    printf("FECHA DE INICIO: %d/%d/%d \n", prod.fechaProd.dia, prod.fechaProd.mes, prod.fechaProd.anio);
    total = montoTotalVentas(prod);
    printf("MONTO TOTAL VENTAS: $%2.f \n", total);
}

void mostrarTodosLosProd(int cant, producto catalogo[]);
void mostrarTodosLosProd(int cant, producto catalogo[])
{
    for (int i = 0; i < cant; i++)
    {
        mostrarProd(catalogo[i]);
    }
}

int main()
{
    int cantProd = 0;
    // Ingreso la cantidad de prod a cargar
    printf("Ingrese la cantidad de productos a cargar: \n");
    scanf("%d", &cantProd);
    // Declaro arreglo catalogo
    producto *catalogo = (producto *)malloc(cantProd * sizeof(producto));
    // Cargo los productos
    cargarDatos(cantProd, &catalogo);
    //mostrarTodosLosProd(cantProd, catalogo);
    free(catalogo);
    return 0;
}