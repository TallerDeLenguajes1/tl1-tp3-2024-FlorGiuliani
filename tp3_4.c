/*4) Considere la siguiente situación: En una distribuidora necesita implementar la carga de productos de sus preventistas, los cuales recolectan los productos que sus clientes van necesitando. El sistema que se utiliza en la empresa es desarrollado por equipos de programadores donde cada equipo se encarga de una tarea específica. Usted forma parte del equipo de programación que se encargará de hacer el módulo para los preventistas:

Tareas:
Cada preventista puede visitar hasta 5 clientes, los cuales por cuestiones operativas solo puede pedir hasta 10 productos

Las estructuras de datos necesarias son las siguientes:
    char *TiposProductos[]={“Galletas”,”Snack”,”Cigarrillos”,”Caramelos”,”Bebidas”};
    struct Producto {
        int ProductoID; //Numerado en ciclo iterativo
        int Cantidad; // entre 1 y 10
        char *TipoProducto; // Algún valor del arreglo TiposProductos
        float PrecioUnitario; // entre 10 - 100
    };
    struct Cliente {
        int ClienteID; // Numerado en el ciclo iterativo
        char *NombreCliente; // Ingresado por usuario
        int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
        Producto *Productos //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
    };

i) Desarrollar una interfaz por consola donde se solicite al usuario la cantidad de clientes.
ii) Solicitar al usuario la carga de los clientes creados dinámicamente en el paso anterior.
iii) A medida que se dé de alta cada cliente, Generar aleatoriamente la cantidad de productos asociados al cliente y sus características.
    Ej: producto cargado nro. 2
        Producto {
            ProductoID=2
            Cantidad = 1;
            *TipoProducto = “Snack”;
            PrecioUnitario = 100;
        }
iv) Implemente una función que calcule el costo total de un producto. Esta función debe recibir como parámetro el producto y devolver el resultado de calcular la Cantidad por el PrecioUnitario.
v) Mostrar por pantalla todo lo cargado. Incluyendo un total a pagar por cliente (sumatoria del costo de todos los productos) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Producto {
    int ProductoID; //Numerado en ciclo iterativo
    int Cantidad; // entre 1 y 10
    char *TipoProducto; // Algún valor del arreglo TiposProductos
    float PrecioUnitario; // entre 10 - 100
} Producto; 

struct Cliente {
    int ClienteID; // Numerado en el ciclo iterativo
    char *NombreCliente; // Ingresado por usuario
    int CantidadProductosAPedir; // (aleatorio entre 1 y 5)
    Producto *Productos; //El tamaño de este arreglo depende de la variable “CantidadProductosAPedir”
};

float costoProducto (Producto prod);

int main()
{
    char *TiposProductos[] = {"Galletas","Snack","Cigarrillos","Caramelos","Bebidas"};

    //VARIABLES AUXILIARES
    //char *nombre  = (char *)malloc(100 * sizeof(char));
    char nombre[100];
    int cpp, tp;

    int cantClientes;
    printf("Ingrese la cantidad de clientes a visitar: ");
    scanf("%d", &cantClientes); //defino la cantidad de clientes a visitar

    struct Cliente listaClientes[cantClientes];

    srand(time(NULL));
    for (int i = 0; i < cantClientes; i++)
    {
        listaClientes[i].ClienteID = i+1; //establezco el ID del cliente

        printf("\nIngrese el nombre del cliente numero %d: ", i+1);
        fflush(stdin);
        gets(nombre);
        listaClientes[i].NombreCliente = (char *)malloc(sizeof(char) * (strlen(nombre)+1));
        strcpy(listaClientes[i].NombreCliente, nombre); //ingreso el nombre del cliente

        listaClientes[i].CantidadProductosAPedir = 1 + rand()%(5-1+1);
        cpp = listaClientes[i].CantidadProductosAPedir; //defino la cantidad de productos a pedir

        listaClientes[i].Productos = (Producto *)malloc(cpp * sizeof(Producto)); //reservo el espacio de memoria para la cantidad de productos a pedir

        for (int j = 0; j < cpp; j++)
        {
            listaClientes[i].Productos[j].ProductoID = j+1;

            listaClientes[i].Productos[j].Cantidad = 1 + rand()%(10-1+1);

            tp = rand()%5;
            listaClientes[i].Productos[j].TipoProducto = (char *)malloc(sizeof(char) * (strlen(TiposProductos[tp])+1));
            strcpy(listaClientes[i].Productos[j].TipoProducto, TiposProductos[tp]); //defino el tipo de producto

            listaClientes[i].Productos[j].PrecioUnitario = (100*100 + rand()%((100-10+1)*100))/100.00; 
        }
    }

    //Comenzaré a mostrar toda la info
    for (int i = 0; i < cantClientes; i++)
    {
        float totalAPagar = 0;

        printf("\nID del cliente = %d", listaClientes[i].ClienteID);
        printf("\nNombre del cliente = %s", listaClientes[i].NombreCliente);
        printf("\nCantidad de productos a pedir = %d", listaClientes[i].CantidadProductosAPedir);
        printf("\nProductos:");

        for (int j = 0; j < listaClientes[i].CantidadProductosAPedir; j++)
        {
            printf("\n\tID del producto = %d \n\tCantidad = %d \n\tTipo de producto = %s \n\tPrecio unitario = $%.2f", listaClientes[i].Productos[j].ProductoID, listaClientes[i].Productos[j].Cantidad, listaClientes[i].Productos[j].TipoProducto, listaClientes[i].Productos[j].PrecioUnitario);

            totalAPagar += costoProducto (listaClientes[i].Productos[j]);
            printf("\n");
        }
        
        printf("\nTotal a pagar = $%.2f", totalAPagar);
        printf("\n");
    }
    
    //free(nombre);
    //free(listaClientes);

    return 0;
}


float costoProducto (Producto prod)
{
    float cant, precio;
    cant = prod.Cantidad;
    precio = prod.PrecioUnitario;
    return cant*precio;
}

