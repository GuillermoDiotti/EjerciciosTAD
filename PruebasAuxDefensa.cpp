#include "PruebasAuxDefensa.h"

/*
// MAT
void pruebaInterseccionLista(const char* inputList1, const char* inputList2)
{
	int largoLista1;
	int largoLista2;
	NodoListaS* lista1 = (NodoListaS*)FrameworkA1::parsearColeccion(inputList1, largoLista1);
	NodoListaS* lista2 = (NodoListaS*)FrameworkA1::parsearColeccion(inputList2, largoLista2);

	ListaPos<int> *l1 = FrameworkA1::ConvertirAListaPos(lista1);
	ListaPos<int> *l2 = FrameworkA1::ConvertirAListaPos(lista2);

	ListaPos<int> *res = InterseccionLista<int>(*l1, *l2);

	cout << *res << endl;

	FrameworkA1::destruir(lista1);
	FrameworkA1::destruir(lista2);
	delete l1;
	delete l2;
	delete res;
}

void pruebaExcluidos(const char* inputList1, const char* inputList2, const char* inputList3)
{
	int largoLista1;
	int largoLista2;
	int largoLista3;
	NodoListaS* lista1 = (NodoListaS*)FrameworkA1::parsearColeccion(inputList1, largoLista1);
	NodoListaS* lista2 = (NodoListaS*)FrameworkA1::parsearColeccion(inputList2, largoLista2);
	NodoListaS* lista3 = (NodoListaS*)FrameworkA1::parsearColeccion(inputList3, largoLista3);

	Diccionario<int> *d1 = FrameworkA1::ConvertirADiccionario(lista1);
	Diccionario<int> *d2 = FrameworkA1::ConvertirADiccionario(lista2);
	Diccionario<int> *d3 = FrameworkA1::ConvertirADiccionario(lista3);

	bool res = Excluidos<int>(*d1, *d2, *d3);

	if (res)
	{
		cout << "No tienen elementos en comun" << endl;
	}
	else
	{
		cout << "Tienen elementos en comun" << endl;
	}

	FrameworkA1::destruir(lista1);
	FrameworkA1::destruir(lista2);
	FrameworkA1::destruir(lista3);
	delete d1;
	delete d2;
	delete d3;
}


void pruebaListarHojas(const char* inputTree)
{
	int largo;
	NodoAB* arbol = (NodoAB*)FrameworkA1::parsearColeccion(inputTree, largo);

	ListaOrd<int> *res = ListarHojas(arbol);

	cout << *res << endl;

	FrameworkA1::destruir(arbol);
	delete res;
}




// NOC

void pruebaEstanContenidos(const char* inputList1, const char* inputList2)
{
	int largoLista1;
	int largoLista2;
	NodoListaS* lista1 = (NodoListaS*)FrameworkA1::parsearColeccion(inputList1, largoLista1);
	NodoListaS* lista2 = (NodoListaS*)FrameworkA1::parsearColeccion(inputList2, largoLista2);

	ListaPos<int> *l1 = FrameworkA1::ConvertirAListaPos(lista1);
	ListaPos<int> *l2 = FrameworkA1::ConvertirAListaPos(lista2);

	bool res = EstanContenidos<int>(*l1, *l2);

	if (res)
	{
		cout << "Estan contenidos los pares" << endl;
	}
	else
	{
		cout << "No estan contenidos los pares" << endl;
	}

	FrameworkA1::destruir(lista1);
	FrameworkA1::destruir(lista2);
	delete l1;
	delete l2;
}

void pruebaMerge(const char* inputCP1elem, const char* inputCP1prio, const char* inputCP2elem, const char* inputCP2prio)
{
	int largoLista;
	NodoListaS* cp1elem = (NodoListaS*)FrameworkA1::parsearColeccion(inputCP1elem, largoLista);
	NodoListaS* cp1prio = (NodoListaS*)FrameworkA1::parsearColeccion(inputCP1prio, largoLista);
	NodoListaS* cp2elem = (NodoListaS*)FrameworkA1::parsearColeccion(inputCP2elem, largoLista);
	NodoListaS* cp2prio = (NodoListaS*)FrameworkA1::parsearColeccion(inputCP2prio, largoLista);

	ColaPrioridad<int, int> *cp1 = FrameworkA1::ConvertirAColaPrioridad(cp1elem, cp1prio);
	ColaPrioridad<int, int> *cp2 = FrameworkA1::ConvertirAColaPrioridad(cp2elem, cp2prio);

	Merge<int, int>(*cp1, *cp2);

	cout << *cp1 << endl;

	FrameworkA1::destruir(cp1elem);
	FrameworkA1::destruir(cp1prio);
	FrameworkA1::destruir(cp2elem);
	FrameworkA1::destruir(cp2prio);
	delete cp1;
	delete cp2;
}

void pruebaListarHojasPorNiveles(const char* inputTree)
{
	int largo;
	NodoAB* arbol = (NodoAB*)FrameworkA1::parsearColeccion(inputTree, largo);

	ListaPos<int> *res = ListarHojasPorNiveles(arbol);

	cout << *res << endl;

	FrameworkA1::destruir(arbol);
	delete res;
}

*/