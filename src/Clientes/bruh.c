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
