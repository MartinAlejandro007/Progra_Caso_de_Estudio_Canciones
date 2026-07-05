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