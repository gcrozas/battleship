#include "battleship.h"

/*PantallaInicio: Imprime un mensaje de bienvenida junto con las reglas del juego*/
void PantallaInicio (void) {
	printf ("XXXXX   XXXX  XXXXXX XXXXXX XX     XXXXXX  XXXXX XX  XX XX XXXX\n");
	printf ("XX  XX XX  XX   XX     XX   XX     XX     XX     XX  XX XX XX  XX\n");
	printf ("XXXXX  XX  XX   XX     XX   XX     XXXX    XXXX  XXXXXX XX XXXX\n"); 
	printf ("XX  XX XXXXXX   XX     XX   XX     XX         XX XX  XX XX XX\n");
	printf ("XXXXX  XX  XX   XX     XX   XXXXXX XXXXXX XXXXX  XX  XX XX XX\n");
	printf ("\n\n");
	printf ("REGLAS DEL JUEGO:\n");
	printf ("1. Este es un juego de dos jugadores.\n");
	printf ("2. El jugador 1 crea el servidor.\n");
	printf ("3. Las dimensiones del tablero es 10x10");
	printf ("4. Existen cinco tipos de barcos que seran ubicados desde el mas grande al mas pequeño.\n");	
	printf ("[P] Portaviones ocupa 5 casillas, [A] Acorazado ocupa 4 casillas, [F] Fragata\n");
	printf ("   ocupa 3 casillas, [S] Submarino ocupa 2 casillas, [B] Buque ocupa 1 casilla\n");
	printf ("5. La computadoa de manera aleatoria selecciona el jugador que comenzara primero\n");
	printf ("6. El juego comienza con cada jugador tratando de adivinar la localizacion de los barcos\n");
	printf ("   del jugador oponente en el tablero del juego; [1] acierto y [0] fallo\n");
	printf ("7. El primer Jugador que adivine la localizacion de todos los barcos, gana\n\n");
}

/*inicializaTablero: Esta funcion inicializa la matriz que representa el tablero del jugador*/
void inicializaTablero (Casilla Tablero[][COLUMNAS]) {
	int i = 0, j = 0;
	/*El tablero se llenara con agua*/
	for (i = 0; i < FILAS; i++)
		for (j = 0; j < COLUMNAS; j++) {
			Tablero[i][j].simbolo          = AGUA;
			Tablero[i][j].posicion.fila    = i;
			Tablero[i][j].posicion.columna = j;
		}
}

/* imprimeTablero: Esta funcion imprime el tablero en la pantalla, y la opcion de mostrar o no mostrar las marcas*/
void imprimeTablero (Casilla Tablero[][COLUMNAS], Boolean mostrarMarcas) {
	int i = 0, j = 0;
	printf ("  0 1 2 3 4 5 6 7 8 9\n");
	for (i = 0; i < FILAS; i++) {
		printf ("%d ", i);
		for (j = 0; j < COLUMNAS; j++) {
			if (mostrarMarcas == TRUE) 
				printf ("%c ", Tablero[i][j].simbolo);
			else {
				switch (Tablero[i][j].simbolo) {
					case ACIERTO:   printf ("%c ", ACIERTO);   break;
					case FALLO:  printf ("%c ", FALLO);  break;
					case AGUA: 
					default:    printf ("%c ", AGUA); break;
				}
			}
		}
		putchar ('\n');
	}
}

/*colocarBarcosEnElTablero: Esto permite al jugador colocar cinco diferentes tipos de barco en
 * una casilla del tablero, ya sea en horizontal o vertical. 
 */
void colocarBarcosEnElTablero (Casilla Tablero[][COLUMNAS], Navio barco, 
	                     Coordenadas posicion, int direccion) {
	int i = barco.longitud - 1;
	for (i = 0; i < barco.longitud; i++) {
		if (direccion == HORIZONTAL)
			/* HORIZONTAL */
			Tablero[posicion.fila][posicion.columna + i].simbolo = barco.simbolo;
		else /* VERTICAL */
			Tablero[posicion.fila + i][posicion.columna].simbolo = barco.simbolo;
	}
}
}