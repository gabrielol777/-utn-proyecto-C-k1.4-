/* ============================================================================
 * TRABAJO PRÁCTICO INTEGRADOR FINAL - ALGORITMOS Y ESTRUCTURAS DE DATOS
 * UNIVERSIDAD TECNOLÓGICA NACIONAL - FACULTAD REGIONAL RESISTENCIA
 * Archivo: main.c
 * ============================================================================ */ 
#include <stdio.h>
#include <stdlib.h>
#include "artemis.h"
#include "validaciones.h"

int main() {
    EstadoOrbitalLEO nave;
    int opcion;

    inicializar_nave(&nave);
    mostrar_encabezado();

    do {
        mostrar_menu();
        opcion = leer_entero_seguro(" Seleccione una opcion [1-5]: ", 1, 5);

        switch(opcion) {
            case 1:
                ejecutar_fase_demostracion(&nave);
                break;
            case 2:
                ejecutar_fase_calculo_periodo(&nave);
                break;
            case 3:
                ejecutar_fase_aceleracion_centripeta(&nave);
                break;
            case 4:
                ejecutar_fase_evento_propulsor(&nave);
                break;
            case 5:
                generar_reporte_final(&nave);
                printf("\n[INFO] Gracias por utilizar el Simulador Artemis II LEO. Finalizando...\n");
                break;
        }
    } while(opcion != 5);

    return 0;
} 
