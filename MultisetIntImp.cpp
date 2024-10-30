#include "MultisetInt.h"

#ifdef MULTISET_INT_IMP

struct _nodoMultisetInt {
    int dato;
    _nodoMultisetInt* izq;
    _nodoMultisetInt* der;
    int ocurrencias;
};


struct _cabezalMultisetInt {
    _nodoMultisetInt* abb;
    int cantElem;
};

typedef _cabezalMultisetInt* MultisetInt;


//AUXILIARES


//PRE: -
//POS: inserta n ocurrencias de el elemento dato en el arbol a
void insABB(int dato, _nodoMultisetInt*& a, int ocurrencias) {
    if (ocurrencias > 0) {
        if (a == NULL) {
            _nodoMultisetInt* nuevo = new _nodoMultisetInt;
            nuevo->dato = dato;
            nuevo->izq = NULL;
            nuevo->der = NULL;
            nuevo->ocurrencias = ocurrencias;
            a = nuevo;
        }
        else if (dato < a->dato) {
            insABB(dato, a->izq, ocurrencias);
        }
        else if (dato > a->dato) {
            insABB(dato, a->der, ocurrencias);
        }
        else {
            a->ocurrencias += ocurrencias;
        }
    }
}


//PRE -
//POS: retorna un puntero al valor minimo de a
_nodoMultisetInt* aux_Min(_nodoMultisetInt* a) {
    if (a == NULL) return NULL;
    while (a->izq != NULL) {
        a = a->izq;
    }
    return a;
}


//PRE: -
//POS: retorna true si y solo si existe el elemento e en el arbol a
bool aux_existe(int e, _nodoMultisetInt* a) {
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
void elimABB(int e, _nodoMultisetInt*& a) {
    if (a != NULL) {
        if (e < a->dato) {
            elimABB(e, a->izq);
        }
        else if (e > a->dato) {
            elimABB(e, a->der);
        }
        else {
            a->ocurrencias--;
            if (a->ocurrencias < 1) {
                _nodoMultisetInt* elim = a;
                if (a->der != NULL) {
                    _nodoMultisetInt* aux = aux_Min(a->der);
                    aux->izq = a->izq;
                    a = a->der;
                    delete elim;
                }
                else {
                    _nodoMultisetInt* res = a->izq;
                    delete elim;
                    a = res;
                }
            }
        }
    }
}


//PRE: -
//POS: inserta todos los elementos de un árbol en otro árbol
void copia(_nodoMultisetInt* a, MultisetInt& nuevo) {
    if (a == NULL) {
        return;
    }
    for (int i = 1; i <= a->ocurrencias; i++) {
        agregar(nuevo, a->dato, 1);
    }
    copia(a->izq, nuevo);
    copia(a->der, nuevo);
}


//PRE: -
//POS: retorna la cantidad de ocurrencias del elemento e
int ocurrencias(_nodoMultisetInt* a, int e) {
    if (a == NULL) {
        return 0;
    }
    else if (a->dato == e) {
        return a->ocurrencias;
    }
    else if (a->dato < e) {
        return ocurrencias(a->der, e);
    }
    else {
        return ocurrencias(a->izq, e);
    }
}


//PRE: -
//POS: retorna true si a1 está contenido en a2
bool aux_contenido(_nodoMultisetInt* a1, _nodoMultisetInt* a2) {
    if (a1 == NULL) {
        return true;
    }
    else if (aux_existe(a1->dato, a2) && (ocurrencias(a1, a1->dato) <= ocurrencias(a2, a1->dato))) {
        return aux_contenido(a1->der, a2) && aux_contenido(a1->izq, a2);
    }
    else {
        return false;
    }
}

//FIN AUXILIAR



MultisetInt crearMultisetInt() {
    MultisetInt nuevo = new _cabezalMultisetInt;
    nuevo->abb = NULL;
    nuevo->cantElem = 0;
    return nuevo;
}


void agregar(MultisetInt& s, int e, unsigned int ocurrencias) {
    insABB(e, s->abb, ocurrencias);
    if(ocurrencias > 0){
        s->cantElem+= ocurrencias;
    }
}


void borrar(MultisetInt& s, int e) {
    if (pertenece(s, e)) {
        elimABB(e, s->abb);
        s->cantElem--;
    }
}


bool pertenece(MultisetInt s, int e) {
    return aux_existe(e, s->abb);
}


MultisetInt unionConjuntos(MultisetInt s1, MultisetInt s2) {
    MultisetInt res = crearMultisetInt();
    MultisetInt c1 = clon(s1);
    MultisetInt c2 = clon(s2);

    while (!esVacio(c1)) {
        int dato = elemento(c1);
        int veces = max(ocurrencias(c1 -> abb, dato), ocurrencias(c2 -> abb, dato));
        agregar(res, dato, veces);
        while(pertenece(c1, dato)){
            borrar(c1, dato);
        }
        while(pertenece(c2, dato)){
            borrar(c2, dato);
        }
    }

    while (!esVacio(c2)) {
        int dato = elemento(c2);
        agregar(res, dato, ocurrencias(c2 -> abb, dato));
        while(pertenece(c2, dato)){
            borrar(c2, dato);
        }
    }
    destruir(c1);
    destruir(c2);
    return res;
}


MultisetInt interseccionConjuntos(MultisetInt s1, MultisetInt s2) {
    MultisetInt res = crearMultisetInt();
    MultisetInt c1 = clon(s1);

    while (!esVacio(c1)) {
        int dato = elemento(c1);
        int veces = min(ocurrencias(c1 -> abb, dato), ocurrencias(s2 -> abb, dato));
        agregar(res, dato, veces);
        while(pertenece(c1, dato)){
            borrar(c1, dato);
        }
    }

    destruir(c1);
    return res;
}


MultisetInt diferenciaConjuntos(MultisetInt s1, MultisetInt s2) {
    MultisetInt res = crearMultisetInt();
    MultisetInt c1 = clon(s1);
    MultisetInt c2 = clon(s2);

    while (!esVacio(c1)) {
        int dato = elemento(c1);
        int o1 = ocurrencias(c1 -> abb, dato);
        int o2 = ocurrencias(c2 -> abb, dato);
        if(o1-o2 > 0){
            agregar(res, dato, o1-o2);
        }
        while(pertenece(c1, dato)){
            borrar(c1, dato);
        }
    }
    destruir(c1);
    return res;
}


bool contenidoEn(MultisetInt s1, MultisetInt s2) {
    return aux_contenido(s1 -> abb, s2 -> abb);
}


int elemento(MultisetInt s) {
    assert(!esVacio(s));
    return s -> abb -> dato;
}


bool esVacio(MultisetInt s) {
    return s -> cantElem == 0;
}


unsigned int cantidadElementos(MultisetInt s) {
    return s -> cantElem;
}


void destruir(MultisetInt& s) {
    while (!esVacio(s)) {
        borrar(s, s -> abb -> dato);
    }
    delete s;
    s = NULL;
}


MultisetInt clon(MultisetInt s) {
    MultisetInt nuevo = crearMultisetInt();
    copia(s->abb, nuevo);
    return nuevo;
}

#endif