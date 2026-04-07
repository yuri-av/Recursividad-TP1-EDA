#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*Ejercicio 6: Se tiene una cadena que representa una onda digital de señales L (Low) y H (High). Se pide obtener recursivamente la onda que representa utilizando “_” y
 “|”.
Ejemplos:
ondaDigital (“LHLHL”) => “_ |¯ |_|¯ |_”
ondaDigital (“HHHHLLLLHHHHHLLHH”) => “¯ ¯ ¯ ¯ | _ _ _ _ |¯ ¯ ¯ ¯ ¯ | _ _ | ¯ ¯*/

void OndaDigital(char *cadena) {
    if (*cadena == '\0') {
        return;
    }

    //caso inicial
    if (*cadena == 'L') {
        printf("_");
    } else {
        printf("¯");
    }

    //si hubo cambio
    if (*(cadena + 1) != '\0') {
        printf(" ");
        if (*cadena != *(cadena + 1)) {
            printf("|");
        }
    }
    OndaDigital(cadena + 1);
}


int main() {
    char cadena[100];
    int valido;

    do {
        valido = 1;
        printf("Ingrese la onda digital (solo L y H): ");
        scanf("%99s", cadena);

        for (int i = 0; cadena[i] != '\0' && valido; i++) {
            if (cadena[i] != 'L' && cadena[i] != 'H') {
                printf("Error. Reintente.\n", cadena[i]);
                valido = 0;
            }
        }

    } while (!valido);

    printf("Resultado: ");
    OndaDigital(cadena);
    printf("\n");

    return 0;
}
