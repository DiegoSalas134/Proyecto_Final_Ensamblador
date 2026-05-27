bits 64
default rel

global intercambiar_celdas

;parametros 5 y 6
;[rsp + 40] fila2
;[rsp + 48] columna2
section .text

intercambiar_celdas:
    ; clacular el indice= fila1*columnas+columna1
    mov eax, r8d ;Copia fila1 (r8d) a la caja de trabajo eax
    imul eax, edx ;Multiplica eax (fila1) por edx (columnas) el Resultado se queda en eax
    add eax, r9d ;suma r9d (columna1) a eax

    ;convertir indice a desplazamiento
    movsxd rax, eax ;Pasa el indice a un registro de 64 bits (rax) para manejar memoria
    lea r10, [rcx + rax*4] ;cargar direccion efectiva

    ;fila2 y columna2
    mov r11d, [rsp + 40] 
    mov eax, r11d
    imul eax, edx
    mov r11d, [rsp + 48]
    add eax, r11d

    movsxd rax, eax
    lea r11, [rcx + rax*4]

    ;intercambiar
    mov eax, [r10]
    mov r8d, [r11]

    mov [r10], r8d
    mov [r11], eax
    ret


