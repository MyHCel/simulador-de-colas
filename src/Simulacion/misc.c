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

int contarLlegadaLaSecuela(int *arr, int len)
{
    int out = 0;

    for(int n = 0; n < len; n++)
    {
        if(arr[n] > 0)
            arr[n]--;

        if(arr[n] == 0)
        {
            out++;
            arr[n] = -1;
        }
    }

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
