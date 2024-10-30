#include "PruebasCorreccion.h"

PruebasCorreccion::PruebasCorreccion(ConductorPrueba* conductor)
	:Prueba(conductor)
{
}

PruebasCorreccion::~PruebasCorreccion()
{
}

const char* PruebasCorreccion::getNombre() const
{
	return "PruebasCorreccion";
}

void PruebasCorreccion::correrPruebaConcreta()
{
}
