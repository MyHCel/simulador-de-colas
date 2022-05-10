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
        aux->ultimo = FALSE;
        out = aux;
        aux = aux->sig;
        id++;
    }

    lista->size = id;

    if(out)
        out->ultimo = TRUE;

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
// Regresa el dato
void *removeRaiz(Lista *lista, bool delDato)
{
    if(lista->raiz)
    {
        void *aux = lista->raiz;

        lista->raiz = lista->raiz->sig;
        aux = destroyNodo(aux, delDato);
        lista->ultimo = recorre(lista);

        return aux;
    }

    else
        return NULL;
}

// ===================== Último ========================

// Agrega un nodo al final de la
// lista
void addUltimo(Lista *lista, void *dato)
{
    if(lista->ultimo)
    {
        lista->ultimo->sig = newNodo();
        setNodo(lista->ultimo->sig, dato);
        lista->ultimo = recorre(lista);
    }

    else
        addRaiz(lista, dato);
}

// Remueve el nodo del final de la
// lista
void removeUltimo_p(Nodo *nodo)
{
    if(nodo->sig->ultimo)
    {
        destroyNodo(nodo->sig, FALSE);
        nodo->sig = NULL;
    }
}

// Remueve el nodo del final de la
// lista y borra el dato
void removeUltimo_p_d(Nodo *nodo)
{
    if(nodo->sig->ultimo)
    {
        nodo->sig = destroyNodo(nodo->sig, TRUE); 
    }
}

// Remueve el nodo del final de la
// lista y regresa el dato
void *removeUltimo(Lista *lista, bool delDato)
{
    if(lista->raiz)
    {
        void *aux = lista->ultimo;

        if(lista->raiz->ultimo)
        {
            aux = removeRaiz(lista, delDato);
            return aux;
        }

        else if(delDato)
        {
            lista->ultimo = recorreFn(lista, removeUltimo_p_d);
            return NULL;
        }

        else
        {
            aux = lista->ultimo->dato;
            lista->ultimo = recorreFn(lista, removeUltimo_p);
            return aux;
        }
    }

    else
        return NULL;
}

// ===================== NUKEEE DA LIIIST!!!! ========================

// PELIGRO!!!!
// Esto borra TODA la lista
void nukeLista(Lista *lista)
{
    while(lista->raiz)
        removeRaiz(lista, TRUE);
}
