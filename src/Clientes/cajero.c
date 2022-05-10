#include<stdio.h>
#include<stdlib.h>
#include"types.h"
#include"bruh.h"

// Configurar un cajero
void setCajero(Cajero *cajero, int id)
{
    cajero->id = id;
    cajero->tiempoA = 0;
    cajero->ocupado = FALSE;
    cajero->cliente = NULL;

    printf("Razón de atención del cajero %d: ", cajero->id + 1);
    scanf("%d", &cajero->rAtencion);
}

// Ocupar un cajero
void ocuparCajero(Cajero *cajero, Cliente *cliente)
{
    cajero->cliente = cliente;
    cajero->ocupado = TRUE;
    cajero->tiempoA = randomNumber(1, cajero->rAtencion);
}

// Desocupar un cajero
void *desocuparCajero(Cajero *cajero)
{
    Cliente *out = cajero->cliente;

    cajero->cliente = NULL;
    cajero->ocupado = FALSE;
    cajero->tiempoA = 0;

    return out;
}
