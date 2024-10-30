#include "ConductorPruebaObl2.h"
#include "ManejadorArchivos.h"
#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;


// NO MODIFICAR ACA. HACER LAS PRUEBAS EN EL ARCHIVO PRUEBASPROPIAS.CPP
int main()
{
	(void)_mkdir("./SalidaDeLasPruebas");
	(void)_mkdir("./SalidaDeLasPruebas/Resultados");
	(void)_mkdir("./SalidaDeLasPruebas/SalidasSinProcesar");
	system("del /Q .\\SalidaDeLasPruebas\\Resultados\\*.*");
	system("del /Q .\\SalidaDeLasPruebas\\SalidasSinProcesar\\*.*");

	ConductorPrueba* prueba = new ConductorPruebaObl2();
	ManejadorArchivos* m;

	prueba->correrPrueba(EjemploDeUsoEntrega, true);

	char rutaLectura1[] = "../SalidaDeLasPruebas/SalidasSinProcesar/PruebasEjemploDeUsoEntrega.txt";
	char rutaCorreccion1[] = "../PruebasEjemploDeUsoEntrega.txt";
	char rutaEscritura1[] = "../SalidaDeLasPruebas/Resultados/PruebasEjemploDeUsoEntregaResultado.txt";
	m = new ManejadorArchivos(rutaLectura1, rutaCorreccion1, rutaEscritura1);

	// Comparar
	// - Parametro 1: si se le pasa true muestra el resultado de todas las salidas incluso cuando dan OK
	// - Parametro 2: si se le pasa true solamente muestra las pruebas que no están correctas
	m->Comparar(false, false);
	delete m;

	prueba->correrPrueba(Correccion, false);

	char rutaLectura3[] = "../SalidaDeLasPruebas/SalidasSinProcesar/PruebasCorreccion.txt";
	char rutaCorreccion3[] = "../PruebasCorreccion.txt";
	char rutaEscritura3[] = "../SalidaDeLasPruebas/Resultados/PruebasCorreccionResultado.txt";
	m = new ManejadorArchivos(rutaLectura3, rutaCorreccion3, rutaEscritura3);

	// Comparar
	// - Parametro 1: si se le pasa true muestra el resultado de todas las salidas incluso cuando dan OK
	// - Parametro 2: si se le pasa true solamente muestra las pruebas que no están correctas
	m->Comparar(false, false);
	delete m;

	prueba->correrPrueba(Propias, false);

	char rutaLectura4[] = "../SalidaDeLasPruebas/SalidasSinProcesar/PruebasPropias.txt";
	char rutaCorreccion4[] = "../PruebasPropias.txt";
	char rutaEscritura4[] = "../SalidaDeLasPruebas/Resultados/PruebasPropiasResultado.txt";
	m = new ManejadorArchivos(rutaLectura4, rutaCorreccion4, rutaEscritura4);
	
	// Comparar
	// - Parametro 1: si se le pasa true muestra el resultado de todas las salidas incluso cuando dan OK
	// - Parametro 2: si se le pasa true solamente muestra las pruebas que no están correctas
	m->Comparar(false, false); 
	delete m;

	prueba->correrPrueba(Defensa, false);

	char rutaLectura5[] = "../SalidaDeLasPruebas/SalidasSinProcesar/PruebasDefensa.txt";
	char rutaCorreccion5[] = "../PruebasDefensa.txt";
	char rutaEscritura5[] = "../SalidaDeLasPruebas/Resultados/PruebasDefensaResultado.txt";
	m = new ManejadorArchivos(rutaLectura5, rutaCorreccion5, rutaEscritura5);
	
	// Comparar
	// - Parametro 1: si se le pasa true muestra el resultado de todas las salidas incluso cuando dan OK
	// - Parametro 2: si se le pasa true solamente muestra las pruebas que no están correctas
	m->Comparar(false, false); 
	delete m;
	
	delete prueba;

	//system("pause");

	return 0;
}

