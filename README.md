# -utn-proyecto-C-k1.4-
//aclaracion: se puede ver desprolijo desde fuera, seleccionar opcion CODE o descargar a archivo readme para mayor claridad
simulador interactivo de una experiencia de manejo por consola del estado orbital de la nave Orion! adentrate y experimenta distintas fases desafia pero divertidas

 ------------------------ I N T E G R A N T E S ---------------------------------------------------------------------------------
 - Aquino Gabriel Lautaro     - legajo:30168
 - Tapia Beccari Santiago     - legajo:30436
 - Moray Salome               - legajo:30319

------------------------ ESCENARIO DESCRIPTO ------------------------------------------------------------------------------------
Nuestro grupo tiene como marco de referencia para la creación del programa el escenario numero 2 
propuesto por la catedra. Este escenario nos introduce a la nave Orion y detalla como es inyectada 
en una órbita terrestre baja o LEO, de estacionamiento, así como conceptos fundamentales para una
compresión mas detallada del fenómeno así como su altitud constante, la masa de la tierra, el radio
terrestre medio, etc. Luego nos propone incluir ciertas interrogantes que sean respuestas dentro del
desarrollo del programa las cuales hacen referencia a; modulo de velocidad orbital, cuanto tiempo
tardaría en realizar una vuelta completa a la Tierra, modulo de aceleración centrípeta que experimentan 
los astronautas dentro de la capsula, etc. De esta manera organizamos ciertas ideas de como integrar
estos conceptos dentro de un juego con ayuda de la inteligencia artificial. 

----------------DINAMICA Y REGLAS DEL JUEGO: Controlador de órbita LEO-----------------------------------------------------------
El juego es un simulador interactivo por consola, donde el usuario asume el rol de un ingeniero de control de vuelo en el Centro Espacial, encargado de estabilizar y monitorear la nave Orion en sus Órbitas Terrestres Baja (Leo). 
El objetivo del juego es mantener la estabilidad y la integridad estructural de la nave Orion, superando desafíos de control orbital, validando cálculos físicos en tiempo real y respondiendo correctamente a eventos imprevistos durante las órbitas.

-------------------------FASES DEL FLUJO DEL JUEGO-------------------------------------------------------------------------------
Menú Principal de Control de Misión: Al iniciar el programa compilado, el usuario accede a una interfaz limpia por consola con 3 opciones, si selecciona la primera iniciaran los eventos, si selecciona la segunda le muestran las reglas del juego y si selecciona la tercera sale del juego, esto fue cambiado debido a que antes era simplemente acceder a cualquiera de las fases pero el grupo de trabajo penso que lo iba a ser mas divertido y tipico de un juego que surgan continuamente los eventos y no que el propio usuario los seleccione.

FASE 1: Inicialización y Diagnóstico de la Órbita LEO ===========================================================================
* Al arrancar el programa, la consola muestra una interfaz con el reporte incial de la mision, cargando las constantes fisicas del sistema.
* El sistema te plantea tu primer desafío como operador: verificar los cálculos teóricos del MCU. El juego te pedirá ingresar la velocidad orbital necesaria. Si tus cálculos son correctos, el sistema autoriza la inserción orbital estable.

FASE 2: El ciclo de Orbitas ==================================================================================================== 
* Una vez estabilizada, la simulación pasa a la siguiente fase, donde en base a datos presentados el usuario debera ingresar el periodo exacto (con cierto margen de error) que realizo la nave Orion, si acierta se mantiene la estabilidad, sino se resta cierto porcentaje que afectaria si la mision final es exitosa o fallida

FASE 3: El desafio evento de emergencia ========================================================================================
* Hacia el final de la simulacion, se activa un evento de emergencia aleatorio.
* Se enciende un propulsor auxiliar lateral que genera un pulso de aceleración constante para corregir el rumbo.
* El usuario debe calcular e ingresar en la consola la desviación lateral instantánea resultante para recalibrar los sistemas de navegación automaticos.
* Si el usuario acierta, la nave recupera su orbita estable, si falla la integridad de la nave disminuye.

FASE 4: Reporte final de la mision ==============================================================================================
* Al superar (o no) el evento critico, la consola imprime un Informe técnico final de la NASA con todos los resultados analíticos requeridos por la catedra ( velocidad orbital, periodo en segundos y minutos, aceleración centrípeta y desviación
lateral), otorgando una puntuación basada en la precisión del usuario y una interfaz con distintas estadisticas y datos para que el mismo vea su desempeno 

=========================================== USO DE LA IA EN EL TRABAJO =========================================================

A lo largo del trabajo hemos recurrido a la inteligencia artificial Gemini para que ayude en ciertos aspectos de sintaxis de C y correccion mas que nada del archivo Makefile ya que ninguno de los integrantes tenia mucho conocimiento ni experiencia previa en una compilacion apropiada de archivos. 
El prompt mas relevante utilizado con la IA fue para que ayude a generar el Makefile asi la compilacion es directa y mucho mas rapida usando el comando mingw32-make y directamente generando un archivo llamado artemis_sim.exe siendo asi mucho mas sencilla la compilacion y ejecuccion correcta del programa, tambien se le ha pedido ciertas lineas como las que se van a citar a continuacion: 
if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            if (sscanf(buffer, "%d", &valor) == 1) {
                if (valor >= min && valor <= max) {
                    valido = 1; 
fgets y sscanf ayudarian a la lectura segura de los datos ingresados por el usuario reinterpretando simbolos letras en caso de numeros ya que de esta manera se podrian evitar errores de bucles infitos y demas sufridos en el desarrollo del programa 
tambien ciertas lineas donde se ha utilizado double/float han sido recomendadas por la IA para una correcta actualizacion de los estados de la nave y demas
Asi como tambien ha sido la IA la cual nos otorgo la idea de un juego de tipo generacion de eventos, aunque la desarrollamos primero como una interfaz donde se podian seleccionar por separado los eventos (como visto en los commits del GitHub), pero al final del trabajo los integrantes han corregido dicha interfaz de manera tal que el juego iba a desarrollarse continuamente fase por fase dandole mas sentido a la "generacion de eventos" y que no se sienta tan aburrido o tosco para el usuario siendo que al fin y al cabo el trabajo se trata de un videojuego. 
Ha ayudado tambien en situaciones de incertidumbre respecto a GitHub, uno de esos casos fue que al compilarse y guardar los archivos en una de las computadoras de uno de los integrantes, se subieron al github archivos derivados de la compilacion de tipo .o y .exe, para limpiarlos se ha solicitado a la IA ciertas lineas que ingresar en la terminal y asi limpiar el repositorio del proyecto
Por ultimo, la IA ha otorgado las formulas a utilizar para los calculos fisicos tales como aceleracion centripeta, periodo de orbita, ya que previamente los integrantes no tenian completa nocion de parametros requeridos, aunque las constantes terrestres y formulas generales han sido extraidas directamente del escenario como tendria que haber sido. 

======================================== INSTRUCCIONES DE COMPILACION Y EJECUCION ===============================================

Para ejecutar el programa es necesario descargar todos los archivos presentes en el github, siendo estos: 
main.c
artemis.c
validaciones.c
artemis.h
validaciones.h
Makefile.mak 

al ya tenerlos descargados es necesario contar con un programa de compilacion en C que pueda ejecutar comandos como gcc y make, teniendo eso en cuenta es necesario que todos los archivos esten en una misma carpeta

Paso siguiente es copiar la direccion de la carpeta donde estan los archivos (su ruta) para luego abrir la terminal de la computadora donde se este ejecutando e introducir las lineas: 

cd ruta/de/la/carpeta 

esto abriria la carpeta en la terminal, de no poder hacerlo, si se realiza click derecho a la carpeta puede existir una opcion llamada Abrir en terminal, al seleccionarla se llegaria al mismo cometido  

luego es necesario compilar los archivos, para ello es necesario ingresar la linea make, de salir un error puede funcionar la linea mingw32-make dependiendo el programa de compilacion con el que se prosiga 

al ejecutarse deberia de haber un mensaje en terminal donde se generan archivos .o y .exe resultantes de la compilacion

acto seguido introducir la linea: 

\.artemis_sim.exe

Y asi podras ejecutar el juego! 

















