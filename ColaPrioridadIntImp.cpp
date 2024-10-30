#include "ColaPrioridadInt.h"

#ifdef COLAPRIORIDAD_INT_IMP

struct _nodoColaPrioridadInt {
	_nodoColaPrioridadInt* sig;
	int dato;
	int prioridad;
};

struct _cabezalColaPrioridadInt {
	_nodoColaPrioridadInt* ppio;
	_nodoColaPrioridadInt* fin;
	int cota;
	int cantElem;
};

typedef _cabezalColaPrioridadInt* ColaPrioridadInt;

//AUXILIARES

//PRE: -
//POS: elimina el primer elemento con prioridad p de la lista en el caso que se encuentre
void borrarLista(_nodoColaPrioridadInt*& l, int p) {
	if (l != NULL) {
		if (l->prioridad >= p) {
			_nodoColaPrioridadInt* aBorrar = l;
			l = l->sig;
			delete aBorrar;
		}
		else {
			borrarLista(l->sig, p);
		}
	}
}

//PRE: -
//POS: devuelve una copia, sin compartir memoria, de una lista
_nodoColaPrioridadInt* copia(_nodoColaPrioridadInt* a) {
	_nodoColaPrioridadInt* res = NULL;
	if (a != NULL) {
		res = new _nodoColaPrioridadInt;
		res->dato = a->dato;
		res->prioridad = a->prioridad;
		res->sig = copia(a->sig);
	}
	return res;
}

//FIN AUXILIARES


ColaPrioridadInt crearColaPrioridadInt(unsigned int cota) {
	ColaPrioridadInt res = new _cabezalColaPrioridadInt;
	res->ppio = NULL;
	res->fin = NULL;
	res->cota = cota;
	res->cantElem = 0;
	return res;
}

void encolar(ColaPrioridadInt& c, int e, int p) {
	assert(!esLlena(c));
	_nodoColaPrioridadInt* nuevo = new _nodoColaPrioridadInt;
	nuevo->dato = e;
	nuevo->prioridad = p;
	nuevo->sig = NULL;
	if (c->ppio == NULL) {
		c->ppio = nuevo;
		c->fin = nuevo;
	}
	else {
		c->fin->sig = nuevo;
		c->fin = nuevo;
	}
	c->cantElem++;
}

int principio(ColaPrioridadInt c) {
	assert(!esVacia(c));
	int res = c->ppio->dato;
	int p = c->ppio->prioridad;
	_nodoColaPrioridadInt* l = c->ppio->sig;
	while (l != NULL) {
		if (l->prioridad > p) {
			res = l->dato;
			p = l->prioridad;
		}
		l = l->sig;
	}
	return res;
}

int principioPrioridad(ColaPrioridadInt c) {
	assert(!esVacia(c));
	int p = c->ppio->prioridad;
	_nodoColaPrioridadInt* l = c->ppio->sig;
	while (l != NULL) {
		if (l->prioridad > p) {
			p = l->prioridad;
		}
		l = l->sig;
	}
	return p;
}


void desencolar(ColaPrioridadInt& c) {
	assert(!esVacia(c));
	borrarLista(c->ppio, principioPrioridad(c));
	c->cantElem--;
}

bool esVacia(ColaPrioridadInt c) {
	return c->cantElem == 0;
}

bool esLlena(ColaPrioridadInt c) {
	return c->cantElem == c->cota;
}

unsigned int cantidadElementos(ColaPrioridadInt c) {
	return c->cantElem;
}

ColaPrioridadInt clon(ColaPrioridadInt c) {
	ColaPrioridadInt nuevo = crearColaPrioridadInt(c ->cota);
	nuevo->cantElem = c->cantElem;
	nuevo->cota = c->cota;
	nuevo->ppio = copia(c->ppio);
	_nodoColaPrioridadInt* aux = nuevo->ppio;
	nuevo->fin = NULL;
	if (aux != NULL) {
		while (aux->sig != NULL) {
			aux = aux->sig;
		}
		nuevo->fin = aux;
	}
	return nuevo;
}

void destruir(ColaPrioridadInt& c) {
	while (!esVacia(c)) {
		desencolar(c);
	}
	delete c;
	c = NULL;
}

#endif