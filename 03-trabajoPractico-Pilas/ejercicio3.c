#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilas.h"
#include "tipo_elemento.h"

/* . Dadas dos pilas, determinar si sus contenidos son exactamente iguales (solo por la clave), sin destruirlas. Utilizar para la 
resolución del problema una única pila auxiliar.
Determinar la complejidad algorítmica de la solución. */

bool p_ej3_iguales(Pila p1, Pila p2) {
    Pila Paux = p_crear();
    bool iguales = true;
    TipoElemento x, y;

    while (!p_es_vacia(p1) && (!p_es_vacia(p2))) {
        x = p_desapilar(p1);
        y = p_desapilar(p2);

        if (x->clave != y->clave) {
            iguales = false;
        }
        p_apilar(Paux,x);
        p_apilar(Paux, y);
    }

    if (!p_es_vacia(p1) || !p_es_vacia(p2)) {
    iguales = false;
    }

    while (!p_es_vacia(Paux)) {
        y = p_desapilar(Paux);
        p_apilar(p2, y);

        x = p_desapilar(Paux);
        p_apilar(p1, x);
    }

    return iguales; 
}

int main() {
      Pila p1 = p_crear();
    Pila p2 = p_crear();

    int n1, n2, valor;

    // Cargar P1
    printf("Ingrese cantidad de elementos para P1: ");
    scanf("%d", &n1);

    for (int i = 0; i < n1; i++) {
        printf("Ingrese valor %d para P1: ", i + 1);
        scanf("%d", &valor);

        TipoElemento te = te_crear(valor);
        p_apilar(p1, te);
    }

    // Cargar P2
    printf("\nIngrese cantidad de elementos para P2: ");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++) {
        printf("Ingrese valor %d para P2: ", i + 1);
        scanf("%d", &valor);

        TipoElemento te = te_crear(valor);
        p_apilar(p2, te);
    }

    if (p_ej3_iguales(p1, p2)) {
        printf("\nLas pilas son iguales\n");
    } else {
        printf("\nLas pilas NO son iguales\n");
    }


    return 0;
}