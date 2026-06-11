#include <stdio.h>
#include <stdlib.h>
#include "juego.h"

void imprimir(char matriz[FILAS][COLUMNAS], int jugador_fila, int jugador_columna, int monedas,int llaves, int pasos, int monedas_totales) {
    system("cls");
    printf(" ===================== Mapa BitQuest 20x20 ====================== \n\n");
    
    //calculos para iniciarcentrando al jugador en el mapa
    int inicio_fila = jugador_fila - 10;
    int inicio_columna = jugador_columna - 10;

    if (inicio_fila < 0) inicio_fila = 0;
    if (inicio_columna < 0) inicio_columna = 0;
    //ajustamos el inicio para no salirnos del mapa
    if (inicio_fila + 20 > FILAS) inicio_fila = FILAS - 20;
    if (inicio_columna + 20 > COLUMNAS) inicio_columna = COLUMNAS - 20;

    for (int i = inicio_fila; i < inicio_fila +20; i++) {
        for (int j = inicio_columna; j < inicio_columna + 20; j++) {
            printf("%c", matriz[i][j]);
        }
        printf("\n");
    }

    //estado del jugador
    printf("\nNivel: 1\n");
    if (llaves == 1){
        printf("Llave: Si\n");
    }else{
        printf("Llave: No\n");
    }

    printf("Pasos: %d\n", pasos);
    printf("Monedas recolectadas: %d / %d\n", monedas, monedas_totales);

    printf("\nControles: w (arriba), a (izquierda), s (abajo), d (derecha), q (salir)\n");

}

void iniciar_matriz(char matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (i == 0 || i == FILAS - 1 || j == 0 || j == COLUMNAS - 1) {
                matriz[i][j] = '#'; //pared
            } else {
                matriz[i][j] = ' '; //camino
            }
        }
    }
    matriz[1][1] = 'P'; //posicion inicial del jugador
    matriz[2][5] = 'M'; //moneda
    matriz[3][5] = 'K'; //llave
    matriz[4][5] = 'D'; //puerta
    matriz[5][5] = 'E'; //Salida
}