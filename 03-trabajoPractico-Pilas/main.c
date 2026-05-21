#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include "tp_pilas.h"
#include "validaciones.h"
#include "tipo_elemento.h"

#define MAX 150

//Dada una pila Auxiliar y una pila a armar , se arma la segunda pila siendo la inversa de la auxiliar
Pila ReApilar(Pila PilaAuxuliar,Pila Armar);

//Invierte la lista con su propio contenido
Pila Invertir(Pila p);

//cargar pila 
void cargarPila(Pila p);

int main(){
    char opcionStr[10];
    char letra;
    char mensaje[MAX];
    // BUCLE DO-WHILE DEL MENU PRINCIPAL
    do
    {
        printf("\n---EJERCICIO A EJECUTAR---\n");
        printf("A) EJERCICIO 2 | Todos\n");
        printf("B) EJERCICIO 3 | Iguales\n");
        printf("C) EJERCICIO 4 | Cambiar Base\n");
        printf("D) EJERCICIO 5 | Invertir\n");
        printf("E) EJERCICIO 6 | Eliminar Clave\n");
        printf("F) EJERCICIO 7 | Elementos Comunes\n");
        printf("G) EJECICIO  8 | Sacar Repetidos\n");
        printf("H) SALIR\n");

        strcpy(mensaje, "Ingrese la letra del ejercicio que quiera ejecutar: ");
        letra=validacionDeLetra(mensaje,opcionStr,sizeof(opcionStr),'A','H');
        // Si el usuario eligio la letra de salida, avisamos y evitamos entrar al switch
        if (letra == 'H'){
            printf("\nSaliendo del programa...\n");
        }
        else
        {
            switch (letra)
            {
            case 'A':{
                /*EJERCICIO 2*/
                Pila p = p_crear();
                cargarPila(p);
                printf("Pila armada con valores de usuario : ");
                p_mostrar(p);

                char opcionStr[10];
                char letra;
                char mensaje[MAX]; 
                
                do
                {
                    printf("\n---EJERCICIO A EJECUTAR---\n");
                    printf("A) EJERCICIO a | Existe Clave\n");
                    printf("B) EJERCICIO b | Colocar elemento\n");
                    printf("C) EJERCICIO c | Eliminar Clave\n");
                    printf("D) EJERCICIO d | Intercambiar Posiciones\n");
                    printf("E) EJERCICIO e | Duplicar\n");
                    printf("F) EJERCICIO f | Contar Elementos\n");
                    printf("G) SALIR\n");

                    strcpy(mensaje, "Ingrese la letra del punto que quiera ejecutar: ");
                    letra=validacionDeLetra(mensaje,opcionStr,sizeof(opcionStr),'A','G');
                    if (letra == 'G'){
                        printf("\n Volviendo al Menu Principal...\n");
                    }
                    else{
                        switch (letra)
                        {
                        case 'A':{
                            /* PUNTO A*/
                            int clave;
                            bool ret;

                            printf("Pila armada con valores de usuario : ");
                            p_mostrar(p);
                            clave = leerEntero("Ingrese la clave que desea Buscar:",true);
                            
                            ret=p_ej2_existeclave(p,clave);

                            if(ret){
                                printf("La clave %d se encuentra en la pila",clave);
                            }
                            else printf("No estaba en la pila");

                            break;
                        }
                        case 'B':{
                            /* PUNTO B*/
                            break;
                        }
                        case ' C':{
                            /* PUNTO C*/
                            break;
                        }
                        case 'D':{
                            /* PUNTO D*/
                            break;
                        }
                        case 'E':{
                            /* PUNTO E*/
                            break;
                        }
                        case 'F':{
                            /* PUNTO F*/
                            break;
                        }
                        
                        default:
                            break;
                        }
                    }

                } while (letra!='G');
        
                break;
            }
            case 'B':{
                /*EJERCICIO 3*/
                Pila p = p_crear();
                cargarPila(p);
                printf("Pila armada con valores de usuario : ");
                p_mostrar(p);



                break;
            }
            case 'C':{
                /*EJERCICIO 4*/
                Pila p = p_crear();
                cargarPila(p);
                printf("Pila armada con valores de usuario : ");
                p_mostrar(p);



                break;
            }
            case 'D':{
                /*EJERCICIO 5*/
                Pila p = p_crear();
                cargarPila(p);
                printf("Pila armada con valores de usuario : ");
                p_mostrar(p);



                break;
            }
            case 'E':{
                /*EJERCICIO 6*/
                Pila p = p_crear();
                cargarPila(p);
                printf("Pila armada con valores de usuario : ");
                p_mostrar(p);



                break;
            }
            case 'F':{
                /*EJERCICIO 7*/
                Pila p = p_crear();
                cargarPila(p);
                printf("Pila armada con valores de usuario : ");
                p_mostrar(p);



                break;
            }
            case 'G':{
                /*EJERCICIO 8*/
                Pila p = p_crear();
                cargarPila(p);
                printf("Pila armada con valores de usuario : ");
                p_mostrar(p);



                break;
            }
            default:
                break;
            }
        }
    } while (letra != 'H'); // CONDICION DE SALIDA: Se repite MIENTRAS la letra NO sea igual a la letra final.

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

void cargarPila(Pila p){
    int tamanio;

    tamanio=leerEntero("Ingrese el tamaño de la Pila (expresado en enteros)",false);

    for(int i = 0;i<tamanio;i++){
        int Clave = 0;
        Clave=leerEntero("ingrese la clave a apilar para P : ",false);

        TipoElemento x = te_crear(Clave);
        p_apilar(p,x);
    }
}