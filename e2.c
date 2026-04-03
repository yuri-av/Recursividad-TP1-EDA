#include <stdio.h>
#include <stdlib.h>

int producto(int m, int n){
    if(m == 0){
        return 0;
    }
    else if (n==0){
        return 0;
    }
    else{
        return m + producto(m, n-1);
    }
}

int main()
{
    int m, n;
    int s = 1;

    printf("Ingrese un numero: ");
    scanf("%d", &m);

    printf("Ingrese un numero: ");
    scanf("%d", &n);
    ///caso de ser negativos
    if(m<0){
        m = -m;
        s *= -1;
    }
    else if(n<0){
        n = -n;
        s *= -1;
    }
    int resultado = producto(m, n);

    resultado *= s;
    printf("El producto entre %d y %d es %d", m, n, resultado);
    return 0;
}
