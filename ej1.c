#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/* Ejercicio 1: Construir una función recursiva que retorne verdadero si una cadena de caracteres
pasada como parámetro es un palíndromo. Ej. “neuquen” ya que se lee igual de atrás
hacia adelante.
Ejemplos:
palindromo(“neuquen”) => verdadero
palindromo(“palindromo”) => falso */

bool palindromo(char *s, int inicio, int fin) {
    
    if (inicio >= fin) {
        return true;}
    if (s[inicio] != s[fin]) {
        return false;}
    
return palindromo(s, inicio + 1,fin - 1); 
    
} 


int main() {
char palabra[100];

printf("Ingrese una palabra: ");
scanf("%99s", palabra);

int longitud = strlen(palabra); 

if (palindromo(palabra, 0, longitud - 1)) {
    printf("%s es un palindromo", palabra);
}
else {
    printf("%s NO es un palindromo", palabra);
}

return 0;
} 

