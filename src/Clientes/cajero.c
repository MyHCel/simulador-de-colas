#include<stdio.h>
#include<stdlib.h>
#include"types.h"
#include"bruh.h"

void setCajero(Cajero *cajero, int razonAtencion, int id)
{
    cajero->id = id;
    cajero->tiempoA = 0;
    cajero->rAtencion = razonAtencion;
    cajero->ocupado = FALSE;
    cajero->cliente = NULL;
}

Cajero *newCajero(int razonAtencion, int id)
{
    Cajero *out = NULL;

    out = (Cajero*)calloc(1, sizeof(Cajero));
    setCajero(out, razonAtencion, id);

    return out;
}

void ocuparCajero(Cajero *cajero, Cliente *cliente, int razonAtencion)
{
    cajero->cliente = cliente;
    cajero->ocupado = TRUE;
    cajero->tiempoA = randomNumber(5, razonAtencion);
}

void *desocuparCajero(Cajero *cajero)
{
    Cliente *out = cajero->cliente;

    cajero->cliente = NULL;
    cajero->ocupado = FALSE;
    cajero->tiempoA = 0;

    return out;
}
