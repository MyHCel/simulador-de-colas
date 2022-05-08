#ifndef _LISTA_H__
#define _LISTA_H__

#include"nodo.h"

// Inicializar la lista a NULL
void listaInit(Lista *lista);

// Recorre la lista y ejecuta una función
// por cada nodo
// Regresa el apuntador al último nodo
void *recorreFn(Lista *lista, void(*function)());

// Agrega un nodo al inicio de la lista
void addRaiz(Lista *lista, void *dato);

// Borrar el nodo del inicio de la
// lista
// Regresa el dato
void *removeRaiz(Lista *lista, bool delDato);

// Agrega un nodo al final de la
// lista
void addUltimo(Lista *lista, void *dato);

// Remueve el nodo del final de la
// lista y regresa el dato
void *removeUltimo(Lista *lista, bool delDato);

// PELIGRO!!!!
// Esto borra TODA la lista
void nukeLista(Lista *lista);

#endif // _LISTA_H__
