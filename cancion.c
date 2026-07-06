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