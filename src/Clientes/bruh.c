#include<stdlib.h>
#include<time.h>
#include<ListaLigada.h>
#include"types.h"

void randomInit()
{
    srand(time(NULL));
}

int randomNumber(int lower, int upper)
{
    int out = (rand() % (upper - lower + 1)) + lower;
    return out;
}

int *getInt()
{
    int *out = NULL;

    out = (int*)calloc(1, sizeof(int));
    *out = 0;

    return out;
}

void getSumatoria(Nodo *nodo)
{
    static int out;

    if(!nodo->ultimo)
    {
        Cliente *aux = nodo->dato;
        out += aux->tiempoE;
    }

    else
    {
        int *aux = nodo->dato;
        *aux = out;
    }
        
}
