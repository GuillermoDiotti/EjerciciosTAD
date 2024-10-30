#pragma once

#include "Prueba.h"
#include "ConductorPrueba.h"
#include "PruebasAuxDefensa.h"


class PruebasDefensa : public Prueba
{

public:
	PruebasDefensa(ConductorPrueba* conductor);
	virtual ~PruebasDefensa();
	virtual void correrPruebaConcreta();


protected:
	virtual const char* getNombre()const;

private:
	ManejadorImpresionPrueba mImpresion;

};