#include <stdio.h>
#include "funciones.h"

/* Caso: 5 productos. Sin structs. Arreglos paralelos. */
int main() {
    char  nombres[5][30];
    float tiempoPorUnidad[5];
    float recursoPorUnidad[5];
    int   demanda[5];

    int n = 0;      /* cuantos productos cargados */
    int op = 0;     /* opcion del menu */
    int seguir = 1; /* 1 = continuar */

    do {
        printf("\n===== MENU PRODUCCION =====\n");
        printf("1) Ingresar/Actualizar productos\n");
        printf("2) Editar producto por nombre\n");
        printf("3) Eliminar producto por nombre\n");
        printf("4) Ver tabla\n");
        printf("5) Totales (tiempo y recursos)\n");
        printf("6) Verificar si alcanza con limites\n");
        printf("7) Salir\n");
        printf("Opcion: ");
        scanf("%d", &op);

        switch (op) {
        case 1:
            n = ingresarProductos(nombres, tiempoPorUnidad, recursoPorUnidad, demanda, 5);
            break;

        case 2:
            editarProducto(nombres, tiempoPorUnidad, recursoPorUnidad, demanda, n);
            break;

        case 3:
            eliminarProducto(nombres, tiempoPorUnidad, recursoPorUnidad, demanda, &n);
            break;

        case 4:
            mostrarTabla(nombres, tiempoPorUnidad, recursoPorUnidad, demanda, n);
            break;

        case 5: {
            if (n == 0) { printf("No hay datos.\n"); break; }
            float t = calcularTiempoTotal(tiempoPorUnidad, demanda, n);
            float r = calcularRecursosTotales(recursoPorUnidad, demanda, n);
            printf("Tiempo total requerido: %.2f\n", t);
            printf("Recursos totales requeridos: %.2f\n", r);
            break;
        }

        case 6:
            verificarFactibilidad(tiempoPorUnidad, recursoPorUnidad, demanda, n);
            break;

        case 7:
            printf("Saliendo...\n");
            seguir = 0;
            break;

        default:
            printf("Opcion invalida.\n");
        }
    } while (seguir == 1);

    return 0;
}