#pragma once
// NOTA: Este archivo no debe ser modificado

#include "Implementaciones.h"

struct _cabezalSetInt;
typedef struct _cabezalSetInt* SetInt;

// PRE: -
// POS: retorna una nuevo set vacio
SetInt crearSetInt();

// PRE: -
// POS: agrega el elemento e en el set
void agregar(SetInt& s, int e);

// PRE: -
// POS: borra el elemento del set
//   	 Si no encuentra no tiene efecto
void borrar(SetInt& s, int e);

// PRE: -
// POS: retorna true sii el elemento e se encuentra en el set
bool pertenece(SetInt s, int e);

// PRE: -
// POS: Retorna un nuevo Set que es la union de s1 y s2,
//   	 o sea, el conjunto que contiene los elementos de s1 y de s2
//   	 El conjunto retornado no debe compartir memoria con s1 ni s2.
SetInt unionConjuntos(SetInt s1, SetInt s2);

// PRE: -
// POS: Retorna un nuevo Set que es la intersección de s1 y s2,
//   	 o sea, el conjunto que contiene solo los elementos comunes a s1 y s2     
//   	 El conjunto retornado no debe compartir memoria con s1 ni s2.
SetInt interseccionConjuntos(SetInt s1, SetInt s2);

// PRE: -
// POS: Retorna un nuevo Set que es la diferencia entre s1 y s2,
//   	 o sea, el conjunto que contiene solo los elementos que estan en s1 pero no en s2 
//   	 El conjunto retornado no debe compartir memoria con s1 ni s2.
SetInt diferenciaConjuntos(SetInt s1, SetInt s2);

//PRE: -
//POS: Retorna true sii todos los elementos de s1 pertenecen a s2
bool contenidoEn(SetInt s1, SetInt s2);

// PRE: !esVacia()
// POS: Retorna un elemento cualquiera del set
int elemento(SetInt s);

// PRE: -
// POS: retorna true si y solo si el set esta vacio
bool esVacio(SetInt s);

// PRE: -
// POS: retorna la cantidad de elementos presentes en el set
unsigned int cantidadElementos(SetInt s);

// PRE: -
// POS: libera la memoria del set
void destruir(SetInt& s);

// PRE: -
// POS: retorna una copia del set s sin compartir memoria
SetInt clon(SetInt s);


