#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cancion.h"

static void leerLinea(const char *prompt, char *dest, int size) {
    if (prompt) printf("%s", prompt);
    if (fgets(dest, size, stdin)) {
        dest[strcspn(dest, "\n")] = '\0';
    } else {
        dest[0] = '\0';
    }
}

/* Agrupa canciones por clasificacion unica.
   Devuelve la cantidad de clasificaciones distintas encontradas.
   'unicas'  -> nombres de cada clasificacion
   'conteos' -> cuantas canciones tiene cada una
   'tiempos' -> suma de duracion (segundos) de cada una           */
static int agruparClasificaciones(const struct Cancion *canciones, int total,
                                  char unicas[][MAX_TEXTO], int *conteos, int *tiempos)
{
    int n = 0;
    for (int i = 0; i < total; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if (strcmp(unicas[j], canciones[i].clasificacion) == 0)
                break;
        }
        if (j == n) {
            strncpy(unicas[n], canciones[i].clasificacion, MAX_TEXTO - 1);
            unicas[n][MAX_TEXTO - 1] = '\0';
            conteos[n] = 1;
            tiempos[n] = canciones[i].duracion_segundos;
            n++;
        } else {
            conteos[j]++;
            tiempos[j] += canciones[i].duracion_segundos;
        }
    }
    return n;
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
int buscarIndicePorCodigo(const struct Cancion *canciones, int total, const 
char *codigo) {
for (int i = 0; i < total; i++) {
if (strcmp(canciones[i].codigo, codigo) == 0)
return i;
}
return -1;
}
void registrarCancion(struct Cancion *canciones, int *total) {
if (*total >= MAX_CANCIONES) {
printf("Error: Biblioteca llena.\n");
return;
}
struct Cancion nueva;
printf("Codigo (unico, sin espacios, max %d chars): ", MAX_CODIGO);
scanf("%15s", nueva.codigo);
limpiarBuffer();
if (strlen(nueva.codigo) == 0) {
printf("Error: codigo obligatorio.\n");
return;
}
if (buscarIndicePorCodigo(canciones, *total, nueva.codigo) != -1) {
printf("Error: ese codigo ya existe.\n");
return;
}
leerLinea("Titulo: ", nueva.titulo, MAX_TEXTO);
if (strlen(nueva.titulo) == 0) {
printf("Error: titulo obligatorio.\n");
return;
}
leerLinea("Clasificacion (pop/rock/jazz/salsa/clasica/electronica/etc): ",
nueva.clasificacion, MAX_TEXTO);
leerLinea("Compositor: ", nueva.compositor, MAX_TEXTO);
if (strlen(nueva.compositor) == 0) {
printf("Error: compositor obligatorio.\n");
return;
}
leerLinea("Artista: ", nueva.artista, MAX_TEXTO);
if (strlen(nueva.artista) == 0) {
printf("Error: artista obligatorio.\n");
return;
}
printf("Duracion en segundos (> 0): ");
scanf("%d", &nueva.duracion_segundos);
limpiarBuffer();
if (nueva.duracion_segundos <= 0) {
printf("Error: duracion debe ser mayor a 0.\n");
return;
}
canciones[*total] = nueva;
(*total)++;
printf("Cancion registrada exitosamente.\n");
}
int buscarIndicePorCodigo(const struct Cancion *canciones, int total, const 
char *codigo) {
for (int i = 0; i < total; i++) {
if (strcmp(canciones[i].codigo, codigo) == 0)
return i;
}
return -1;
}
void registrarCancion(struct Cancion *canciones, int *total) {
if (*total >= MAX_CANCIONES) {
printf("Error: Biblioteca llena.\n");
return;
}
struct Cancion nueva;
printf("Codigo (unico, sin espacios, max %d chars): ", MAX_CODIGO);
scanf("%15s", nueva.codigo);
limpiarBuffer();
if (strlen(nueva.codigo) == 0) {
printf("Error: codigo obligatorio.\n");
return;
}
if (buscarIndicePorCodigo(canciones, *total, nueva.codigo) != -1) {
printf("Error: ese codigo ya existe.\n");
return;
}
leerLinea("Titulo: ", nueva.titulo, MAX_TEXTO);
if (strlen(nueva.titulo) == 0) {
printf("Error: titulo obligatorio.\n");
return;
}
leerLinea("Clasificacion (pop/rock/jazz/salsa/clasica/electronica/etc): ",
nueva.clasificacion, MAX_TEXTO);
leerLinea("Compositor: ", nueva.compositor, MAX_TEXTO);
if (strlen(nueva.compositor) == 0) {
printf("Error: compositor obligatorio.\n");
return;
}
leerLinea("Artista: ", nueva.artista, MAX_TEXTO);
if (strlen(nueva.artista) == 0) {
printf("Error: artista obligatorio.\n");
return;
}
printf("Duracion en segundos (> 0): ");
scanf("%d", &nueva.duracion_segundos);
limpiarBuffer();
if (nueva.duracion_segundos <= 0) {
printf("Error: duracion debe ser mayor a 0.\n");
return;
}
canciones[*total] = nueva;
(*total)++;
printf("Cancion registrada exitosamente.\n");
}
void listarCanciones(const struct Cancion *canciones, int total) {
if (total == 0) {
printf("No hay canciones registradas.\n");
return;
}
printf("\n%-15s %-25s %-15s %-20s %-20s %s\n",
"CODIGO", "TITULO", "CLASIFICACION", "COMPOSITOR", "ARTISTA", "DURACION");
printf("---------------------------------------------------------------------------------------------------------------------\n");
for (int i = 0; i < total; i++) {
printf("%-15s %-25s %-15s %-20s %-20s ",
canciones[i].codigo,
canciones[i].titulo,
canciones[i].clasificacion,
canciones[i].compositor,
canciones[i].artista);
mostrarDuracion(canciones[i].duracion_segundos);
}
}
void buscarCancion(const struct Cancion *canciones, int total) {
if (total == 0) {
printf("No hay canciones registradas.\n");
return;
}
int criterio;
printf("\nBuscar por:\n"
"1. Codigo\n"
"2. Titulo\n"
"3. Compositor\n"
"4. Artista\n"
"5. Clasificacion\n"
"Seleccione criterio: ");
scanf("%d", &criterio);
limpiarBuffer();
char busqueda[MAX_TEXTO];
leerLinea("Ingrese termino de busqueda: ", busqueda, MAX_TEXTO);
int encontrados = 0;
for (int i = 0; i < total; i++) {
int coincide = 0;
switch (criterio) {
case 1: coincide = (strcmp(canciones[i].codigo, busqueda) == 0); break;
case 2: coincide = (strstr(canciones[i].titulo, busqueda) != NULL); break;
case 3: coincide = (strstr(canciones[i].compositor, busqueda) != NULL); 
break;
case 4: coincide = (strstr(canciones[i].artista, busqueda) != NULL); break;
case 5: coincide = (strcmp(canciones[i].clasificacion, busqueda) == 0); 
break;
default: printf("Criterio invalido.\n"); return;
}
if (coincide) {
if (encontrados == 0) {
printf("\n%-15s %-25s %-15s %-20s %-20s %s\n",
"CODIGO", "TITULO", "CLASIFICACION", "COMPOSITOR", "ARTISTA", "DURACION");
printf("---------------------------------------------------------------------------------------------------------------------\n");
}
printf("%-15s %-25s %-15s %-20s %-20s ",
canciones[i].codigo,
canciones[i].titulo,
canciones[i].clasificacion,
canciones[i].compositor,
canciones[i].artista);
mostrarDuracion(canciones[i].duracion_segundos);
encontrados++;
}
}
if (encontrados == 0)
printf("No se encontraron canciones.\n");
else
printf("Total encontrados: %d\n", encontrados);
}
void actualizarCancion(struct Cancion *canciones, int total) {
if (total == 0) {
printf("No hay canciones registradas.\n");
return;
}
char codigo[MAX_CODIGO + 1];
printf("Ingrese codigo de la cancion a actualizar: ");
scanf("%15s", codigo);
limpiarBuffer();
int idx = buscarIndicePorCodigo(canciones, total, codigo);
if (idx == -1) {
printf("Cancion no encontrada.\n");
return;
}
printf("\nCancion actual:\n"
"Codigo: %s\n"
"Titulo: %s\n"
"Clasificacion: %s\n"
"Compositor: %s\n"
"Artista: %s\n"
"Duracion: ",
canciones[idx].codigo,
canciones[idx].titulo,
canciones[idx].clasificacion,
canciones[idx].compositor,
canciones[idx].artista);
mostrarDuracion(canciones[idx].duracion_segundos);
printf("\n--- Deje en blanco para mantener valor actual ---\n");
char temp[MAX_TEXTO];
printf("Nuevo titulo [%s]: ", canciones[idx].titulo);
leerLinea(NULL, temp, MAX_TEXTO);
if (strlen(temp) > 0) strcpy(canciones[idx].titulo, temp);
printf("Nueva clasificacion [%s]: ", canciones[idx].clasificacion);
leerLinea(NULL, temp, MAX_TEXTO);
if (strlen(temp) > 0) strcpy(canciones[idx].clasificacion, temp);
printf("Nuevo compositor [%s]: ", canciones[idx].compositor);
leerLinea(NULL, temp, MAX_TEXTO);
if (strlen(temp) > 0) strcpy(canciones[idx].compositor, temp);
printf("Nuevo artista [%s]: ", canciones[idx].artista);
leerLinea(NULL, temp, MAX_TEXTO);
if (strlen(temp) > 0) strcpy(canciones[idx].artista, temp);
printf("Nueva duracion en segundos [%d]: ", 
canciones[idx].duracion_segundos);
char durStr[20];
if (fgets(durStr, sizeof(durStr), stdin)) {
durStr[strcspn(durStr, "\n")] = '\0';
if (strlen(durStr) > 0) {
int nuevaDur = atoi(durStr);
if (nuevaDur > 0) canciones[idx].duracion_segundos = nuevaDur;
}
}
printf("Cancion actualizada exitosamente.\n");
}
void eliminarCancion(struct Cancion *canciones, int *total) {
if (*total == 0) {
printf("No hay canciones registradas.\n");
return;
}
char codigo[MAX_CODIGO + 1];
printf("Ingrese codigo de la cancion a eliminar: ");
scanf("%15s", codigo);
limpiarBuffer();
int idx = buscarIndicePorCodigo(canciones, *total, codigo);
if (idx == -1) {
printf("Cancion no encontrada.\n");
return;
}
printf("\nVa a eliminar: %s - %s\n", canciones[idx].codigo, 
canciones[idx].titulo);
printf("Confirmar (1=Si, 0=No): ");
int confirmar;
scanf("%d", &confirmar);
limpiarBuffer();
if (confirmar != 1) {
printf("Eliminacion cancelada.\n");
return;
}
canciones[idx] = canciones[*total - 1];
(*total)--;
printf("Cancion eliminada exitosamente.\n");
}
void mostrarDuracion(int segundos) {
int min = segundos / 60;
int seg = segundos % 60;
printf("%02d:%02d\n", min, seg);
}
void calcularTiempoTotal(const struct Cancion *canciones, int total) {
if (total == 0) {
printf("No hay canciones registradas.\n");
return;
}
int suma = 0;
for (int i = 0; i < total; i++) suma += canciones[i].duracion_segundos;
printf("Tiempo total de reproduccion: ");
mostrarDuracion(suma);
printf("(%d segundos en total)\n", suma);
}
void cancionMasLarga(const struct Cancion *canciones, int total) {
if (total == 0) {
printf("No hay canciones registradas.\n");
return;
}
int idx = 0;
for (int i = 1; i < total; i++) {
if (canciones[i].duracion_segundos > canciones[idx].duracion_segundos)
idx = i;
}
printf("Cancion mas larga: %s - %s (", canciones[idx].artista,
canciones[idx].titulo);
mostrarDuracion(canciones[idx].duracion_segundos);
printf(")\n");
}
void cancionMasCorta(const struct Cancion *canciones, int total) {
if (total == 0) {
printf("No hay canciones registradas.\n");
return;
}
int idx = 0;
for (int i = 1; i < total; i++) {
if (canciones[i].duracion_segundos < canciones[idx].duracion_segundos)
idx = i;
}
printf("Cancion mas corta: %s - %s (", canciones[idx].artista,
canciones[idx].titulo);
mostrarDuracion(canciones[idx].duracion_segundos);
printf(")\n");
}
void contarPorClasificacion(const struct Cancion *canciones, int total) {
if (total == 0) {
printf("No hay canciones registradas.\n");
return;
}
char unicas[MAX_CANCIONES][MAX_TEXTO];
int conteos[MAX_CANCIONES];
int tiempos[MAX_CANCIONES]; /* no se usa aqui, pero agrupar lo llena */
int n = agruparClasificaciones(canciones, total, unicas, conteos, tiempos);
printf("\n--- Canciones por clasificacion ---\n");
for (int i = 0; i < n; i++)
printf("%s: %d cancion(es)\n", unicas[i], conteos[i]);
}
void duracionPromedio(const struct Cancion *canciones, int total) {
if (total == 0) {
printf("No hay canciones registradas.\n");
return;
}
int suma = 0;
for (int i = 0; i < total; i++) suma += canciones[i].duracion_segundos;
float promedio = (float)suma / total;
int min = (int)(promedio / 60);
int seg = (int)(promedio) % 60;
printf("Duracion promedio: %02d:%02d (%.1f segundos)\n", min, seg,
promedio);
}
void clasificacionMasFrecuente(const struct Cancion *canciones, int total) {
if (total == 0) {
printf("No hay canciones registradas.\n");
return;
}
char unicas[MAX_CANCIONES][MAX_TEXTO];
int conteos[MAX_CANCIONES];
int tiempos[MAX_CANCIONES];
int n = agruparClasificaciones(canciones, total, unicas, conteos, tiempos);
int maxIdx = 0;
for (int i = 1; i < n; i++) {
if (conteos[i] > conteos[maxIdx]) {
maxIdx = i;
}
}
/* Si n==0 no pasa porque total>0, pero por robustez: */
if (n > 0) {
printf("Clasificacion con mas canciones: %s (%d canciones)\n",
unicas[maxIdx], conteos[maxIdx]);
}
}
void tiempoTotalPorClasificacion(const struct Cancion *canciones, int total)
{
if (total == 0) {
printf("No hay canciones registradas.\n");
return;
}
char unicas[MAX_CANCIONES][MAX_TEXTO];
int conteos[MAX_CANCIONES];
int tiempos[MAX_CANCIONES];
int n = agruparClasificaciones(canciones, total, unicas, conteos, tiempos);
printf("\n--- Tiempo total por clasificacion ---\n");
for (int i = 0; i < n; i++) {
printf("%s: ", unicas[i]);
mostrarDuracion(tiempos[i]);
}
}
void consultarDuracionCancion(const struct Cancion *canciones, int total) {
if (total == 0) {
printf("No hay canciones registradas.\n");
return;
}
char codigo[MAX_CODIGO + 1];
printf("Ingrese codigo de la cancion: ");
scanf("%15s", codigo);
limpiarBuffer();
int idx = buscarIndicePorCodigo(canciones, total, codigo);
if (idx == -1) {
printf("Cancion no encontrada.\n");
} else {
printf("Duracion de %s: ", canciones[idx].titulo);
mostrarDuracion(canciones[idx].duracion_segundos);
}
}
void guardarCSV(const struct Cancion *canciones, int total) {
FILE *fp = fopen("canciones.csv", "w");
if (!fp) {
printf("Error al abrir archivo para guardar.\n");
return;
}
fprintf(fp,
"codigo_cancion;titulo;clasificacion;compositor;artista;duracion_segundos\n"
);
for (int i = 0; i < total; i++) {
fprintf(fp, "%s;%s;%s;%s;%s;%d\n",
canciones[i].codigo,
canciones[i].titulo,
canciones[i].clasificacion,
canciones[i].compositor,
canciones[i].artista,
canciones[i].duracion_segundos);
}
fclose(fp);
printf("Datos guardados en canciones.csv (%d canciones).\n", total);
}
void cargarCSV(struct Cancion *canciones, int *total) {
FILE *fp = fopen("canciones.csv", "r");
if (!fp) {
printf("No existe archivo previo (canciones.csv). Empezando biblioteca
vacia.\n");
return;
}
char linea[512];
if (!fgets(linea, sizeof(linea), fp)) {
fclose(fp);
return;
}
*total = 0;
while (fgets(linea, sizeof(linea), fp) && *total < MAX_CANCIONES) {
struct Cancion c;
if (sscanf(linea, "%14[^;];%99[^;];%99[^;];%99[^;];%99[^;];%d",
c.codigo, c.titulo, c.clasificacion,
c.compositor, c.artista, &c.duracion_segundos) == 6) {
canciones[*total] = c;
(*total)++;
}
}
fclose(fp);
printf("%d canciones cargadas desde canciones.csv.\n", *total);
}
