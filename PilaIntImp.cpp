#include "PilaInt.h"

#ifdef PILA_INT_IMP

struct _nodoPilaInt {
    int dato;
    _nodoPilaInt* abajo;
};

struct _cabezalPilaInt {
    _nodoPilaInt* cima;
    unsigned int cantElem;
};


typedef _cabezalPilaInt* PilaInt;

//AUXILIARES

//PRE: -
//POS: agrega todos los elementos de la pila p a la pila nuevo
void aux_clon(PilaInt& nuevo, PilaInt p) {
    int i = 0;
    while (i < cantidadElementos(p)) {
        _nodoPilaInt* cima = p->cima;
        push(nuevo, cima->dato);
        p->cima = cima->abajo;
        i++;
    }
}

//FIN AUXILIARES

PilaInt crearPilaInt() {
    PilaInt p = new _cabezalPilaInt;
    p->cantElem = 0;
    p->cima = NULL;
    return p;
}


void push(PilaInt& p, int e) {
    _nodoPilaInt* nuevo = new _nodoPilaInt;
    _nodoPilaInt* resto = p->cima;
    nuevo->dato = e;
    nuevo->abajo = resto;
    p->cima = nuevo;
    p->cantElem++;
}


int top(PilaInt p) {
    assert(!esVacia(p));
    _nodoPilaInt* cima = p->cima;
    return cima->dato;
}


void pop(PilaInt& p) {
    assert(!esVacia(p));
    _nodoPilaInt* elim = p->cima;
    p->cima = elim->abajo;
    delete elim;
    p->cantElem--;
}


unsigned int cantidadElementos(PilaInt p) {
    return p->cantElem;
}


bool esVacia(PilaInt p) {
    return p->cantElem == 0;
}


PilaInt clon(PilaInt p) {
    PilaInt aux = crearPilaInt();
    PilaInt res = crearPilaInt();
    while (!esVacia(p)) {
        push(aux, top(p));
        pop(p);
    }
    while (!esVacia(aux)) {
        push(res, top(aux));
        push(p, top(aux));
        pop(aux);
    }
    destruir(aux);
    return res;
}


void destruir(PilaInt& p) {
    while (!esVacia(p)) {
        pop(p);
    }
    delete p;
    p = NULL;
}

#endif