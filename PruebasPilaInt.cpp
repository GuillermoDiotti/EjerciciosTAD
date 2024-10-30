#include "PruebasPilaInt.h"

void pruebasPilaIntNoAcotada(Prueba* pruebaConcreta);

void pruebasPilaInt(Prueba* pruebaConcreta) {
	pruebaConcreta->mImpresion.iniciarSeccion("PRUEBAS PilaInt");
	pruebasPilaIntNoAcotada(pruebaConcreta);
	pruebaConcreta->mImpresion.cerrarSeccion("PRUEBAS PilaInt");
}

void pruebasPilaIntNoAcotada(Prueba* pruebaConcreta)
{
	PilaInt p = crearPilaInt();

	cout << "cantidad de elementos al crear la pila: " << cantidadElementos(p) << endl;
	cout << "Esta vacia: " << esVacia(p) << endl;

	pruebaConcreta->ver3("Imprimo la cantidad de elementos al crear la pila y valido que sea vacia");

	push(p, 4);

	cout << "tope de la pila cuando agrego el primer elemento: " << top(p) << endl;

	pruebaConcreta->ver3("Imprimo el tope de la pila con 1 elemento para validar el caso base de push");

	push(p, 5);
	push(p, 2);
	push(p, 3);
	push(p, -1);

	cout << "Esta vacia: " << esVacia(p) << endl;

	pruebaConcreta->ver3("Imprimo si esta vacia o llena antes y despues de agregar, verificando que push funcione");

	cout << "Largo de pila: " << cantidadElementos(p) << endl;

	pruebaConcreta->ver3("Imprimo largo luego de agregar");

	cout << "el primer elemento antes del pop es: " << top(p) << endl;

	pop(p);

	cout << "el primer elemento luego del pop es: " << top(p) << endl;
	cout << "la cantidad de elementos luego del pop es: " << cantidadElementos(p) << endl;

	pruebaConcreta->ver3("Imprimo el primer elemento antes y despues del pop, verificando que disminuya la cantidad de elementos");

	PilaInt clonpila = clon(p);
	cout << "elementos de la pila: " << endl;
	while (!esVacia(clonpila))
	{
		int e = top(clonpila);
		pop(clonpila);
		if (!esVacia(clonpila)) {
			cout << e << ",";
		}
		else {
			cout << e << endl;
		}
	}
	pruebaConcreta->ver3("Clono e imprimo los elementos de la pila clonando y poppeando");

	cout << "Largo de clon luego de vaciarlo: " << cantidadElementos(clonpila) << endl;
	cout << "Largo de la pila original luego de vaciar clon: " << cantidadElementos(p) << endl;

	pruebaConcreta->ver3("Verifico que se modifique el clon y no el original");

	push(clonpila, 38);
	push(clonpila, 20);
	push(clonpila, -16);

	cout << "El tope de la pila clon luego de agregar 3 elementos es: " << top(clonpila) << endl;

	pop(clonpila);
	pop(clonpila);

	cout << "El tope de la pila clon luego de poppear 2 elementos es: " << top(clonpila) << endl;

	pruebaConcreta->ver3("Verifico que pushear y poppear elementos no altere la estructura de la pila");

	pop(clonpila);

	cout << "vacio el clon totalmente. Cantidad de elementos: " << cantidadElementos(clonpila) << endl;
	cout << "Es vacia: " << esVacia(clonpila) << endl;
	pruebaConcreta->ver3("Verifico que funcione el caso base de pop dejando la pila vacia");

	destruir(clonpila);

	cout << "cantidad de elementos de la pila original luego de destruir clon: " << cantidadElementos(p);
	cout << "tope de la pila original luego de destruir clon" << top(p);
	pruebaConcreta->ver3("Verifico que destruir el clon no altere la pila original");

	PilaInt clonp = clon(p);
	cout << "elementos de la pila: " << endl;
	while (!esVacia(p))
	{
		int e = top(p);
		pop(p);
		if (!esVacia(p)) {
			cout << e << ",";
		}
		else {
			cout << e << endl;
		}
	}

	cout << "elementos del clon de la pila: " << endl;
	while (!esVacia(clonp))
	{
		int e = top(clonp);
		pop(clonp);
		if (!esVacia(clonp)) {
			cout << e << ",";
		}
		else {
			cout << e << endl;
		}
	}

	pruebaConcreta->ver3("Verifico que el clon copie todos los elementos de la pila");

	destruir(clonp);
	destruir(p);

	pruebaConcreta->ver3("Libero memoria");
}
