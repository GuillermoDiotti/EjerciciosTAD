#include "PruebasDefensa.h"

PruebasDefensa::PruebasDefensa(ConductorPrueba* conductor)
	:Prueba(conductor)
{
}

PruebasDefensa::~PruebasDefensa()
{
}

const char* PruebasDefensa::getNombre()const
{
	return "PruebasDefensa";
}

void PruebasDefensa::correrPruebaConcreta()
{
}
