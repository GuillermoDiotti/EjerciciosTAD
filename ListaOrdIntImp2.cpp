#include "ListaOrdInt.h"

#ifdef LISTA_ORD_INT_IMP_2

struct _nodoListaOrdInt {
    int dato;
    _nodoListaOrdInt* izq;
    _nodoListaOrdInt* der;
    int cantRepetidos;
};


struct _cabezalListaOrdInt {
    _nodoListaOrdInt* abb;
    int cantElem;
};


typedef _cabezalListaOrdInt* ListaOrdInt;


//AUXILIARES

//PRE: -
//POS: inserta una ocurrencia de el elemento dato en el arbol a
void insABB(int dato, _nodoListaOrdInt*& a) {
    if (a == NULL) {
        _nodoListaOrdInt* nuevo = new _nodoListaOrdInt;
        nuevo->dato = dato;
        nuevo->izq = NULL;
        nuevo->der = NULL;
        nuevo->cantRepetidos = 0;
        a = nuevo;
    }
    else if (dato < a->dato) {
        insABB(dato, a->izq);
    }
    else if (dato > a->dato) {
        insABB(dato, a->der);
    }
    else {
        a->cantRepetidos++;
    }
}


//PRE -
//POS: retorna un puntero al valor minimo de a
_nodoListaOrdInt* aux_Min(_nodoListaOrdInt* a) {
    if (a == NULL) return NULL;
    while (a->izq != NULL) {
        a = a->izq;
    }
    return a;
}


//PRE -
//POS: retorna un puntero a el valor maximo de a
_nodoListaOrdInt* aux_Max(_nodoListaOrdInt* a) {
    if (a == NULL) return NULL;
    while (a->der != NULL) {
        a = a->der;
    }
    return a;
}


//PRE: -
//POS: retorna true si y solo si existe el elemento e en el arbol a
bool aux_existe(int e, _nodoListaOrdInt* a) {
    if (a == NULL) {
        return false;
    }
    if (a->dato == e) {
        return true;
    }
    else {
        return aux_existe(e, a->izq) || aux_existe(e, a->der);
    }
}


//PRE: -
//POS: devuelve true si elimina el valor e del arbol a
bool elimABB(int e, _nodoListaOrdInt*& a) {
    if (a != NULL) {
        if (e < a->dato) {
            return elimABB(e, a->izq);
        }
        else if (e > a->dato) {
            return elimABB(e, a->der);
        }
        else {
            a->cantRepetidos--;
            if (a->cantRepetidos < 0) {
                _nodoListaOrdInt* elim = a;
                if (a->der != NULL) {
                    _nodoListaOrdInt* aux = aux_Min(a->der);
                    aux->izq = a->izq;
                    a = a->der;
                    delete elim;
                }
                else {
                    a = a->izq;
                    delete elim;
                }
            }
            return true;
        }
    }
    return false;
}


//PRE: -
//POS: inserta todos los elementos de un árbol en otro árbol
void copia(_nodoListaOrdInt* a, _cabezalListaOrdInt*& nuevo) {
    if (a == NULL) {
        return;
    }
    for (int i = 0; i <= a->cantRepetidos; i++) {
        agregar(nuevo, a->dato);
    }
    copia(a->izq, nuevo);
    copia(a->der, nuevo);
}

//FIN AUXILIAR


ListaOrdInt crearListaOrdInt() {
    ListaOrdInt cabezal = new _cabezalListaOrdInt;
    cabezal->cantElem = 0;
    cabezal->abb = NULL;
    return cabezal;
}


void agregar(ListaOrdInt& l, int e) {
    insABB(e, l->abb);
    l->cantElem++;
}


void borrar(ListaOrdInt& l, int e) {
    if (elimABB(e, l->abb)) {
        l->cantElem--;
    }
}


void borrarMinimo(ListaOrdInt& l) {
    _nodoListaOrdInt* min = aux_Min(l->abb);
    if (min != NULL) {
        borrar(l, min->dato);
    }
}


void borrarMaximo(ListaOrdInt& l) {
    _nodoListaOrdInt* max = aux_Max(l->abb);
    if (max != NULL) {
        borrar(l, max->dato);
    }
}


int minimo(ListaOrdInt l) {
    assert(!esVacia(l));
    _nodoListaOrdInt* min = aux_Min(l->abb);
    return min->dato;
}


int maximo(ListaOrdInt l) {
    assert(!esVacia(l));
    _nodoListaOrdInt* max = aux_Max(l->abb);
    return max->dato;
}


bool existe(ListaOrdInt l, int e) {
    return aux_existe(e, l->abb);
}


bool esVacia(ListaOrdInt l) {
    return l->cantElem == 0;
}


unsigned int cantidadElementos(ListaOrdInt l) {
    return l->cantElem;
}


ListaOrdInt clon(ListaOrdInt l) {
    _cabezalListaOrdInt* nuevo = crearListaOrdInt();
    copia(l->abb, nuevo);
    return nuevo;
}


void destruir(ListaOrdInt& l) {
    while (!esVacia(l)) {
        borrarMinimo(l);
    }
    delete l;
    l = NULL;
}


#endif