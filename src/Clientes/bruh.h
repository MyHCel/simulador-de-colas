#ifndef _BRUH_H__
#define _BRUH_H__

#include<ListaLigada.h>

// Inicializar el randomizador
void randomInit();

// Obtener un número aleatorio
int randomNumber(int lower, int upper);

// Obtener un apuntador a un int
int *getInt();

// Obtener la sumatoria de todos los
// clientes
void getSumatoria(Nodo *nodo);

#endif // _BRUH_H__
