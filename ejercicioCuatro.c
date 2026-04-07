/*Dados los números enteros m y n, construir una función recursiva que devuelva el
cociente de ambos, calculando el mismo mediante restas sucesivas. Se deberá tener
en cuenta que en el caso de que la división no sea exacta, se devolverán hasta "n"
cifras decimales (si es necesario).
Ejemplos:
division(10, 2) => 5
division(22, 3) => 7,33333  (precision 5)
division(23, 4) => 5,75     (precision 3)
*/
#include <stdlib.h>
#include <stdio.h>


void divisionResolucion(int m, int n, int *decimales, float *resultado, float peso, int limite) {
    if ((m == 0) || *decimales > limite) {
        return;
    }

    if (m < n) {
        *decimales += 1;
        divisionResolucion(m * 10, n, decimales, resultado, peso / 10.0, limite);
    } else {
        *resultado += peso;
        divisionResolucion(m - n, n, decimales, resultado, peso, limite);
    }
}


float division(int m, int n, int d) {
    int contadorDecimales = 0;
    float resultado = 0;
    
    divisionResolucion(m, n, &contadorDecimales, &resultado, 1.0, d);

    return resultado;
}

int main(){
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
    return 0;
}