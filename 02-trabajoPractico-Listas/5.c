#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "tp_2_listas.h"
#include "listas.h"
#include "tipo_elemento.h"

void hacerPolinomio(Lista list);
float evaluarPoliomio(Lista list, float x);
Lista calcularRango(Lista list, double x, double y, double sumando);

int main()
{
    Lista polinomio = l_crear();
    Lista rango;

    float x;
    double desde, hasta, intervalo;
    float resultado;

    int cantidad;
    int i;
    int control;

    printf("=== CARGA DEL POLINOMIO ===\n");
    printf("Ejemplo: 3x^2 + 2x + 1\n");
    printf("Cada termino se carga como:\n");
    printf("exponente (clave) y coeficiente (valor)\n\n");

    /* VALIDAR CANTIDAD DE TERMINOS */
    printf("Ingrese cantidad de terminos del polinomio (mayor a 0): ");
    control = scanf("%d", &cantidad);

    while (control != 1 || cantidad <= 0)
    {
        printf("Error: debe ingresar un numero entero mayor a 0.\n");

        while (getchar() != '\n');

        printf("Ingrese cantidad de terminos del polinomio (mayor a 0): ");
        control = scanf("%d", &cantidad);
    }

    /* CARGA DEL POLINOMIO */
    for (i = 0; i < cantidad; i++)
    {
        printf("\nTermino %d\n", i + 1);
        hacerPolinomio(polinomio);
    }

    printf("\nPolinomio cargado:\n");
    l_mostrar(polinomio);

    /* EVALUAR POLINOMIO */
    printf("\n=== EVALUAR POLINOMIO ===\n");

    printf("Ingrese valor de x: ");
    control = scanf("%f", &x);

    while (control != 1)
    {
        printf("Error: debe ingresar un numero valido, no letras.\n");

        while (getchar() != '\n');

        printf("Ingrese valor de x: ");
        control = scanf("%f", &x);
    }

    resultado = evaluarPoliomio(polinomio, x);

    printf("Resultado de F(%.2f) = %.2f\n", x, resultado);

    /* CALCULAR RANGO */
    printf("\n=== CALCULAR RANGO ===\n");

    printf("Ingrese valor inicial de x: ");
    control = scanf("%lf", &desde);

    while (control != 1)
    {
        printf("Error: debe ingresar un numero valido, no letras.\n");

        while (getchar() != '\n');

        printf("Ingrese valor inicial de x: ");
        control = scanf("%lf", &desde);
    }

    printf("Ingrese valor final de x (mayor o igual al inicial): ");
    control = scanf("%lf", &hasta);

    while (control != 1 || hasta < desde)
    {
        printf("Error: debe ingresar un numero valido y mayor o igual al valor inicial.\n");

        while (getchar() != '\n');

        printf("Ingrese valor final de x (mayor o igual al inicial): ");
        control = scanf("%lf", &hasta);
    }

    printf("Ingrese intervalo (mayor a 0): ");
    control = scanf("%lf", &intervalo);

    while (control != 1 || intervalo <= 0)
    {
        printf("Error: debe ingresar un numero mayor a 0 y no letras.\n");

        while (getchar() != '\n');

        printf("Ingrese intervalo (mayor a 0): ");
        control = scanf("%lf", &intervalo);
    }

    rango = calcularRango(polinomio, desde, hasta, intervalo);

    printf("\nValores del polinomio en el rango:\n");
    l_mostrar(rango);

    return 0;
}