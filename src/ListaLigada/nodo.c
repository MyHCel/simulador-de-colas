#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"types.h"

// Crear un nuevo nodo
Nodo *newNodo()
{
    Nodo *new = NULL;

    new = (Nodo*)calloc(1, sizeof(Nodo));

    if(!new)
    {
        puts("Sin memoria suficiente :U");
        return NULL;
    }

    new->dato = NULL;
    new->sig = NULL;
    new->id = 0;
    new->ultimo = 0;

    return new;
}

// Destruir un nodo
Nodo *destroyNodo(Nodo *nodo)
{
    nodo->sig = NULL;
    free(nodo->dato);
    nodo->dato = NULL;
    free(nodo);
    nodo = NULL;

    return nodo;
}

// Asignarle algún valor al dato del nodo
// Debe ser un apuntador
void setNodo(Nodo *nodo, void *dato)
{
    nodo->dato = dato;
}
