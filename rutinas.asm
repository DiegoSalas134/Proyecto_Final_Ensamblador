bits 64
default rel

global contar_caracteres
global validar_movimiento

section .text

;funcion 1: contar_caracteres
contar_caracteres:
    xor rax, rax ;contador de monedas
    xor r9, r9 ;i=0 (indice para recorrer el mapa)

.ciclo:
    cmp r9, rdx ;comparar el indice r9 con el total de celdas rdx
    jge .fin ;si el indice es mayor o igual al total de celdas salimos del ciclo

    mov r10b, byte [rcx + r9] ;cargar el caracter actual del mapa en r10d
    cmp r10b, r8b ;comparar el caracter que se nos pide desde C
    jne .siguiente ;si no son iguales saltamos y no cuentamos

    inc rax ;si son iguales incrementamos el contador

.siguiente:
    inc r9 ;i++
    jmp .ciclo ;repetimos el ciclo
.fin:
    ret

;funcion 2: validar_movimiento
validar_movimiento:
    mov eax, r8d ;le pasamos nueva_fila a eax
    imul eax, edx ;multiplicamos por las columnas
    add eax, r9d ;sumamos nueva_columna para obtener el indice final

    movsxd rax, eax ;extendemos a 64 bits
    mov r10b, byte [rcx + rax] ;cargamos el caracter del mapa en r10b

    ;validamos si es una pared
    cmp r10b, '#' ;comparar con el caracter de pared
    je .es_pared ;si es una pared no se puede mover

    mov rax, 1 ;ponemos 1 porque es un movimiento valido
    ret
.es_pared:
    mov rax, 0 ;ponemos 0 porque es un movimiento no valido
    ret