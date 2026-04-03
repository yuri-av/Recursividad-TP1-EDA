#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

/*Ejercicio 5: Generar un algoritmo recursivo que le ponga los “.” de los miles a un String de números.
Ejemplos:
agregarSeparadorMiles (“123456”) => “123.456”
agregarSeparadorMiles (“12345678”) => “12.345.678*/

void agregarSeparadorMiles(char *a, char *b)
{
    if (*a == '\0')
    {
        *b = '\0';
        return;
    }

    *b = *a;

    if (strlen(a + 1) > 0 && (strlen(a + 1) % 3 == 0))
    {
        *(b + 1) = '.';
        agregarSeparadorMiles(a + 1, b + 2);
    }
    else
    {
        agregarSeparadorMiles(a + 1, b + 1);
    }
}

int main()
{
    char a[MAX];
    char b[MAX];
    int valido = 0;
    int negativo = 0;

    do
    {
        printf("Ingrese un numero: ");
        if (scanf("%99[-0-9]", a) == 1)
        {
            // verificar que lo siguiente sea enter
            if (getchar() == '\n')
            {
                valido = 1;
            }
            else
            {
                printf("Error: solo numeros.\n");
                while (getchar() != '\n')
                    ;
            }
            if (a[0] == '-')
            {
                negativo = 1;
            }
        }
        else
        {
            printf("Error: entrada invalida.\n");
            while (getchar() != '\n')
                ;
        }

    } while (!valido);

    if (negativo == 1)
    {
        agregarSeparadorMiles(a + 1, b);
        printf("Resultado: -%s\n", b);
    }
    else
    {
        agregarSeparadorMiles(a, b);
        printf("Resultado: %s\n", b);
    }
}
