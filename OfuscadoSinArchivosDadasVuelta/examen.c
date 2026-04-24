#include <stdlib.h>
#include <ctype.h>
#include "examen.h"
#include <stdio.h>
#include <string.h>

#define MAX_TAM_PAL 24

char* desofuscarALU(char* linea){

    if(!linea)
        return NULL;

    char palabra[MAX_TAM_PAL];
    char grupo[] = "abcdghijkoqtuv";

    char* vPal = palabra;

    while(*linea)
    {
        while(*linea!='\0' && !isalpha(*linea))
            linea++;

        char* iniPalEnLinea = linea;

        while(*linea!='\0' && isalpha(*linea))
        {
            *vPal = *linea;

            linea++;
            vPal++;
        }

        *vPal = '\0';
        vPal = palabra;

        while(*vPal)
        {
            char* pgrupo = NULL;

            pgrupo = strchr(grupo, *vPal);
/**
---Version anterior---
Problema: pgrupo += pos;
Nota: A veces al sumar pos se pasa del final, esto genera un comportamiento indefinido que puede hacer algo o no hace nada

            if(pgrupo)
            {
                int pos = (vPal - palabra) + 1;
                int cantGrupo = strlen(grupo);

                while(pos > cantGrupo)
                    pos -= cantGrupo;

                pgrupo += pos;

                *vPal = *pgrupo;
            }
**/
            if(pgrupo)
            {
                int cantDesplazamiento = (vPal - palabra) + 1;
                int cantGrupo = strlen(grupo);

                //Posicion actual de la letra del grupo
                int posGrupo = pgrupo - grupo;

                //Obtenemos la nueva posicion (esto solo sirve si va para la derecha)
                //Explicado por el profe (circular): (posActualGrupo + cantDesplazamiento) % cantTotalElemsGrupo
                int nuePosGrupo = (posGrupo + cantDesplazamiento) % cantGrupo;

                *vPal = *(grupo + nuePosGrupo);
            }

            vPal++;
        }

        darVueltaPalabra(palabra);

        reemplazarPalabra(iniPalEnLinea, palabra);

        vPal = palabra;
    }

    return NULL;
}

void darVueltaPalabra(char* pal)
{
    char* finPal = pal + strlen(pal) - 1;
    char aux;

    while(*pal && pal < finPal)
    {
        aux = *pal;
        *pal = *finPal;
        *finPal = aux;

        pal++;
        finPal--;
    }
}

void reemplazarPalabra(char* linea, char* pal)
{
    // Por favor fijarse de que linea no explote.

    while(*pal)
    {
        *linea = *pal;

        linea++;
        pal++;
    }
}

/**
Revisar si esto esta bien o hay algo mal: surjscaukvncn -> nanodijkstras

Linea ofuscada: nE vadjomrbfno, vl vgvnoucrrg es ebdm ne surjscaukvncn --nulA yuK.
Linea desofuscada (implemente el metodo!):En informatica, la arrogancia se mide en nanodijkstras --Alan Kay.


Actualizacion: Buscando en internet la frase existe tal cual asi, asi que la damos como valida.
Fuente: Alan Kay, Discurso de OOPSLA 1997
---Caso Cerrado---
**/
