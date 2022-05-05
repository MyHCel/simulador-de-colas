#include"nodo.h"

// ===================== Init ========================

// Inicializar la lista a NULL
void listaInit(Lista *lista)
{
    lista->raiz = NULL;
    lista->ultimo = NULL;
    lista->size = 0;
}

// ===================== Recorre ========================

// Recorre la lista y ejecuta una función
// por cada nodo
// Regresa el apuntador al último nodo
void *recorreFn(Lista *lista, void(*function)())
{
    Nodo *aux = lista->raiz;
    Nodo *out = NULL;
    int id = 0;

    while(aux)
    {
        function(aux);
        aux->id = id;
        aux->ultimo = 0;
        out = aux;
        aux = aux->sig;
        id++;
    }

    lista->size = id;
    out->ultimo = 1;

    return out;
}

// Nada, no hay, no existe
void vacio_p()
{
    // Aquí no hay nada
}

// Recorre la lista y regresa
// el apuntador al último nodo
void *recorre(Lista *lista)
{
    Nodo *out = recorreFn(lista, vacio_p);
    return out;
}

// ===================== Raíz ========================

// Agrega un nodo al inicio de la lista
void addRaiz(Lista *lista, void *dato)
{
    if(!lista->raiz)
    {
        lista->raiz = newNodo();
        setNodo(lista->raiz, dato);
    }

    else
    {
        Nodo *aux = lista->raiz;

        lista->raiz = newNodo();
        setNodo(lista->raiz, dato);
        lista->raiz->sig = aux;
    }

    lista->ultimo = recorre(lista);
}

// Borrar el nodo del inicio de la
// lista
void removeRaiz(Lista *lista)
{
    Nodo *aux = lista->raiz;

    lista->raiz = lista->raiz->sig;
    aux = destroyNodo(aux);
    lista->ultimo = recorre(lista);
}

// ===================== Último ========================

// Agrega un nodo al final de la
// lista
void addUltimo(Lista *lista, void *dato)
{
    lista->ultimo->sig = newNodo();
    setNodo(lista->ultimo->sig, dato);
    lista->ultimo = recorre(lista);
}

// Borra el nodo del final de la
// lista
void removeUltimo_p(Nodo *nodo)
{
    if(nodo->sig->ultimo)
        nodo->sig = destroyNodo(nodo->sig);
}

// Borra el nodo del final de la
// lista
void removeUltimo(Lista *lista)
{
    lista->ultimo = recorreFn(lista, removeUltimo_p);
}