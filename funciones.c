#include <stdio.h>
#include <string.h>
#include "funciones.h"

/* ---------------- Utilidades de entrada ---------------- */

/* Consume caracteres restantes hasta el salto de línea */
void limpiarBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }
}

/* Lee una línea completa y quita el '\n' final si viene */
void leerLinea(char destino[], int max) {
    if (fgets(destino, max, stdin) != NULL) {
        size_t fin = strcspn(destino, "\n");
        destino[fin] = '\0';
    }
}

/* ---------------- Carga/actualización de datos ---------------- */

int ingresarProductos(char nombres[][30],
                      float tiempoPorUnidad[],
                      float recursoPorUnidad[],
                      int demanda[],
                      int capacidad)
{
    int n = 0;

    do {
        printf("Cantidad de productos (1..%d): ", capacidad);
        scanf("%d", &n);
        if (n < 1 || n > capacidad) {
            printf("Valor invalido. Intente otra vez.\n");
        }
        limpiarBuffer();  /* limpia '\n' antes de leer líneas con espacios */
    } while (n < 1 || n > capacidad);

    for (int i = 0; i < n; i++) {
        printf("\nProducto %d\n", i + 1);

        printf("Nombre: ");
        leerLinea(nombres[i], 30);  /* ahora permite espacios */

        do {
            printf("Tiempo por unidad (>=0): ");
            scanf("%f", &tiempoPorUnidad[i]);
            if (tiempoPorUnidad[i] < 0) {
                printf("Valor invalido.\n");
            }
        } while (tiempoPorUnidad[i] < 0);

        do {
            printf("Recurso por unidad (>=0): ");
            scanf("%f", &recursoPorUnidad[i]);
            if (recursoPorUnidad[i] < 0) {
                printf("Valor invalido.\n");
            }
        } while (recursoPorUnidad[i] < 0);

        do {
            printf("Demanda (>=0): ");
            scanf("%d", &demanda[i]);
            if (demanda[i] < 0) {
                printf("Valor invalido.\n");
            }
            limpiarBuffer(); /* dejamos listo para el próximo nombre con espacios */
        } while (demanda[i] < 0);
    }

    return n;
}

/* ---------------- Búsqueda ---------------- */

int buscarProducto(char nombres[][30], int n, char nombre[]) {
    for (int i = 0; i < n; i++) {
        if (strcmp(nombres[i], nombre) == 0) {
            return i;
        }
    }
    return -1;  /* no encontrado */
}

/* ---------------- Visualización ---------------- */

void mostrarTabla(char nombres[][30], float tiempo[], float recurso[], int demanda[], int n) {
    if (n == 0) {
        printf("No hay datos.\n");
        return;
    }

    printf("\n--- Produccion ---\n");
    printf("#\tNombre\t\tT/uni\tR/uni\tDemanda\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t\t%.2f\t%.2f\t%d\n",
               i, nombres[i], tiempo[i], recurso[i], demanda[i]);
    }
}

/* ---------------- Edición ---------------- */

void editarProducto(char nombres[][30], float tiempo[], float recurso[], int demanda[], int n) {
    if (n == 0) {
        printf("No hay datos.\n");
        return;
    }

    char buscado[30];
    printf("Nombre a editar: ");
    leerLinea(buscado, 30);

    int pos = buscarProducto(nombres, n, buscado);
    if (pos == -1) {
        printf("No existe ese producto.\n");
        return;
    }

    printf("Nuevo nombre: ");
    leerLinea(nombres[pos], 30);

    do {
        printf("Nuevo tiempo por unidad: ");
        scanf("%f", &tiempo[pos]);
        if (tiempo[pos] < 0) {
            printf("Valor invalido.\n");
        }
    } while (tiempo[pos] < 0);

    do {
        printf("Nuevo recurso por unidad: ");
        scanf("%f", &recurso[pos]);
        if (recurso[pos] < 0) {
            printf("Valor invalido.\n");
        }
    } while (recurso[pos] < 0);

    do {
        printf("Nueva demanda: ");
        scanf("%d", &demanda[pos]);
        if (demanda[pos] < 0) {
            printf("Valor invalido.\n");
        }
        limpiarBuffer();
    } while (demanda[pos] < 0);

    printf("Registro actualizado.\n");
}

/* ---------------- Eliminación ---------------- */

void eliminarProducto(char nombres[][30], float tiempo[], float recurso[], int demanda[], int *n) {
    if (*n == 0) {
        printf("No hay datos.\n");
        return;
    }

    char buscado[30];
    printf("Nombre a eliminar: ");
    leerLinea(buscado, 30);

    int pos = buscarProducto(nombres, *n, buscado);
    if (pos == -1) {
        printf("No existe ese producto.\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        strcpy(nombres[i], nombres[i + 1]);
        tiempo[i]  = tiempo[i + 1];
        recurso[i] = recurso[i + 1];
        demanda[i] = demanda[i + 1];
    }
    (*n)--;

    printf("Eliminado.\n");
}

/* ---------------- Cálculos ---------------- */

float calcularTiempoTotal(float tiempo[], int demanda[], int n) {
    float total = 0.0f;
    for (int i = 0; i < n; i++) {
        total += tiempo[i] * demanda[i];
    }
    return total;
}

float calcularRecursosTotales(float recurso[], int demanda[], int n) {
    float total = 0.0f;
    for (int i = 0; i < n; i++) {
        total += recurso[i] * demanda[i];
    }
    return total;
}

/* ---------------- Verificación ---------------- */

void verificarFactibilidad(float tiempo[], float recurso[], int demanda[], int n) {
    if (n == 0) {
        printf("No hay datos.\n");
        return;
    }

    float limT = 0.0f, limR = 0.0f;

    do {
        printf("Tiempo disponible total: ");
        scanf("%f", &limT);
        if (limT < 0) {
            printf("Valor invalido.\n");
        }
    } while (limT < 0);

    do {
        printf("Recursos disponibles totales: ");
        scanf("%f", &limR);
        if (limR < 0) {
            printf("Valor invalido.\n");
        }
    } while (limR < 0);

    float t = calcularTiempoTotal(tiempo, demanda, n);
    float r = calcularRecursosTotales(recurso, demanda, n);

    printf("\nRequerido  Tiempo: %.2f  Recursos: %.2f\n", t, r);
    printf("Disponible Tiempo: %.2f  Recursos: %.2f\n", limT, limR);

    if (t <= limT && r <= limR) {
        printf("Resultado: SI se puede cumplir la demanda.\n");
    } else {
        printf("Resultado: NO se puede cumplir la demanda.\n");
    }
}