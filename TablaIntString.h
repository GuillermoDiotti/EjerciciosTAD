#pragma once
// NOTA: Este archivo no debe ser modificado

#include "Implementaciones.h"

struct _cabezalTablaIntString;
typedef struct _cabezalTablaIntString* TablaIntString;

// PRE: -
// POS: retorna una nueva tabla vacia.
//		Al crear la tabla se recibe la cantidad esperada de elementos, 
//		aunque puedan insertarse más elementos.
TablaIntString crearTablaIntString(unsigned int esperados);

// PRE: -
// POS: Define T(d) = r si la tabla no esta definida en d.
//  	En caso contrario actualiza el valor T(d) con r.
void agregar(TablaIntString& t, int d, const char* r);

// PRE: -
// POS: Retorna true si y solo si la tabla esta definida en d.
bool estaDefinida(TablaIntString t, int d);

// PRE: estaDefinida(d)    
// POS: Retorna T(d)
const char* recuperar(TablaIntString t, int d);

// PRE: -
// POS: Borra la asociacion ligada a d, siempre que esta exista.
void borrar(TablaIntString& t, int d);

// PRE: !esVacia()
// POS: Retorna un dominio cualquiera de la tabla
int elemento(TablaIntString t);

// PRE: -
// POS: retorna true si y solo si la tabla esta vacia
bool esVacia(TablaIntString t);

// PRE: -
// POS: retorna la cantidad de elementos presentes en la tabla
unsigned int cantidadElementos(TablaIntString t);

// PRE: -
// POS: libera la memoria de la tabla
void destruir(TablaIntString& t);

// PRE: -
// POS: retorna una copia de la tabla t sin compartir memoria
TablaIntString clon(TablaIntString t);
