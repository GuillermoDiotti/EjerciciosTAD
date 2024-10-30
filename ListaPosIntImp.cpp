#include "ListaPosInt.h"

#ifdef LISTA_POS_INT_IMP

struct _cabezalListaPosInt {
    int* vec;
    unsigned int largoVec;
    unsigned int cantElem;
};

typedef _cabezalListaPosInt* ListaPosInt;

//AUXILIARES

//PRE: -
//POS: inserta todos los elementos de un vector en otro vector
void copiar(int*& vec, ListaPosInt l) {
    for (int i = 0; i < cantidadElementos(l); i++) {
        vec[i] = l->vec[i];
    }
}


//FIN AUXILIARES


ListaPosInt crearListaPosInt()
{
    ListaPosInt lista = new _cabezalListaPosInt;
    lista->largoVec = 0;
    lista->cantElem = 0;
    lista->vec = NULL;
    return lista;
}


void agregar(ListaPosInt& l, int e, unsigned int pos)
{
    if (cantidadElementos(l) == l->largoVec) {
        int largo = 10 + l->largoVec;
        int* vec = new int[largo];
        copiar(vec, l);
        delete[](l->vec);
        l->vec = vec;
        l->largoVec = largo;
    }
    if (pos >= cantidadElementos(l)) {
        pos = cantidadElementos(l);
        l->vec[pos] = e;
    }
    else {
        for (int i = cantidadElementos(l) - 1; i > pos - 1; i--) {
            l->vec[i + 1] = l->vec[i];
        }
        l->vec[pos] = e;
    }
    l->cantElem++;
}


void borrar(ListaPosInt& l, unsigned int pos)
{
    if (pos < cantidadElementos(l)) {
        for (int i = pos; i < cantidadElementos(l) - 1; i++) {
            l->vec[i] = l->vec[i + 1];
        }
        l->cantElem--;
        if (l->largoVec - 10 == cantidadElementos(l)) {
            int* vec = new int[l->largoVec - 10];
            copiar(vec, l);
            delete[](l->vec);
            l->vec = vec;
            l->largoVec = l->largoVec - 10;
        }
    }
}


int elemento(ListaPosInt l, unsigned int pos)
{
    return l->vec[pos];
}


bool esVacia(ListaPosInt l)
{
    return l->cantElem == 0;
}


unsigned int cantidadElementos(ListaPosInt l)
{
    return l->cantElem;
}


ListaPosInt clon(ListaPosInt l)
{
    ListaPosInt lista = crearListaPosInt();
    lista->vec = new int[l->largoVec];
    copiar(lista->vec, l);
    lista->cantElem = l->cantElem;
    lista->largoVec = l->largoVec;
    return lista;
}


void destruir(ListaPosInt& l)
{
    delete[](l->vec);
    delete l;
    l = NULL;
}


#endif