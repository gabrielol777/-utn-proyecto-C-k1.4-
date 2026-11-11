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