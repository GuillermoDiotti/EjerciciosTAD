#pragma once

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "PruebasAuxEntrega.h"

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

class PruebasPropias : public Prueba  
{

public:
	PruebasPropias(ConductorPrueba* conductor);
	virtual ~PruebasPropias();
	virtual void correrPruebaConcreta();

protected:
	ManejadorImpresionPrueba mImpresion;
	virtual const char* getNombre() const;

private:
	
};

