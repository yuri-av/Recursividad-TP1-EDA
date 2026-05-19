/*Dada una pila con valores al azar eliminar todas las ocurrencias de un determinado
ítem sin perder la pila original. Deberá retornar una nueva pila sin el ítem en
consideración. Resolver iterativamente y recursivamente. Determinar la complejidad
algorítmica de ambas soluciones.*/

#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"
#include "tipo_elemento.h"
// retornar la nueva pila sin la clave que se debe sacar (eliminar).
// Si la clave no esta se retorna la pila recibida.
// La definicion vale para ambas resoluciones
Pila p_ej6_eliminarclave(Pila p, int clave);
Pila eliminar_clave_recursiva(Pila aux, int clave, Pila original);
int validacion_ingreso();

int main()
{
    Pila pila_original = p_crear();
    Pila pila_resultado;
    int clave_a_buscar;
    // Pido clave a buscar
    printf("Ingrese que clave quiere eliminar de la pila: ");
    // Valido su ingreso
    clave_a_buscar = validacion_ingreso();
    // Cargo en pila_resultado lo que me da la funcion
    pila_resultado = p_ej6_eliminarclave(pila_original, clave_a_buscar);
    // Muestro la pila
    p_mostrar(pila_resultado);
    return 0;
}

int validacion_ingreso()
{
    int numero;
    char car;

    while (scanf("%d%c", &numero, &car) != 2 || car != '\n')
    {
        // Mensaje genérico para cualquier número entero
        printf("Opcion invalida. Ingrese un numero entero: ");

        // Limpieza del buffer de entrada
        if (car != '\n')
        {
            while (getchar() != '\n')
                ;
        }
    }

    // Retornamos el valor ya validado
    return numero;
}
// Version iterativa
Pila p_ej6_eliminarclave(Pila p, int clave)
{
    Pila aux = p_crear();
    Pila resultado = p_crear();
    bool encontrado = false;
    while (!p_es_vacia(p))
    {
        TipoElemento te = p_desapilar(p);
        p_apilar(aux, te);
    }
    while (!p_es_vacia(aux))
    {
        TipoElemento te_aux = p_desapilar(aux);
        if (te_aux->clave != clave)
        {
            p_apilar(resultado, te_aux);
        }
        else if (te_aux->clave == clave)
        {
            encontrado = true;
        }

        p_apilar(p, te_aux);
    }

    if (encontrado == true)
    {
        return resultado;
    }
    else
    {
        return p;
    }
}

// Version recursiva
Pila p_ej6_eliminarclave(Pila p, int clave)
{
    Pila auxiliar = p_crear();
    eliminar_clave_recursiva(auxiliar, clave, p);
}
Pila eliminar_clave_recursiva(Pila aux, int clave, Pila original)
{
}
