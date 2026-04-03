#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

void ondadigital(char c[], int i){
    if (c[i] == '\0') {
        return;
    }
    if(i>1 && c[i]!=c[i-1]){
        printf("|");
    }
    else if(c[i]== "L"){
        printf("__");
    }
    else if(c[i]== "H"){
        printf("‾‾");
    }
    ondadigital(c, i+1);
}

int main()
{
    char c[100];
    printf("Ingrese la onda digital: ");
    scanf("%s", c);
    ondadigital(c, 0);
    return 0;
}
