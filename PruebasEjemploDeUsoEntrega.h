#pragma once

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "PruebasAuxEntrega.h"
#include "PruebasAuxDefensa.h"

#include "PruebasPilaInt.h"
#include "PruebasColaInt.h"
#include "PruebasColaPrioridadInt.h"
#include "PruebasListaPosInt.h"
#include "PruebasListaOrdInt.h"
#include "PruebasDiccionarioInt.h"
#include "PruebasTablaIntString.h"
#include "PruebasTablaIntInt.h"
#include "PruebasSetInt.h"
#include "PruebasMultisetInt.h"

class PruebasEjemploDeUsoEntrega : public Prueba  
{

public:
	PruebasEjemploDeUsoEntrega(ConductorPrueba* conductor);
	virtual ~PruebasEjemploDeUsoEntrega();
	virtual void correrPruebaConcreta();

protected:
	virtual const char* getNombre() const;

private:
	ManejadorImpresionPrueba mImpresion;

	void PruebasEjerciciosTAD();

};
