#ifndef _SIMULACION_TYPES_H__
#define _SIMULACION_TYPES_H__

#include<Clientes.h>

typedef struct
{
    int ncajeros;
    Cajero *cajero;
    int razonLlegada;

    int atendidos;
    int rezagados;
    int sumatoria;
    int vecesVacia;
    int promedio;
} Simulacion;

#endif // _SIMULACION_TYPES_H__
