#include "PruebasMultisetInt.h"

void pruebasMultisetIntNoAcotada(Prueba* pruebaConcreta);


void pruebasMultisetInt(Prueba* pruebaConcreta) {
    pruebaConcreta->mImpresion.iniciarSeccion("PRUEBAS MultisetInt");
    pruebasMultisetIntNoAcotada(pruebaConcreta);
    pruebaConcreta->mImpresion.cerrarSeccion("PRUEBAS MultisetInt");
}


void pruebasMultisetIntNoAcotada(Prueba* pruebaConcreta)
{
    MultisetInt s = crearMultisetInt();

    agregar(s, 5, 2);
    agregar(s, 7, 2);
    agregar(s, -1, 1);
    agregar(s, -2, 1);
    agregar(s, 15, 1);
    agregar(s, 4, 1);

    cout << "Largo de lista Pos: " << cantidadElementos(s) << endl;
    pruebaConcreta->ver3("Imprimo largo luego de agregar");



    MultisetInt clonS = clon(s);
    NodoListaInt* lord = NULL;
    while (!esVacio(clonS)) {
        int e = elemento(clonS);
        FrameworkA1::agregarOrd(lord, e);
        borrar(clonS, e);
    }
    char* salida = FrameworkA1::serializar(lord);
    FrameworkA1::destruir(lord);
    cout << "Clon de multiset: " << salida << endl;
    delete[] salida;
    pruebaConcreta->ver3("Clono e imprimo");
    cout << "Largo de clon luego de vaciarlo: " << cantidadElementos(clonS) << endl;
    cout << "Largo de Set luego de vaciar clon: " << cantidadElementos(s) << endl;
    pruebaConcreta->ver3("Verifico que se modifique el clon y no el original");


    MultisetInt s2 = crearMultisetInt();

    agregar(s2, 5, 2);
    agregar(s2, 1, 1);
    agregar(s2, 2, 3);
    agregar(s2, 13, 1);
    agregar(s2, 15, 1);
    agregar(s2, 4, 2);
    agregar(s2, 7, 1);

    MultisetInt unionS = unionConjuntos(s, s2);
    lord = NULL;
    while (!esVacio(unionS)) {
        int e = elemento(unionS);
        FrameworkA1::agregarOrd(lord, e);
        borrar(unionS, e);
    }
    salida = FrameworkA1::serializar(lord);
    FrameworkA1::destruir(lord);
    cout << "Union de multiset: " << salida << endl;
    delete[] salida;
    pruebaConcreta->ver3("Hago union e imprimo");
    cout << "Largo de la union luego de vaciarlo: " << cantidadElementos(unionS) << endl;
    cout << "Largo de Multiset1 luego de vaciar la union: " << cantidadElementos(s) << endl;
    cout << "Largo de Multiset2 luego de vaciar la union: " << cantidadElementos(s2) << endl;
    pruebaConcreta->ver3("Verifico que se modifique la union y no los originales");



    MultisetInt interS = interseccionConjuntos(s, s2);
    lord = NULL;
    while (!esVacio(interS)) {
        int e = elemento(interS);
        FrameworkA1::agregarOrd(lord, e);
        borrar(interS, e);
    }
    salida = FrameworkA1::serializar(lord);
    FrameworkA1::destruir(lord);
    cout << "Interseccion de multiset: " << salida << endl;
    delete[] salida;
    pruebaConcreta->ver3("Hago interseccion e imprimo");
    cout << "Largo de la interseccion luego de vaciarlo: " << cantidadElementos(interS) << endl;
    cout << "Largo de Multiset1 luego de vaciar la interseccion: " << cantidadElementos(s) << endl;
    cout << "Largo de Multiset2 luego de vaciar la interseccion: " << cantidadElementos(s2) << endl;
    pruebaConcreta->ver3("Verifico que se modifique la interseccion y no los originales");


    MultisetInt difS = diferenciaConjuntos(s, s2);
    lord = NULL;
    while (!esVacio(difS)) {
        int e = elemento(difS);
        FrameworkA1::agregarOrd(lord, e);
        borrar(difS, e);
    }
    salida = FrameworkA1::serializar(lord);
    FrameworkA1::destruir(lord);
    cout << "Diferencia de multiset: " << salida << endl;
    delete[] salida;
    pruebaConcreta->ver3("Hago diferencia e imprimo");
    cout << "Largo de la diferencia luego de vaciarlo: " << cantidadElementos(difS) << endl;
    cout << "Largo de Multiset1 luego de vaciar la diferencia: " << cantidadElementos(s) << endl;
    cout << "Largo de Multiset2 luego de vaciar la diferencia: " << cantidadElementos(s2) << endl;
    pruebaConcreta->ver3("Verifico que se modifique la diferencia y no los originales");


    cout << "Pertenece elemento: " << pertenece(s, -1) << endl;
    borrar(s, -1);
    cout << "Pertenece elemento luego de borrarlo: " << pertenece(s, -1) << endl;
    cout << "Pertenece otro elemento: " << pertenece(s, 10) << endl;
    pruebaConcreta->ver3("Verifico si pertenecen algunos elementos");

    cout << "Subconjunto: " << contenidoEn(s2, s) << endl;
    borrar(s2, 1);
    borrar(s2, 2);
    borrar(s2, 2);
    borrar(s2, 2);
    borrar(s2, 13);
    cout << "Subconjunto luego de borrar elementos: " << contenidoEn(s2, s) << endl;
    borrar(s2, 4);
    cout << "Subconjunto luego de borrar mas elementos: " << contenidoEn(s2, s) << endl;
    borrar(s2, 4);
    borrar(s2, 5);
    borrar(s2, 5);
    borrar(s2, 7);
    borrar(s2, 15);
    cout << "Es vacio: " << esVacio(s2) << endl;
    cout << "Cantidad elementos de vacio: " << cantidadElementos(s2) << endl;
    cout << "Subconjunto vacio: " << contenidoEn(s2, s) << endl;
    pruebaConcreta->ver3("Verifico si a partir de un Multiset que no pertenece a otro, luego de borrarle algunos elementos, si pertenece");


    borrar(s, -5);
    borrar(s, 5);
    borrar(s, 15);
    borrar(s, 21);
    cout << "Largo del multiset luego de borrar otro elemento: " << cantidadElementos(s) << endl;



    while (!esVacio(s)) {
        int e = elemento(s);
        FrameworkA1::agregarOrd(lord, e);
        borrar(s, e);
    }

    salida = FrameworkA1::serializar(lord);
    FrameworkA1::destruir(lord);
    cout << "Multiset luego de haber borrado 2 elementos: " << salida << endl;
    delete[] salida;
    pruebaConcreta->ver3("Borro algunos elementos");

    destruir(s);
    destruir(s2);
    destruir(clonS);
    destruir(unionS);
    destruir(interS);
    destruir(difS);

    pruebaConcreta->ver3("Libero memoria");
}

