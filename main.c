#include <stdio.h>
#include "funciones.h"

int main() {
    int opcion;
    int tiempoDisponible;
    int recursosDisponibles;
    do {
        printf("Ingrese tiempo total disponible (min): ");
        scanf("%d", &tiempoDisponible);
        if (tiempoDisponible < 0) {
            printf("No se permiten valores negativos.\n");
        }
        printf("Ingrese recursos disponibles: ");
        scanf("%d", &recursosDisponibles);
        if (recursosDisponibles < 0) {
            printf("No se permiten valores negativos.\n");
        }

    } while (tiempoDisponible < 0 && recursosDisponibles < 0);

    do {
        printf("\n--- Menú ---\n");
        printf("1. Agregar producto\n");
        printf("2. Editar producto\n");
        printf("3. Eliminar producto\n");
        printf("4. Calcular producción\n");
        printf("5. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarProducto(); 
                break;
            case 2: 
                editarProducto();  
                break;
            case 3: 
                eliminarProducto(); 
                break;
            case 4: 
                calcularProduccion(tiempoDisponible, recursosDisponibles); 
                break;
            case 5: 
                printf("Cerrando programa\n");
                 break;
            default: 
                break;
        }
    } while (opcion != 5);

    return 0;
}