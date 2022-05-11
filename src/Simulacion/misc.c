#include<stdlib.h>
#include<Clientes.h>

// Crear un int
int *newInt(int val)
{
    int *out = NULL;

    out = (int*)calloc(1, sizeof(int));
    *out = val;

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
