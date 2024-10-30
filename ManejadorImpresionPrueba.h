#pragma once

#include <iostream>
using namespace std;
#include <string.h>
#include "TipoRetorno.h"
#include "EstadisticaPrueba.h"

class ManejadorImpresionPrueba  
{
public:
	ManejadorImpresionPrueba(bool paraParseo = true);
	virtual ~ManejadorImpresionPrueba();

	void imprimirResultado(const char* comentario, bool paraParseo)const;
	void imprimirResultado(TipoRetorno retorno, TipoRetorno retornoEsperado, const char* comentario, bool paraParseo)const;
	void imprimirTotalResultados(const EstadisticaPrueba& estadistica, bool paraParseo)const;

	void iniciarSeccion(const char* seccion);
	void cerrarSeccion(const char* seccion);

	static ManejadorImpresionPrueba getInstancia();
protected:
	void imprimirComentario(const char* comentario)const;
	void imprimirRetorno(TipoRetorno retorno, TipoRetorno retornoEsperado)const;

private:
	static ManejadorImpresionPrueba* instanciaManejador;
	const char* getStringRetorno(TipoRetorno retorno)const;
};