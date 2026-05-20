#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tp_pilas.h"

//Dada una pila Auxiliar y una pila a armar , se arma la segunda pila siendo la inversa de la auxiliar
Pila ReApilar(Pila PilaAuxuliar,Pila Armar);

//Invierte la lista con su propio contenido
Pila Invertir(Pila p);

//Eliminar ocurrencias de una clave
Pila p_ej6_eliminarclave(Pila p, int clave);// Complejidad : O(n), version: iterativa
Pila p_ej6_eliminarclaveRecu(Pila p, int clave);// Complejidad : O(n),version: recursiva

//Funcion auxiliar para la forma recursiva del ejercicio 6
void Filtrar(Pila p,int Clave,Pila Resultado);

TipoElemento p_buscar(Pila P,int Clave);// Dada una pila y una clave, devuelve el TipoElemento con esa clave o NULL en caso de no encontralo
Pila p_ej7_elementoscomunes(p1,p2);//Complejidad : O(n^2), Recorre con un bucle O(n) y dentro de este p_buscar Ejecuta otro osea : O(n) * O(n) = O(n^2) 

int main(){
    
    Pila p = p_crear();
    Pila p1 = p_crear();

    for(int i = 0;i<10;i++){
        int Clave = 0;
        printf("ingrese la clave a apilar para P : ");
        scanf("%d",&Clave);

        TipoElemento x = te_crear(Clave);
        p_apilar(p,x);


        printf("ingrese la clave a apilar para P1 : ");
        scanf("%d",&Clave);
        x = te_crear(Clave);
        p_apilar(p1,x);
    }

    printf("Pila armada con valores de usuario : ");
    p_mostrar(p);
    p_mostrar(p1);    
    
    Pila Interseccion = p_crear();
    Interseccion = p_ej7_elementoscomunes(p,p1);

    printf("Como quedo p : ");
    p_mostrar(p);

    printf("Pila con la interseccion : ");
    p_mostrar(Interseccion);


    return 0;
}



Pila ReApilar(Pila PilaAuxuliar,Pila Armar){
    TipoElemento x;
    while (!p_es_vacia(PilaAuxuliar))
    {
    x = p_desapilar(PilaAuxuliar);
    p_apilar(Armar,x);
    }
    
    return Armar;
}

Pila p_ej6_eliminarclave(Pila p, int clave){
    if (p_es_vacia(p))
    {
        return p;
    }
    

    TipoElemento x;
    Pila Auxiliar = p_crear(); //Guardamos los TipoElemento de la Pila original
    Pila ResultadoAux = p_crear();
    Pila Resultado = p_crear();

    while (!p_es_vacia(p))//Recorro la Pila original
    {
        x = p_desapilar(p);
        if (x->clave != clave)//Si tiene la clave la añado a la Pila Que vamos a retornar
        {
            p_apilar(ResultadoAux,x);
        }
        p_apilar(Auxiliar,x);
    }
    
    p = ReApilar(Auxiliar,p);
    p_mostrar(p);
    //INVIERTO la lista Resultado porque como guardaba de forma secuencial los primeros elemtnos estan en la base de la pila
    Resultado = ReApilar(ResultadoAux,Resultado);

    return Resultado;
}
Pila p_ej6_eliminarclaveRecu(Pila p, int clave){
// Primero creo una copia

    Pila Resultado = p_crear();

    Filtrar(p,clave,Resultado);

    printf("LA PILA QUE ENTRO: "); // para verificar si modifico la pila
    p_mostrar(p);

    return Resultado;

}
//le paso los punteros de las auxiliares para 1° no perder la Pila original y 2° luego volver a apilar la pila de resultados para tener el orden original
void Filtrar(Pila p,int Clave,Pila Resultado){
    if (p_es_vacia(p))//caso base no tiene mas elemetos la pila
    {
        return;
    }
    else{
        TipoElemento x = p_desapilar(p);
    
        Filtrar(p,Clave,Resultado);

        if (x->clave != Clave )// no tiene la clave?
        {
            p_apilar(Resultado,x);//subo a la Pila Filtrada
        }
        p_apilar(p,x);
    }
    
}
TipoElemento p_buscar(Pila P,int Clave){

    Pila Paux = p_crear();
    TipoElemento x, Resultado;
    Resultado = NULL;
    bool Encontrado = false;

    if (p_es_vacia(P))
    {
        return Resultado;
    }

    while (!p_es_vacia(P)&& !Encontrado)
    {
        x = p_desapilar(P);

        if (x->clave == Clave)
        {
            Resultado = x;
            Encontrado = true;
        }
        

        p_apilar(Paux,x);
    }
    
    ReApilar(Paux,P);
    return Resultado;
}

Pila p_ej7_elementoscomunes(Pila p1,Pila p2){

    Pila Paux = p_crear();
    Pila ResultadoAux = p_crear();


    if(p_es_vacia(p1)||p_es_vacia(p2)){ //Retorno PIla vacia si estaban asi cuando fueron ingresadas osea: Si NO tienen elementos en comun el  output es PILA VACIA!
        return ResultadoAux;
    }

    TipoElemento x;

    while (!p_es_vacia(p1))
    {
        x = p_desapilar(p1);

        if (p_buscar(p2,x->clave) != NULL) //Si esta en p2 lo apilo en la nueva Pila, si no esta p_buscar da NULL
        {
            p_apilar(ResultadoAux,x);
        }
        
        p_apilar(Paux,x);

    }
    
    p1=ReApilar(Paux,p1);//Re apilo para dejarla como la original

    Pila Resultado = p_crear();
    Resultado = ReApilar(ResultadoAux,Resultado);

    return Resultado;

}