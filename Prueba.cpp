#include "Prueba.h"


Prueba::Prueba(ConductorPrueba* conductor)
{
	conductorPrueba = conductor;
}

Prueba::~Prueba()
{
}

void Prueba::ver(TipoRetorno retorno, TipoRetorno retornoEsperado, const char* comentario)
{
	getEstadisticaPrueba().actualizarEstadisticas(retorno, retornoEsperado);
	
	conductorPrueba->ver(retorno,retornoEsperado,comentario);
}

void Prueba::ver2(TipoRetorno retorno, TipoRetorno retornoEsperado, const char* comentario)
{
	getEstadisticaPrueba().actualizarEstadisticas(retorno, retornoEsperado);
	
	conductorPrueba->ver2(retorno,retornoEsperado,comentario);
}

void Prueba::ver3(const char* comentario)
{
	conductorPrueba->ver3(comentario);
}

void Prueba::ver3(const char* comentario, double puntaje)
{
	conductorPrueba->ver3(comentario, puntaje);
}

EstadisticaPrueba& Prueba::getEstadisticaPrueba()
{
	return estadisticaPrueba;
}

ManejadorImpresionPrueba Prueba::getManejadorImpresion()
{
	return ManejadorImpresionPrueba::getInstancia();
}

ManejadorSalidaPrueba Prueba::getManejadorSalida()
{
	return ManejadorSalidaPrueba::getInstancia();
}

void Prueba::correrPrueba(bool paraParseo)
{
	const char* nombrePrueba = getNombre();
	std::size_t largo = strlen(nombrePrueba) + 5;
	char* nombreArchivo = new char[largo];
	strcpy_s(nombreArchivo, largo, nombrePrueba);
	strcat_s(nombreArchivo, largo, ".txt");

	ManejadorSalidaPrueba msp = getManejadorSalida();
	//msp.crearDirectorio(nombrePrueba); 
	msp.crearDirectorio("SalidasSinProcesar");
	msp.setSalidaArchivo(nombreArchivo);

	delete [] nombreArchivo;

	conductorPrueba->comenzarNuevaPrueba();

	correrPruebaConcreta();
	
	//ManejadorImpresionPrueba mip = getManejadorImpresion();
	//mip.imprimirTotalResultados(getEstadisticaPrueba(), paraParseo);
	mImpresion.imprimirTotalResultados(getEstadisticaPrueba(), paraParseo);

	msp.cambiarDirectorio("..");
}
