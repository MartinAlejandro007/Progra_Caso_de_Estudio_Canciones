#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cancion.h"

int main() {
    struct Cancion biblioteca[MAX_CANCIONES];
    int total = 0;
    int opcion;

    cargarCSV(biblioteca, &total);

    do {
        printf("\n===== BIBLIOTECA MUSICAL =====\n");
        printf("1. Registrar cancion\n");
        printf("2. Listar canciones\n");
        printf("3. Buscar cancion\n");
        printf("4. Actualizar cancion\n");
        printf("5. Eliminar cancion\n");
        printf("6. Mostrar duracion de una cancion\n");
        printf("7. Calcular tiempo total de reproduccion\n");
        printf("8. Identificar cancion mas larga\n");
        printf("9. Identificar cancion mas corta\n");
        printf("10. Cantidad de canciones por clasificacion\n");
        printf("11. Calcular duracion promedio\n");
        printf("12. Identificar clasificacion con mas canciones\n");
        printf("13. Calcular tiempo total por clasificacion\n");
        printf("14. Guardar cambios en archivo\n");
        printf("0. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1:
                registrarCancion(biblioteca, &total);
                break;
            case 2:
                listarCanciones(biblioteca, total);
                break;
            case 3:
                buscarCancion(biblioteca, total);
                break;
            case 4:
                actualizarCancion(biblioteca, total);
                break;
            case 5:
                eliminarCancion(biblioteca, &total);
                break;
            case 6: {
                if (total == 0) {
                    printf("No hay canciones registradas.\n");
                    break;
                }
                char codigo[MAX_CODIGO + 1];
                printf("Ingrese codigo de la cancion: ");
                scanf("%15s", codigo);
                limpiarBuffer();

                int idx = -1;
                for (int i = 0; i < total; i++) {
                    if (strcmp(biblioteca[i].codigo, codigo) == 0) {
                        idx = i;
                        break;
                    }
                }

                if (idx == -1) {
                    printf("Cancion no encontrada.\n");
                } else {
                    printf("Duracion de %s: ", biblioteca[idx].titulo);
                    mostrarDuracion(biblioteca[idx].duracion_segundos);
                }
                break;
            }
            case 7:
                calcularTiempoTotal(biblioteca, total);
                break;
            case 8:
                cancionMasLarga(biblioteca, total);
                break;
            case 9:
                cancionMasCorta(biblioteca, total);
                break;
            case 10:
                contarPorClasificacion(biblioteca, total);
                break;
            case 11:
                duracionPromedio(biblioteca, total);
                break;
            case 12:
                clasificacionMasFrecuente(biblioteca, total);
                break;
            case 13:
                tiempoTotalPorClasificacion(biblioteca, total);
                break;
            case 14:
                guardarCSV(biblioteca, total);
                break;
            case 0:
                guardarCSV(biblioteca, total);
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}
