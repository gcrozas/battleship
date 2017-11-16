#include "battleship.h"

int main (void)
{
	/*  */
	
	Puntuacion Jugadores[2] = {{0, 0, 0, 0.0}, {0, 0, 0, 0.0}}; /* Puntuacion de los jugadores: aciertos,fallos,total de disparos, ratio f/a */
	
	Casilla TableroJugadorUno[FILAS][COLUMNAS];       /* Tablero del jugador 1 */
	Casilla TableroJugadorDos[FILAS][COLUMNAS];       /* Tablero del jugador 2 */
	
	Coordenadas blanco;             /* valores fila y columna de un blanco */
	Coordenadas blancoTemp;         /* valores fila y columna para almacenar un valor temporal*/
	Coordenadas blancoOriginal;       /* valores fila y columna originales del blanco */
	Navio Barco[N_BARCOS] = {{'P', 5, "Portaaviones"}, 
	                         {'A', 4, "Acorazado"}, 
	                         {'F', 3, "Fragata"}, 
	                         {'S', 2, "Submarino"}, 
	                         {'B', 1, "Buque"}};
	Boolean    targetMode     = FALSE;                    /* modo: Hubo un acierto*/
	Boolean    p_cardinals[4]   = {TRUE, TRUE, TRUE, TRUE}; /* Representa los 4 puntos cadinales, N, S, O, E */
	Boolean    Hundido = FALSE;                    /* Si un barco fue hundido */
	
	short BarcosHundidos[2][N_BARCOS] = {{5, 4, 3, 2, 1},    
	                                   {5, 4, 3, 2, 1}};  /* Registra partes de cada barco destruidas  */
	short Jugador = 0;	           /* 0 -> Jugador 1, 1 -> Jugador 2 */
	short Disparo = 0;             /* Almacena un valor temporal que representa si un barco fue disparado */
	int   opcion = 0;             /* Opcion del jugador de ubicar sus barcos de forma maanual o random */
	
	
	int   Norte = 0,             /* Almacena cambios del valor cuando van hacia el norte */
		  Sur = 0,             /* Almacena cambios del valor cuando van hacia el sur */
		  Este = 0,             /* Almacena cambios del valor cuando van hacia el este */
		  Oeste = 0;             /* Almacena cambios del valor cuando van hacia el oeste */
		  
	int   i = 0, contador = 1;  /* i y contador son usados como contadores */
		  
	char  SimboloBarco = '\0'; /* valor temporal que se da para guardar el simbolo que representa un barco */
	
	/* Inicia programa */
	srand ((unsigned int) time (NULL));
	
	/* Imprime el mensaje de bienvenida en pantalla */
	PantallaInicio();
	systemMessage ("                            Presione <ENTER> para continuar!\n");
	system ("cls"); //Limpia la pantalla
	/* Cada tablero de los jugadores debe inicializarse lleno de '~' indicando
	 * que no se ha colocado barcos en ninguno de los tableros.
	 */

	inicializaTablero (TableroJugadorUno);
	inicializaTablero (TableroJugadorDos);

	/* La flota de ambos jugadores se encuentra compuesta por 5 barcos que estan escondiendose del enemigo. 
	 * Cada barco se diferencia entre si por su "tamano" 
	 * o por el numero de casillas que ocupa en el tablero. 
	 *      Portaaviones ocupa 5 casillas, 
	 *      Acorazado ocupa 4 casillas, 
	 *      Fragata ocupa 3 casillas, 
	 *      Submarino ocupa 2 casillas, y 
	 *      Buque ocupa 1 casilla. 
	 */

	/* Antes de que la partida inicie, el jugador tiene la opcion de 
	 * ubicar manualmente cada uno de los 5 barcos en el tablero o que estos sean 
	 * ubicados de manera aleatoria en el tablero. Si el jugador decide ubicar los barcos 
	 * de forma manual, entonces el/ella debera colocar primero el Portaaviones, 
	 * despues el Acorazado, luego la Fragata, despues el Submarino, 
	 * y de ultimo, el Buque. 
	 */
	printf ("> Seleccione el modo en que ubicara los barcos:\n");
	printf ("> [1] Manual\n");
	printf ("> [2] Random\n");
	printf ("> Ingrese una opcion: ");
	scanf ("%d", &opcion);

	switch (opcion) {
		case 1: ModoManual (TableroJugadorUno, Barco);
	            break;
		case 2: ModoRandom (TableroJugadorUno, Barco);
				break;
	}

	/* Los barcos no puedes ser ubicados en diagonal en el tablero, 
	 * solo pueden ubicarse en vertical o en horizontal. El programa 
	 * verifica que el usuario trate de ubicar el barco fuera de las condiciones posibles 
	 * o sobre un barco que ya este colocado. Cada casilla en el tablero 
	 * contiene una parte del barco que se identifica como 'P' para los 
	 * Portaaviones, 'A' para el Acorazado, 'F' para la Fragata, 'S' para el Submarino, o 
	 * 'B' para el Buque.
	 */
	return 0;
}