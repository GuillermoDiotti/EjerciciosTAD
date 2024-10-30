// Comentar la siguiente linea si es DLL
#define FRAMEWORKA1DLL_API  

// Descomentar las siguiente linea si es DLL
/*
#ifdef FRAMEWORKA1DLL_EXPORTS
#define FRAMEWORKA1DLL_API __declspec(dllexport) 
#else
#define FRAMEWORKA1DLL_API __declspec(dllimport) 
#endif
*/

#pragma once

#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cmath>
#include <algorithm> 
using namespace std;
#include "Definiciones.h"
#include "ColaArray.h"
#include "FuncAux_s.h"

namespace FrameworkA1
{

	// Funciones de impresion
	/*
	PRE: 
	POS: imprime resultado esp vs rec
	*/
	FRAMEWORKA1DLL_API void imprimirEsperadoVsRecibido(NodoListaInt *esp, NodoListaInt *rec);
	/*
	PRE:
	POS: imprime resultado esp vs rec y también los paramtros de entrada
	*/
	FRAMEWORKA1DLL_API void imprimirEsperadoVsRecibido(NodoListaInt *esp, NodoListaInt *rec, const char *inputParametersFormated);
	/*
	PRE: 
	POS: imprime resultado esp vs rec y también los paramtros de entrada
	*/
	FRAMEWORKA1DLL_API void imprimirEsperadoVsRecibido(NodoABInt *esp, NodoABInt *rec, const char *inputParametersFormated);
	/*
	PRE: 
	POS: imprime resultado esp vs rec y también los paramtros de entrada
	*/
	FRAMEWORKA1DLL_API void imprimirEsperadoVsRecibido(NodoAGInt *esp, NodoAGInt *rec, const char *inputParametersFormated);
	/*
	PRE: 
	POS: imprime resultado esp vs rec y también los paramtros de entrada
	*/
	FRAMEWORKA1DLL_API void imprimirEsperadoVsRecibido(bool esp, bool rec, const char *inputParametersFormated);
	/*
	PRE: 
	POS: imprime resultado esp vs rec y también los paramtros de entrada
	*/
	FRAMEWORKA1DLL_API void imprimirEsperadoVsRecibido(int esp, int rec, const char *inputParametersFormated);
	/*
	PRE: 
	POS: imprime resultado esp vs rec y también los paramtros de entrada
	*/
	FRAMEWORKA1DLL_API void imprimirEsperadoVsRecibido(const char *esp, const char *rec, const char *inputParametersFormated);
	/*
	PRE: 
	POS: si res es true, incrementa correctos en 1, sino incrementa error en 1
	*/
	FRAMEWORKA1DLL_API void ver(bool res, int &correctos, int &error);


	// Funciones de comparacion
	/*
	Pre: los vectores deben tener el largo largo
	Pos: Devuelve true si los string resultado y esperado son iguales
	*/
	FRAMEWORKA1DLL_API bool sonIguales(const char* resultado, const char* esperado);
	/*
	Pre: los vectores deben tener el largo largo
	Pos: Devuelve true si los vectores resultado y esperado son iguales
	*/
	FRAMEWORKA1DLL_API bool sonIguales(int* resultado, int* esperado, int largo);
	/*
	Pre: debe recibir dos matrices que deben tener las columnas y filas indicadas
	Pos: Devuelve true si las matrices de enteros resultado y esperado son iguales
	*/
	FRAMEWORKA1DLL_API bool sonIguales(int** resultado, int** esperado, int columnas, int filas);
	/*
	Pre: debe recibir dos matrices de char que deben tener las columnas y filas indicadas
	Pos: Devuelve true si las matrices de char resultado y esperado son iguales
	*/
	FRAMEWORKA1DLL_API bool sonIguales(char** resultado, char** esperado, int columnas, int filas);
	/*
	PRE: debe recibir dos vectores de strings de largo filas
	POS: devuelve true si las matrices resultado y esperado son iguales
	*/
	FRAMEWORKA1DLL_API bool sonIguales(char** resultado, char** esperado, int cantStr);
	/*
	PRE:
	POS: devuelve true si las listas tienen los mismos datos y misma forma
	*/
	FRAMEWORKA1DLL_API bool sonIgualesDatosForma(NodoListaInt *l1, NodoListaInt *l2);
	/*
	PRE:
	POS: devuelve true si los arboles tienen los mismos datos
	*/
	FRAMEWORKA1DLL_API bool sonIgualesDatos(NodoListaInt *l1, NodoListaInt *l2);
	/*
	PRE:
	POS: devuelve true si los arboles tienen los mismos datos y misma forma
	*/
	FRAMEWORKA1DLL_API bool sonIgualesDatosForma(NodoABInt *a1, NodoABInt *a2); 
	/*
	PRE:
	POS: devuelve true si los arboles tienen los mismos datos
	*/
	FRAMEWORKA1DLL_API bool sonIgualesDatos(NodoABInt *a1, NodoABInt *a2);
	/*
	PRE:
	POS: devuelve true si los arboles tienen los mismos datos y misma forma
	*/
	FRAMEWORKA1DLL_API bool sonIgualesDatosForma(NodoAGInt *a1, NodoAGInt *a2); 
	/*
	PRE:
	POS: devuelve true si los arboles tienen los mismos datos
	*/
	FRAMEWORKA1DLL_API bool sonIgualesDatos(NodoAGInt *a1, NodoAGInt *a2);
	/*
	PRE: debe recibir dos matrices de strings que deben tener los largos indicados
	POS: devuelve true si los strings en los vectores comparten memoria
	*/
	FRAMEWORKA1DLL_API bool compartenMemoria(char** vec1, int largoVec1, char** vec2, int largoVec2);
	/*
	PRE:
	POS: devuelve true si l1 y l2 comparten memoria
	*/
	FRAMEWORKA1DLL_API bool compartenMemoria(NodoListaInt *l1, NodoListaInt *l2);
	/*
	PRE: debe recibir 2 vectores de int y sus respectivos largos
	POS: devuelve true si vec1 y vec2 comparten memoria
	*/
	FRAMEWORKA1DLL_API bool compartenMemoria(int *vec1, int *vec2, int largoVec1, int largoVec2);
	/*
	PRE:
	POS: devuelve true si a1 y a2 comparten memoria
	*/
	FRAMEWORKA1DLL_API bool compartenMemoria(NodoABInt *a1, NodoABInt *a2);
	/*
	PRE:
	POS: devuelve true si a1 y a2 comparten memoria
	*/
	FRAMEWORKA1DLL_API bool compartenMemoria(NodoAGInt *a1, NodoAGInt *a2);

	/*
	PRE:
	POS: devuelve true si a es un ABB
	*/
	FRAMEWORKA1DLL_API bool esABB(NodoABInt *a);


	// Funciones de Destruccion
	/*
	PRE: debe recibir un vector de strings del largo indicado
	POS: destruye vector vec
	*/
	FRAMEWORKA1DLL_API void destruir(char** vec, int largo);
	/*
	PRE: debe recibir un vector de int 
	POS: destruye vector vec
	*/
	FRAMEWORKA1DLL_API void destruir(int* vec);
	/*
	PRE: debe recibir una matriz que debe tener las columnas indicadas
	POS: destruye matriz mat
	*/
	FRAMEWORKA1DLL_API void destruir(int** mat, int columnas);
	/*
	PRE:
	POS: destruye la lista l
	*/
	FRAMEWORKA1DLL_API void destruir(NodoListaInt*& l);
	/*
	PRE:
	POS: destruye la lista l
	*/
	FRAMEWORKA1DLL_API void destruir(NodoListaString*& l);
	/*
	PRE:
	POS: destruye arbol a
	*/
	FRAMEWORKA1DLL_API void destruir(NodoABInt *&a);
	/*
	PRE:
	POS: destruye arbol a
	*/
	FRAMEWORKA1DLL_API void destruir(NodoAGInt*& a);


	/*
	PRE:
	POS: agrega un elemento a la lista ordenado
	*/
	FRAMEWORKA1DLL_API void agregarOrd(NodoListaInt*& l, int val);

	/*
	PRE: 
	POS: devuleve copia de str sin compartir memoria. Se debe destruir con delete []
	*/
	FRAMEWORKA1DLL_API char *copioString(const char *str);
	/*
	PRE:
	POS: imprime el arbol por niveles
	*/
	FRAMEWORKA1DLL_API void imprimirABGrande(NodoABInt *a);

	/*
	PRE: los caracteres de stringDatos pueden ser colecciones con el siguiente formato:
		 arbol binario:  {...} Formato "{2,#,8,1,2}" Se carga por niveles
		 arbol general:  {{...}} Formato "{{2,8,#,1,2}}" Se van cargando los hijos primero. El # es NULL, vuelve al padre y sigue con hermano.
		 lista:  (...) Formato "(8,1,2)"
		 vector int:    [...] Formato "[8,1,2]"
		 vector string: [...] Formato "['str1','str2']"
	POS: convierte stringDatos a un arbol, lista, vector int o vector strings.
		 se debe castear al tipo (NodoABInt *), (NodoAGInt *), (NodoLista *), (int *), (char **)
	*/
	FRAMEWORKA1DLL_API void* parsearColeccion(const char *stringDatos, int &largo);

	/*
	PRE:
	POS: retorna un string a partir de un int. Formato "-12". Se debe liberar la memoria retornada con delete []
	*/
	FRAMEWORKA1DLL_API char *serializar(int);
	/*
	PRE:
	POS: retorna un string a partir de un bool. Formato "true". Se debe liberar la memoria retornada con delete []
	*/
	FRAMEWORKA1DLL_API char *serializar(bool);
	/*
	PRE:
	POS: retorna un string a partir de una lista. Formato "(8,1,2)". Se debe liberar la memoria retornada con delete []
	*/
	FRAMEWORKA1DLL_API char *serializar(NodoListaInt *l);
	/*
	PRE:
	POS: retorna un string a partir de un arbol. Formato "{2,#,8,1,2}". Se debe liberar la memoria retornada con delete []
	*/
	FRAMEWORKA1DLL_API char *serializar(NodoABInt *a);
	/*
	PRE:
	POS: retorna un string a partir de un arbol general. Formato "{{2,8,#,1,2}}". Se debe liberar la memoria retornada con delete []
	*/
	FRAMEWORKA1DLL_API char *serializar(NodoAGInt *a);
	/*
	PRE:
	POS: retorna un string a partir de vector de int. Se debe liberar la memoria retornada con delete []
	*/
	FRAMEWORKA1DLL_API char *serializar(int *vec, int largo);
	/*
	PRE:
	POS: retorna un string a partir de vector de strings. Se debe liberar la memoria retornada con delete []
	*/
	FRAMEWORKA1DLL_API char *serializar(char **vecStr, int largo);

};