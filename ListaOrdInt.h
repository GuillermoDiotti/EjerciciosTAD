#pragma once
// NOTA: Este archivo no debe ser modificado

#include "Implementaciones.h"

struct _cabezalListaOrdInt;
typedef struct _cabezalListaOrdInt* ListaOrdInt;

// PRE: -
// POS: retorna una nueva lista vacia
ListaOrdInt crearListaOrdInt();

// PRE: -
// POS: agrega el elemento e en la lista ordenada de menor a mayor
void agregar(ListaOrdInt& l, int e);

// PRE: -
// POS: borra una ocurrencia del menor elemento de la lista. Si no hay elementos no tiene efecto
void borrarMinimo(ListaOrdInt& l);

// PRE: -
// POS: borra una ocurrencia del mayor elemento de la lista. Si no hay elementos no tiene efecto
void borrarMaximo(ListaOrdInt& l);

// PRE: -
// POS: borra una ocurrencia del primer elemento que sea igual a e
//        Si no encuentra no tiene efecto
void borrar(ListaOrdInt& l, int e);

// PRE: !esVacia()
// POS: retorna el menor elemento
int minimo(ListaOrdInt l);

// PRE: !esVacia()
// POS: retorna el mayor elemento     
int maximo(ListaOrdInt l);

// PRE: -
// POS: retorna true sii existe al menos un elemento que sea igual a e
bool existe(ListaOrdInt l, int e);

// PRE: -
// POS: retorna true si la lista esta vacia
bool esVacia(ListaOrdInt l);

// PRE: -
// POS: retorna la cantidad de elementos presentes en la lista
unsigned int cantidadElementos(ListaOrdInt l);

// PRE: -
// POS: retorna una copia de la lista l sin compartir memoria
ListaOrdInt clon(ListaOrdInt l);

// PRE: -
// POS: libera la memoria de la lista
void destruir(ListaOrdInt& l);


