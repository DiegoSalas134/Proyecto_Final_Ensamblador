#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FILAS 60
#define COLUMNAS 60

void intercambiar_celdas(
    char *matriz, int columnas, int fila1, int columna1,
    int fila2, int columna2
);

void imprimir(char matriz[FILAS][COLUMNAS], int jugador_fila, int jugador_columna) {
    system("cls");
    printf(" ==== Mapa BitQuest 20x20 ==== \n\n");
    
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
    printf("\nControles: w (arriba), a (izquierda), s (abajo), d (derecha)\n");
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
    matriz[1][1] = 'X'; //posicion inicial del jugador
}

int main(){
    char matriz[FILAS][COLUMNAS];

    int jugador_fila = 1, jugador_columna = 1;
    char movimiento;

    iniciar_matriz(matriz);
    do
    {
        imprimir(matriz, jugador_fila, jugador_columna);
        printf("Ingrese su movimiento: ");
        scanf(" %c", &movimiento);
        movimiento = tolower(movimiento);

        //calcular a donde se movera el jugador
        int tmp_fila = jugador_fila;
        int tmp_columna = jugador_columna;

        //coordenadas a donde se movera el jugador
        switch (movimiento) {
            case 'w': 
                tmp_fila--;
                break; 
            case 'a': 
                tmp_columna--; 
                break; 
            case 's': 
                tmp_fila++; 
                break;
            case 'd': 
                tmp_columna++; 
                break;
            case 'q': 
                printf("Saliendo del juego...\n"); 
                return 0;
            default: 
                printf("Movimiento no valido. Use w, a, s o d.\n"); 
                continue;
        }
        
        //verificar que el movimiento sea valido (no chocar con paredes)
        if (matriz[tmp_fila][tmp_columna] != '#') {
            matriz[jugador_fila][jugador_columna]= '.'; //ponemos un punto en la celda anterior del jugador
            jugador_fila = tmp_fila;
            jugador_columna = tmp_columna;//actualizamos la posicion del jugador
            matriz[jugador_fila][jugador_columna] = 'P'; //colocamos al jugador en la nueva posicion
        } 
           
    } while (movimiento != 'q');
    
    return 0;
}