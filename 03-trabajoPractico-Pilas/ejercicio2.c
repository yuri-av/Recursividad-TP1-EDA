#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pilas.h"
#include "tipo_elemento.h"

/*2. Dada una pila cargada con valores al azar realizar los siguientes ejercicios:

a. Buscar una clave y determinar si existe en la Pila (sin perder la pila).*/
bool p_ej2_existeclave(Pila p, int clave) {
    Pila Paux = p_crear();
    TipoElemento x;
    
    bool encontrado = false;

    while (p_es_vacia(p) != true) {
        x = p_desapilar(p);
        
        if (x->clave == clave) {
            encontrado = true; 
        }

        p_apilar(Paux, x);
    }

    while (p_es_vacia(Paux) != true) {
        x = p_desapilar(Paux);
        p_apilar(p, x);
    }

    return encontrado;
}

/* b. Colocar en una posición ordinal determinada, recibida por parámetro, un nuevo elemento (Insertar un elemento nuevo).*/
Pila p_ej2_colocarelemento(Pila p, int posicionordinal, TipoElemento x) {
    Pila Paux = p_crear();
    TipoElemento elem;
    int pos = 1;

    while (p_es_vacia(p) != true && pos < posicionordinal) {
        elem = p_desapilar(p);
        p_apilar(Paux, elem);      
        pos++;
    }
    p_apilar(p,x);

    while (p_es_vacia(Paux) != true) {
        elem = p_desapilar(Paux);
        p_apilar(p,elem);
    }

    return p;
}

/*c. Eliminar de una pila un elemento dado (primera ocurrencia encontrada por la clave). */
Pila p_ej2_eliminarclave(Pila p, int clave) {
    Pila Paux = p_crear();
    TipoElemento x;
    int eliminado = 0;

    while (!p_es_vacia(p)) {
        x = p_desapilar(p);

        if (x->clave == clave && eliminado == 0) {
            eliminado = 1;
        } else { 
            p_apilar(Paux, x);
        }
    }

    while (!p_es_vacia(Paux)) {
        x = p_desapilar(Paux);
        p_apilar(p,x);
    } 

    return p;
}

/* d. Intercambiar los valores de 2 posiciones ordinales de la pila, por ejemplo la 2da con la 4ta.*/
Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2) {
    Pila Paux = p_crear();
    TipoElemento x, elemA, elemB;
    int pos = 1;

    while (!p_es_vacia(p)) {
        x = p_desapilar(p);

        if (pos == pos1) {
            elemA = x;
        } 
        if (pos == pos2) {
            elemB = x;
        }

        p_apilar(Paux, x);
        pos++;
    }
    
    pos = pos - 1;
    while (!p_es_vacia(Paux)) {
        x = p_desapilar(Paux);

        if (pos == pos1) {
            p_apilar(p, elemB);
        } else if (pos == pos2) {
            p_apilar(p,elemA);
        } else {
            p_apilar(p,x);
        }
        pos--;
    }

    return p;
}

/*e. Duplicar el contenido de una pila. */
Pila p_ej2_duplicar(Pila p) {
    Pila Paux = p_crear();
    Pila nueva = p_crear();
    TipoElemento x;

    while (!p_es_vacia(p)) {
        x = p_desapilar(p);
        p_apilar(Paux, x);
    }

    while (!p_es_vacia(Paux)) {
        x= p_desapilar(Paux);

        p_apilar(p, x);
        p_apilar(nueva, x);
    }

    return nueva;
}

/*f. Contar los elementos de la pila. */
int p_ej2_cantidadelementos(Pila p) {
    Pila Paux = p_crear();
    TipoElemento x;
    int contador = 0;

    if (p_es_vacia(p)) {
        return 0;
    }

    while (!p_es_vacia(p)) {
        x = p_desapilar(p);
        contador++;
        p_apilar(Paux, x);
    }

    while (!p_es_vacia(Paux)) {
        x = p_desapilar(Paux);
        p_apilar(p, x);
    }

    return contador;
}


int main() {
    Pila p = p_crear();
    TipoElemento x;

    // Cargar pila
    x = te_crear(1); p_apilar(p, x);
    x = te_crear(2); p_apilar(p, x);
    x = te_crear(3); p_apilar(p, x);
    x = te_crear(4); p_apilar(p, x);
    x = te_crear(5); p_apilar(p, x);

    printf("===== PILA ORIGINAL =====\n");
    p_mostrar(p);

    // Buscar
    int clave_buscar = 3;
    bool existe = p_ej2_existeclave(p, clave_buscar);
    printf("\nBuscar %d: %s\n", clave_buscar, existe ? "SI" : "NO");


    // Insertar en posición
    printf("\nInsertar elemento 99 en posicion 3\n");
    TipoElemento nuevo = te_crear(99);
    p = p_ej2_colocarelemento(p, 3, nuevo);
    p_mostrar(p);

    // Eliminar
    int clave_eliminar = 2;
    printf("\nEliminar %d...\n", clave_eliminar);
    p = p_ej2_eliminarclave(p, clave_eliminar);

    printf("Pila despues de eliminar:\n");
    p_mostrar(p);

    // Intercambiar
    printf("\nIntercambiar posiciones 2 y 4\n");
    p = p_ej2_intercambiarposiciones(p, 2, 4);
    p_mostrar(p);

    // Duplicar
    printf("\nDuplicando pila...\n");
    Pila copia = p_ej2_duplicar(p);

    printf("Pila original:\n");
    p_mostrar(p);

    printf("Pila copia:\n");
    p_mostrar(copia);

    // Contar
    int cant =p_ej2_cantidadelementos(p);
    printf("\nCantidad: %d\n", cant);

    printf("\nPila despues de contar:\n");
    p_mostrar(p);

    return 0;
}
