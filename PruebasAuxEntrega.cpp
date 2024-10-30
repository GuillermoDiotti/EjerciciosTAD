#include "PruebasAuxEntrega.h"

void pruebaEnlistar(const char* inputTree)
{
	cout << "Llamada: " << "Enlistar" << "(" << inputTree << ")" << endl;
	int largo;
	NodoABInt* arbol = (NodoABInt*)FrameworkA1::parsearColeccion(inputTree, largo);

	assert(FrameworkA1::esABB(arbol));

	ListaOrdInt res = Enlistar(arbol);

	if (res != NULL) {
		if (esVacia(res)) {
			cout << "No hay elementos" << endl;
		}
		else {
			while (!esVacia(res))
			{
				int e = minimo(res);
				cout << e;
				borrarMinimo(res);
				if (!esVacia(res)) cout << " ";
			}
			cout << endl;
		}
		destruir(res);
	}
	else {
		cout << "NULL" << endl;
	}

	FrameworkA1::destruir(arbol);
}

void pruebaUnionListaOrd(const char* inputList1, const char* inputList2)
{
	cout << "Llamada: " << "UnionListaOrd" << "(" << inputList1 << ", " << inputList2 << ")" << endl;
	int largoLista1;
	int largoLista2;
	NodoListaInt* lista1 = (NodoListaInt*)FrameworkA1::parsearColeccion(inputList1, largoLista1);
	NodoListaInt* lista2 = (NodoListaInt*)FrameworkA1::parsearColeccion(inputList2, largoLista2);

	ListaOrdInt l1 = FrameworkA1::ConvertirAListaOrd(lista1);
	ListaOrdInt l2 = FrameworkA1::ConvertirAListaOrd(lista2);

	ListaOrdInt res = UnionListaOrd(l1, l2);

	if (res != NULL) {
		if (esVacia(res)) {
			cout << "No hay elementos" << endl;
		}
		else {
			while (!esVacia(res)) {
				int e = minimo(res);
				cout << e;
				borrarMinimo(res);
				if (!esVacia(res)) cout << " ";
			}
			cout << endl;
		}
		destruir(res);
	}
	else {
		cout << "NULL" << endl;
	}

	FrameworkA1::destruir(lista1);
	FrameworkA1::destruir(lista2);

	destruir(l1);
	destruir(l2);
}

void pruebaEstaContenida(const char* inputList1, const char* inputList2)
{
	cout << "Llamada: " << "EstaContenida" << "(" << inputList1 << ", " << inputList2 << ")" << endl;
	int largoLista1;
	int largoLista2;
	NodoListaInt* lista1 = (NodoListaInt*)FrameworkA1::parsearColeccion(inputList1, largoLista1);
	NodoListaInt* lista2 = (NodoListaInt*)FrameworkA1::parsearColeccion(inputList2, largoLista2);

	PilaInt p1 = FrameworkA1::ConvertirAPila(lista1);
	PilaInt p2 = FrameworkA1::ConvertirAPila(lista2);

	bool res = EstaContenida(p1, p2);

	if (res)
	{
		cout << "Esta contenida" << endl;
	}
	else
	{
		cout << "No esta contenida" << endl;
	}

	FrameworkA1::destruir(lista1);
	FrameworkA1::destruir(lista2);

	destruir(p1);
	destruir(p2);
}

void pruebaObtenerRepetidos(const char* lista)
{
	cout << "Llamada: " << "ObtenerRepetidos" << "(" << lista << ")" << endl;
	int largo;
	NodoListaInt* listaParseada = (NodoListaInt*)FrameworkA1::parsearColeccion(lista, largo);

	MultisetInt m = FrameworkA1::ConvertirAMultiSet(listaParseada);

	ListaOrdInt l = ObtenerRepetidos(m);

	if (l != NULL) {
		if (esVacia(l)) {
			cout << "No hay elementos" << endl;
		}
		else {
			while (!esVacia(l))
			{
				int e = minimo(l);
				cout << e;
				borrarMinimo(l);
				if (!esVacia(l)) cout << " ";
			}
			cout << endl;
		}
		destruir(l);
	}
	else {
		cout << "NULL" << endl;
	}

	FrameworkA1::destruir(listaParseada);
	destruir(m);
}

void pruebaXor(const char* inputMultiSet1, const char* inputMultiSet2)
{
	cout << "Llamada: " << "Xor" << "(" << inputMultiSet1 << ", " << inputMultiSet2 << ")" << endl;
	int largoLista1;
	int largoLista2;
	NodoListaInt* lista1 = (NodoListaInt*)FrameworkA1::parsearColeccion(inputMultiSet1, largoLista1);
	NodoListaInt* lista2 = (NodoListaInt*)FrameworkA1::parsearColeccion(inputMultiSet2, largoLista2);

	MultisetInt m1 = FrameworkA1::ConvertirAMultiSet(lista1);
	MultisetInt m2 = FrameworkA1::ConvertirAMultiSet(lista2);

	MultisetInt res = Xor(m1, m2);

	if (res != NULL) {
		if (esVacio(res)) {
			cout << "No hay elementos" << endl;
		}
		else {
			NodoListaInt* lord = NULL;
			while (!esVacio(res))
			{
				int e = elemento(res);
				FrameworkA1::agregarOrd(lord, e);
				borrar(res, e);
			}
			char* salida = FrameworkA1::serializar(lord);
			cout << salida << endl;
			delete[]salida;
			FrameworkA1::destruir(lord);
		}
		destruir(res);
	}
	else {
		cout << "NULL" << endl;
	}

	FrameworkA1::destruir(lista1);
	FrameworkA1::destruir(lista2);
	destruir(m1);
	destruir(m2);
}

void pruebaMenorPrioridad(const char* inputCpElem, const char* inputCpPrio)
{
	int largoLista;
	NodoListaInt* cp1elem = (NodoListaInt*)FrameworkA1::parsearColeccion(inputCpElem, largoLista);
	NodoListaInt* cp1prio = (NodoListaInt*)FrameworkA1::parsearColeccion(inputCpPrio, largoLista);

	cout << "Llamada: " << "MenorPrioridad" << "((";
	NodoListaInt* ptre = cp1elem;
	NodoListaInt* ptrp = cp1prio;
	while (ptre != NULL)
	{
		cout << ptre->dato << ":" << ptrp->dato;
		ptre = ptre->sig;
		ptrp = ptrp->sig;
		if (ptre != NULL) cout << ",";
	}
	cout << "))" << endl;

	ColaPrioridadInt cp1 = FrameworkA1::ConvertirAColaPrioridad(cp1elem, cp1prio);

	ColaPrioridadInt res = MenorPrioridad(cp1);

	if (res != NULL) {
		cout << "La cola de prioridad esta llena? " << (esLlena(res) ? "SI" : "NO") << endl;
		if (esVacia(res)) {
			cout << "No hay elementos" << endl;
		}
		else {
			while (!esVacia(res))
			{
				int e = principio(res);
				int p = principioPrioridad(res);
				cout << e << ":" << p;
				desencolar(res);
				if (!esVacia(res)) cout << " ";
			}
			cout << endl;
			cout << "La cola de prioridad esta llena? " << (esLlena(res) ? "SI" : "NO") << endl;
		}
		destruir(res);
	}
	else {
		cout << "NULL" << endl;
	}

	FrameworkA1::destruir(cp1elem);
	FrameworkA1::destruir(cp1prio);
	destruir(cp1);
}



