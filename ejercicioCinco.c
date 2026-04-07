#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void agregarSeparadorResultado(char origen[],char destino[],int posOriginal, int posDestino,int largo){
    if(posOriginal==largo){
        destino[posDestino]='\0';
        return;
    }
    else{
        destino[posDestino]=origen[posOriginal];
        int quedanHaciaDerecha=(largo-1)-posOriginal;

        if(quedanHaciaDerecha>0 && (quedanHaciaDerecha%3==0)){
            destino[posDestino+1]='.';
            agregarSeparadorResultado(origen,destino,posOriginal+1,posDestino+2,largo);
        }
        else{
            agregarSeparadorResultado(origen,destino,posOriginal+1,posDestino+1,largo);
        }

    }
}


char * agregarSeparadorMiles(char numero[]){
   int largo,puntos,espacioTotal;
    //largo de la cadena
   largo=strlen(numero);
   //cantidad de puntos que va a tener el numero
   puntos=(largo-1)/3;
   //total de numeros + puntos + '/0'
   espacioTotal=largo+puntos+1;
   char *cadena = (char *)malloc(espacioTotal * sizeof(char));

   agregarSeparadorResultado(numero,cadena,0,0,largo);

   return cadena;
}

int main() {
    char numero[100];
    int esValido = 0;
    int esNegativo = 0;
    char *resultadoFinal = NULL;

    // --- BLOQUE DE VALIDACIÓN ---
    do {
        printf("Ingrese un numero: ");
        
        // Intentamos leer solo números y el signo menos
        if (scanf("%99[-0-9]", numero) == 1) {
            
            // Verificamos que el usuario no haya escrito letras después de los números
            if (getchar() == '\n') {
                esValido = 1;
            } else {
                printf("Error: Solo se permiten numeros enteros.\n");
                while (getchar() != '\n');
            }

            // Detectamos si el número ingresado empieza con el signo menos
            if (numero[0] == '-') {
                esNegativo = 1;
            }
        } else {
            printf("Error: Entrada invalida.\n");
            while (getchar() != '\n');
        }

    } while (!esValido);

    // --- BLOQUE DE PROCESAMIENTO ---
    
    if (esNegativo == 1) {
        resultadoFinal = agregarSeparadorMiles(&numero[1]);
    } else {
        resultadoFinal = agregarSeparadorMiles(numero);
    }

    // --- SALIDA Y LIBERACIÓN ---
    
    if (resultadoFinal != NULL) {
        printf("Original: %s\n", numero);
        printf("Formateado: %s%s\n", (esNegativo ? "-" : ""), resultadoFinal);


        free(resultadoFinal);
    } else {
        printf("Error al procesar el numero.\n");
    }

    return 0;
}