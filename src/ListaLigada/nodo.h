#ifndef _NODO_H__
#define _NODO_H__

#include<stdlib.h>
#include"types.h"

// Crear un nuevo nodo
Nodo *newNodo();

// Asignarle algún valor al dato del nodo
// Debe ser un apuntador
void setNodo(Nodo *nodo, void *dato);

// Destruir un nodo
// Regresa el dato
void *destroyNodo(Nodo *nodo, bool delDato);

#endif // _NODO_H__
