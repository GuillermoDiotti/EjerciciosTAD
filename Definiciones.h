#pragma once

// NOTA: Este archivo no debe ser modificado
// NOTA: Si quieren hacer sus propios struct los definen en el cpp del TAD correspondiente.

#include <iostream>
using namespace std;
#include <string.h>
#include <assert.h>

struct NodoListaInt {
	int dato;
	NodoListaInt *sig;
	NodoListaInt() : dato(0), sig(NULL) {}
	NodoListaInt(int d) : dato(d), sig(NULL) {}
};

struct NodoListaString {
	char* dato;
	NodoListaString* sig;
	NodoListaString() : dato(NULL), sig(NULL) {}
};

struct NodoABInt {
	int dato;
	NodoABInt *izq;
	NodoABInt *der;
	NodoABInt() : dato(0), izq(NULL), der(NULL) {}
	NodoABInt(int d) : dato(d), izq(NULL), der(NULL) {}
};

struct NodoAGInt {
	int dato;
	NodoAGInt *ph;
	NodoAGInt *sh;
	NodoAGInt() : dato(0), ph(NULL), sh(NULL) {}
	NodoAGInt(int d) : dato(d), ph(NULL), sh(NULL) {}
};

struct NodoListaIntDobleDato {
	int dato1;
	int dato2;
	NodoListaIntDobleDato *sig;
	NodoListaIntDobleDato() : dato1(0), dato2(0), sig(NULL) {}
	NodoListaIntDobleDato(int d1, int d2) : dato1(d1), dato2(d2), sig(NULL) {}
};

struct NodoABIntDobleDato {
	int dato1;
	int dato2;
	NodoABIntDobleDato *izq;
	NodoABIntDobleDato *der;
	NodoABIntDobleDato() : dato1(0), dato2(0), izq(NULL), der(NULL) {}
	NodoABIntDobleDato(int d1, int d2) : dato1(d1), dato2(d2), izq(NULL), der(NULL) {}
};