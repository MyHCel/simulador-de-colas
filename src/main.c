#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<ListaLigada.h>
#include<Clientes.h>

#define CAJEROS 8

int main()
{
    Lista fila, formados;
    Cajero cajero[CAJEROS];
    int razonAtencion = 1800;
    int razonLlegada = 160;
    int atendidos = 0;
    int rezagados = 0;
    int *sumatoria = NULL;
    double promedio = 0.0;

    randomInit();
    listaInit(&fila);
    listaInit(&formados);

    for(int n = 0; n < CAJEROS; n++)
        setCajero(&cajero[n], razonAtencion, n);

    // ================================================

    int tiempo = 0;
    int llegada = 0;

    while(tiempo < 32400)
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
                        ocuparCajero(&cajero[n], nuevo, razonAtencion);
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

            llegada = randomNumber(3, razonLlegada);
        }

        // =============== Actualizar cajeros y filas ======================

        for(int n = 0; n < CAJEROS; n++)
        {
            if(fila.raiz)
            {
                if(!cajero[n].ocupado)
                    ocuparCajero(&cajero[n], removeRaiz(&fila, FALSE), razonAtencion);
            }

            if(!cajero[n].tiempoA && cajero[n].ocupado)
            {
                Cliente *aux = desocuparCajero(&cajero[n]);
                atendidos++;

                if(aux->espero)
                    addRaiz(&formados, aux);

                else
                    free(aux);
            }
        }

        // ============== Acualiza tiempo ==============

        recorreFn(&fila, esperar);

        for(int n = 0; n < CAJEROS; n++)
        {
            if(cajero[n].ocupado && cajero[n].tiempoA)
                cajero[n].tiempoA--;
        }

        if(llegada)
            llegada--;

        tiempo++;
    }

    rezagados = fila.size;

    while(fila.raiz)
        addRaiz(&formados, removeRaiz(&fila, FALSE));

    addUltimo(&formados, getInt());
    recorreFn(&formados, getSumatoria);
    sumatoria = formados.ultimo->dato;
    promedio = *sumatoria / (double)formados.size;

return 0;
}
