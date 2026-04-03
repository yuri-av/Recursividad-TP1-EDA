#include <stdio.h>
#include <stdlib.h>

int fibonacci(int k){
    if(k==1){
        return 1;
    }
    else if(k==2){
        return 1;
    }
    return fibonacci(k-1) + fibonacci(k-2);
}

int main()
{
    int k;
    printf("Ingrese numero a calcular: ");
    scanf("%d", &k);
    int resultado = fibonacci(k);
    printf("Resultad: %d", resultado);
    return 0;
}
