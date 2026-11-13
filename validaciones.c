#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"

int leer_entero_seguro(const char *mensaje, int min, int max) {
    int valor;
    char buffer[100];
    int valido = 0;

    do {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &valor) == 1) {
                if (valor >= min && valor <= max) {
                    valido = 1;
                } else {
                    printf(" [ERROR] El numero debe estar entre %d y %d.\n", min, max);
                }
            } else {
                printf(" [ERROR] Entrada invalida. Por favor, ingrese un numero entero.\n");
            }
        }
    } while (!valido);

    return valor;
}

double leer_flotante_seguro(const char *mensaje, double min, double max) {
    double valor;
    char buffer[100];
    int valido = 0;

    do {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%lf", &valor) == 1) {
                if (valor >= min && valor <= max) {
                    valido = 1;
                } else {
                    printf(" [ERROR] El valor debe estar entre %.2lf y %.2lf.\n", min, max);
                }
            } else {
                printf(" [ERROR] Entrada invalida. Ingrese un valor numerico flotante.\n");
            }
        }
    } while (!valido);

    return valor;
}