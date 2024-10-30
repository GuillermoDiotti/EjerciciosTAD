#include "PruebasColaPrioridadInt.h"

void pruebasColaDePrioridadIntNoAcotada(Prueba* pruebaConcreta);

void pruebasColaPrioridadInt(Prueba* pruebaConcreta) {
	pruebaConcreta->mImpresion.iniciarSeccion("PRUEBAS ColaPrioridadInt");
	pruebasColaDePrioridadIntNoAcotada(pruebaConcreta);
	pruebaConcreta->mImpresion.cerrarSeccion("PRUEBAS ColaPrioridadInt");
}


void pruebasColaDePrioridadIntNoAcotada(Prueba* pruebaConcreta) 
{
	ColaPrioridadInt cola = crearColaPrioridadInt(10);

	encolar(cola, 3, 3);
	encolar(cola, 5, 5);
	encolar(cola, 8, 8);
	encolar(cola, 1, 1);
	encolar(cola, 6, 6);
	encolar(cola, 2, 3);
	encolar(cola, 9, 9);
	encolar(cola, -5, 3);
	encolar(cola, 20, 3);

	cout << "La cola de prioridad esta llena? " << (esLlena(cola) ? "SI" : "NO") << endl;
	pruebaConcreta->ver3("Verifico si la cola se lleno");

	encolar(cola, 1, -1);

	cout << "La cola de prioridad esta llena? " << (esLlena(cola) ? "SI" : "NO") << endl;
	pruebaConcreta->ver3("Verifico si la cola se lleno");

	cout << "Cantidad de elementos de la cola: " << cantidadElementos(cola) << endl;
	pruebaConcreta->ver3("Imprimo largo luego de agregar");

	ColaPrioridadInt colaClon = clon(cola);
	int e;
	int p;
	cout << "Clon de elementos colaPrioridadInt: ";
	while (!esVacia(colaClon))
	{
		e = principio(colaClon);
		p = principioPrioridad(colaClon);
		desencolar(colaClon);
		if (!esVacia(colaClon)) {
			cout << e << ":" << p << ",";
		}
		else {
			cout << e << ":" << p << endl;
		}
	}

	pruebaConcreta->ver3("Clono e imprimo");
	cout << "Cantidad de elementos del clon luego de vaciarlo: " << cantidadElementos(colaClon) << endl;
	cout << "Cantidad de elementos de la cola luego de vaciar clon: " << cantidadElementos(cola) << endl;
	pruebaConcreta->ver3("Verifico que se modifique el clon y no el original");
	
	ColaPrioridadInt colaClonPriori = clon(cola);	
	cout << "Clon de prioridades colaPrioridadInt: ";
	while (!esVacia(colaClonPriori))
	{
		e = principio(colaClonPriori);
		p = principioPrioridad(colaClonPriori);
		desencolar(colaClonPriori);
		if (!esVacia(colaClonPriori)) {
			cout << e << ":" << p << ",";
		}
		else {
			cout << e << ":" << p << endl;
		}

	}

	pruebaConcreta->ver3("Clono e imprimo");
	cout << "Cantidad de elementos del clon luego de vaciarlo: " << cantidadElementos(colaClonPriori) << endl;
	cout << "Cantidad de elementos de la cola luego de vaciar clon: " << cantidadElementos(cola) << endl;
	pruebaConcreta->ver3("Verifico que se modifique el clon y no el original");

	desencolar(cola);
	desencolar(cola);
	desencolar(cola);

	cout << "Cantidad de elementos luego de borrar 3 elementos: " << cantidadElementos(cola) << endl;
	pruebaConcreta->ver3("Cantidad de elementos luego de borrar 3 elementos");

	destruir(cola);
	destruir(colaClon);
	destruir(colaClonPriori);

	pruebaConcreta->ver3("Libero memoria");
}

