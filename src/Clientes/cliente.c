#include<stdio.h>
#include<stdlib.h>
#include"types.h"

Cliente *newCliente()
{
    Cliente *out = NULL;

    out = (Cliente*)calloc(1, sizeof(Cliente));
    out->tiempoE = 0;
    out->espero = FALSE;

    return out;
}

void esperar(Nodo *nodo)
{
    Cliente *aux = nodo->dato;
    aux->tiempoE++;
}

void printCliente(Cliente *cliente)
{
    //printf("Tiempo atención: %d\n", cliente->tiempoA);
    printf("Tiempo esperando: %d\n", cliente->tiempoE);
}
