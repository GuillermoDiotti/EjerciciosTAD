#include "DiccionarioInt.h"

#ifdef DICCIONARIO_INT_IMP

struct _nodoHash {
    _nodoHash* sig;
    int dato;
};


struct _cabezalDiccionarioInt {
    _nodoHash** tabla;
    int cota;
    int cantidad;
};


typedef _cabezalDiccionarioInt* DiccionarioInt;

//AUXILIARES

//PRE: esperados > 0
//POS: retorna el una posicion entre 0 y esperados-1
int hashDiccionario(int i, int esperados) {
    return (abs(i)) % esperados;
}


//PRE: -
//POS: elimina el elemento e del dicionario en el caso que se encuentre
void borrarLista(_nodoHash*& l, int e) {
    if (l != NULL) {
        if (l->dato == e) {
            _nodoHash* aBorrar = l;
            l = l->sig;
            delete aBorrar;
        }
        else {
            borrarLista(l->sig, e);
        }
    }
}


//PRE: -
//POS: elimina todos los elementos en una posicion del diccionario
void destruirLista(_nodoHash*& l) {
    if (l != NULL) {
        destruirLista(l->sig);
        delete l;
    }
}

//FIN AUXILIARES


DiccionarioInt crearDiccionarioInt(unsigned int esperados) {
    _cabezalDiccionarioInt* res = new _cabezalDiccionarioInt;
    res->cota = esperados;
    res->cantidad = 0;
    res->tabla = new _nodoHash * [esperados];
    for (int i = 0; i < esperados; i++) res->tabla[i] = NULL;
    return res;
}


void agregar(DiccionarioInt& d, int e) {
    if (!pertenece(d, e)) {
        int posicion = hashDiccionario(e, d->cota);
        _nodoHash* nuevo = new _nodoHash;
        nuevo->dato = e;
        nuevo->sig = d->tabla[posicion];
        d->tabla[posicion] = nuevo;
        d->cantidad++;
    }
}


void borrar(DiccionarioInt& d, int e) {
    if (pertenece(d, e)) {
        int posicion = hashDiccionario(e, d->cota);
        borrarLista(d->tabla[posicion], e);
        d->cantidad--;
    }
}


bool pertenece(DiccionarioInt d, int e) {
    int posicion = hashDiccionario(e, d->cota);
    _nodoHash* lista = d->tabla[posicion];
    while (lista != NULL && lista->dato != e) {
        lista = lista->sig;
    }
    return lista != NULL;
}


int elemento(DiccionarioInt d) {
    assert(!esVacio(d));
    for (int i = 0; i < d->cota; i++) {
        _nodoHash* aux = d->tabla[i];
        if (aux != NULL) return aux->dato;
    }
    return 0;
}


bool esVacio(DiccionarioInt d) {
    return d->cantidad == 0;
}


unsigned int cantidadElementos(DiccionarioInt d) {
    return d->cantidad;
}


DiccionarioInt clon(DiccionarioInt d) {
    _cabezalDiccionarioInt* res = crearDiccionarioInt(d->cota);
    for (int i = 0; i < d->cota; i++) {
        _nodoHash* aux = d->tabla[i];
        while (aux != NULL) {
            agregar(res, aux->dato);
            aux = aux->sig;
        }
    }
    return res;
}


void destruir(DiccionarioInt& d) {
    for (int i = 0; i < d->cota; i++) {
        destruirLista(d->tabla[i]);
    }
    delete[] d->tabla;
    delete d;
    d = NULL;
}


#endif