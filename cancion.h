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

// CRUD
void registrarCancion(struct Cancion *canciones, int *total);
void listarCanciones(const struct Cancion *canciones, int total);
void buscarCancion(const struct Cancion *canciones, int total);
void actualizarCancion(struct Cancion *canciones, int total);
void eliminarCancion(struct Cancion *canciones, int *total);

// Calculos
void mostrarDuracion(int segundos);
void calcularTiempoTotal(const struct Cancion *canciones, int total);
void cancionMasLarga(const struct Cancion *canciones, int total);
void cancionMasCorta(const struct Cancion *canciones, int total);
void contarPorClasificacion(const struct Cancion *canciones, int total);
void duracionPromedio(const struct Cancion *canciones, int total);
void clasificacionMasFrecuente(const struct Cancion *canciones, int total);
void tiempoTotalPorClasificacion(const struct Cancion *canciones, int total);

// Archivos
void guardarCSV(const struct Cancion *canciones, int total);
void cargarCSV(struct Cancion *canciones, int *total);

// Utilidades
int buscarIndicePorCodigo(const struct Cancion *canciones, int total, const char *codigo);
void consultarDuracionCancion(const struct Cancion *canciones, int total);
void limpiarBuffer();

#endif
