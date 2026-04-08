#include "tp_1_recursividad.h"
//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//prototipo de validacion
int validacionEntero(int *n, int scan, char c);
int validacionn(void);

int main(){
    char opcion[2];
    int valido=0;

    printf("---ELIJA QUE EJERCICIO EJECUTAR---\n");
    printf("A) EJERCICIO 1 |Palindromo\n");
    printf("B) EJERCICIO 2 |Producto\n");
    printf("C) EJERCICIO 3 |Fibonacci\n");
    printf("D) EJERCICIO 4 |Division\n");
    printf("E) EJERCICIO 5 |SeparadorMiles\n");
    printf("F) EJERCICIO 6 |MafiaChina\n");
    printf("G) EJERCICIO 7 |ondaDigital\n");
    printf("H) EJERCICIO 8 |subconjuntosQueSuman\n");
    printf("I) EJERCICIO 9 |divisiblePor7\n");
    printf("J) EJERCICIO 10|Explosion\n");

    do{
        printf("Ingrese la letra del ejercicio: ");
        if (scanf(" %1[A-Ja-j]", opcion) == 1){
            // verificar que lo siguiente sea enter
            if (getchar() == '\n'){
                valido = 1;
            }
            else{
                printf("Error: solo una letra entre A y J.\n");
                while (getchar() != '\n')
                        ;
                }
            }
            else{
                printf("Error: entrada invalida.\n");
                while (getchar() != '\n')
                    ;
            }
    } while (!valido);

        char letra = toupper(opcion[0]);
        switch (letra)
        {
        ////////////////////////////////////_UNO_/////////////////////////////////////////////////
    
        case 'A': {
            char palabra[100];
                
                printf("Ingrese una palabra o frase: ");
                
                fgets(palabra, sizeof(palabra), stdin);
                palabra[strcspn(palabra, "\n")] = 0; //quita el salto de linea

                if (palindromo(palabra)) {
                    printf("Es un palindromo.\n");
                } else {
                    printf("No es un palindromo.\n");
                }
            break;
        }
        ////////////////////////////////////_DOS_/////////////////////////////////////////////////
        case 'B': {
            int a, b;
            char c;
            printf("Ingrese un numero entero 'a' para ser multiplicado: ");
            while (scanf("%d%c", &a, &c) != 2 || c != '\n')
            {
                while (getchar() != '\n')
                    ;
                printf("Error de tipo de datos: ingrese un numero entero: ");
            }
            printf("Ingrese un numero entero 'b' para multiplicar: ");
            while (scanf("%d%c", &b, &c) != 2 || c != '\n')
            {
                while (getchar() != '\n')
                    ;
                printf("Error de tipo de datos: ingrese un numero entero: ");
            }
            printf("Iniciando recursion...\n");
            int prod = producto(a, b);
            printf("resultado = %i\n", prod);
            break;
        }
        ////////////////////////////////////_TRES_/////////////////////////////////////////////////
        case 'C':{
            int fibo;
            char c;
            printf("Ingrese un numero entero: ");
            int scan = scanf("%d%c", &fibo, &c);

            validacionEntero(&fibo, scan, c);

            int resultado = terminoSeridFibonacci(fibo);
            printf("fibonacci(%d) = %i\n", fibo, resultado);
            break;
        }
        ////////////////////////////////////_CUATRO_/////////////////////////////////////////////////
        case 'D': {
            int dividendo, divisor, precision;
            float resultado;
            printf("Ingrese el dividendo: ");
            scanf("%i", &dividendo);

            printf("Ingrese el divisor: ");
            scanf("%i", &divisor);
            while (divisor == 0)
            {
                printf("Error: no se puede dividir por 0, ingrese de nuevo: ");
                scanf("%i", &divisor);
            }

            printf("Digitos de precision: ");
            scanf("%i", &precision);

            resultado=division(dividendo,divisor,precision);
            
            printf("el resultado es: %.*f",precision,resultado);
            break;
        }
        ////////////////////////////////////_CINCO_/////////////////////////////////////////////////
        case 'E': {
            char numero[100];
            int esValido = 0;
            int esNegativo = 0;
            char *resultadoFinal = NULL;

            // --- BLOQUE DE VALIDACIÓN ---
            do {
                printf("Ingrese un numero: ");
                
                // Intentamos leer solo números y el signo menos
                if (scanf("%99[-0-9]", numero) == 1) {
                    
                    // Verificamos que el usuario no haya escrito letras después de los números
                    if (getchar() == '\n') {
                        esValido = 1;
                    } else {
                        printf("Error: Solo se permiten numeros enteros.\n");
                        while (getchar() != '\n');
                    }

                    // Detectamos si el número ingresado empieza con el signo menos
                    if (numero[0] == '-') {
                        esNegativo = 1;
                    }
                } else {
                    printf("Error: Entrada invalida.\n");
                    while (getchar() != '\n');
                }

            } while (!esValido);

            // --- BLOQUE DE PROCESAMIENTO ---
            
            if (esNegativo == 1) {
                resultadoFinal = agregarSeparadorMiles(&numero[1]);
            } else {
                resultadoFinal = agregarSeparadorMiles(numero);
            }

            // --- SALIDA Y LIBERACIÓN ---
            
            if (resultadoFinal != NULL) {
                printf("Original: %s\n", numero);
                printf("Formateado: %s%s\n", (esNegativo ? "-" : ""), resultadoFinal);


                free(resultadoFinal);
            } else {
                printf("Error al procesar el numero.\n");
            }
            break;
        }
        ////////////////////////////////////_SEIS_/////////////////////////////////////////////////
        case 'F': {
                char c;
                int n;
                printf("Ingrese el nivel de la reunion: ");
                int scan = scanf("%d%c", &n, &c);
                validacionEntero(&n, scan, c);

                char *resultadoM= reunionMafia(n);
                printf("Vista frontal de la delegacion: %s\n", resultadoM);

                free(resultadoM);
            break;
        }

        ////////////////////////////////////_SIETE_/////////////////////////////////////////////////
        case 'G': {
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
            char *onda=ondaDigital(cadena);
            //OndaDigital(cadena);
            printf("\n");

            break;
        }
        ////////////////////////////////////_OCHO_/////////////////////////////////////////////////
        case 'H': {
            #define MAX_ELEMENTOS 100
            int lista_num[MAX_ELEMENTOS + 1];
            int tamanio, objetivo;

            printf("=== Subconjuntos que suman N ===\n\n");

            while (1)
            {
                tamanio = leer_entero("Cuantos elementos tiene el conjunto? ");
                if (tamanio <= 0)
                    printf("  Error: debe ser mayor a 0.\n");
                else
                    break;
            }

            printf("Ingrese los %d elementos (pueden ser negativos):\n", tamanio);
            for (int i = 0; i < tamanio; i++)
            {
                char mensaje[30];
                sprintf(mensaje, "  Elemento [%d]: ", i + 1);
                lista_num[i] = leer_entero(mensaje);
            }
            lista_num[tamanio] = -999;

            objetivo = leer_entero("Ingrese el numero objetivo (N): ");

            printf("\nSubconjuntos que suman %d:\n", objetivo);
            subconjuntosQueSumanN(lista_num, objetivo);
            break;
        }
        ////////////////////////////////////_NUEVE_/////////////////////////////////////////////////
        case 'I': {
        
            int n = validacionn();

            bool resultado = divisiblePor7(n);
            if (resultado == true)
            {
                printf("%i es divisible por 7\n", n);
            }
            else
            {
                printf("%i no es divisible por 7\n", n);
            }
            break;
        }
        ////////////////////////////////////_DIEZ_/////////////////////////////////////////////////
        case 'J':{
            int n,b;

            printf("ingrese un valor a explotar: ");
            scanf("%d",&n);
            printf("\n");
            printf("ingrese un valor bomba: ");
            scanf("%d",&b);
            printf("\n");

            int *arrayExplosivo=explosion(n,b);

            printf("la explosion creo este array: \n");
            printf("[");
            for(int i=0;arrayExplosivo[i]!=-1;i++){
                printf("%d ",arrayExplosivo[i]);
            }
            printf("]\n");
            break;}
        ////////////////////////////////////_FIN_/////////////////////////////////////////////////
        default:
            break;
        }
}

int validacion_entero(int *n, int scan, char c){
    while (scan != 2 || c != '\n' || *n < 1){
        if (scan != 2 || c != '\n'){
            while (getchar() != '\n'){
                    ;
        }
        printf("Error de tipo de datos: ingrese un numero entero mayor a 0: ");
        scan = scanf("%d%c", n, &c);
    }
    return *n;
}

int validacionn(){
    int n;
    char buffer[100];
    char extra;

    while (1){
        printf("Ingrese un valor: ");

        if (fgets(buffer, sizeof(buffer), stdin) == NULL)
            continue;

        if (buffer[0] == '\n')
        {
            printf("Error: No ingreso nada. Por favor, ");
            continue;
        }

        int leidos = scanf(buffer, "%d %c", &n, &extra);

        if (leidos == 1)
        {
            return n;
        }
        else{
            printf("Error de tipo de datos: ingrese un numero entero: ");
        }
    }

}