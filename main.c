#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "juego.h"

int main(){
    char matriz[FILAS][COLUMNAS];

    int jugador_fila = 1, jugador_columna = 1;
    char movimiento;

    int contador_monedas = 0;
    int contador_llaves = 0;
    int contador_pasos = 0;


    iniciar_matriz(matriz);

    int total_celdas = FILAS * COLUMNAS;
    int monedas_totales = contar_caracteres(&matriz[0][0], total_celdas, 'M');
    
    do
    {
        imprimir(matriz, jugador_fila, jugador_columna, contador_monedas, contador_llaves, contador_pasos, monedas_totales);
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
        
        //que hya en la celda?
        if (validar_movimiento(&matriz[0][0], COLUMNAS, tmp_fila, tmp_columna) == 0){
            continue;
        }
        char destino = matriz[tmp_fila][tmp_columna];
        if (destino == 'D' && contador_llaves == 0){
            continue;
        }
        //ya en esta seccion el movimiento es valido y se va a mover el jugador
        if (destino == 'M') {
            contador_monedas++;
        }else if (destino=='K'){
            contador_llaves++;
        }else if (destino=='E'){
            printf("Felicidades!!! Has ganado el juego BitQuest\n");
            return 0;
        }
        contador_pasos++;
        matriz[jugador_fila][jugador_columna] = '.';//deja un rastro del camino recorrido
        jugador_fila = tmp_fila;
        jugador_columna = tmp_columna;
        matriz[jugador_fila][jugador_columna] = 'P';//mover al jugador
        
    } while (movimiento != 'q');
    
    return 0;
}