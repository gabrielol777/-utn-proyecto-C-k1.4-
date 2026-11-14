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
void ejecutar_fase_demostracion(EstadoOrbitalLEO *nave) {
    printf("\n[FASE 1]: Analisis de Fuerza Gravitatoria como Fuerza Centripeta\n");
    printf(" Demuestre el modulo de velocidad orbital v (m/s).\n");
    
    double respuesta = leer_flotante_seguro(" Ingrese la velocidad calculada (m/s): ", 1000.0, 20000.0);
    
    if (fabs(respuesta - nave->velocidad_orbital) < 100.0) {
        printf(" -> [CORRECTO] Insercion en LEO exitosa. v = %.2f m/s\n", nave->velocidad_orbital);
        nave->pruebas_superadas++;
    } else {
        printf(" -> [INCORRECTO] Desviacion critica. Valor real: %.2f m/s\n", nave->velocidad_orbital);
        nave->estabilidad_pct -= 15.0f;
    }
}
void ejecutar_fase_calculo_periodo(EstadoOrbitalLEO *nave) {
    printf("\n[FASE 2]: Calculo del Periodo Orbital (T)\n");
    double t_min = leer_flotante_seguro(" Ingrese el periodo T en MINUTOS: ", 10.0, 300.0);
    
    if (fabs(t_min - nave->periodo_minutos) < 2.0) {
        printf(" -> [CORRECTO] T = %.2f s (%.2f minutos por vuelta)\n", nave->periodo_segundos, nave->periodo_minutos);
        nave->pruebas_superadas++;
    } else {
        printf(" -> [INCORRECTO] Error de sincronizacion. Valor real: %.2f min\n", nave->periodo_minutos);
        nave->estabilidad_pct -= 15.0f;
    }
}
void ejecutar_fase_aceleracion_centripeta(EstadoOrbitalLEO *nave) {
    printf("\n[FASE 3]: Evaluacion de Aceleracion Centripeta\n");
    double ac = leer_flotante_seguro(" Ingrese la aceleracion centripeta (m/s^2): ", 1.0, 50.0);
    
    if (fabs(ac - nave->aceleracion_c) < 0.5) {
        printf(" -> [CORRECTO] Aceleracion soportada por tripulacion: %.2f m/s^2\n", nave->aceleracion_c);
        nave->pruebas_superadas++;
    } else {
        printf(" -> [INCORRECTO] Diagnostico erroneo. Valor real: %.2f m/s^2\n", nave->aceleracion_c);
        nave->estabilidad_pct -= 15.0f;
    }
}

void ejecutar_fase_evento_propulsor(EstadoOrbitalLEO *nave) {
    printf("\n[ALERTA FASE 4]: Activacion de Propulsor Auxiliar Lateral (a = 0.50 m/s^2, dt = 10s)\n");
    double dy = leer_flotante_seguro(" Ingrese la desviacion lateral instantanea dy (m): ", 0.0, 500.0);
    
    if (fabs(dy - nave->desviacion_lateral) < 1.0) {
        printf(" -> [EXITO] Correccion efectuada. Desviacion calculada: %.2f m\n", nave->desviacion_lateral);
        nave->pruebas_superadas++;
    } else {
        printf(" -> [FALLO] Deriva no compensada. Desviacion real: %.2f m\n", nave->desviacion_lateral);
        nave->estabilidad_pct -= 20.0f;
    }
} 
void generar_reporte_final(const EstadoOrbitalLEO *nave) {
    printf("\n====================================================================\n");
    printf("                  REPORTE FINAL DE MISIÓN ARTEMIS LEO\n");
    printf("====================================================================\n");
    printf(" Mision:                     %s\n", nave->nombre_mision);
    printf(" Radio Orbital Total (r):    %.2f km\n", nave->radio_orbital / 1000.0);
    printf(" Velocidad Orbital (v):      %.2f m/s\n", nave->velocidad_orbital);
    printf(" Periodo Orbital (T):        %.2f s (%.2f min)\n", nave->periodo_segundos, nave->periodo_minutos);
    printf(" Aceleracion Centripeta:    %.2f m/s^2\n", nave->aceleracion_c);
    printf(" Desviacion Propulsor:       %.2f m\n", nave->desviacion_lateral);
    printf(" Pruebas Superadas:          %d / 4\n", nave->pruebas_superadas);
    printf(" Estabilidad Final:          %.1f%%\n", nave->estabilidad_pct);
    printf(" Estado Final:               %s\n", (nave->estabilidad_pct >= 70.0) ? "ÉXITO DE ORBITA" : "MISIÓN FALLIDA");
    printf("====================================================================\n");
} 
