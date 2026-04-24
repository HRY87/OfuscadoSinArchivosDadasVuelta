#include <stdio.h>
#include <stdlib.h>
#include "examen.h"
#define MAXLINE 1024



int main()
{
    /*
    Ejercicio Cadenas
    ----------------------
    Mediante el metodo quieroUnaLineaDeTextoOfuscadaV1 adquiera una cita en texto
    afuscada que impide su lectura. Cada palabra de las citas se ha ofuscado primero dando vuelta la palabra
    y luego tomando cada letra y si la misma se encuentra en el grupo "abcdghijkoqtuv" se remplaza
    por la letra que esta hacia la izquierda tantos lugares como posicion en la palabra (dada vuelta)
    ocupa. Una palabra es un conjunto contiguo de caracteres considerados por la funcion isalpha.
    Ejemplo:
    Si la palabra es hola, primero se dio vuelta y quedo "aloh"
    "a":un lugar atras queda "v"
    "l":queda igual, no esta en grupo "l"
    "o":tres lugares atras queda "i"
    "h":cuatro lugares atras queda "b"
    Resultado esperado: hola => vlib
    Sabiendo como se ha ofuscado implemente un algoritmo que le muestre la frase desofuscada.

    Algunos consejos:
    .Antes de codificar piense una estrategia de solucion
    .Separe el problema en partes y pruebe individualmente cada una si es necesario.

    .
    Nota:
    .Las frases estan en espanol (excepto probablemente una) y son varias, en cada ejecucion puede obtener cualquiera
    aleatoriamente.

    Disclaimer: Las citas no representan las opiniones de quien formulo el ejercicio :)
    */

    char linea[MAXLINE];

    quieroUnaLineaDeTextoOfuscadaDVV(linea);

    printf("Linea ofuscada: %s\n", linea);
    desofuscarALU(linea);//Esta la tiene que implemetar usted.
    printf("Linea desofuscada (implemente el metodo!):%s\n", linea);


    return 0;
}

