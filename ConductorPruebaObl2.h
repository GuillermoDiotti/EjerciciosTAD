#pragma once

#include "ConductorPrueba.h"
#include "PruebasEjemploDeUsoEntrega.h"
#include "PruebasPropias.h"
#include "PruebasCorreccion.h"
#include "PruebasDefensa.h"
#include "TipoPruebas.h"

class ConductorPruebaObl2 : public ConductorPrueba 
{
	public:
		ConductorPruebaObl2();
		virtual ~ConductorPruebaObl2();

	protected:
		virtual void correrPruebaConcreta();
		virtual void correrPruebaConcreta(TipoPruebas tipoPruebas);
		virtual const char* getNombre() const;

private:
	// Empezar aqui a agregar los archivos de prueba

	Prueba* pruebasEjemploDeUsoEntrega;
	
	Prueba* pruebasPropias;

	Prueba* pruebasCorreccion;

	Prueba* pruebasDefensa;

	/* Ej:
	
	Prueba* miPrueba;

	*/

	// Terminar aqui
};
