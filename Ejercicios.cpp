#include "Ejercicios.h"

//PRE: -
//POS: Agrega a una ListaOrdInt los mismos elementos presentes en el arbol.
void aux_Enlistar(ListaOrdInt& l, NodoABInt* a) {
    if (a != NULL) {
        agregar(l, a->dato);
        aux_Enlistar(l, a->izq);
        aux_Enlistar(l, a->der);
    }
}


//PRE: -
//POS: Retorna una ListaOrdInt con los mismos elementos presentes en el arbol.
ListaOrdInt Enlistar(NodoABInt* a)
{
    ListaOrdInt res = crearListaOrdInt();
    aux_Enlistar(res, a);
    return res;
}




//PRE: -
//POS: Se inserta ordenadamente a una lista los elementos de otra lista
void aux_UnionListaOrd(ListaOrdInt l, ListaOrdInt& res) {
    if (!esVacia(l)) {
        agregar(res, minimo(l));
        borrarMinimo(l);
        aux_UnionListaOrd(l, res);
    }
}



//PRE: -
//POS: Se retorna una lista sin compartir memoria, que contiene todos los elementos de l1 y l2
ListaOrdInt UnionListaOrd(ListaOrdInt l1, ListaOrdInt l2)
{
    ListaOrdInt res = crearListaOrdInt();
    ListaOrdInt clonel1 = clon(l1);
    ListaOrdInt clonel2 = clon(l2);
    aux_UnionListaOrd(clonel1, res);
    aux_UnionListaOrd(clonel2, res);
    destruir(clonel1);
    destruir(clonel2);
    return res;
}


//PRE: -
//POS: Retorna true si y solo si todos los elementos de p1 se encuentran en p2
bool EstaContenida(PilaInt p1, PilaInt p2)
{
    PilaInt copiaP1 = clon(p1);
    PilaInt copiaP2 = clon(p2);

    while (!esVacia(copiaP1)) {
        bool encontrado = false;
        PilaInt aux = crearPilaInt();
        while (!esVacia(copiaP2)) {
            if (!encontrado && top(copiaP1) == top(copiaP2)) {
                encontrado = true;
                pop(copiaP2);
            }
            else {
                push(aux, top(copiaP2));
                pop(copiaP2);
            }
        }
        if (!encontrado) {
            destruir(copiaP1);
            destruir(copiaP2);
            destruir(aux);
            return false;
        }
        copiaP2 = clon(aux);
        pop(copiaP1);
        destruir(aux);
    }
    destruir(copiaP1);
    destruir(copiaP2);
    return true;
}


ListaOrdInt ObtenerRepetidos(MultisetInt m) 
{
	ListaOrdInt lista = crearListaOrdInt();
	MultisetInt aux = clon(m);
	while (!esVacio(aux)) {
		int dato = elemento(aux);
		borrar(aux, dato);
		if (pertenece(aux, dato) && !existe(lista, dato)) {
			agregar(lista, dato);
		}
	}
	destruir(aux);
	return lista;
}


MultisetInt Xor(MultisetInt m1, MultisetInt m2)
{
    MultisetInt u = unionConjuntos(m1, m2);
    MultisetInt i = interseccionConjuntos(m1, m2);
    MultisetInt res = diferenciaConjuntos(u, i);
    destruir(u);
    destruir(i);
	return res;
}

ColaPrioridadInt MenorPrioridad(ColaPrioridadInt c) {
    if (esVacia(c)) {
        return crearColaPrioridadInt(cantidadElementos(c));
    }
    else {
         ColaPrioridadInt aux1 = clon(c);
         ColaPrioridadInt aux2 = clon(c);
         int menorP = principioPrioridad(c);
         int cuantos = 1;
         int a;
         desencolar(aux1);
         while (!esVacia(aux1)) {
             a = principioPrioridad(aux1);
             if (a < menorP) {
                 menorP = a;
                 cuantos = 1;
             }
             else {
                cuantos++;
             }
             desencolar(aux1);
         }
         int d;
         int p;
         ColaPrioridadInt nuevo = crearColaPrioridadInt(cuantos);
         while (!esVacia(aux2) && (cantidadElementos(nuevo) < cuantos)) {
             p = principioPrioridad(aux2);
             d = principio(aux2);
             if (p == menorP) {
                 encolar(nuevo, d, p);
             }
             desencolar(aux2);
         }
         destruir(aux1);
         destruir(aux2);
	     return nuevo;
    }
}

