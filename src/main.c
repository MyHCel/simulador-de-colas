#include<stdio.h>
#include<string.h>
#include<ListaLigada.h>

// Constructor de prueba
char *newString(char *string)
{
    char *ggg = NULL;
    ggg = (char*)calloc(strlen(string), sizeof(char));
    memcpy(ggg, string, strlen(string));
}

// Función de prueba
void print(Nodo *nodo)
{
    printf("[%s]\n", nodo->dato);
}

int main()
{
    Lista clientes;

    listaInit(&clientes);
    addUltimo(&clientes, newString("Juan Premium"));
    addUltimo(&clientes, newString("Juan"));
    addUltimo(&clientes, newString("Pancha"));
    addUltimo(&clientes, newString("Alan Brito Delgado"));
    addUltimo(&clientes, newString("Elba Surita"));
    addUltimo(&clientes, newString("io merengues"));
    
    recorreFn(&clientes, print);
    puts(" ");

    removeRaiz(&clientes);
    removeRaiz(&clientes);
    removeRaiz(&clientes);

    recorreFn(&clientes, print);
    nukeLista(&clientes);

return 0;
}
