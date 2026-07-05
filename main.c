#include <stdio.h>
#include "cancion.h"

int main() {
    struct Cancion biblioteca[MAX_CANCIONES];
    int total = 0;
    int opcion;

    cargarCSV(biblioteca, &total);

    do {
        printf("\n===== BIBLIOTECA MUSICAL =====\n"
               "1.  Registrar cancion\n"
               "2.  Listar canciones\n"
               "3.  Buscar cancion\n"
               "4.  Actualizar cancion\n"
               "5.  Eliminar cancion\n"
               "6.  Mostrar duracion de una cancion\n"
               "7.  Calcular tiempo total de reproduccion\n"
               "8.  Identificar cancion mas larga\n"
               "9.  Identificar cancion mas corta\n"
               "10. Cantidad de canciones por clasificacion\n"
               "11. Calcular duracion promedio\n"
               "12. Identificar clasificacion con mas canciones\n"
               "13. Calcular tiempo total por clasificacion\n"
               "14. Guardar cambios en archivo\n"
               "0.  Salir\n"
               "Seleccione una opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer();

        switch (opcion) {
            case 1: registrarCancion(biblioteca, &total); break;
            case 2: listarCanciones(biblioteca, total); break;
            case 3: buscarCancion(biblioteca, total); break;
            case 4: actualizarCancion(biblioteca, total); break;
            case 5: eliminarCancion(biblioteca, &total); break;
            case 6: consultarDuracionCancion(biblioteca, total); break;
            case 7: calcularTiempoTotal(biblioteca, total); break;
            case 8: cancionMasLarga(biblioteca, total); break;
            case 9: cancionMasCorta(biblioteca, total); break;
            case 10: contarPorClasificacion(biblioteca, total); break;
            case 11: duracionPromedio(biblioteca, total); break;
            case 12: clasificacionMasFrecuente(biblioteca, total); break;
            case 13: tiempoTotalPorClasificacion(biblioteca, total); break;
            case 14: guardarCSV(biblioteca, total); break;
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