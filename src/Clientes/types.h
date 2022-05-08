#ifndef _CLIENTES_TYPES_H__
#define _CLIENTES_TYPES_H__

#include<ListaLigada.h>

typedef struct
{
    //int tiempoA; // Atender
    int tiempoE; // Esera
    bool espero;
} Cliente;

typedef struct
{
    int id;
    int tiempoA;
    int rAtencion;
    bool ocupado;
    Cliente *cliente;
} Cajero;

#endif // _CLIENTES_TYPES_H__
