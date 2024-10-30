#pragma once
// NOTA: Este archivo no debe ser modificado

#include "Implementaciones.h"

struct _cabezalDiccionarioInt;
typedef struct _cabezalDiccionarioInt* DiccionarioInt;

// PRE: -
// POS: retorna una nuevo diccionario vacio
//		Al crear el diccionario se recibe la cantidad esperada de elementos, 
//		aunque puedan insertarse más elementos.
DiccionarioInt crearDiccionarioInt(unsigned int esperados);

// PRE: -
// POS: agrega el elemento e en el diccionario
void agregar(DiccionarioInt& d, int e);

// PRE: -
// POS: borra el elemento del diccionario
//        Si no encuentra no tiene efecto
void borrar(DiccionarioInt& d, int e);

// PRE: -
// POS: retorna true sii el elemento e se encuentra en el diccionario
bool pertenece(DiccionarioInt d, int e);

// PRE: !esVacia()
// POS: Retorna un elemento cualquiera del diccionario
int elemento(DiccionarioInt d);

// PRE: -
// POS: retorna true si y solo si el diccionario esta vacio
bool esVacio(DiccionarioInt d);

// PRE: -
// POS: retorna la cantidad de elementos presentes en el diccionario
unsigned int cantidadElementos(DiccionarioInt d);

// PRE: -
// POS: retorna una copia del diccionario d sin compartir memoria
DiccionarioInt clon(DiccionarioInt d);

// PRE: -
// POS: libera la memoria del diccionario
void destruir(DiccionarioInt& d);
