#ifndef _SIM_H__
#define _SIM_H__

#include"types.h"

// Configurar una simulación
void setSimulacion(Simulacion *sim);

// Crear una simulación
Simulacion *newSimulacion();

// Empezar la simulación
void startSimulacion(Simulacion *sim);

// Imprimir los resultados de la simulación
void printSimulacion(Simulacion sim);

#endif // _SIM_H__
