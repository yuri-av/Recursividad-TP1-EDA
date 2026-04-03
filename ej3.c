#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*Ejercicio 3: Generar un algoritmo recursivo que calcule el k-ésimo número de la serie de Fibonacci.
Ejemplos:
terminoSeriedeFibonacci (1) => 1
terminoSeriedeFibonacci (5) => 8 */

int Fibonacci(int k) {
    if (k <= 2) {
        return 1;
    }
    else return Fibonacci(k-1) + Fibonacci(k-2);
}


int main() {
    int k, entradaValida = 0;
    printf("Ingrese un numero: ");
    while (!entradaValida) {

        if (scanf("%d", &k) != 1) {
            printf("Error, debe ingresar un numero entero: ");
            while (getchar() != '\n'); 
        } 
        else if (k <= 0) {
            printf("Error, debe ser un numero mayor a 0: ");
        } 
        else {
            entradaValida = 1; 
        }
    }
 

    int resu = Fibonacci(k);
    printf("%d", resu);
    return 0;
} 
