/* Prototipos del proyecto de producción con arreglos*/

int  ingresarProductos(char nombres[][30], float tiempoPorUnidad[], float recursoPorUnidad[],
int demanda[], int capacidad);

int  buscarProducto(char nombres[][30], int n, char nombre[]);

void mostrarTabla(char nombres[][30], float tiempo[], float recurso[], int demanda[], int n);
void editarProducto(char nombres[][30], float tiempo[], float recurso[], int demanda[], int n);
void eliminarProducto(char nombres[][30], float tiempo[], float recurso[], int demanda[], int *n);

float calcularTiempoTotal(float tiempo[], int demanda[], int n);
float calcularRecursosTotales(float recurso[], int demanda[], int n);

void verificarFactibilidad(float tiempo[], float recurso[], int demanda[], int n);

/* Utilidades para entrada de texto con espacios */
void limpiarBuffer(void);
void leerLinea(char destino[], int max);