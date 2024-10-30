#pragma once
// NOTA: Este archivo no debe ser modificado

#include "Implementaciones.h"

struct _cabezalMultisetInt;
typedef struct _cabezalMultisetInt* MultisetInt;

// PRE: -
// POS: retorna una nuevo multiset vacio
MultisetInt crearMultisetInt();

// PRE: -
// POS: agrega las ocurrencias del elemento e en el multiset 
void agregar(MultisetInt& m, int e, unsigned int ocurrencias);

// PRE: -
// POS: borra una ocurrencia del elemento e del multiset 
//   	 Si no pertenece no tiene efecto
void borrar(MultisetInt& m, int e);

// PRE: -
// POS: retorna true sii el elemento e se encuentra en el multiset
bool pertenece(MultisetInt m, int e);

// PRE: -
// POS: Retorna un nuevo multiset que es la union de m1 y m2,
//   	 o sea, el conjunto que contiene los elementos de m1 y de m2
//   	 El conjunto retornado no debe compartir memoria con m1 ni m2.
MultisetInt unionConjuntos(MultisetInt m1, MultisetInt m2);

// PRE: -
// POS: Retorna un nuevo multiset que es la intersección de m1 y m2,
//   	 o sea, el conjunto que contiene solo los elementos comunes a m1 y m2     
//   	 El conjunto retornado no debe compartir memoria con m1 ni m2.
MultisetInt interseccionConjuntos(MultisetInt m1, MultisetInt m2);

// PRE: -
// POS: Retorna un nuevo multiset que es la diferencia entre m1 y m2,
//   	 o sea, el conjunto que contiene solo los elementos que estan en m1 pero no en m2.
//   	 El conjunto retornado no debe compartir memoria con m1 ni m2.
MultisetInt diferenciaConjuntos(MultisetInt m1, MultisetInt m2);

//PRE: -
//POS: Retorna true sii todos los elementos de m1 pertenecen a m2
bool contenidoEn(MultisetInt m1, MultisetInt m2);

// PRE: !esVacia()
// POS: Retorna un elemento cualquiera del multiset
int elemento(MultisetInt m);

// PRE: -
// POS: retorna true si y solo si el multiset esta vacio
bool esVacio(MultisetInt m);

// PRE: -
// POS: retorna la cantidad de elementos presentes en el multiset
unsigned int cantidadElementos(MultisetInt m);

// PRE: -
// POS: libera la memoria del multiset
void destruir(MultisetInt& m);

// PRE: -
// POS: retorna una copia del multiset m sin compartir memoria
MultisetInt clon(MultisetInt m);
