#pragma once
// NOTA: Este archivo no debe ser modificado

#include "Implementaciones.h"

struct _cabezalTablaIntInt;
typedef struct _cabezalTablaIntInt* TablaIntInt;

// PRE: -
// POS: retorna una nueva tabla vacia. 
//		Al crear la tabla se recibe la cantidad esperada de elementos, 
//		aunque puedan insertarse más elementos.
TablaIntInt crearTablaIntInt(unsigned int esperados);

// PRE: -
// POS: Define T(d) = r si la tabla no esta definida en d.
//  	En caso contrario actualiza el valor T(d) con r.
void agregar(TablaIntInt& t, int d, int r);

// PRE: -
// POS: Retorna true si y solo si la tabla esta definida en d.
bool estaDefinida(TablaIntInt t, int d);

// PRE: estaDefinida(d)    
// POS: Retorna T(d)
int recuperar(TablaIntInt t, int d);

// PRE: -
// POS: Borra la asociacion ligada a d, siempre que esta exista.
void borrar(TablaIntInt& t, int d);

// PRE: !esVacia()
// POS: Retorna un dominio cualquiera de la tabla
int elemento(TablaIntInt t);

// PRE: -
// POS: retorna true si y solo si la tabla esta vacia
bool esVacia(TablaIntInt t);

// PRE: -
// POS: retorna la cantidad de elementos presentes en la tabla
unsigned int cantidadElementos(TablaIntInt t);

// PRE: -
// POS: libera la memoria de la tabla
void destruir(TablaIntInt& t);

// PRE: -
// POS: retorna una copia de la tabla t sin compartir memoria
TablaIntInt clon(TablaIntInt t);
