#ifndef _NODO_TYPES_H__
#define _NODO_TYPES_H__

typedef struct Nodo
{
    void *dato;
    int id;
    int ultimo;
    struct Nodo *sig;
} Nodo;

typedef struct
{
    Nodo *raiz;
    Nodo *ultimo;
    size_t size;
} Lista;

#endif // _NODO_TYPES__
