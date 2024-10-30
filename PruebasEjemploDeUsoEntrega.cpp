
#include "PruebasEjemploDeUsoEntrega.h"

PruebasEjemploDeUsoEntrega::PruebasEjemploDeUsoEntrega(ConductorPrueba* conductor)
:Prueba(conductor)
{

}

PruebasEjemploDeUsoEntrega::~PruebasEjemploDeUsoEntrega()
{
	
}

const char* PruebasEjemploDeUsoEntrega::getNombre() const
{
	return "PruebasEjemploDeUsoEntrega";
}

void PruebasEjemploDeUsoEntrega::correrPruebaConcreta()
{
	PruebasEjerciciosTAD();

	pruebasPilaInt(this);
	pruebasListaPosInt(this);
	pruebasColaInt(this);
	pruebasDiccionarioInt(this);
	pruebasListaOrdInt(this);
	pruebasTablaIntString(this);
	pruebasMultisetInt(this);
	pruebasColaPrioridadInt(this);

	//pruebasTablaIntInt(this);
	//pruebasSetInt(this);
}

void PruebasEjemploDeUsoEntrega::PruebasEjerciciosTAD()
{

	// Pruebas Enlistar
	this->mImpresion.iniciarSeccion("PRUEBAS Enlistar");
	pruebaEnlistar("{2,1,5}");
	ver3("Prueba de pasar ABB a ListaOrd 1");

	pruebaEnlistar("{1,#,2,#,5}");
	ver3("Prueba de pasar ABB a ListaOrd 2");

	pruebaEnlistar("{1,#,2,#,15,10,20,8,#,16,30,7,9,#,18}");
	ver3("Prueba de pasar ABB a ListaOrd 3");
	this->mImpresion.cerrarSeccion("PRUEBAS Enlistar");


	// Pruebas UnionListaOrd
	this->mImpresion.iniciarSeccion("PRUEBAS UnionListaOrd");
	pruebaUnionListaOrd("(1,3,5,7,9)", "(2,4,6,8)");
	ver3("Prueba union de dos listas ordenadas 1");
	
	pruebaUnionListaOrd("(100,200,300,400)", "(100,200,300,400)");
	ver3("Prueba union de dos listas ordenadas 2");

	pruebaUnionListaOrd("()", "(-1,0,1,5)");
	ver3("Prueba union de dos listas ordenadas 3");
	this->mImpresion.cerrarSeccion("PRUEBAS UnionListaOrd");


	// Pruebas EstaContenida
	this->mImpresion.iniciarSeccion("PRUEBAS EstaContenida");
	pruebaEstaContenida("(1,7,4,2)", "(7,3,2,1)");
	ver3("Prueba de pila contenida 1");
	
	pruebaEstaContenida("(1,7,4,2)", "(7,3,2,1,4,8)");
	ver3("Prueba de pila contenida 2");

	pruebaEstaContenida("(1,7,4,2,7,4,4,7)", "(7,3,7,2,4,1,4,8)");
	ver3("Prueba de pila contenida 3");

	pruebaEstaContenida("(1,7,4,2,7,4,4,7)", "(7,3,7,2,4,4,4,7,1,4,8)");
	ver3("Prueba de pila contenida 4");
	this->mImpresion.cerrarSeccion("PRUEBAS EstaContenida");



	// Pruebas ObtenerRepetidos
	this->mImpresion.iniciarSeccion("PRUEBAS ObtenerRepetidos");
	pruebaObtenerRepetidos("(1, 1, 2)");
	ver3("Prueba ObtenerRepetidos 1");
	pruebaObtenerRepetidos("()");
	ver3("Prueba ObtenerRepetidos 2");
	pruebaObtenerRepetidos("(1, 2, 3, 2, 1)");
	ver3("Prueba ObtenerRepetidos 3");
	pruebaObtenerRepetidos("(10, 4, 6, 1, 1, 10, 5, 8)");
	ver3("Prueba ObtenerRepetidos 4");
	pruebaObtenerRepetidos("(4)");
	ver3("Prueba ObtenerRepetidos 5");
	pruebaObtenerRepetidos("(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)");
	ver3("Prueba ObtenerRepetidos 6");
	pruebaObtenerRepetidos("(1, 1, 1, 1, 1, 1)");
	ver3("Prueba ObtenerRepetidos 7");
	pruebaObtenerRepetidos("(1, 10, 100, 1000)");
	ver3("Prueba ObtenerRepetidos 8");
	pruebaObtenerRepetidos("(4, 6, 4, 6, 4, 6, 4, 6)");
	ver3("Prueba ObtenerRepetidos 9");
	pruebaObtenerRepetidos("(1, 2, 1, 4, 2, 1, 4, 2, 7)");
	ver3("Prueba ObtenerRepetidos 10");
	pruebaObtenerRepetidos("(6, 6)");
	ver3("Prueba ObtenerRepetidos 11");
	pruebaObtenerRepetidos("(6, 6, 6, 7, 7, 7)");
	ver3("Prueba ObtenerRepetidos 12");
	this->mImpresion.cerrarSeccion("PRUEBAS ObtenerRepetidos");


	// Pruebas Xor
	this->mImpresion.iniciarSeccion("PRUEBAS Xor");
	pruebaXor("()", "()");
	ver3("Prueba Xor de multisets 1");  //()
	pruebaXor("(1,2,3)", "(3,2,1)");
	ver3("Prueba Xor de multisets 2");  //()
	pruebaXor("(1,2,3)", "()");
	ver3("Prueba Xor de multisets 3");  //(1,2,3)
	pruebaXor("()", "(3,2,1)");
	ver3("Prueba Xor de multisets 4");  //(3,2,1)
	pruebaXor("(1,3,4,7)", "(8,1,2,3)");  //(4,7,8,2)
	ver3("Prueba Xor de multisets 5");
	pruebaXor("(1,1,2)", "(1,2)");  //(1)
	ver3("Prueba Xor de multisets 6");
	pruebaXor("(1,1,2,3,3,3)", "(1,3)");  //(1,2,3,3)
	ver3("Prueba Xor de multisets 7");
	pruebaXor("(1,1,1)", "()");  //(1,1,1)
	ver3("Prueba Xor de multisets 8");
	pruebaXor("(1,1,1)", "(5)");  //(1,1,1,5)
	ver3("Prueba Xor de multisets 9");
	pruebaXor("(1,1,1,0)", "(1,1,1)");  //(0)
	ver3("Prueba Xor de multisets 10");
	this->mImpresion.cerrarSeccion("PRUEBAS Xor");

	this->mImpresion.iniciarSeccion("PRUEBAS MenorPrioridad");
	pruebaMenorPrioridad("()", "()");
	ver3("Prueba pruebaMenorPrioridad 1");
	pruebaMenorPrioridad("(4,2,3,1)", "(1,3,2,4)");
	ver3("Prueba pruebaMenorPrioridad 2");
	pruebaMenorPrioridad("(5,9,2,-3,5,7,9,-2,1,-1)", "(5,6,2,3,8,2,4,-4,2,-1)");
	ver3("Prueba pruebaMenorPrioridad 3");
	pruebaMenorPrioridad("(6,30,4,-10,9)", "(-1,0,7,-1,9)");
	ver3("Prueba pruebaMenorPrioridad 4");
	pruebaMenorPrioridad("(15,-4,3,-3,-2,12,5,7,6,9,-3,-5,1)", "(5,4,4,3,2,2,2,1,2,4,3,5,1)");
	ver3("Prueba pruebaMenorPrioridad 5");
	pruebaMenorPrioridad("(2,2,4,4)", "(4,4,4,4)");
	ver3("Prueba pruebaMenorPrioridad 6");
	pruebaMenorPrioridad("(2,1,7,6,8)", "(4,4,5,4,4)");
	ver3("Prueba pruebaMenorPrioridad 7");
	pruebaMenorPrioridad("(9,8,7,5,3,2,5,4,1,3)", "(-1,-2,-3,-4,-5,-6,-7,-8,-9,-10)");
	ver3("Prueba pruebaMenorPrioridad 8");
	pruebaMenorPrioridad("(1)", "(-1)");
	ver3("Prueba pruebaMenorPrioridad 9");
	pruebaMenorPrioridad("(1,2,3,4,5,6,7,8,9)", "(1,-1,-2,1,-1,-2,-2,-1,1)");
	ver3("Prueba pruebaMenorPrioridad 10");
	this->mImpresion.cerrarSeccion("PRUEBAS MenorPrioridad");
}


