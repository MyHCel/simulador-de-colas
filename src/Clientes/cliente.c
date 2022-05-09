#include<stdio.h>
#include<stdlib.h>
#include"types.h"

// Crear un cliente
Cliente *newCliente()
{
    Cliente *out = NULL;

    out = (Cliente*)calloc(1, sizeof(Cliente));
    out->tiempoE = 0;
    out->espero = FALSE;

    return out;
}

// Hacer que un cliente espere
void esperar(Nodo *nodo)
{
    Cliente *aux = nodo->dato;
    aux->tiempoE++;
}
