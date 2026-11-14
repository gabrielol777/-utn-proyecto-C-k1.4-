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
    int opcion;
    
    do {
        printf("\n============================================================\n");
        printf("         SIMULADOR DE MISIONES ARTEMIS - UTN FRRe           \n");
        printf("    Modulo LEO: Insercion y Estabilidad en Orbita Baja      \n");
        printf("============================================================\n");
        printf(" 1. Iniciar Juego (Secuencia de Mision)\n");
        printf(" 2. Ver Reglas\n");
        printf(" 3. Salir\n");
        printf("============================================================\n");
        
        opcion = leer_entero_seguro(" Seleccione una opcion [1-3]: ", 1, 3);
        
        switch(opcion) {
            case 1: {
                EstadoOrbitalLEO nave;
                inicializar_nave(&nave);
                
                printf("\n>>> INICIANDO SECUENCIA DE VUELO ARTEMIS II <<<\n");
                
                ejecutar_fase_demostracion(&nave);      // Fase 1: Velocidad Orbital
                ejecutar_fase_calculo_periodo(&nave);    // Fase 2: Periodo Orbital
                ejecutar_fase_aceleracion_centripeta(&nave); // Fase 3: Aceleracion Centripeta
                ejecutar_fase_pulso_propulsor(&nave);     // Fase 4: Evento Deriva / Propulsor
                
                generar_reporte_final(&nave);
                
                break;
            }
            case 2:
                mostrar_reglas();
                break;
                
            case 3:
                printf("\n Saliendo del simulador de mision. ¡Hasta luego!\n");
                break;
        }
        
    } while(opcion != 3);
    
    return 0;
}
