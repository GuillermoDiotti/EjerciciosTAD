#include "PruebasListaPosInt.h"

void pruebasListaPosIntNoAcotada(Prueba* pruebaConcreta);


void pruebasListaPosInt(Prueba* pruebaConcreta) {
	pruebaConcreta->mImpresion.iniciarSeccion("PRUEBAS ListaPosInt");
	pruebasListaPosIntNoAcotada(pruebaConcreta);
	pruebaConcreta->mImpresion.cerrarSeccion("PRUEBAS ListaPosInt");
}

void pruebasListaPosIntNoAcotada(Prueba* pruebaConcreta)
{
	ListaPosInt l = crearListaPosInt();
	
	agregar(l, 5, 0);
	agregar(l, 7, 1);
	agregar(l, -1, 2);
	agregar(l, 5, 21);
	agregar(l, -2, 3);
	agregar(l, 4, 11);
	agregar(l, 15, 10);

	cout << "Largo de lista Pos: " << cantidadElementos(l) << endl;
	pruebaConcreta->ver3("Imprimo largo luego de agregar");

	ListaPosInt l2 = clon(l);
	
	borrar(l2, 50); //borro mas alla de la posicion - no deberia tener efecto

	while (!esVacia(l2))
	{
		int e = elemento(l2, 0);
		borrar(l2, 0);
		if (!esVacia(l2)) {
			cout << e << ",";
		}
		else {
			cout << e << endl;
		}
	}

	borrar(l2, 0); //Borro una vez que la lista ya esta vacia, no deberia tener efecto

	pruebaConcreta->ver3("Clono e imprimo");
	cout << "Cantidad de elementos del clon luego de vaciarlo: " << cantidadElementos(l2) << endl;
	cout << "Cantidad de elementos de la cola luego de vaciar clon: " << cantidadElementos(l) << endl;
	pruebaConcreta->ver3("Verifico que se modifique el clon y no el original");

	borrar(l, 0);
	borrar(l, 1);
	borrar(l, 4);
	borrar(l, 1);
	borrar(l, 50); //Borro mucho mas alla de la ultima posicion

	cout << "Largo de lista Pos luego de borrar 4 elementos: " << cantidadElementos(l) << endl;

	while(!esVacia(l))
	{
		elemento(l, 0);
		borrar(l, 0);
	}

	cout << "Largo de lista Pos luego de vaciarla: " << cantidadElementos(l) << endl;
	pruebaConcreta->ver3("Borro algunos elementos y vacio la lista");

	destruir(l);
	destruir(l2);

	pruebaConcreta->ver3("Libero memoria");
}
