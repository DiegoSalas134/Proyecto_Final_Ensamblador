#ifndef JUEGO_H
#define JUEGO_H

#define FILAS 60
#define COLUMNAS 60

void iniciar_matriz(char matriz[FILAS][COLUMNAS]);
void imprimir(char matriz[FILAS][COLUMNAS], int jugador_fila, int jugador_columna, int monedas,int llaves, int pasos);

#endif