#include "ConductorPruebaObl2.h"

ConductorPruebaObl2::ConductorPruebaObl2()
{
	// Empezar aqui a instanciar los archivos de prueba

	pruebasEjemploDeUsoEntrega = new PruebasEjemploDeUsoEntrega(this);

	pruebasPropias = new PruebasPropias(this);

	pruebasCorreccion = new PruebasCorreccion(this);

	pruebasDefensa = new PruebasDefensa(this);

	/* Ej:
	
	miPrueba = new MiPrueba(this);

	Recordar que el constructor de la prueba recibe el Conductor

	*/

	// Terminar aqui
}

ConductorPruebaObl2::~ConductorPruebaObl2()
{
	// Empezar aqui a borrar los archivos de prueba

	delete pruebasEjemploDeUsoEntrega;

	delete pruebasPropias;

	delete pruebasCorreccion;

	delete pruebasDefensa;

	/* Ej:
	
	delete miPrueba;

	*/

	// Terminar aqui
}

void ConductorPruebaObl2::correrPruebaConcreta()
{
	// Empezar aqui a llamar los metodos de prueba

	pruebasEjemploDeUsoEntrega->correrPrueba(true);

	pruebasPropias->correrPrueba();

	pruebasCorreccion->correrPrueba(true);

	pruebasDefensa->correrPrueba(true);

	/* Ej:
	
	miPrueba->correrPrueba();

	*/

	// Terminar aqui
}

void ConductorPruebaObl2::correrPruebaConcreta(TipoPruebas tipoPruebas)
{
	if (tipoPruebas == EjemploDeUsoEntrega)
		pruebasEjemploDeUsoEntrega->correrPrueba(true);
	else if (tipoPruebas == Propias)
		pruebasPropias->correrPrueba(true);
	else if (tipoPruebas == Correccion)
		pruebasCorreccion->correrPrueba(true);
	else if (tipoPruebas == Defensa)
		pruebasDefensa->correrPrueba(true);
	else
		assert(false);

}

const char* ConductorPruebaObl2::getNombre()const
{
	return "SalidaDeLasPruebas";
}
