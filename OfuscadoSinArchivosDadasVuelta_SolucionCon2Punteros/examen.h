#ifndef OFUSCADO_INCLUDED
#define OFUSCADO_INCLUDED

typedef struct {
    const char* ini;
    const char* fin;
} Palabra;

size_t quieroUnaLineaDeTextoOfuscadaDVV(char* linea);
char* desofuscarALU(char* linea);

Palabra obtenerPalabra(const char* linea);
void desplazarCaracter(char* c, int desplazamiento);
void procesarPalabra(Palabra pal, char* destino);
void reemplazarPalabra(char* linea, const char* pal);


/**Funciones auxilires string.h**/

size_t str_len(const char* s);
char* str_chr(char* s, int c); /**Localia la primera aparicion de c en s**/

#endif // OFUSCADO_INCLUDED
