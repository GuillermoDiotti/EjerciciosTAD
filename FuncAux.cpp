#include "FuncAux.h"

//#ifndef FUNCAUX_CPP
//#define FUNCAUX_CPP

struct NodoListaIntAux {
	int dato;
	bool esVacio;
	NodoListaIntAux *sig;
	NodoListaIntAux(int x, bool vacio) : dato(x), esVacio(vacio), sig(NULL) {}
	NodoListaIntAux() : dato(-1), esVacio(true), sig(NULL) {} //constructor por defecto
};

/*
struct NodoABNivel {
	int dato;
	int nivel;
	NodoABNivel *izq;
	NodoABNivel *der;
	NodoABNivel() : dato(-1), izq(NULL), der(NULL), nivel(-1) {}
	NodoABNivel(int x, int n) : dato(x), izq(NULL), der(NULL), nivel(n) {}
};
*/

namespace FrameworkA1
{
	void append(char *&str, const char *strA);
	char *intToStr(int i);
	unsigned int cantDatos(NodoListaInt* l);
	unsigned int cantDatos(NodoListaIntAux* l);
	NodoABInt *convertListaAuxToAB(NodoListaIntAux* & l, int &largo);
	NodoAGInt *convertListaAuxToAG(NodoListaIntAux* & l, int &largo);
	void destruir(NodoListaIntAux*& l);
	void agregarFin(NodoListaInt *&l, int val);
	void abALista(NodoABInt *a, NodoListaInt *&l);
	unsigned int pow2(unsigned pwr);
	unsigned int altura(NodoABInt* a);
	void imprimirListaAux(NodoListaInt *l);
	char *abAStrAux(NodoABInt *a);
	void borrarPpio(NodoListaIntAux* & l);
	void listaAVector(NodoListaInt *l, int *vec, int &pos);
	int *listaAVectorOrdenado(NodoListaInt *l, int &largoVec);
	char *agAStrAux(NodoAGInt *a);
	void abAVector(NodoABInt *a, int *vec, int &pos);
	void agAVector(NodoAGInt *a, int *vec, int &pos);
	int *agAVectorOrdenado(NodoAGInt *a, int &largoVec);
	NodoListaIntAux* splitStringToListaAux(char *stringDatos);
	void convertListaAuxToAG(NodoListaIntAux* &l, NodoAGInt *&a, int &largo);
	void recorroABYCargoVector(NodoABInt *a, NodoABInt **vec, unsigned int posVecActual, unsigned int largoVec);
	char *serializar(int i);
	void serializarAux(NodoListaInt *l, char *&str);
	NodoAGInt* parsearAG(char *stringDatos, int &largo);
	/*
	PRE:
	POS:ordena el vector recibido
	*/
	void ordenarVector(int *vec, int largoVec);
	/*
	PRE:
	POS:devuelve un vector ordenado con los datos del arbol a 
	*/
	int *abAVectorOrdenado(NodoABInt *a, int &largoVec);

	/*
	PRE: 
	POS: concatena dest y src, poniendo src al final de dest. Aumenta el tamaño  de dest.
	*/
	void concat(char *&dest, const char *src);
	/*
	PRE: debe recibir un vector de strings del largo indicado
	POS: imprime el vector vec
	*/
	void imprimirVectorStrings(char** vec, int largo);
	/*
	PRE: debe recibir una matriz que debe tener las columnas y filas indicadas
	POS: imprime matriz mat
	*/
	void imprimirMatrizInts(int** mat, int columnas, int filas);
	/*
	PRE:
	POS:Imprime lista l
	*/
	void imprimirLista(NodoListaInt *l);

	/*
	PRE: todos los caracteres de stringDatos son enteros. Formato: "1,4,7,2"
	POS: devuelve un vector con los enteros de stringDatos y retorna la cantidad de datos en el parametro largo
		 El vector retornado debe ser destruido
	*/
	int *parsearVectorInt(char *stringDatos, int &largo);
	/*
	PRE: todos los caracteres de stringDatos son strings. Formato: "'str1','str2','str3'"
	POS: devuelve un vector de strings con los datos de stringDatos y retorna la cantidad de datos en el parametro largo
		 El vector retornado y cada uno de los strings debe ser destruido
	*/
	char **parsearVectorStrings(char *stringDatos, int &largo);

	/*
	PRE: Formato ""str1","str2","str3","str4""
	POS: devuelve una lista con los substrings de stringDatos y el largo
	*/
	NodoListaString* parsearListaStr(char* stringDatos, int& largo);
	/*
	PRE: todos los caracteres de stringDatos son enteros. Formato "2,4,1,8"
	POS: devuelve una lista con los enteros de stringDatos y el largo
	*/
	NodoListaInt *parsearLista(char *stringDatos, int &largo);
	/*
	PRE: los caracteres de stringDatos son enteros o #. # indica fin de la rama. Formato "2,#,8,1,2"
	POS: devuelve una arbol con los datos de stringDatos y la cantidad de elementos
	*/
	NodoABInt* parsearAB(char *stringDatos, int &largo);
	/*
	PRE:
	POS: devuelve una nueva lista, igual a l
	*/
	NodoListaInt *copiarLista(NodoListaInt *l);
	/*
	PRE:
	POS: devuelve la altura de a
	*/
	unsigned int altura(NodoABInt* a);
	/*
	PRE:
	POS: devuelve cantidad de nodos de a
	*/
	unsigned int cantDatos(NodoABInt* a);
	/*
	PRE:
	POS: retorna el maximo de un AB no vacio
	*/ 
	int maxAB(NodoABInt *a);
	/*
	PRE:
	POS: retorna el minimo de un AB no vacio
	*/ 
	int minAB(NodoABInt *a);
	unsigned int cantDatos(NodoAGInt* a);

}


void FrameworkA1::imprimirVectorStrings(char** vec, int largo){
	if(vec!=NULL){
		for(int i=0; i < largo; i++){
			int j = 0;
			while(vec[i][j]!='\0') {
				cout<<vec[i][j];
				j++;
			} 
			cout<<" ";
		}
		cout << endl;
	}else
		cout<<"Array Vacio!"<<endl;
}

void FrameworkA1::imprimirMatrizInts(int** mat, int columnas, int filas){
	if(mat!=NULL){
		for(int f=0; f < filas; f++){
			for(int c=0; c < columnas; c++){
				cout<<mat[c][f] <<"\t";
			} 
			cout<<endl;
		}
	}else
		cout<<"Matriz Vacia!"<<endl;
}








void FrameworkA1::imprimirListaAux(NodoListaInt *l) {
	if (l == NULL)
		return;
	cout << l->dato;
	if (l->sig != NULL)
		cout << ",";
	imprimirListaAux(l->sig);
}

void FrameworkA1::imprimirLista(NodoListaInt *l) {
	cout << "{";
	imprimirListaAux(l);
	cout << "}";
}

void FrameworkA1::imprimirEsperadoVsRecibido(NodoListaInt *esp, NodoListaInt *rec) {
	cout << "\tParametros de entrada: FrameworkA1::ver ARCHIVO DE PRUEBAS" << endl;
	cout << "\tSe esperaba: ";
	imprimirLista(esp);
	cout << endl;
	cout << "\tSe recibio:  ";
	imprimirLista(rec);
	cout << endl;
}

void FrameworkA1::imprimirEsperadoVsRecibido(NodoListaInt *esp, NodoListaInt *rec, const char *inputParametersFormated) {
	cout << "\tParametros de entrada: " << inputParametersFormated << endl;
	cout << "\tSe esperaba: ";
	imprimirLista(esp);
	cout << endl;
	cout << "\tSe recibio:  ";
	imprimirLista(rec);
	cout << endl;
}

void FrameworkA1::imprimirEsperadoVsRecibido(NodoABInt *esp, NodoABInt *rec, const char *inputParametersFormated) {
	char* esperado = FrameworkA1::serializar(esp);
	char* recibido = FrameworkA1::serializar(rec);
	cout << "\tParametros de entrada: " << inputParametersFormated << endl;
	cout << "\tSe esperaba: " << esperado << endl;
	cout << "\tSe recibio:  " << recibido << endl;
	delete[] esperado;
	delete[] recibido;
}

void FrameworkA1::imprimirEsperadoVsRecibido(NodoAGInt *esp, NodoAGInt *rec, const char *inputParametersFormated) {
	char* esperado = FrameworkA1::serializar(esp);
	char* recibido = FrameworkA1::serializar(rec);
	cout << "\tParametros de entrada: " << inputParametersFormated << endl;
	cout << "\tSe esperaba: " << esperado << endl;
	cout << "\tSe recibio:  " << recibido << endl;
	delete[] esperado;
	delete[] recibido;
}

void FrameworkA1::imprimirEsperadoVsRecibido(bool esp, bool rec, const char *inputParametersFormated) {
	char* esperado = FrameworkA1::serializar(esp);
	char* recibido = FrameworkA1::serializar(rec);
	cout << "\tParametros de entrada: " << inputParametersFormated << endl;
	cout << "\tSe esperaba: " << esperado << endl;
	cout << "\tSe recibio:  " << recibido << endl;
	delete[] esperado;
	delete[] recibido;
}

void FrameworkA1::imprimirEsperadoVsRecibido(int esp, int rec, const char *inputParametersFormated) {
	char* esperado = FrameworkA1::serializar(esp);
	char* recibido = FrameworkA1::serializar(rec);
	cout << "\tParametros de entrada: " << inputParametersFormated << endl;
	cout << "\tSe esperaba: " << esperado << endl;
	cout << "\tSe recibio:  " << recibido << endl;
	delete[] esperado;
	delete[] recibido;
}

void FrameworkA1::imprimirEsperadoVsRecibido(const char *esp, const char *rec, const char *inputParametersFormated) {
	cout << "\tParametros de entrada: " << inputParametersFormated << endl;
	cout << "\tSe esperaba: " << esp << endl;
	if (rec != NULL)
		cout << "\tSe recibio:  " << rec << endl;
	else
		cout << "\tSe recibio:  " << "NULL" << endl;
}

void FrameworkA1::ver(bool res, int &correctos, int &error) {
	if (res == true)
		correctos++;
	else
		error++;
}





//
//// IMPRIME LOS ELEMENTOS DEL ARBOL POR NIVELES CON EL #. TODO: quitar los # del final (pero que quede siempre par)
//void imprimirABAux(NodoABInt *a) {
//	if(a==NULL){
//		return;
//	}
//	ColaArray c = crearColaArray(pow2(altura(a)+1) - 1); // calculo lugar para todos los nodos del arbol como si fuera completo mas un nivel extra por los #
//	encolar(c, a);
//	while(!esVacia(c)){
//		NodoABInt* nodo = (NodoABInt*)frente(c);
//		if (nodo == NULL)
//			cout << "#";
//		else
//			cout << nodo->dato;
//		
//		desencolar(c);
//		if (nodo != NULL) {
//		//if (nodo->izq != NULL) {
//			encolar(c, nodo->izq);
//		//}
//		//if (nodo->der != NULL) {
//			encolar(c, nodo->der);
//		//}
//		}
//		if (!esVacia(c)) 
//			cout << ",";
//	}	
//	FrameworkA1::destruir(c);
//	return;
//}


void FrameworkA1::recorroABYCargoVector(NodoABInt *a, NodoABInt **vec, unsigned int posVecActual, unsigned int largoVec) {
	if (a==NULL)
		return;
	recorroABYCargoVector(a->izq, vec, 2*posVecActual+1, largoVec);
	assert(posVecActual < largoVec);
	vec[posVecActual] = a;
	recorroABYCargoVector(a->der, vec, 2*posVecActual+2, largoVec);
}

void FrameworkA1::imprimirABGrande(NodoABInt *a) {
//	imprimirAB(a);
	if (a == NULL) {
		cout << "Arbol vacio" << endl;
		return;
	}

	unsigned int alt = altura(a);
	unsigned int largoVec = pow2(alt) - 1; 
	NodoABInt **vec = new NodoABInt*[largoVec];
	for (unsigned int i=0; i<largoVec; i++)
		vec[i] = NULL;
	recorroABYCargoVector(a, vec, 0, largoVec);

	//for (unsigned int i=0; i<largoVec; i++) {
	//	if (vec[i] == NULL)
	//		cout << "# ";
	//	else
	//		cout << vec[i]->dato << " ";
	//}
	//cout << endl;

	//unsigned int cantNodosUltimoNivel = pow2(alt-1);

	for (unsigned int i=1; i<=alt; i++) {
		unsigned int posInicialNivel = pow2(i-1) - 1; 
		unsigned int cantNodosNivel = pow2(i-1);
		unsigned int espacios;
		if (alt == i) {
			espacios = 0;
			cout << " ";
		}
		else
			espacios = pow2(alt - i - 1);
		//for (unsigned int i=0; i<espacios; i++) {
		//	cout << setw(3) << "";
		//}
		for (unsigned int j=posInicialNivel; j<posInicialNivel+cantNodosNivel; j++) {
			for (unsigned int k=0; k<espacios; k++)
				cout << setw(3) << "";
			assert(j < largoVec);
#pragma warning(suppress: 6385)
			if (vec[j] == NULL)
				cout << setw(3) << "#";
			else
				cout << setw(3) << vec[j]->dato;
			//for (unsigned int i=0; i<espacios; i++)
			//	cout << setw(3) << "";
		}
		cout << endl;
	}

}



// PRE: 
// POS: RETORNA STRING CON LOS ELEMENTOS DEL ARBOL POR NIVELES CON EL #. NOTA: tambien quita los # del final pero lo deja siempre par)
char *FrameworkA1::abAStrAux(NodoABInt *a) {
	int numConsecutivos = 0, cantElementos = 0;
	char *ret = copioString("");
	if(a==NULL){
		return ret;
	}

	ColaArray c = crearColaArray(pow2(altura(a)+1) - 1); // calculo lugar para todos los nodos del arbol como si fuera completo mas un nivel extra por los #
	ColaArray salida = crearColaArray(pow2(altura(a)+1) - 1); // calculo lugar para todos los nodos del arbol como si fuera completo mas un nivel extra por los #
	encolar(c, a);
	while(!esVacia(c)){
		NodoABInt* nodo = (NodoABInt*)frente(c);
		if (nodo == NULL) {
			char* aux = copioString("#");
			encolar(salida, aux);
			numConsecutivos++;
			cantElementos++;
		}
		else {
			char* aux = intToStr(nodo->dato);
			encolar(salida, aux);
			numConsecutivos = 0;
			cantElementos++;
		}
		
		desencolar(c);
		if (nodo != NULL) {
		//if (nodo->izq != NULL) {
			encolar(c, nodo->izq);
		//}
		//if (nodo->der != NULL) {
			encolar(c, nodo->der);
		//}
		}
	}	
	destruir(c);

	if (numConsecutivos % 2 != 0) 
		numConsecutivos--;
	int cantidadACopiar = cantElementos - numConsecutivos;
	// concateno en el string a retornar
	concat(ret, "{");
	for (int i=0; i<cantidadACopiar; i++) {
		char* aux = (char*)frente(salida);
		desencolar(salida);
		concat(ret, aux);
		delete [] aux;
		if (i < cantidadACopiar-1) {
			concat(ret, ",");
		}
	}
	while (!esVacia(salida)) { // solo quedan #
		char* aux = (char*)frente(salida);
		assert(aux != NULL && aux[0] == '#');
		desencolar(salida);
		delete[] aux;
	}
	concat(ret, "}");
	destruir(salida);
	return ret;
}



// PRE: 
// POS: RETORNA STRING CON LOS ELEMENTOS DEL AG
char *FrameworkA1::agAStrAux(NodoAGInt *a) {
	char *ret = copioString("");
	if(a==NULL){
		append(ret, ",#");
		return ret;
	}
	append(ret, ",");
	char *aux = intToStr(a->dato);
	append(ret, aux);
	char *ph = agAStrAux(a->ph);
	append(ret, ph);
	delete [] ph;
	char *sh = agAStrAux(a->sh);
	append(ret, sh);
	delete [] sh;
	return ret;
}



unsigned int FrameworkA1::pow2( unsigned pwr ) {
   return pwr==0? 1 : 2*pow2(pwr-1);
}

char *FrameworkA1::copioString(const char *str) {
	std::size_t len = strlen(str) + 1;
	char *ret = new char[len];
	strcpy_s(ret, len, str);
	return ret;
}

void FrameworkA1::append(char *&str, const char *strA)
{
	std::size_t l = strlen(str) + strlen(strA) + 1;
	char *ret = new char[l];
	strcpy_s(ret, l, str);
	strcat_s(ret, l, strA);
	delete [] str;
	str = ret;
}

char *FrameworkA1::intToStr(int i) {
	unsigned int len = 11 + 1; // int min: -2147483648 max: 2147483647
	char *ret = new char[len];
	_itoa_s(i, ret, len, 10);
	char *ret2 = copioString(ret); // reservo la memoria justa
	delete [] ret;
	return ret2;
}

void FrameworkA1::concat(char *&dest, const char *src) {
	std::size_t retL = strlen(dest) + strlen(src) + 1;
	char *ret = new char[retL];
	strcpy_s(ret, retL, dest);
	strcat_s(ret, retL, src);
	delete [] dest;
	dest = ret;
}

NodoListaInt * FrameworkA1::copiarLista(NodoListaInt *l) {
	if (l == NULL)
		return NULL;
	NodoListaInt *n = new NodoListaInt(l->dato);
	n->sig = copiarLista(l->sig);
	return n;
}

void FrameworkA1::borrarPpio(NodoListaIntAux* & l) {
	NodoListaIntAux* temp = l;
	l = l->sig;
	delete temp;
}

void FrameworkA1::agregarFin(NodoListaInt *&l, int val)
{
    if (l == NULL)
        l = new NodoListaInt(val);
    else
        agregarFin(l->sig, val);
}

void FrameworkA1::agregarOrd(NodoListaInt*& l, int val)
{
	if (l == NULL || l->dato >= val) {
		NodoListaInt* aux = new NodoListaInt(val);
		aux->sig = l;
		l = aux;
	}
	else
		agregarOrd(l->sig, val);
}


void FrameworkA1::ordenarVector(int *vec, int largoVec) {
	for (int i = 0; i < largoVec; i++) {
		for (int j = 0; j < largoVec - 1; j++) {
			if (vec[j] > vec[j + 1]) {
				int aux = vec[j];
				vec[j] = vec[j + 1];
				vec[j + 1] = aux;
			}
		}
	}
}

void FrameworkA1::listaAVector(NodoListaInt *l, int *vec, int &pos)
{
    if (l != NULL) {
        vec[pos++] = l->dato;
		listaAVector(l->sig, vec, pos);
    }
}

int *FrameworkA1::listaAVectorOrdenado(NodoListaInt *l, int &largoVec) {
	largoVec = cantDatos(l);
	int *vec = new int[largoVec];
	int pos = 0;
	listaAVector(l, vec, pos);
	ordenarVector(vec, largoVec);
	return vec;
}

void FrameworkA1::abAVector(NodoABInt *a, int *vec, int &pos)
{
    if (a != NULL) {
        abAVector(a->izq, vec, pos);
        vec[pos++] = a->dato;
        abAVector(a->der, vec, pos);
    }
}

int *FrameworkA1::abAVectorOrdenado(NodoABInt *a, int &largoVec) {
	largoVec = cantDatos(a);
	int *vec = new int[largoVec];
	int pos = 0;
	abAVector(a, vec, pos);
	ordenarVector(vec, largoVec);
	return vec;
}

void FrameworkA1::agAVector(NodoAGInt *a, int *vec, int &pos)
{
    if (a != NULL) {
        agAVector(a->ph, vec, pos);
        vec[pos++] = a->dato;
        agAVector(a->sh, vec, pos);
    }
}

int *FrameworkA1::agAVectorOrdenado(NodoAGInt *a, int &largoVec) {
	largoVec = cantDatos(a);
	int *vec = new int[largoVec];
	int pos = 0;
	agAVector(a, vec, pos);
	ordenarVector(vec, largoVec);
	return vec;
}



unsigned int FrameworkA1::cantDatos(NodoListaIntAux* l) {
	if (l == NULL)
		return 0;
	return cantDatos(l->sig) + 1;
}

unsigned int FrameworkA1::cantDatos(NodoListaInt* l) {
	if (l == NULL)
        return 0;
    return cantDatos(l->sig) + 1;
}

unsigned int FrameworkA1::cantDatos(NodoABInt* a) {
	if (a == NULL)
        return 0;
    return cantDatos(a->izq) + cantDatos(a->der) + 1;
}

unsigned int FrameworkA1::cantDatos(NodoAGInt* a) {
	if (a == NULL)
        return 0;
    return cantDatos(a->ph) + cantDatos(a->sh) + 1;
}

unsigned int FrameworkA1::altura(NodoABInt* a) {
    if (a == NULL)
        return 0;
    return max(altura(a->izq), altura(a->der)) + 1;
}











void FrameworkA1::destruir(char** vec, int largo){
	if(vec!=NULL){
		for(int i=0; i < largo; i++){
			delete[] vec[i];
		}
		delete[] vec;
	}
}

void FrameworkA1::destruir(int** mat, int columnas){
	if(mat!=NULL){
		for(int i=0; i < columnas; i++){
			delete [] mat[i];
		}
		delete mat;
	}else
		cout<<"Matriz Vacia!"<<endl;
}

void FrameworkA1::destruir(int* vec) {
	if(vec!=NULL){
		delete [] vec;
	}
}

void FrameworkA1::destruir(NodoListaInt *&l) {
    while (l!=NULL) {
        NodoListaInt *aux = l;
        l = l->sig;
        delete aux;
    }
}

void FrameworkA1::destruir(NodoListaString*& l) {
	while (l != NULL) {
		NodoListaString* aux = l;
		l = l->sig;
		delete [] aux->dato;
		delete aux;
	}
}

void destruir(NodoListaIntAux *&l) {
    while (l!=NULL) {
        NodoListaIntAux *aux = l;
        l = l->sig;
        delete aux;
    }
}

void FrameworkA1::destruir(NodoABInt *&a) {
    if (a!=NULL) {
        FrameworkA1::destruir(a->izq);
        FrameworkA1::destruir(a->der);
        delete a;
		a = NULL;
    }
}

void FrameworkA1::destruir(NodoAGInt *&a) {
    if (a!=NULL) {
        FrameworkA1::destruir(a->ph);
        FrameworkA1::destruir(a->sh);
        delete a;
		a = NULL;
    }
}



bool FrameworkA1::sonIguales(const char* resultado, const char* esperado){
	if(resultado==NULL && esperado==NULL)
		return true;

	if(resultado==NULL || esperado==NULL)
		return false;
	
	return strcmp(resultado, esperado) == 0;
}

bool FrameworkA1::sonIguales(int* resultado, int* esperado, int largo){
	if(resultado==NULL && esperado==NULL)
		return true;

	if(resultado==NULL || esperado==NULL)
		return false;

	for(int i=0; i < largo; i++){
		if (resultado[i]!=esperado[i])
			return false; 
	}	
	return true;
}

bool FrameworkA1::sonIguales(int** resultado, int** esperado,int columnas,int filas){
	if(resultado==NULL && esperado==NULL)
		return true;

	if(resultado==NULL || esperado==NULL)
		return false;

	for(int f=0; f < filas; f++){
		for(int c=0; c < columnas; c++){
			if (resultado[c][f]!=esperado[c][f])
				return false;
		} 
	}	
	return true;
}

bool FrameworkA1::sonIguales(char** resultado, char** esperado, int cantStr){
	if(resultado==NULL && esperado==NULL)
		return true;

	if(resultado==NULL || esperado==NULL)
		return false;

	for(int f=0; f < cantStr; f++){
		if(strcmp(resultado[f], esperado[f]) != 0) 
			return false;
	}
	return true;
}

bool FrameworkA1::sonIguales(char** resultado, char** esperado, int columnas, int filas) {
	if(resultado==NULL && esperado==NULL)
		return true;

	if(resultado==NULL || esperado==NULL)
		return false;

	for(int f=0; f < filas; f++){
		for(int c=0; c < columnas; c++){
			if (resultado[c][f]!=esperado[c][f])
				return false;
		} 
	}	
	return true;
}

bool FrameworkA1::sonIgualesDatosForma(NodoListaInt *l1, NodoListaInt *l2) {
    if (l1 == NULL && l2 == NULL)
        return true;
    if (l1 == NULL || l2 == NULL)
        return false;
    if (l1->dato != l2->dato)
        return false;
    return sonIgualesDatosForma(l1->sig, l2->sig);
}

bool FrameworkA1::sonIgualesDatos(NodoListaInt *l1, NodoListaInt *l2) {
	int largo1, largo2;
	int *v1 = listaAVectorOrdenado(l1, largo1);
	int *v2 = listaAVectorOrdenado(l2, largo2);
	bool ret;
	if (largo1 != largo2)
		ret = false;
	else
		ret = sonIguales(v1, v2, largo1);
	delete [] v1;
	delete [] v2;
	return ret;
}

bool FrameworkA1::sonIgualesDatosForma(NodoABInt *a1,NodoABInt *a2) {
	if (a1 == NULL && a2 == NULL)
        return true;
    if (a1 == NULL || a2 == NULL)
        return false;
    if (a1->dato != a2->dato)
        return false;
    return sonIgualesDatosForma(a1->izq, a2->izq) && sonIgualesDatosForma(a1->der, a2->der);
}

bool FrameworkA1::sonIgualesDatos(NodoABInt *a1, NodoABInt *a2) {
	int largo1, largo2;
	int *v1 = abAVectorOrdenado(a1, largo1);
	int *v2 = abAVectorOrdenado(a2, largo2);
	bool ret;
	if (largo1 != largo2)
		ret = false;
	else
		ret = sonIguales(v1, v2, largo1);
	delete [] v1;
	delete [] v2;
	return ret;
}

bool FrameworkA1::sonIgualesDatosForma(NodoAGInt *a1,NodoAGInt *a2) {
	if (a1 == NULL && a2 == NULL)
        return true;
    if (a1 == NULL || a2 == NULL)
        return false;
    if (a1->dato != a2->dato)
        return false;
    return sonIgualesDatosForma(a1->ph, a2->ph) && sonIgualesDatosForma(a1->sh, a2->sh);
}

bool FrameworkA1::sonIgualesDatos(NodoAGInt *a1, NodoAGInt *a2) {
	int largo1, largo2;
	int *v1 = agAVectorOrdenado(a1, largo1);
	int *v2 = agAVectorOrdenado(a2, largo2);
	bool ret;
	if (largo1 != largo2)
		ret = false;
	else
		ret = sonIguales(v1, v2, largo1);
	delete [] v1;
	delete [] v2;
	return ret;
}

bool FrameworkA1::compartenMemoria(char** vec1, int largoVec1, char** vec2, int largoVec2) {
	if (vec1 == NULL || vec2 == NULL)
		return false;
	for(int i1=0; i1<largoVec1; i1++) {
		for(int i2=0; i2<largoVec2; i2++) {
			if (vec1[i1] == vec2[i2]) {
				return true;
			}
		}
	}
	return false;
}

bool FrameworkA1::compartenMemoria(NodoListaInt *l1, NodoListaInt *l2) {
	NodoListaInt *l1aux = l1;
	NodoListaInt *l2aux = l2;
	while (l1aux != NULL) {
		l2aux = l2;
		while (l2aux != NULL) {
			if (l1aux == l2aux) return true;
			l2aux = l2aux->sig;
		}
		l1aux = l1aux->sig;
	}
	return false;
}

bool FrameworkA1::compartenMemoria(int *vec1, int *vec2, int largoVec1, int largoVec2) {
	if (vec1 == NULL || vec2 == NULL)
	{
		return false;
	}
	int contador1 = 0;
	int contador2 = 0;
	while (contador1 < largoVec1)
	{
		contador2 = 0;
		while (contador2 < largoVec2)
		{
			if (&vec1[contador1] == &vec2[contador2]) return true;
			contador2++;
		}
		contador1++;
	}
	return false;
}

void abAVectorPunteros(NodoABInt *a1, NodoABInt **vec, unsigned int &pos) {
	if (a1 != NULL) {
		vec[pos++] = a1;
		abAVectorPunteros(a1->izq, vec, pos);
		abAVectorPunteros(a1->der, vec, pos);
	}
}

void agAVectorPunteros(NodoAGInt *a1, NodoAGInt **vec, unsigned int &pos) {
	if (a1 != NULL) {
		vec[pos++] = a1;
		agAVectorPunteros(a1->ph, vec, pos);
		agAVectorPunteros(a1->sh, vec, pos);
	}
}

bool FrameworkA1::compartenMemoria(NodoABInt *a1, NodoABInt *a2) {
	unsigned int pos1 = 0, pos2 = 0;
	unsigned int cant1 = cantDatos(a1);
	unsigned int cant2 = cantDatos(a2);
	NodoABInt **vec1 = new NodoABInt *[cant1];
	NodoABInt **vec2 = new NodoABInt *[cant2];
	abAVectorPunteros(a1, vec1, pos1);
	abAVectorPunteros(a2, vec2, pos2);

	for (unsigned int i1=0; i1<cant1; i1++) {
		for (unsigned int i2=0; i2<cant2; i2++) {
			if (vec1[i1] == vec2[i2]) return true;
		}
	}
	return false;
}

bool FrameworkA1::compartenMemoria(NodoAGInt *a1, NodoAGInt *a2) {
	unsigned int pos1 = 0, pos2 = 0;
	unsigned int cant1 = cantDatos(a1);
	unsigned int cant2 = cantDatos(a2);
	NodoAGInt **vec1 = new NodoAGInt *[cant1];
	NodoAGInt **vec2 = new NodoAGInt *[cant2];
	agAVectorPunteros(a1, vec1, pos1);
	agAVectorPunteros(a2, vec2, pos2);

	for (unsigned int i1=0; i1<cant1; i1++) {
		for (unsigned int i2=0; i2<cant2; i2++) {
			if (vec1[i1] == vec2[i2]) return true;
		}
	}
	return false;
}

// Retorna el maximo de un AB no vacio
int FrameworkA1::maxAB(NodoABInt *a) 
{
	if (a->izq == NULL && a->der == NULL)
		return a->dato;
	if (a->izq == NULL)
		return max(maxAB(a->der), a->dato);
	if (a->der == NULL)
		return max(maxAB(a->izq), a->dato);
	int maxIzq2 = max(maxAB(a->izq), a->dato);
	int maxDer2 = max(maxAB(a->der), a->dato);
	return max(maxIzq2, maxDer2);
}

// Retorna el minimo de un AB no vacio
int FrameworkA1::minAB(NodoABInt *a) 
{
	if (a->izq == NULL && a->der == NULL)
		return a->dato;
	if (a->izq == NULL)
		return min(minAB(a->der), a->dato); 
	if (a->der == NULL)
		return min(minAB(a->izq), a->dato);
	int minIzq2 = min(minAB(a->izq), a->dato);
	int minDer2 = min(minAB(a->der), a->dato);
	return min(minIzq2, minDer2);
}

bool FrameworkA1::esABB(NodoABInt *a) 
{
	if (a == NULL) 
		return true;
	if (a->izq != NULL && maxAB(a->izq) > a->dato)
		return false;
	if (a->der != NULL && minAB(a->der) < a->dato)
		return false;
	return esABB(a->izq) && esABB(a->der);
}




int *FrameworkA1::parsearVectorInt(char *stringDatos, int &largo) {
	NodoListaInt *l = parsearLista(stringDatos, largo);
	largo = cantDatos(l);
	if (largo == 0) {
		destruir(l);
		return NULL;
	}
	int *ret = new int[largo];
	NodoListaInt *aux = l;
	for (int i=0; i<largo; i++) {
		ret[i] = aux->dato;
		aux = aux->sig;
	}
	destruir(l);
	return ret;
}

char **FrameworkA1::parsearVectorStrings(char *stringDatos, int &largo) {
	std::size_t largoStr = strlen(stringDatos);
	char *stringDatosC = FrameworkA1::copioString(stringDatos);
	int cant = 0;
	for(unsigned int i=0; i<largoStr; i++) {
		if (stringDatosC[i] == '\'') {
			cant++;
			for(i++; i<largoStr; i++) {
				if (stringDatosC[i] == '\'') {
					break;
				}
			}
		}
	}
	largo = cant;
	if (largo == 0) {
		delete[] stringDatosC;
		return NULL;
	}
	char** ret = new char*[largo];
	int pos = 0;
	for(unsigned int i=0; i<largoStr; i++) {
		if (stringDatosC[i] == '\'') {
			char *ini = &stringDatosC[i+1];
			for(i++; i<largoStr; i++) {
				if (stringDatosC[i] == '\'') {
					stringDatosC[i] = '\0';
					ret[pos++] = FrameworkA1::copioString(ini);
					break;
				}
			}
		}
	}
	delete [] stringDatosC;
	return ret;
}

NodoListaString* FrameworkA1::parsearListaStr(char* stringDatos, int& largo) {
	char* str = FrameworkA1::copioString(stringDatos);
	unsigned long len = strlen(str);
	unsigned int startPos = 0;
	bool started = false;
	NodoListaString* ret = NULL;
	NodoListaString* ult = NULL;

	for (unsigned int i = 0; i < len; i++) {
		if (str[i] == '\"') {
			if (!started) {
				startPos = i + 1;
				started = true;
			}
			else {
				str[i] = '\0';
				started = false;
				char* token = &(str[startPos]);
				unsigned long tokenLen = strlen(str) + 1;
				char* tokenCpy = new char[tokenLen];
				strcpy_s(tokenCpy, tokenLen, token);

				NodoListaString* n = new NodoListaString;
				n->dato = tokenCpy;
				if (ret == NULL) {
					ret = ult = n;
				}
				else {
					ult->sig = n;
					ult = n;
				}
			}
		}
	}
	assert(!started);
	delete[] str;
	return ret;
}

NodoListaInt *FrameworkA1::parsearLista(char *stringDatos, int &largo) {
	char *stringDatosC = FrameworkA1::copioString(stringDatos);
	NodoListaInt *ret = NULL;
	NodoListaInt *ant = NULL;
	largo = 0;
	char *next_token1 = NULL;
	char *token1 = strtok_s(stringDatosC, ", ", &next_token1);
	while (token1 != NULL) {
		int val = atoi(token1);
		largo++;
		NodoListaInt *n = new NodoListaInt(val);
		if (ret == NULL) {
			ret = ant = n;
		}
		else {
			ant->sig = n;
			ant = n;
		}
		token1 = strtok_s(NULL, ", ", &next_token1);
	}
	delete [] stringDatosC;
	return ret;
}

NodoListaIntAux* FrameworkA1::splitStringToListaAux(char *stringDatos) {
	char *stringDatosC = FrameworkA1::copioString(stringDatos);
	NodoListaIntAux *ret = NULL;
	NodoListaIntAux *ant = NULL;
	char *next_token1 = NULL;
	char *token1 = strtok_s(stringDatosC, ", ", &next_token1);
	while (token1 != NULL) {
		NodoListaIntAux *n;
		if(token1[0] == '#'){
			n = new NodoListaIntAux(-1, true);
		}else{
			int val = atoi(token1);
			n = new NodoListaIntAux(val, false);
		}
		if (ret == NULL) {
			ret = ant = n;
		}
		else {
			ant->sig = n;
			ant = n;
		}
		token1 = strtok_s(NULL, ", ", &next_token1);
	}
	delete [] stringDatosC;
	return ret;
}

NodoABInt *FrameworkA1::convertListaAuxToAB(NodoListaIntAux* & l, int &largo){
	ColaArray c = crearColaArray(cantDatos(l));
	NodoABInt* a = NULL;
	if(l==NULL || l->esVacio){
		destruir(c);
		largo = 0;
		return a;
	}
	largo = 1;
	a = new NodoABInt(l->dato);
	encolar(c, a);
	borrarPpio(l);
	while(!esVacia(c)){
		NodoABInt* nodo = (NodoABInt*)frente(c);
		desencolar(c);
		if(l!=NULL){
			if (!l->esVacio) {
				largo++;
				nodo->izq = new NodoABInt(l->dato);
				encolar(c, nodo->izq);
			}
			borrarPpio(l);
		}
		if(l!=NULL){
			if (!l->esVacio) {
				largo++;
				nodo->der = new NodoABInt(l->dato);
				encolar(c, nodo->der);
			}
			borrarPpio(l);
		}
	}	
	destruir(c);
	return a;
}

NodoAGInt *FrameworkA1::convertListaAuxToAG(NodoListaIntAux* & l, int &largo){
	if (l == NULL)
		return NULL;

	NodoAGInt* a = NULL;

	
	return a;
}

void FrameworkA1::convertListaAuxToAG(NodoListaIntAux* &l, NodoAGInt *&a, int &largo){
	if (l == NULL)
	{
		a = NULL;
		return;		
	}

	if (l->esVacio)
	{
		a = NULL;
		borrarPpio(l);
		return;
	}

	a = new NodoAGInt(l->dato);
	largo++;
	borrarPpio(l);
	convertListaAuxToAG(l, a->ph, largo);
	convertListaAuxToAG(l, a->sh, largo);
}

NodoABInt* FrameworkA1::parsearAB(char *stringDatos, int &largo) {
	NodoListaIntAux *listaAB = splitStringToListaAux(stringDatos);
	NodoABInt* ret = convertListaAuxToAB(listaAB, largo);
	return ret;
}

NodoAGInt* FrameworkA1::parsearAG(char *stringDatos, int &largo) {
	NodoListaIntAux *listaAux = splitStringToListaAux(stringDatos);
	largo = 0;
	NodoAGInt* ret;
	convertListaAuxToAG(listaAux, ret, largo);
	return ret;
}

void* FrameworkA1::parsearColeccion(const char *stringDatos, int &largo) {
	// detecto tipo de dato
	NodoABInt *a;
	NodoAGInt *ag;
	NodoListaInt* l;
	NodoListaString* lStr;
	char **vecStr;
	int *vecInt;

	char *stringDatosC = copioString(stringDatos);
	unsigned long len = strlen(stringDatosC) + 1;

	bool contieneStr = false;
	for (unsigned int i = 0; i < len; i++) {
		if (stringDatosC[i] == '\"') {
			contieneStr = true;
		}
	}

	char* ini = &stringDatosC[1];
	stringDatosC[len - 2] = '\0';

	switch (stringDatos[0]) {
	case '{': // arbol
		assert(!contieneStr); // Arboles con datos string no implementado
		if (stringDatos[1] != '{') { //AB
			a = parsearAB(ini, largo);
			delete [] stringDatosC;
			return a;
		}
		else // AG
		{
			ini++;
			stringDatosC[strlen(stringDatosC)-1] = '\0';
			ag = parsearAG(ini, largo);
			delete [] stringDatosC;
			return ag;
		}
	case '(': // lista
		if (!contieneStr) {
			l = parsearLista(ini, largo);
			delete [] stringDatosC;
			return l;
		}
		else {
			lStr = parsearListaStr(ini, largo);
			delete [] stringDatosC;
			return lStr;
		}
	case '[': // vector
		assert(!contieneStr); // vector con datos string no implementado
		if (stringDatosC[1] == '\'') { // vector string
			vecStr = parsearVectorStrings(ini, largo);
			delete [] stringDatosC;
			return vecStr;
		}
		else { // vector int
			vecInt = parsearVectorInt(ini, largo);
			delete [] stringDatosC;
			return vecInt;
		}
	}

	assert(false); // no se reconoce el formato
	return NULL;
}

char *FrameworkA1::serializar(int i) {
	return intToStr(i);
}

char *FrameworkA1::serializar(bool b) {
	char *str;
	if (b) {
		str = copioString("true");
	}
	else {
		str = copioString("false");
	}
	return str;
}

void FrameworkA1::serializarAux(NodoListaInt *l, char *&str) {
	if (l == NULL)
		return;
	char *strNum = FrameworkA1::serializar(l->dato);
	concat(str, strNum);
	delete [] strNum;
	if (l->sig != NULL)
		concat(str, ",");
	serializarAux(l->sig, str);
}

char *FrameworkA1::serializar(NodoListaInt *l) {
	char *str;
	if(l!=NULL){
		str = copioString("(");
		serializarAux(l, str);
		concat(str, ")");
	}else {
		str = copioString("()");
	}
	return str;
}

char *FrameworkA1::serializar(NodoABInt *a) {
	char *str;
	if(a!=NULL){
		str = abAStrAux(a);
	}else {
		str = copioString("{}");
	}
	return str;
}

char *FrameworkA1::serializar(NodoAGInt *a) {
	char *str;
	if(a!=NULL){
		str = copioString("{{");
		char *str2 = agAStrAux(a);
		char *str3 = str2;
		if (strlen(str3) > 0) str3++;
		append(str, str3);
		delete [] str2;
		append(str, "}}");
	}else {
		str = copioString("{{}}");
	}
	return str;
}

char *FrameworkA1::serializar(int *vec, int largo) {
	char *str;
	if(vec!=NULL){
		str = copioString("[");
		for(int i=0; i < largo; i++){
			char *numStr = serializar(vec[i]);
			concat(str, numStr);
			delete [] numStr;
			if (i<largo-1)
				concat(str, ",");
		}
		concat(str, "]");
	}else {
		str = copioString("[]");
	}
	return str;
}

char *FrameworkA1::serializar(char **vecStr, int largo) {
	char *str;
	if(vecStr!=NULL){
		str = copioString("[");
		for(int i=0; i < largo; i++){
			concat(str, "\'");
			concat(str, vecStr[i]);
			concat(str, "\'");
			if (i<largo-1)
				concat(str, ",");
		}
		concat(str, "]");
	}else {
		str = copioString("[]");
	}
	return str;
}
