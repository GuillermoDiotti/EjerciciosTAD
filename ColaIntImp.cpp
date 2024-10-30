#include "ColaInt.h"

#ifdef COLA_INT_IMP

struct _nodoColaInt {
    int dato;
    _nodoColaInt* sig;
};

struct _cabezalColaInt {
    int cantElem;
    _nodoColaInt* ppio;
    _nodoColaInt* fin;
};

typedef _cabezalColaInt* ColaInt;


ColaInt crearColaInt() {
    ColaInt c = new _cabezalColaInt;
    c->cantElem = 0;
    c->fin = NULL;
    c->ppio = c->fin;
    return c;
}


void encolar(ColaInt& c, int e) {
    _nodoColaInt* nuevo = new _nodoColaInt;
    nuevo->dato = e;
    nuevo->sig = NULL;
    if (c->ppio == NULL) {
        c->ppio = nuevo;
    }
    else {
        c->fin->sig = nuevo;
    }
    c->fin = nuevo;
    c->cantElem++;
}


int principio(ColaInt c) {
    assert(!esVacia(c));
    return c->ppio->dato;
}


void desencolar(ColaInt& c) {
    assert(!esVacia(c));
    _nodoColaInt* elim = c->ppio;
    c->ppio = elim->sig;
    delete elim;
    c->cantElem--;
}


bool esVacia(ColaInt c) {
    return c->cantElem == 0;
}


unsigned int cantidadElementos(ColaInt c) {
    return c->cantElem;
}


_nodoColaInt* copia(_nodoColaInt* a) {
    _nodoColaInt* res = NULL;
    if (a != NULL) {
        res = new _nodoColaInt;
        res->dato = a->dato;
        res->sig = copia(a->sig);
    }
    return res;
}


ColaInt clon(ColaInt c) {
    ColaInt nuevo = crearColaInt();
    nuevo->cantElem = c->cantElem;
    nuevo->ppio = copia(c->ppio);
    _nodoColaInt* aux = nuevo->ppio;
    nuevo->fin = NULL;
    if (aux != NULL) {
        while (aux->sig != NULL) {
            aux = aux->sig;
        }
        nuevo->fin = aux;
    }
    return nuevo;
}


void destruir(ColaInt& c) {
    while (!esVacia(c)) {
        desencolar(c);
    }
    delete c;
    c = NULL;
}

#endif