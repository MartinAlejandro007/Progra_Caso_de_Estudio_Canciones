#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "cancion.h"

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int existeCodigo(const struct Cancion *canciones, int total, const char *codigo) {
    for (int i = 0; i < total; i++) {
        if (strcmp(canciones[i].codigo, codigo) == 0) {
            return 1;
        }
    }
    return 0;
}
