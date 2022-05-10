#ifndef _MISC_H__
#define _MISC_H__

#include<Clientes.h>

// Crear un int
int *newInt(int val);

void contarLlegada(Nodo *nodo);
int contarLlegadaLaSecuela(int *arr, int len);

// Obtener la sumatoria de todos los
// clientes
void getSumatoria(Nodo *nodo);

#endif // _MISC_H__
