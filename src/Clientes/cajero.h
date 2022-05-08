#ifndef _CAJERO_H__
#define _CAJERO_H__

#include"types.h"

void setCajero(Cajero *cajero, int razonAtencion, int id);
Cajero *newCajero(int id);
void ocuparCajero(Cajero *cajero, Cliente *cliente, int razonAtencion);
void *desocuparCajero(Cajero *cajero);

#endif // _CAJERO_H__
