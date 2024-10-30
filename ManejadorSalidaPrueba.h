#pragma once

#include <iostream>
#include <fstream>
#include <streambuf>

#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	#include <direct.h>
#else
	#include <sys/stat.h>
	#include <unistd.h>
#endif

using namespace std;

class ManejadorSalidaPrueba  
{
public:
	ManejadorSalidaPrueba(const ManejadorSalidaPrueba &m);
	
	void setSalidaArchivo(const char* nombreArchivo);
	void setSalidaPantalla();

	static ManejadorSalidaPrueba getInstancia();

	void crearDirectorio(const char* nombreDirectorio);
	void cambiarDirectorio(const char* nombreDirectorio);

	virtual ~ManejadorSalidaPrueba();

protected:
	ManejadorSalidaPrueba();
	ManejadorSalidaPrueba& operator=(const ManejadorSalidaPrueba &manejador);

private:
	streambuf* pantalla;
	ofstream archivoActual;
};
