/*se conoce que la mafia china es muy organizada y protege mucho a sus miembros,
cuando deciden asistir a una reunión se dispone de una cantidad de chinos que
asisten, y ellos se ubican de forma que al mirarlos frontalmente generan cierto respeto
y temor. A continuación, se tiene una serie de posibles reuniones y su nivel y la
apariencia que se tiene del grupo que va a la reunión vistos frontalmente:
 Nivel reunión Vista frontal de la delegación
 1 (-.-)
 2 (-.(-.-).-)
 3 (-.(-.(-.-).-).-)
 4 (-.(-.(-.(-.-).-).-).-)
Considerando esta descripción, diseñar los procesos recursivos que permitan mostrar
la apariencia del grupo de chinos que asisten a una reunión de nivel “n”. */
#include <stdio.h>
#include <stdlib.h>

void chinos(int n)
{
    if (n <= 0)
    {
        return;
    }
    if (n == 1)
    {
        printf("(-.-)");
    }
    else
    {
        printf("(-.");
        chinos(n - 1);
        printf(".-)");
    }
}

int validacion_entero(int *n, int scan, char c)
{

    while (scan != 2 || c != '\n' || *n < 1)
    {
        if (scan != 2 || c != '\n')
        {
            // Limpia el buffer si hay letras o si hay cualquier cantidad que no sea 2 datos retornados por scanf
            while (getchar() != '\n')
                ;
        }
        printf("Error de tipo de datos: ingrese un numero entero: ");
        scan = scanf("%d%c", n, &c);
    }
    return *n;
}

int main()
{
    char c;
    int n;
    printf("Ingrese un numero entero: ");
    int scan = scanf("%d%c", &n, &c);
    // Validamos primero que sea de tipo int el valor de n
    validacion_entero(&n, scan, c);
    // Cuando sea correcto, se ejecuta la recursividad
    chinos(n);
    return 0;
}