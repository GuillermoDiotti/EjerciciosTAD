#pragma once

// Elegir la implementacion a usar de ListaOrd (solo 1 descomentada a la vez):
//#define LISTA_ORD_INT_IMP			// Esta es la implementacion que entregamos
#define LISTA_ORD_INT_IMP_2		// Esta es la implementacion que corresponde al ejericio


// No modificar de aca en adelante
#if defined(LISTA_ORD_INT_IMP)
#include "ListaOrdIntImp.h"
#elif defined(LISTA_ORD_INT_IMP_2)
#include "ListaOrdIntImp2.h"
#endif

#define COLA_INT_IMP
#if defined(COLA_INT_IMP)
#include "ColaIntImp.h"
#endif

#define COLAPRIORIDAD_INT_IMP
#if defined(COLAPRIORIDAD_INT_IMP)
#include "ColaPrioridadIntImp.h"
#endif

#define MULTISET_INT_IMP
#if defined(MULTISET_INT_IMP)
#include "MultisetIntImp.h"
#endif

#define SET_INT_IMP
#if defined(SET_INT_IMP)
#include "SetIntImp.h"
#endif

#define DICCIONARIO_INT_IMP
#if defined(DICCIONARIO_INT_IMP)
#include "DiccionarioIntImp.h"
#endif

#define LISTA_POS_INT_IMP
#if defined(LISTA_POS_INT_IMP)
#include "ListaPosIntImp.h"
#endif

#define PILA_INT_IMP
#if defined(PILA_INT_IMP)
#include "PilaIntImp.h"
#endif

#define TABLA_INT_INT_IMP
#if defined(TABLA_INT_INT_IMP)
#include "TablaIntIntImp.h"
#endif

#define TABLA_INT_STRING_IMP
#if defined(TABLA_INT_STRING_IMP)
#include "TablaIntStringImp.h"
#endif
