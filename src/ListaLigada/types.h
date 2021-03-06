#ifndef _LISTALIGADA_TYPES_H__
#define _LISTALIGADA_TYPES_H__

#define TRUE    1
#define FALSE   0

typedef unsigned char bool;

typedef struct Nodo
{
    void *dato;
    int id;
    bool ultimo;
    struct Nodo *sig;
} Nodo;

typedef struct
{
    Nodo *raiz;
    Nodo *ultimo;
    size_t size;
} Lista;

#endif // _LISTALIGADA_TYPES__
