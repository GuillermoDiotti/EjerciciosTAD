#include "PruebasListaOrdInt.h"

void pruebasListaOrdIntNoAcotada(Prueba* pruebaConcreta);



void pruebasListaOrdInt(Prueba* pruebaConcreta) {
	pruebaConcreta->mImpresion.iniciarSeccion("PRUEBAS ListaOrdInt");
	pruebasListaOrdIntNoAcotada(pruebaConcreta);
	pruebaConcreta->mImpresion.cerrarSeccion("PRUEBAS ListaOrdInt");

}


void pruebasListaOrdIntNoAcotada(Prueba* pruebaConcreta)
{
	ListaOrdInt l = crearListaOrdInt();

	agregar(l, 5);
	agregar(l, 7);
	agregar(l, -1);
	agregar(l, -2);
	agregar(l, 15);
	agregar(l, 4);
	agregar(l, 5);

	cout << "Largo de lista Ord: " << cantidadElementos(l) << endl;
	pruebaConcreta->ver3("Imprimo largo luego de agregar 7 elementos");


	int principio = minimo(l);
	int final = maximo(l);

	cout << "Elemento del principio de lista Ord: " << principio << endl;
	cout << "Elemento del final de lista Ord: " << final << endl;
	pruebaConcreta->ver3("Imprimo el primer elemento de la lista y el utlimo");

	borrarMinimo(l);
	cout << "Elimino el " << principio << " de la lista" << endl;
	cout << "El largo de la lista ord " << cantidadElementos(l) << endl;
	pruebaConcreta->ver3("Imprimo largo luego de borrar el minimo");

	borrarMaximo(l);
	cout << "Elimino el " << final << " de la lista" << endl;
	cout << "El largo de la lista ord " << cantidadElementos(l) << endl;
	pruebaConcreta->ver3("Imprimo largo luego de borrar el maximo");

	borrar(l,-20);
	cout << "Elimino un elemento que no existe en la lista" << endl;
	cout << "El largo de la lista ord " << cantidadElementos(l) << endl;
	pruebaConcreta->ver3("Imprimo largo luego de borrar un elemento que no existe");

	borrar(l, 4);
	cout << "Elimino un elemento que existe en la lista" << endl;
	cout << "El largo de la lista ord " << cantidadElementos(l) << endl;
	pruebaConcreta->ver3("Imprimo largo luego de borrar un elemento que existe");

	string vacia = esVacia(l) ? " si " : " no ";
	cout << "La lista " << vacia << " es vacia" << endl;
	pruebaConcreta->ver3("Imprimo la lista no es vacia");

	string existeElemento = existe(l, 32)?" si ":" no ";
	cout << "La lista " << existeElemento << " contiene el elemento 32" << endl;
	pruebaConcreta->ver3("Imprimo la lista no contiene el elemento 32");

	existeElemento = existe(l, 7) ? " si " : " no ";
	cout << "La lista " << existeElemento << " contiene el elemento 7" << endl;
	pruebaConcreta->ver3("Imprimo la lista si contiene el elemento 7");

	ListaOrdInt clonL = clon(l);

	cout << "Clon de lista Ord: ";
	while (!esVacia(clonL))
	{
		int e = minimo(clonL);
		borrar(clonL, e);
		if (!esVacia(clonL)) {
			cout << e << ",";
		}
		else {
			cout << e << endl;
		}
	}
	cout << endl;
	pruebaConcreta->ver3("Clono e imprimo");

	cout << "Largo de clon luego de vaciarlo: " << cantidadElementos(clonL) << endl;
	cout << "Largo de lista Ord luego de vaciar clon: " << cantidadElementos(l) << endl;
	pruebaConcreta->ver3("Verifico que se modifique el clon y no el original");

	borrarMinimo(l);
	borrarMinimo(l);
	borrarMinimo(l);
	borrarMinimo(l);
	borrar(l, 50); //Borro elemento que no existe

	cout << "Largo de lista Ord luego de borrar 4 elementos: " << cantidadElementos(l) << endl;
	pruebaConcreta->ver3("Imprimo luego de borrar elementos");

	cout << "Lista ord luego de borrar los elementos:";
	while (!esVacia(l))
	{
		int e = minimo(l);
		borrar(l, e);
		if (!esVacia(l)) {
			cout << e << ",";
		}
		else {
			cout << e << endl;
		}
	}

	cout << endl;
	cout << "Largo de lista Ord luego de vaciarla: " << cantidadElementos(l) << endl;
	pruebaConcreta->ver3("Borro algunos elementos y vacio la lista");

	borrarMinimo(l);
	cout << "El largo de la lista ord " << cantidadElementos(l) << endl;
	pruebaConcreta->ver3("Imprimo largo luego de borrar el minimo en la lista vacia");

	borrarMaximo(l);
	cout << "El largo de la lista ord " << cantidadElementos(l) << endl;
	pruebaConcreta->ver3("Imprimo largo luego de borrar el maximo en la lista vacia");

	existeElemento = existe(l, 7) ? " si " : " no ";
	cout << "La lista vacia" << existeElemento << " contiene el elemento 7" << endl;
	pruebaConcreta->ver3("Imprimo la lista vacia no contiene el elemento 7");

	destruir(l);
	destruir(clonL);

	pruebaConcreta->ver3("Libero memoria");
}
