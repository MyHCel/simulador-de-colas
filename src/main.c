// Proyecto final de programación avanzada
// Hecho por Rodrigo de Jesús Aguilar Vazquez Y
// Hector Yariel Celis Murillo

#include<stdio.h>
#include<string.h>
#include<Simulacion.h>

int main()
{
    Simulacion simulacion;

    puts("========= Simulador de Colas =========\n");

    setSimulacion(&simulacion);
    startSimulacion(&simulacion);
    printSimulacion(simulacion);

    puts("======================================\n");

return 0;
}
