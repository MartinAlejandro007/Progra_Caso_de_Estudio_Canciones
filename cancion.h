#ifndef CANCION_H
#define CANCION_H

#define MAX_CANCIONES 1000
#define MAX_CODIGO 15
#define MAX_TEXTO 100

struct Cancion {
    char codigo[MAX_CODIGO + 1];
    char titulo[MAX_TEXTO];
    char clasificacion[MAX_TEXTO];
    char compositor[MAX_TEXTO];
    char artista[MAX_TEXTO];
    int duracion_segundos;
};

void registrarCancion(struct Cancion *canciones, int *total);
void listarCanciones(const struct Cancion *canciones, int total);
void buscarCancion(const struct Cancion *canciones, int total);
void actualizarCancion(struct Cancion *canciones, int total);
void eliminarCancion(struct Cancion *canciones, int *total);
void guardarCSV(const struct Cancion *canciones, int total);
void cargarCSV(struct Cancion *canciones, int *total);
void limpiarBuffer();

#endif