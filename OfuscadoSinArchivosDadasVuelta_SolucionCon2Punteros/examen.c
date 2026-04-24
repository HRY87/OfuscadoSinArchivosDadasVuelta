#include <stdio.h>
#include <ctype.h>
#include <string.h>

#include "examen.h"
#define MAX_TAM_PAL 24

#define ES_MAYUS(X)((X) >= 'A' && (X) <= 'Z')
#define ES_MINUS(X)((X) >= 'a' && (X) <= 'z')
#define IS_ALPHA(X)(ES_MAYUS(X) || ES_MINUS(X))

char* desofuscarALU(char* linea)
{
    if(!linea)
        return NULL;

    char buffer[MAX_TAM_PAL]; //Por ahora tenemos un buffer con un limite
    char* pLect = linea;

    while(*pLect)
    {
        Palabra pal = obtenerPalabra(pLect);

        if(pal.ini == pal.fin) //Si pasa esto es que no hay mas palabras y salgo (se puede mejorar)
            break;

        procesarPalabra(pal, buffer);
        reemplazarPalabra((char*)pal.ini, buffer);

        pLect = (char*)pal.fin;
    }

    return linea;
}

Palabra obtenerPalabra(const char* linea)
{
    Palabra pal;

    const char* pLect = linea;

    while(*pLect && !IS_ALPHA(*pLect)) //Condicion de corte: Si es fin de cadena (\0) o si encuentra una letra (a-z / A-Z)
    {
        pLect++;
    }

    pal.ini = pLect; //Guardo la direccion del primer caracter de la palabra


    while(*pLect && IS_ALPHA(*pLect))
    {
        pLect++;
    }

    pal.fin = pLect; //Guardo la direccion del ultimo caracter de la palabra

    return pal;
}

void desplazarCaracter(char* c, int desplazamiento)
{

    char grupo[] = "abcdghijkoqtuv";

    const char* pGrupo = str_chr(grupo, *c); //Busco si existe el caracter en el grupo, si existe devuelve la direccion, caso contrario NULL

    if(!pGrupo) //Si es NULL devuelvo el caracter original
        return;

    int posGrupo = pGrupo - grupo;
    int cantGrupo = str_len(grupo);

    int nuevaPos = (posGrupo + desplazamiento) % cantGrupo;

    *c =  *(grupo + nuevaPos);
}

/**
        Como funciona el calculo de la nueva posicion:
        1- Se le suma el desplazamiento
        2- El resultado de la suma, se usa el operador % para evitar que no salga del rango y sea circular [0, cantGrupo - 1]
        Aclaracion: Esto solo funciona para desplamientos positivos (derecha), para desplazamientos negativos hay que hacer ajustes.
**/

void procesarPalabra(Palabra pal, char* destino)
{
    int tam = pal.fin - pal.ini;

    if(tam >= MAX_TAM_PAL) //Si existe una palabra que supera el limite, evito que explote haciendo que solo procese esa cantidad de caracteres
        tam = MAX_TAM_PAL - 1;

    char* pLect = (char*)pal.ini; //ptr de lectura: Recorre toda la palabra

    char* pEsct = destino + (tam - 1); //ptr de escritura: Se posiciona en la direccion del ultimo caracter (segun su tam)

    char* pLimite = (char*)(pal.ini + tam); //ptr de seguridad: En caso de que haya una palabra que supere el limite, caso contrario siempre sera igual a pal.fin

    int desplazamiento = 1; //Contador de desplazamiento

    char c; //Auxiliar para guardar el caracter temporalmente (no es completamente necesario pero al depurar en mas facil ver algun error)

    while(pLect < pLimite)
    {
        c = *pLect; //Guardo el caracter

        desplazarCaracter(&c, desplazamiento); //Si esta en el grupo se desplaza, sino queda igual

        *pEsct = c; //Escribo el caracter y lo doy vuelta a la vez

        pLect++;
        pEsct--;
        desplazamiento++;
    }


    *(destino + tam) = '\0';//No olvidar el fin de cadena
}

void reemplazarPalabra(char* linea, const char* pal)
{
    //Copia la palabra en la linea
    while(*pal)
    {
        *(linea++) = *(pal++);
    }
}


size_t str_len(const char* s)
{
    size_t tam = 0;

    while(*(s++))
    {
        tam++;
    }

    return tam;
}

char* str_chr(char* s, int c)
{
    while(*s && *s != c)
    {
        s++;
    }

    return(*s == c ? s : NULL); //Si son iguales devuelve la posicion de pLec, caso contrario no existe devuelve NULL
}
