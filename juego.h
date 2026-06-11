#ifndef JUEGO_H
#define JUEGO_H

#define FILAS 60
#define COLUMNAS 60

void iniciar_matriz(char matriz[FILAS][COLUMNAS]);
void imprimir(char matriz[FILAS][COLUMNAS], int jugador_fila, int jugador_columna, int monedas,int llaves, int pasos, int monedas_totales);
//Funciones en Ensamblador (NASM)
int contar_caracteres(char *matriz, int total_celdas, char caracter);
int validar_movimiento(char *matriz, int columnas, int nueva_fila, int nueva_columna);
#endif