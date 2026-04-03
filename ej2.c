#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*ejercicio 2: Dados dos números enteros m y n, construir una función recursiva que devuelva el producto de ambos, calculando el mismo como sumas sucesivas. Esto es:
m*n=m+m+...+m, n veces.
Ejemplos:
producto(5, 3) => 15
producto (10, 4) => 40 */

int producto(int m, int n) {
    if (n==0) {
        return 0;
    }
    return m + producto(m,n-1);
}

int main() {
    int m, n;
    printf("Ingrese el primer numero: ");
    while (scanf("%d", &m) != 1) {
        printf("Error, debe ingresar un numero entero: ");
        while (getchar() !='\n');
    }
    printf("ingrese el segundo numero: ");
    while (scanf("%d", &n) != 1) {
        printf("Error, ingrese un numero entero: ");
        while (getchar() !='\n'); 
    }
    while (n<0) {
        printf("Error, el segundo numero debe ser positivo: ");
        while (scanf("%d", &n) != 1) {
        printf("Error, ingrese un numero entero: ");
        while (getchar() != '\n');
    }
}

    int resultado = producto(m,n);
    printf("%d", resultado);
    return 0;    
}