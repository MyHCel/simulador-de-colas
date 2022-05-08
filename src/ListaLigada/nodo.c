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
// Regresa el dato
void *destroyNodo(Nodo *nodo, bool delDato)
{
    void *out = nodo->dato;

    nodo->sig = NULL;
    nodo->dato = NULL;

    free(nodo);
    nodo = NULL;

    if(delDato)
    {
        free(out);
        return nodo;
    }

    else
    {
        return out;
    }
}

// Asignarle algún valor al dato del nodo
// Debe ser un apuntador
void setNodo(Nodo *nodo, void *dato)
{
    nodo->dato = dato;
}

void printNodo(Nodo *nodo, void(*printDato)())
{
    if(nodo)
    {
        printf("ID: %d\n", nodo->id);
        printDato(nodo->dato);
    }
}
