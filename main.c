#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ARTICULOS 100

typedef struct {
    char titulo[100];
    char fecha[11];
    char directorio[100];
} Articulo;

Articulo revista[MAX_ARTICULOS];
int numArticulos = 0;

void agregarArticulo() {
    if (numArticulos < MAX_ARTICULOS) {
        printf("Ingrese el título del artículo: ");
        scanf(" %[^\n]", revista[numArticulos].titulo);
        printf("Ingrese la fecha de publicación (YYYY-MM-DD): ");
        scanf(" %10s", revista[numArticulos].fecha);
        printf("Ingrese el directorio del archivo (con extensión .pdf): ");
        scanf(" %99s", revista[numArticulos].directorio);
        numArticulos++;
    } else {
        printf("No se pueden agregar más artículos.\n");
    }
}

void actualizarArticulo() {
    int index;
    printf("Ingrese el índice del artículo a actualizar (0-%d): ", numArticulos - 1);
    scanf("%d", &index);
    if (index >= 0 && index < numArticulos) {
        printf("Ingrese el nuevo título del artículo: ");
        scanf(" %[^\n]", revista[index].titulo);
        printf("Ingrese la nueva fecha de publicación (YYYY-MM-DD): ");
        scanf(" %10s", revista[index].fecha);
        printf("Ingrese el nuevo directorio del archivo (con extensión .pdf): ");
        scanf(" %99s", revista[index].directorio);
    } else {
        printf("Índice no válido.\n");
    }
}

void eliminarArticulo() {
    int index;
    printf("Ingrese el índice del artículo a eliminar (0-%d): ", numArticulos - 1);
    scanf("%d", &index);
    if (index >= 0 && index < numArticulos) {
        for (int i = index; i < numArticulos - 1; i++) {
            revista[i] = revista[i + 1];
        }
        numArticulos--;
    } else {
        printf("Índice no válido.\n");
    }
}

void mostrarArticulos() {
    for (int i = 0; i < numArticulos; i++) {
        printf("Artículo %d:\n", i);
        printf("  Título: %s\n", revista[i].titulo);
        printf("  Fecha: %s\n", revista[i].fecha);
        printf("  Directorio: %s\n", revista[i].directorio);
    }
}

void ejecutarArticulo() {
    int index;
    printf("Ingrese el índice del artículo a ejecutar (0-%d): ", numArticulos - 1);
    scanf("%d", &index);
    if (index >= 0 && index < numArticulos) {
        char comando[150];
        snprintf(comando, sizeof(comando), "xdg-open %s", revista[index].directorio);
        system(comando);
    } else {
        printf("Índice no válido.\n");
    }
}

int main() {
    int opcion;
    do {
        printf("\nGestión de Artículos de Revista\n");
        printf("1. Agregar artículo\n");
        printf("2. Actualizar artículo\n");
        printf("3. Eliminar artículo\n");
        printf("4. Mostrar artículos\n");
        printf("5. Ejecutar artículo\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                agregarArticulo();
                break;
            case 2:
                actualizarArticulo();
                break;
            case 3:
                eliminarArticulo();
                break;
            case 4:
                mostrarArticulos();
                break;
            case 5:
                ejecutarArticulo();
                break;
            case 6:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida.\n");
        }
    } while (opcion != 6);

    return 0;
}

// jaiker figueredo 30916384//
//aaron piña 31026016//
//fecha de entrega 06/08/2024 //