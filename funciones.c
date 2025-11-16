#include <stdio.h>
#include <string.h>
#include "funciones.h"


#define MAX_PRODUCTOS 100
#define MAX_NOMBRE 50

char nombres[MAX_PRODUCTOS][MAX_NOMBRE];
int cantidades[MAX_PRODUCTOS];
int tiempos[MAX_PRODUCTOS];
int recursos[MAX_PRODUCTOS];
int totalProductos = 0;

void limpiarSalto(char *cadena) {
    size_t len = strlen(cadena);
    if (len > 0 && cadena[len - 1] == '\n') {
        cadena[len - 1] = '\0';
    }
}


int leerEnteroPositivo(const char *mensaje) {
    int valor;
    do {
        printf("%s", mensaje);
        scanf("%d", &valor);
        if (valor < 0) {
            printf("No se permiten valores negativos. Intente nuevamente.\n");
        }
    } while (valor < 0);
    return valor;
}

void agregarProducto() {
    if (totalProductos >= MAX_PRODUCTOS) {
        printf("No se pueden agregar más productos.\n");
        return;
    }

    printf("Nombre del producto: ");
    getchar();
    fgets(nombres[totalProductos], MAX_NOMBRE, stdin);
    limpiarSalto(nombres[totalProductos]);

    cantidades[totalProductos] = leerEnteroPositivo("Cantidad demandada: ");
    tiempos[totalProductos] = leerEnteroPositivo("Tiempo de fabricación (min): ");
    recursos[totalProductos] = leerEnteroPositivo("Recursos requeridos: ");

    totalProductos++;
}

int buscarProducto(char nombre[]) {
    for (int i = 0; i < totalProductos; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            return i;
        }
    }
    return -1;
}

void editarProducto() {
    char nombre[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a editar: ");
    getchar();
    fgets(nombre, MAX_NOMBRE, stdin);
    limpiarSalto(nombre);

    int index = buscarProducto(nombre);
    if (index == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    printf("Nuevo nombre: ");
    fgets(nombres[index], MAX_NOMBRE, stdin);
    limpiarSalto(nombres[index]);

    cantidades[index] = leerEnteroPositivo("Nueva cantidad: ");
    tiempos[index] = leerEnteroPositivo("Nuevo tiempo de fabricación: ");
    recursos[index] = leerEnteroPositivo("Nuevos recursos requeridos: ");
}

void eliminarProducto() {
    char nombre[MAX_NOMBRE];
    printf("Ingrese el nombre del producto a eliminar: ");
    getchar();
    fgets(nombre, MAX_NOMBRE, stdin);
    limpiarSalto(nombre);

    int index = buscarProducto(nombre);
    if (index == -1) {
        printf("Producto no encontrado.\n");
        return;
    }

    for (int i = index; i < totalProductos - 1; i++) {
        strcpy(nombres[i], nombres[i + 1]);
        cantidades[i] = cantidades[i + 1];
        tiempos[i] = tiempos[i + 1];
        recursos[i] = recursos[i + 1];
    }

    totalProductos--;
    printf("Producto eliminado.\n");
}

void calcularProduccion(int tiempoDisponible, int recursosDisponibles) {
    int tiempoTotal = 0;
    int recursosTotales = 0;

    for (int i = 0; i < totalProductos; i++) {
        tiempoTotal += cantidades[i] * tiempos[i];
        recursosTotales += cantidades[i] * recursos[i];
    }

    printf("Tiempo total requerido: %d minutos\n", tiempoTotal);
    printf("Recursos totales requeridos: %d unidades\n", recursosTotales);

    if (tiempoTotal <= tiempoDisponible && recursosTotales <= recursosDisponibles) {
        printf("✅ La fábrica puede cumplir con la demanda.\n");
    } else {
        printf("La fábrica NO puede cumplir con la demanda.\n");
    }
}