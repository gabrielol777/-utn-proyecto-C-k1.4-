/* ============================================================================
 * Archivo: artemis.h
 * Declaración de constantes, structs y prototipos de funciones
 * ============================================================================ */ 
#ifndef ARTEMIS_H
#define ARTEMIS_H 
// Constantes Físicas Universales y del Dominio Artemis
#define G_CONST 6.674e-11        // N m^2 / kg^2
#define MASA_TIERRA 5.972e24     // kg
#define RADIO_TIERRA 6371000.0   // m
#define ALTITUD_LEO 192000.0     // m
#define MASA_ORION 33000.0       // kg 

typedef struct {
    char nombre_mision[50];
    double radio_orbital;        // r = RT + h
    double velocidad_orbital;    // v (m/s)
    double periodo_segundos;     // T (s)
    double periodo_minutos;      // T (min)
    double aceleracion_c;        // ac (m/s^2)
    double desviacion_lateral;   // Delta y (m)
    float estabilidad_pct;       // %
    int pruebas_superadas;
} EstadoOrbitalLEO;
void inicializar_nave(EstadoOrbitalLEO *nave);
void mostrar_encabezado();
void mostrar_menu();
void ejecutar_fase_demostracion(EstadoOrbitalLEO *nave);
void ejecutar_fase_calculo_periodo(EstadoOrbitalLEO *nave);
void ejecutar_fase_aceleracion_centripeta(EstadoOrbitalLEO *nave);
void ejecutar_fase_evento_propulsor(EstadoOrbitalLEO *nave);
void generar_reporte_final(const EstadoOrbitalLEO *nave);

#endif