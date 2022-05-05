#include<stdio.h>
#include<string.h>
#include<ListaLigada.h>

char *nuevoChar(char *string)
{
    char *ggg = NULL;
    ggg = (char*)calloc(strlen(string), sizeof(char));
    memcpy(ggg, string, strlen(string));
}

void print(Nodo *nodo)
{
    printf("[%s]\n", nodo->dato);
}

int main()
{
    Lista clientes;

    listaInit(&clientes);
    addRaiz(&clientes, nuevoChar("Juan premium"));
    addRaiz(&clientes, nuevoChar("Panchito"));
    addUltimo(&clientes, nuevoChar("Juana"));
    removeRaiz(&clientes);
    removeUltimo(&clientes);
    recorreFn(&clientes, print);

return 0;
}
