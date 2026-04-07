#include <stdio.h>

#define MAX_ELEMENTOS 100

void subconjuntos_que_suman_N(int lista_num[], int objetivo)
{
    static int actual[MAX_ELEMENTOS];
    static int tam_actual = 0;

    // Caso base exitoso: imprimir el subconjunto directamente
    if (objetivo == 0)
    {
        printf("{");
        for (int i = 0; i < tam_actual; i++)
        {
            printf("%d", actual[i]);
            if (i < tam_actual - 1)
                printf(", ");
        }
        printf("}\n");
        return;
    }

    // Caso base sin solucion: fin del arreglo (centinela -999)
    if (lista_num[0] == -999)
        return;

    // Rama 1: No incluir el elemento actual
    subconjuntos_que_suman_N(lista_num + 1, objetivo);

    // Rama 2: Si incluir el elemento actual
    actual[tam_actual] = lista_num[0];
    tam_actual++;
    subconjuntos_que_suman_N(lista_num + 1, objetivo - lista_num[0]);
    tam_actual--;
}

int leer_entero(const char *mensaje)
{
    char buffer[50];
    int valor;
    char extra;

    while (1)
    {
        printf("%s", mensaje);

        if (fgets(buffer, sizeof(buffer), stdin) == NULL || buffer[0] == '\n')
        {
            printf("  Error: no puede ser nulo. Intente de nuevo.\n");
            continue;
        }
        if (sscanf(buffer, "%d%c", &valor, &extra) == 2 && extra != '\n')
        {
            printf("  Error: solo se permiten numeros enteros. Intente de nuevo.\n");
            continue;
        }
        if (sscanf(buffer, "%d", &valor) != 1)
        {
            printf("  Error: solo se permiten numeros enteros. Intente de nuevo.\n");
            continue;
        }

        return valor;
    }
}

int main()
{
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
    lista_num[tamanio] = -999; // centinela que marca el fin del arreglo

    objetivo = leer_entero("Ingrese el numero objetivo (N): ");

    printf("\nSubconjuntos que suman %d:\n", objetivo);
    subconjuntos_que_suman_N(lista_num, objetivo);

    return 0;
}