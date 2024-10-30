#include "PruebasColaInt.h"

void pruebasColaIntNoAcotada(Prueba* pruebaConcreta);

void pruebasColaInt(Prueba* pruebaConcreta) {
	pruebaConcreta->mImpresion.iniciarSeccion("PRUEBAS ColaInt");
	pruebasColaIntNoAcotada(pruebaConcreta);
	pruebaConcreta->mImpresion.cerrarSeccion("PRUEBAS ColaInt");
}

void pruebasColaIntNoAcotada(Prueba* pruebaConcreta)
{
	ColaInt c = crearColaInt();

	cout << "cantidad de elementos al crear la cola: " << cantidadElementos(c) << endl;
	cout << "Esta vacia: " << esVacia(c) << endl;

	pruebaConcreta->ver3("Imprimo la cantidad de elementos al crear la cola y valido que sea vacia");

	encolar(c, 4);

	cout << "Principio de la cola cuando agrego el primer elemento: " << principio(c) << endl;

	pruebaConcreta->ver3("Imprimo el principio de la cola con 1 elemento para validar el caso base de encolar");

	encolar(c, 5);
	encolar(c, 2);
	encolar(c, 3);
	encolar(c, -1);

	cout << "Esta vacia: " << esVacia(c) << endl;

	pruebaConcreta->ver3("Imprimo si esta vacia o llena antes y despues de agregar, verificando que encolar funcione");

	cout << "Largo de cola: " << cantidadElementos(c) << endl;

	pruebaConcreta->ver3("Imprimo largo luego de agregar");

	cout << "el primer elemento antes de desencolar es: " << principio(c) << endl;

	desencolar(c);

	cout << "el primer elemento luego de desencolar es: " << principio(c) << endl;
	cout << "la cantidad de elementos luego de desencolar es: " << cantidadElementos(c) << endl;

	pruebaConcreta->ver3("Imprimo el primer elemento antes y despues de desencolar, verificando que disminuya la cantidad de elementos");

	ColaInt clonCola = clon(c);
	cout << "elementos de la cola: " << endl;
	while (!esVacia(clonCola))
	{
		int e = principio(clonCola);
		desencolar(clonCola);
		if (!esVacia(clonCola)) {
			cout << e << ",";
		}
		else {
			cout << e << endl;
		}
	}
	pruebaConcreta->ver3("Clono e imprimo los elementos de la cola clonando y desencolando");

	cout << "Largo de clon luego de vaciarlo: " << cantidadElementos(clonCola) << endl;
	cout << "Largo de la cola original luego de vaciar clon: " << cantidadElementos(c) << endl;

	pruebaConcreta->ver3("Verifico que se modifique el clon y no el original");

	encolar(clonCola, 38);
	encolar(clonCola, 20);
	encolar(clonCola, -16);

	cout << "El principio de la cola clon luego de agregar 3 elementos es: " << principio(clonCola) << endl;

	desencolar(clonCola);
	desencolar(clonCola);

	cout << "El principio de la cola clon luego de desencolar 2 elementos es: " << principio(clonCola) << endl;

	pruebaConcreta->ver3("Verifico que encolar y desencolar elementos no altere la estructura de la cola");

	desencolar(clonCola);

	cout << "vacio el clon totalmente. Cantidad de elementos: " << cantidadElementos(clonCola) << endl;
	cout << "Es vacia: " << esVacia(clonCola) << endl;
	pruebaConcreta->ver3("Verifico que funcione el caso base de desencolar dejando la cola vacia");

	destruir(clonCola);

	cout << "cantidad de elementos de la cola original luego de destruir clon: " << cantidadElementos(c);
	cout << "principio de la cola original luego de destruir clon" << principio(c);
	pruebaConcreta->ver3("Verifico que destruir el clon no altere la cola original");


	ColaInt clonc = clon(c);
	cout << "elementos de la cola: " << endl;
	while (!esVacia(c))
	{
		int e = principio(c);
		desencolar(c);
		if (!esVacia(c)) {
			cout << e << ",";
		}
		else {
			cout << e << endl;
		}
	}

	cout << "elementos del clon de la cola: " << endl;
	while (!esVacia(clonc))
	{
		int e = principio(clonc);
		desencolar(clonc);
		if (!esVacia(clonc)) {
			cout << e << ",";
		}
		else {
			cout << e << endl;
		}
	}

	pruebaConcreta->ver3("Verifico que el clon copie todos los elementos de la cola");

	destruir(clonc);
	destruir(c);
	pruebaConcreta->ver3("Libero memoria");
}
