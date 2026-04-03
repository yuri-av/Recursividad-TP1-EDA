#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool palindromo (char palabra[], int inicio, int fin){
    if (inicio >= fin){
        return true;
    }
    else if (palabra[inicio]!=palabra[fin]){
        return false;
    }
    else{
        return palindromo(palabra, inicio+1, fin-1);
    }
}

int main()
{
    char palabra[100];
    print("Ingrese una palabra: ");
    scanf("%s", palabra);
    int inicio = 0;
    int fin = strlen(palabra)-1;
    if(palindromo(palabra, inicio, fin))
        printf("Es un palindromo");
    else
        printf("No es un palindromo");
    
    return 0;
}
