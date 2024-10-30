#pragma once

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "ListaPosInt.h"

class PruebasCorreccion : public Prueba  
{

public:
	PruebasCorreccion(ConductorPrueba* conductor);
	virtual ~PruebasCorreccion();
	virtual void correrPruebaConcreta();


protected:
	virtual const char* getNombre()const;

private:
	ManejadorImpresionPrueba mImpresion;

};
