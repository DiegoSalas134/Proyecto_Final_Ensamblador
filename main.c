#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FILAS 60
#define COLUMNAS 60

void intercambiar_celdas(
    char *matriz, int columnas, int fila1, int columna1,
    int fila2, int columna2
);

void imprimir(char matriz[FILAS][COLUMNAS], int jugador_fila, int jugador_columna, int monedas,int llaves, int pasos) {
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
    printf("Monedas obtenidas: %d\n", monedas);

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

int main(){
    char matriz[FILAS][COLUMNAS];

    int jugador_fila = 1, jugador_columna = 1;
    char movimiento;

    int contador_monedas = 0;
    int contador_llaves = 0;
    int contador_pasos = 0;


    iniciar_matriz(matriz);
    do
    {
        imprimir(matriz, jugador_fila, jugador_columna, contador_monedas, contador_llaves, contador_pasos);
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
        char destino = matriz[tmp_fila][tmp_columna];
        if (destino == '#')
        {
            continue; //es una pared
        }
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