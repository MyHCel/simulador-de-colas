#include<stdlib.h>
#include<time.h>
#include<ListaLigada.h>
#include"types.h"

// Inicializar el randomizador
void randomInit()
{
    srand(time(NULL));
}

// Obtener un número aleatorio
int randomNumber(int lower, int upper)
{
    int out = (rand() % (upper - lower + 1)) + lower;
    return out;
}

// Obtener un apuntador a un int
int *getInt()
{
    int *out = NULL;

    out = (int*)calloc(1, sizeof(int));
    *out = 0;

    return out;
}

// Obtener la sumatoria de todos los
// clientes
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
