#pragma once
// NOTA: Este archivo no debe ser modificado

#include "Implementaciones.h"

struct _cabezalListaPosInt;
typedef struct _cabezalListaPosInt* ListaPosInt;

// PRE: -
// POS: retorna una nueva lista vacia
ListaPosInt crearListaPosInt();

// PRE: -
// POS: Agrega el elemento e en la posicion pos de la lista haciendo que los elementos 
//    	 en esa y siguientes posiciones avancen una posicion.
//   	 El primer elemento se encuentra en la posicion 0.
//   	 Si pos es mayor o igual al largo de la lista insertar al final
void agregar(ListaPosInt& l, int e, unsigned int pos);

// PRE: -
// POS: Borra el elemento en la posicion pos de la lista haciendo que los elementos 
//    	 en las siguientes posiciones retrocedan una posicion.
//   	 El primer elemento se encuentra en la posicion 0.
//   	 Si pos es mayor o igual al largo de la lista la operacion no tiene efecto
void borrar(ListaPosInt& l, unsigned int pos);

// PRE: 0 <= pos < CantidadElementos()
// POS: Retorna el elemento en la posicion pos
//   	 El primer elemento se encuentra en la posicion 0.
int elemento(ListaPosInt l, unsigned int pos);

// PRE: -
// POS: retorna true si la lista esta vacia
bool esVacia(ListaPosInt l);

// PRE: -
// POS: retorna la cantidad de elementos presentes en la lista
unsigned int cantidadElementos(ListaPosInt l);

// PRE: -
// POS: retorna una copia de la lista l sin compartir memoria
ListaPosInt clon(ListaPosInt l);

// PRE: -
// POS: libera la memoria de la lista
void destruir(ListaPosInt& l);



