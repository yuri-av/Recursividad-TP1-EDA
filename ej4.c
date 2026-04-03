#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*Ejercicio 4: Dados los números enteros m y n, construir una función recursiva que devuelva el cociente de ambos, calculando el mismo mediante restas sucesivas. Se 
deberá tener en cuenta que en el caso de que la división no sea exacta, se devolverán hasta “n” cifras decimales (si es necesario), donde “n” es un valor entre 1 a 10 a 
ingresar como precisión de la división.
Ejemplos:
division (10,2) => 5 (en este caso “n” podría haber sido cualquier valor, nada cambia el resultado porque la división fue exacta.)
division (22,3) => 7,33333 (en este caso “n” fue 5)
division (23,4) => 5,75 (en este caso “n” fue 3, pero como el resultado con 2 decimales fue suficiente no es necesario mostrar el 5,750 (es decir el “0” final no se 
muestra) */

int divisionEntera(int m, int n) {

    if (m < n) {
        return 0;
    } else {
        return 1 + divisionEntera(m-n, n);
    }
}


void parteDecimal(int resto, int divisor, int precision) {

    if (precision == 0 || resto == 0) {
        return;
    } 
    
    resto = resto * 10;
    int dig = divisionEntera(resto, divisor);
    printf("%d", dig);

    int nuevoResto = resto - dig * divisor;

    parteDecimal(nuevoResto, divisor, precision - 1);
}


int main() {
    int m, n, prec;

    printf("ingrese el dividendo: ");
    while (scanf("%d", &m) != 1 || m < 0) {
    printf("Entrada invalida. Ingrese un numero entero positivo: ");
    while (getchar() != '\n');
    }
    
    printf("Ingrese el divisor: ");
    while (scanf("%d", &n) != 1 || n <= 0) {
    printf("Error: El divisor debe ser un numero positivo y distinto de 0: ");
    while (getchar() != '\n');
    }
    
    printf("Ingrese la cantidad de decimales: ");
    while (scanf("%d", &prec) != 1 || prec < 0) {
        printf("Error. La precision debe ser 0 o mas: ");
        while (getchar() != '\n');
    }

    int cociente = divisionEntera(m, n);
    int restoInicial = m - (cociente * n);

    printf("\nResultado: %d", cociente);

    if (restoInicial > 0 && prec > 0) {
        printf(",");
        parteDecimal(restoInicial, n, prec);
    }

    printf("\n");
    return 0;
}