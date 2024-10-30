#include "PruebasDiccionarioInt.h"

void pruebasDiccionarioIntNoAcotado(Prueba* pruebaConcreta);

void pruebasDiccionarioInt(Prueba* pruebaConcreta) {
	pruebaConcreta->mImpresion.iniciarSeccion("PRUEBAS Diccionario");
	pruebasDiccionarioIntNoAcotado(pruebaConcreta);
	pruebaConcreta->mImpresion.cerrarSeccion("PRUEBAS Diccionario");
}

void pruebasDiccionarioIntNoAcotado(Prueba* pruebaConcreta) {

	DiccionarioInt d = crearDiccionarioInt(5);

	agregar(d, 5);
	agregar(d, 7);
	agregar(d, -1);
	agregar(d, -5);
	agregar(d, 15);
	agregar(d, 4);
	agregar(d, 5);

	cout << "Largo de diccionario: " << cantidadElementos(d) << endl;
	pruebaConcreta->ver3("Imprimo largo luego de agregar");

	DiccionarioInt d2 = clon(d);
	NodoListaInt* l = NULL;
	while (!esVacio(d2)) {
		int e = elemento(d2);
		FrameworkA1::agregarOrd(l, e);
		borrar(d2, e);
	}

	char * salida = FrameworkA1::serializar(l); 
	FrameworkA1::destruir(l);
	cout << "Clon de diccionario: " << salida << endl;
	delete[] salida;
	pruebaConcreta->ver3("Clono e imprimo");
	cout << "Largo de clon luego de vaciarlo: " << cantidadElementos(d2) << endl;
	cout << "Largo de diccionario luego de vaciar clon: " << cantidadElementos(d) << endl;
	pruebaConcreta->ver3("Verifico que se modifique el clon y no el original");

	borrar(d, -5);
	borrar(d, 5);
	borrar(d, 5);
	borrar(d, 15);
	borrar(d, -15);

	cout << "Largo de diccionario luego de borrar 3 elementos: " << cantidadElementos(d) << endl;

	while (!esVacio(d)) {
		int e = elemento(d);
		FrameworkA1::agregarOrd(l, e);
		borrar(d, e);
	}

	salida = FrameworkA1::serializar(l);
	FrameworkA1::destruir(l);
	cout << "Diccionario luego de borrar 3 elementos: " << salida << endl;
	delete[] salida;
	pruebaConcreta->ver3("Borro algunos elementos");

	destruir(d);
	destruir(d2);

	pruebaConcreta->ver3("Libero memoria");
}
