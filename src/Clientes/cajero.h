#ifndef _CAJERO_H__
#define _CAJERO_H__

#include"types.h"

// Configurar un cajero
void setCajero(Cajero *cajero, int id);

// Ocupar un cajero
void ocuparCajero(Cajero *cajero, Cliente *cliente);

// Desocupar un cajero
void *desocuparCajero(Cajero *cajero);

#endif // _CAJERO_H__
