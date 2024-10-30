#include "TablaIntString.h"

#ifdef TABLA_INT_STRING_IMP

struct _nodoTablaIntString {
    int d;
    const char* r;
    _nodoTablaIntString* sig;
};


struct _cabezalTablaIntString {
    _nodoTablaIntString** tabla;
    int cota;
    int cantidad;
};

typedef _cabezalTablaIntString* TablaIntString;

//AUXILIARES

//PRE: esperados > 0
//POS: retorna el valor del resto de la division entera del valor absoluto de un numero, y esperados
int hashTabla(int d, int esperados) {
    return (abs(d)) % esperados;
}

//PRE: -
//POS: Borra la asociacion ligada a d, siempre que esta exista.
void borrarLista(_nodoTablaIntString*& l, int d) {
    if (l != NULL) {
        if (l->d == d) {
            _nodoTablaIntString* aBorrar = l;
            l = l->sig;
            delete aBorrar;
        }
        else {
            borrarLista(l->sig, d);
        }
    }
}

//PRE: -
//POS: elimina todos los elementos en una lista
void destruirLista(_nodoTablaIntString*& l) {
    if (l != NULL) {
        destruirLista(l->sig);
        delete l;
    }
}

//FIN AUXILIARES


TablaIntString crearTablaIntString(unsigned int esperados) {
    _cabezalTablaIntString* res = new _cabezalTablaIntString;
    res->cota = esperados;
    res->cantidad = 0;
    res->tabla = new _nodoTablaIntString * [esperados];
    for (int i = 0; i < esperados; i++) res->tabla[i] = NULL;
    return res;
}



void agregar(TablaIntString& t, int d, const char* r) {
    if (!estaDefinida(t, d)) {
        int posicion = hashTabla(d, t->cota);
        _nodoTablaIntString* nuevo = new _nodoTablaIntString;
        nuevo->d = d;
        nuevo->r = r;
        nuevo->sig = t->tabla[posicion];
        t->tabla[posicion] = nuevo;
        t->cantidad++;
    }
    else {
        int posicion = hashTabla(d, t->cota);
        _nodoTablaIntString* lista = t->tabla[posicion];
        while (lista != NULL && lista->d != d) {
            lista = lista->sig;
        }
        lista->r = r;
    }
}


bool estaDefinida(TablaIntString t, int d) {
    int posicion = hashTabla(d, t->cota);
    _nodoTablaIntString* lista = t->tabla[posicion];
    while (lista != NULL && lista->d != d) {
        lista = lista->sig;
    }
    return lista != NULL;
}


const char* recuperar(TablaIntString t, int d) {
    int posicion = hashTabla(d, t->cota);
    _nodoTablaIntString* lista = t->tabla[posicion];
    while (lista != NULL && lista->d != d) {
        lista = lista->sig;
    }
    return lista->r;
}


void borrar(TablaIntString& t, int d) {
    if (estaDefinida(t, d)) {
        int posicion = hashTabla(d, t->cota);
        borrarLista(t->tabla[posicion], d);
        t->cantidad--;
    }
}


int elemento(TablaIntString t) {
    for (int i = 0; i < t->cota; i++) {
        _nodoTablaIntString* aux = t->tabla[i];
        if (aux != NULL) {
            return aux->d;
        }
    }
    return 0;
}


bool esVacia(TablaIntString t) {
    return t->cantidad == 0;
}


unsigned int cantidadElementos(TablaIntString t) {
    return t->cantidad;
}


void destruir(TablaIntString& t) {
    for (int i = 0; i < t->cota; i++) {
        destruirLista(t->tabla[i]);
    }
    delete[] t->tabla;
    delete t;
    t = NULL;
}


TablaIntString clon(TablaIntString t) {
    TablaIntString res = crearTablaIntString(t->cota);
    for (int i = 0; i < t->cota; i++) {
        _nodoTablaIntString* aux = t->tabla[i];
        while (aux != NULL) {
            agregar(res, aux->d, aux->r);
            aux = aux->sig;
        }
    }
    return res;
}


#endif