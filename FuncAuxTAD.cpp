#include "FuncAuxTAD.h"

ListaOrdInt FrameworkA1::ConvertirAListaOrd(NodoListaInt *l) {
	ListaOrdInt ret = crearListaOrdInt();
	while (l != NULL) {
		agregar(ret, l->dato);
        l = l->sig;
    }
	return ret;
}


ListaPosInt FrameworkA1::ConvertirAListaPos(NodoListaInt *l) {
	ListaPosInt ret = crearListaPosInt();
	unsigned int pos = 0;
	while (l != NULL) {
		agregar(ret, l->dato, pos++);
        l = l->sig;
    }
	return ret;
}

PilaInt FrameworkA1::ConvertirAPila(NodoListaInt *l) {
	PilaInt ret = crearPilaInt();
	while (l != NULL) {
		push(ret, l->dato);
        l = l->sig;
    }
	return ret;
}

ColaInt FrameworkA1::ConvertirACola(NodoListaInt *l) {
	ColaInt ret = crearColaInt();
	while (l != NULL) {
		encolar(ret, l->dato);
        l = l->sig;
    }
	return ret;
}


MultisetInt FrameworkA1::ConvertirAMultiSet(NodoListaInt *l) {
	MultisetInt ret = crearMultisetInt();
	while (l != NULL) {
		agregar(ret, l->dato, 1);
        l = l->sig;
    }
	return ret;
}

SetInt FrameworkA1::ConvertirASet(NodoListaInt *l) {
	SetInt ret = crearSetInt();
	while (l != NULL) {
		agregar(ret, l->dato);
		l = l->sig;
    }
	return ret;
}


DiccionarioInt FrameworkA1::ConvertirADiccionario(NodoListaInt *l) {
	DiccionarioInt ret = crearDiccionarioInt(10);
	while (l != NULL) {
		agregar(ret, l->dato);
        l = l->sig;
    }
	return ret;
}

TablaIntInt FrameworkA1::ConvertirATabla(NodoListaInt *d, NodoListaInt *r) {
	TablaIntInt ret = crearTablaIntInt(10);
	while (d != NULL && r != NULL) {
		agregar(ret, d->dato, r->dato);
		d = d->sig;
		r = r->sig;
    }
	assert (d == NULL && r == NULL);
	return ret;
}

TablaIntString FrameworkA1::ConvertirATabla(NodoListaInt *d, NodoListaString *r) {
	TablaIntString ret = crearTablaIntString(10);
	while (d != NULL && r != NULL) {
		agregar(ret, d->dato, r->dato);
		d = d->sig;
		r = r->sig;
    }
	assert (d == NULL && r == NULL);
	return ret;
}

ColaPrioridadInt FrameworkA1::ConvertirAColaPrioridad(NodoListaInt *e, NodoListaInt *p) {
	unsigned int cota = 0;
	NodoListaInt* auxe = e;
	while (auxe != NULL) {
		cota++;
		auxe = auxe->sig;
	}

	ColaPrioridadInt ret = crearColaPrioridadInt(cota);
	while (e != NULL && p != NULL) {
		encolar(ret, e->dato, p->dato);
		e = e->sig;
		p = p->sig;
    }
	assert (e == NULL && p == NULL);
	return ret;
}

