/* ============================================================================
 * Archivo: artemis.c
 * Implementación de cálculos físicos y mecánicas de la simulación
 * ============================================================================ */ 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "artemis.h"
#include "validaciones.h" 

void inicializar_nave(EstadoOrbitalLEO *nave) {
    strcpy(nave->nombre_mision, "Artemis II LEO Mission");
    nave->radio_orbital = RADIO_TIERRA + ALTITUD_LEO;
    
    
    nave->velocidad_orbital = sqrt((G_CONST * MASA_TIERRA) / nave->radio_orbital);
    
    
    nave->periodo_segundos = (2.0 * M_PI * nave->radio_orbital) / nave->velocidad_orbital;
    nave->periodo_minutos = nave->periodo_segundos / 60.0;
    
    
    nave->aceleracion_c = (nave->velocidad_orbital * nave->velocidad_orbital) / nave->radio_orbital;
    
    
    nave->desviacion_lateral = 0.5 * 0.50 * pow(10.0, 2);
    
    nave->estabilidad_pct = 100.0f;
    nave->pruebas_superadas = 0;
} 
void mostrar_encabezado() {
    printf("====================================================================\n");
    printf("        SIMULADOR DE MISIONES ARTEMIS - UTN FRRe\n");
    printf("    Modulo LEO: Insercion y Estabilidad en Orbita Terrestre Baja\n");
    printf("====================================================================\n");
}
void mostrar_menu() {
    printf("\n--- PANEL DE CONTROL DE MISIÓN LEO ---\n");
    printf("1. Demostrar Fuerzas y Calcular Velocidad Orbital\n");
    printf("2. Calcular Periodo Orbital (T) de la Nave Orion\n");
    printf("3. Evaluar Aceleracion Centripeta sobre Astronautas\n");
    printf("4. Simular Pulso Propulsor Auxiliar Lateral (Evento Deriva)\n");
    printf("5. Generar Reporte Final y Salir\n");
} 