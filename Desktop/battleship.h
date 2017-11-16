#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

/*MACROS*/

#define FILAS 10 //Filas del tablero
#define COLUMNAS 10 //Columnas del tablero

#define N_BARCOS 5 //Numero de barcos

#define HORIZONTAL 0 //Posicion horizontal
#define VERTICAL 1 //Posicion vertica

#define JUGADOR_UNO 0 //Turno del jugador 1
#define JUGADOR_DOS 1 //Turno del jugador 2

#define AGUA '~' //Agua en el tablero
#define ACIERTO '1' //Acierto a una parte de un barco
#define FALLO '0' //Fallo en darle a una parte de un barco

#define PORTAAVIONES 'P'
#define ACORAZADO 'A'
#define FRAGATA 'F'
#define SUBMARINO 'S'
#define BUQUE 'B'

#define NORTE 0
#define SUR 1
#define OESTE 2
#define ESTE 3

/* ATRIBUTOS */

typedef struct num_casillas {
	int PORTAAVIONES_l = 5;
	int ACORAZADO_l = 4;
	int FRAGATA_l = 3;
	int SUBMARINO_l = 2;
	int BUQUE_l = 1;
} Tipo_barco;

/* CLASES */

typedef struct navio {
	char simbolo; //Simbolo que lo representa
	short longitud; //Tamano del barco
	char *nombre; //Nombre del barco
} Navio;

typedef struct puntuacion {
	int n_aciertos; //numero de aciertos
	int n_fallos; //numero de fallos
	int t_disparos; //total de disparos
	double af_ratio; //ratio de aciertos/fallos
} Puntuacion;

typedef struct coordenadas {
	int fila;
	int columna;
} Coordenadas;

typedef struct casilla {
	char simbolo; //Simnolo en la casilla
	Coordenadas posicion; //Posicion en el tablero
} Casilla;