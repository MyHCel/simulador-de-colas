#include<stdio.h>
#include"types.h"
#include"misc.h"

// Configurar una simulación
void setSimulacion(Simulacion *sim)
{
    sim->atendidos = 0;
    sim->rezagados = 0;
    sim->sumatoria = 0;
    sim->promedio = 0.0;

    printf("Razón de llegadas promedio: ");
    scanf("%d", &sim->razonLlegada);

    printf("Número de cajeros: ");
    scanf("%d", &sim->ncajeros);

    sim->cajero = (Cajero*)calloc(sim->ncajeros, sizeof(Cajero));

    for(int n = 0; n < sim->ncajeros; n++)
        setCajero(&sim->cajero[n], n);
}

// Crear una simulación
Simulacion *newSimulacion()
{
    Simulacion *out = NULL;

    out = (Simulacion*)calloc(1, sizeof(Simulacion));
    setSimulacion(out);

    return out;
}

// Empezar la simulación
void startSimulacion(Simulacion *sim)
{
    // Simulación
    Lista fila, formados;
    int llegada = 0;
    int *sumatoria = NULL;
    int tiempo = 0;
    bool vacia = TRUE;

    // Entrada
    Cajero *cajero = sim->cajero;
    int CAJEROS = sim->ncajeros;
    int razonLlegada = sim->razonLlegada;

    // Salida
    int atendidos = 0;
    int rezagados = 0;
    int vecesVacia = 0;

    randomInit();
    listaInit(&fila);
    listaInit(&formados);

    // ================================================

    while(tiempo < 34200)
    {
        // ============== Agrega clientes ==============

        if(!llegada)
        {
            Cliente *nuevo = newCliente();

            if(!fila.raiz)
            {
                int n = 0;

                for(n = 0; n < CAJEROS; n++)
                {
                    if(!cajero[n].ocupado)
                    {
                        ocuparCajero(&cajero[n], nuevo);
                        break;
                    }
                }

                if(n == CAJEROS)
                {
                    nuevo->espero = TRUE;
                    addUltimo(&fila, nuevo);
                }
            }

            else
            {
                nuevo->espero = TRUE;
                addUltimo(&fila, nuevo);
            }

            llegada = randomNumber(1, razonLlegada);
        }

        // =============== Actualizar cajeros y filas ======================

        for(int n = 0; n < CAJEROS; n++)
        {
            if(fila.raiz)
            {
                if(!cajero[n].ocupado)
                    ocuparCajero(&cajero[n], removeRaiz(&fila, FALSE));
            }

            if((cajero[n].tiempoA == 1) && cajero[n].ocupado)
            {
                Cliente *aux = desocuparCajero(&cajero[n]);
                atendidos++;

                if(aux->espero)
                    addRaiz(&formados, aux);

                else
                    free(aux);
            }
        }

        // ======== Revisar si la fila se vacio o lleno ==========

        if(fila.raiz && vacia)
            vacia = FALSE;

        if(!fila.raiz && !vacia)
        {
            vacia = TRUE;
            vecesVacia++;
        }

        // ============== Acualiza tiempo ==============

        recorreFn(&fila, esperar);

        for(int n = 0; n < CAJEROS; n++)
        {
            if(cajero[n].tiempoA)
                cajero[n].tiempoA--;
        }

        llegada--;
        tiempo++;
    }

    // ============== Vaciar cajeros ==============

    for(int n = 0; n < CAJEROS; n++)
    {
        if(cajero[n].ocupado)
        {
            Cliente *aux = desocuparCajero(&cajero[n]);
            atendidos++;

            if(aux->espero)
                addRaiz(&formados, aux);

            else
                free(aux);
        }
    }

    // ============== Estadisticas ==============

    rezagados = fila.size;

    while(fila.raiz)
        addRaiz(&formados, removeRaiz(&fila, FALSE));

    addUltimo(&formados, newInt(0));
    recorreFn(&formados, getSumatoria);

    sim->atendidos = atendidos;
    sim->rezagados = rezagados;
    sumatoria = formados.ultimo->dato;
    sim->sumatoria = *sumatoria;
    sim->vecesVacia = vecesVacia;

    // Promedio
    sim->promedio = sim->sumatoria / formados.size;

    nukeLista(&fila);
    nukeLista(&formados);
}

// Imprimir los resultados de la simulación
void printSimulacion(Simulacion sim)
{
    puts("\nEstadísticas:");
    puts("Inicio de actividades: 8:00");
    puts("Fin de actividades: 5:30\n");

    printf("Se atendieron %d clientes\n", sim.atendidos);
    printf("Quedaron %d clientes en cola de espra\n", sim.rezagados);
    printf("El cliente permanece en promedio %d segundos en la cola\n", sim.promedio);

    printf("La cola estuvo vacía %d veces\n\n", sim.vecesVacia);
}
