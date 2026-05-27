#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define FILAS 8
#define COLUMNAS 8

void intercambiar_celdas(
    int *matriz, int columnas, int fila1, int columna1,
    int fila2, int columna2
);

void imprimir(int matriz[FILAS][COLUMNAS]) {
    printf("Matriz actual\n\n");
    printf("\t");
    for (int i = 0; i < COLUMNAS; i++) {
        printf("-----");

    }
    printf("\n");
    for (int i = 0; i < FILAS; i++) {
        printf("%3d |", i);
        for (int j = 0; j < COLUMNAS; j++) {
            printf("%4d |", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void iniciar_matriz(int matriz[FILAS][COLUMNAS]) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = i * 10 + j;
        }
    }
}

int main(){
    int matriz[FILAS][COLUMNAS];

    int fila1, columna1, fila2, columna2;

    char direccion, continuar;

    iniciar_matriz(matriz);
    do {
        system("cls");
        imprimir(matriz);

        printf("Selecciona la celda base\n");
        printf("Fila: ");
        scanf("%d", &fila1);

        printf("Columna: ");
        scanf("%d", &columna1);

        printf("Selecciona la direccion a intercambiar (w/a/s/d): ");
        scanf(" %c", &direccion);

        direccion = tolower(direccion);

        fila2 = fila1;
        columna2 = columna1;

        if (direccion == 'w') {
            fila2--;
        } else if (direccion == 's') {
            fila2++;
        } else if (direccion == 'a') {
            columna2--;
        } else if (direccion == 'd') {
            columna2++;
        } else {
            printf("Direccion no valida. Intenta de nuevo.\n");
            printf("Presiona Enter para continuar...");
            getchar(); // Limpiar el buffer
            getchar(); // Esperar a que el usuario presione Enter
            continue;
        }
        if (fila2 < 0 || fila2 >= FILAS || columna2 < 0 || columna2 >= COLUMNAS) {
            printf("Movimiento fuera de los limites. Intenta de nuevo.\n");
            printf("Presiona Enter para continuar...");
            getchar(); // Limpiar el buffer
            getchar(); // Esperar a que el usuario presione Enter
            continue;
        }

        // Intercambiar las celdas
        intercambiar_celdas(
            &matriz[0][0], COLUMNAS, fila1, columna1, fila2, columna2
        );
        printf("¿Deseas hacer otro movimiento? (s/n): ");
        scanf(" %c", &continuar);
    } while (tolower(continuar) == 's');
    system("pause");
    return 0;
}