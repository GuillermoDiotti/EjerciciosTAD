#include "ListaOrdInt.h"

#ifdef LISTA_ORD_INT_IMP

struct _cabezalListaOrdInt {
	NodoListaInt* ppio;
	unsigned int largo;
};

/* AUXILIARES */

// PRE:
// POS: Agrega el dato ordenado creando un nuevo nodo
void agregar(NodoListaInt*& l, int dato) {
	if (l == NULL) {
		l = new NodoListaInt(dato);
	}
	else if (dato <= l->dato) {
		NodoListaInt* nuevo = new NodoListaInt(dato);
		nuevo->sig = l;
		l = nuevo;
	}
	else { // if (dato > l->dato)
		agregar(l->sig, dato);
	}
}

// PRE:
// POS: Borra el nodo con el dato maximo
bool borrarMaximo(NodoListaInt*& l) {
	if (l == NULL) {
		return false;
	}
	if (l->sig != NULL) {
		return borrarMaximo(l->sig);
	}
	NodoListaInt* temp = l;
	l = l->sig;
	delete temp;
	return true;
}


// PRE:
// POS: Borra el nodo con el dato
bool borrar(NodoListaInt*& l, int dato) {
	if (l == NULL) return false;
	if (dato > l->dato) {
		return borrar(l->sig, dato);
	}
	if (dato < l->dato) {
		return false;
	}
	NodoListaInt* temp = l;
	l = l->sig;
	delete temp;
	return true;
}

// PRE:
// POS: Borra todos los nodos
void vaciar(NodoListaInt*& l) {
	if (l != NULL) {
		vaciar(l->sig);
		delete l;
		l = NULL;
	}
}

// PRE:
// POS: Retorna un puntero a la copia de todos los nodos
NodoListaInt* clon(NodoListaInt* l) {
	if (l == NULL) return NULL;
	NodoListaInt* nuevo = new NodoListaInt;
	nuevo->dato = l->dato;
	nuevo->sig = clon(l->sig);
	return nuevo;
}

// PRE:
// POS: Retorna si existe el dato en un nodo
bool existe(NodoListaInt* l, int dato) {
	if (l == NULL) return false;
	if (dato > l->dato) {
		return existe(l->sig, dato);
	}
	if (dato < l->dato) {
		return false;
	}
	return true;
}
/* FIN AUXILIARES */


ListaOrdInt crearListaOrdInt() {
	ListaOrdInt cabezal = new _cabezalListaOrdInt;
	cabezal->ppio = NULL;
	cabezal->largo = 0;
	return cabezal;
}

void agregar(ListaOrdInt& l, int e) {
	agregar(l->ppio, e);
	l->largo++;
}

void borrarMinimo(ListaOrdInt& l) {
	if (l->ppio == NULL) return;
	NodoListaInt *borro = l->ppio;
	l->ppio = l->ppio->sig;
	l->largo--;
	delete borro;
}

void borrarMaximo(ListaOrdInt& l) {
	if (borrarMaximo(l->ppio)) l->largo--;
}

void borrar(ListaOrdInt& l, int e) {
	if (borrar(l->ppio, e)) l->largo--;
}

int minimo(ListaOrdInt l) {
	assert(!esVacia(l));
	return l->ppio->dato;
}

int maximo(ListaOrdInt l) {
	assert(!esVacia(l));
	NodoListaInt* aux = l->ppio;
#pragma warning(suppress: 28182)
	while (aux->sig != NULL) {
		aux = aux->sig;
	}
	return aux->dato;
}

bool existe(ListaOrdInt l, int e) {
	return existe(l->ppio, e);
}

bool esVacia(ListaOrdInt l) {
	return l->largo == 0;
}

unsigned int cantidadElementos(ListaOrdInt l) {
	return l->largo;
}

ListaOrdInt clon(ListaOrdInt l) {
	ListaOrdInt cabezal = new _cabezalListaOrdInt;
	cabezal->ppio = clon(l->ppio);
	cabezal->largo = l->largo;
	return cabezal;
}

void destruir(ListaOrdInt& l) {
	vaciar(l->ppio);
	delete l;
	l = NULL;
}



#endif