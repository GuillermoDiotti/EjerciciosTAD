#pragma once

#include "Definiciones.h"
#include "ListaOrdInt.h"
#include "PilaInt.h"
#include "MultisetInt.h"
#include "ColaPrioridadInt.h"

// Ver Ejercicios.txt para la documentación de estas funciones

ListaOrdInt Enlistar(NodoABInt* a);
ListaOrdInt UnionListaOrd(ListaOrdInt l1, ListaOrdInt l2);
bool EstaContenida(PilaInt p1, PilaInt p2);
ListaOrdInt ObtenerRepetidos(MultisetInt m);
MultisetInt Xor(MultisetInt m1, MultisetInt m2);
ColaPrioridadInt MenorPrioridad(ColaPrioridadInt c);

