# -utn-proyecto-C-k1.4-
simulador interactivo de una experiencia de manejo por consola del estado orbital de la nave Orion! adentrate y experimenta distintas fases desafiantes pero divertidas
 ------------------------ I N T E G R A N T E S ----------------------------
 - Aquino Gabriel Lautaro     - legajo:30168
 - Tapia Beccari Santiago     - legajo:
 - Moray Salome               - legajo:30319

------------------------ ESCENARIO DESCRIPTO ----------------------------------------------------
Nuestro grupo tiene como marco de referencia para la creación del programa el escenario numero 2 
propuesto por la catedra. Este escenario nos introduce a la nave Orion y detalla como es inyectada 
en una órbita terrestre baja o LEO, de estacionamiento, así como conceptos fundamentales para una
compresión mas detallada del fenómeno así como su altitud constante, la masa de la tierra, el radio
terrestre medio, etc. Luego nos propone incluir ciertas interrogantes que sean respuestas dentro del
desarrollo del programa las cuales hacen referencia a; modulo de velocidad orbital, cuanto tiempo
tardaría en realizar una vuelta completa a la Tierra, modulo de aceleración centrípeta que experimentan 
los astronautas dentro de la capsula, etc. De esta manera organizamos ciertas ideas de como integrar
estos conceptos dentro de un juego con ayuda de la inteligencia artificial. 

----------------DINAMICA Y REGLAS DEL JUEGO: Controlador de órbita LEO---------------------------
El juego es un simulador interactivo por consola, donde el usuario asume el rol de un ingeniero de control de vuelo en el Centro Espacial, encargado de estabilizar y monitorear la nave Orion en sus Órbitas Terrestres Baja (Leo). 
El objetivo del juego es mantener la estabilidad y la integridad estructural de la nave Orion, superando desafíos de control orbital, validando cálculos físicos en tiempo real y respondiendo correctamente a eventos imprevistos durante las órbitas.
-------------------------FASES DEL FLUJO DEL JUEGO-----------------------------------------------
Menú Principal de Control de Misión: Al iniciar el programa compilado, el usuario accede a una interfaz limpia por consola con opciones numeradas para gestionar los diagnósticos de la nave, iniciar las simulaciones orbitales o salir de la sesión.
FASE 1: Inicialización y Diagnóstico de la Órbita LEO
* Al arrancar el programa, la consola muestra una interfaz con el reporte incial de la mision, cargando las constantes fisicas del sistema.
* El sistema te plantea tu primer desafío como operador: verificar los cálculos teóricos del MCU. El juego te pedirá ingresar datos como la velocidad orbital necesaria o el tiempo que le toma dar una vuelta completa a la Tierra. Si tus cálculos son correctos, el sistema autoriza la inserción orbital estable.
FASE 2: El ciclo de Orbitas 
* Una vez estabilizada, la simulación entra en un bucle por turnos que representan las vueltas orbitales de la nave.
* En cada turno, el programa te informa el estado actual de la misión: cuantas orbitas se han completado y el porcentaje de integridad de la capsula.
FASE 3: El desafio evento de emergencia
* Hacia el final de la simulacion, se activa un evento de emergencia aleatorio.
* Se enciende un propulsor auxiliar lateral que genera un pulso de aceleración constante para corregir el rumbo.
* El usuario debe calcular e ingresar en la consola la desviación lateral instantánea resultante para recalibrar los sistemas de navegación automaticos.
* Si el usuario acierta, la nave recupera su orbita estable, si falla la integridad de la nave disminuye.
  FASE 4: Reporte final de la mision
  * Al superar (o no) el evento critico, la consola imprime un Informe técnico final de la NASA con todos los resultados analíticos requeridos por la catedra ( velocidad orbital, periodo en segundos y minutos, aceleración centrípeta y desviación lateral), otorgando una puntuación basada en la precisión del usuario.












