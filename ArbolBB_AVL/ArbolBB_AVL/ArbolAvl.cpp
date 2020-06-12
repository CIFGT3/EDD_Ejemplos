#include "ArbolAvl.h"

// metodo para buscar
NodoAvl* ArbolAvl::buscarNodo(int numero, NodoAvl* raiz) {
	if (raiz==nullptr){
		return nullptr;
	}
	else if (raiz->numero==numero){
		return raiz;
	}
	else if (raiz->numero < numero) {
		return buscarNodo(numero, raiz->derecha);
	}
	else {
		return buscarNodo(numero, raiz->izquierda);
	}
}


NodoAvl* ArbolAvl::rotacionSimpleI(NodoAvl* nodo) { //rotacion simple por la izquierda
	NodoAvl* aux = nodo->derecha;
	NodoAvl* aux2 = aux->izquierda;

	// rotacion 
	aux->izquierda = nodo;
	nodo->derecha = aux2;

	// actualizar alturas  
	nodo->FE = max(obtenerFE(nodo->izquierda), obtenerFE(nodo->derecha)) + 1;
	aux->FE = max(obtenerFE(aux->izquierda), obtenerFE(aux->derecha)) + 1;

	return aux;
}

NodoAvl* ArbolAvl::rotacionSimpleD(NodoAvl* nodo) { //rotacion simple por la derecha
	NodoAvl* aux = nodo->izquierda;
	NodoAvl* aux2 = aux->derecha;

	// rotacion 
	aux->derecha = nodo;
	nodo->izquierda = aux2;

	// actualizar alturas  
	nodo->FE = max(obtenerFE(nodo->izquierda), obtenerFE(nodo->derecha)) + 1;
	aux->FE = max(obtenerFE(aux->izquierda), obtenerFE(aux->derecha)) + 1;

	return aux;
}

NodoAvl* ArbolAvl::insertar(NodoAvl* nodoR, int n) { //-------------------------------------------------------- N
	if (nodoR == nullptr) {
		nodoR = new NodoAvl(n);
		return nodoR;
	}

	if (n < nodoR->numero)
		nodoR->izquierda = insertar(nodoR->izquierda, n);
	else if (n > nodoR->numero)
		nodoR->derecha = insertar(nodoR->derecha, n);
	else // Cuando ya no es igual, retorna  
		return nodoR;

	//2. Se deben actualizar las alturas
	nodoR->FE = 1 + max(obtenerFE(nodoR->izquierda), obtenerFE(nodoR->derecha));

	// 3. Se obtiene el factor de equilibrio del nodo para ver si este de desbalanceo
	int balance = obtenerFB(nodoR);

	// Si el nodo esta desequilibrado, hay 4 casos 

	//      1. rotacion simple a la derecha
	if (balance > 1 && n < nodoR->izquierda->numero)
		return rotacionSimpleD(nodoR);

	//      2. rotacion simple a la izquierda
	if (balance < -1 && n > nodoR->derecha->numero)
		return rotacionSimpleI(nodoR);
	//      3. rotacion izquierda derecha (Doble por la izquierda)
	if (balance > 1 && n > nodoR->izquierda->numero)
	{
		nodoR->izquierda = rotacionSimpleI(nodoR->izquierda);
		return rotacionSimpleD(nodoR);
	}
	//      4. rotacion derecha izquierda (Doble por la derecha)
	if (balance < -1 && n < nodoR->derecha->numero)
	{
		nodoR->derecha = rotacionSimpleD(nodoR->derecha);
		return rotacionSimpleI(nodoR);
	}

	// retornar el nodo 
	return nodoR;
}

void ArbolAvl::insertarNodoAvl(int n) {
	this->raiz = insertar(raiz, n);
}


// Funcion para obtener el factor de balance
int ArbolAvl::obtenerFB(NodoAvl* nodo) {
	if (nodo == nullptr)
	{
		return 0;
	}
	else {
		return obtenerFE(nodo->izquierda) - obtenerFE(nodo->derecha);
	}
}

// metodo para obtener el factor de equilibrio de cada nodo
int ArbolAvl::obtenerFE(NodoAvl* nodo) {
	if (nodo==nullptr){
		return 0;
	}
	else {
		return nodo->FE;
	}
}


void ArbolAvl::eliminarNodoAvl(int n) {
	this->raiz = eliminarNodo(raiz, n);
}

// Metodo para eliminar un nodo
NodoAvl* ArbolAvl::eliminarNodo(NodoAvl* nodo,int n) {
	// 1 eliminar nodo
	if (nodo == nullptr)
		return nodo;
	// Si el id es menor que la raiz, se va hacia el lado izquierdo
	if (n < nodo->numero)
		nodo->izquierda = eliminarNodo(nodo->izquierda, n);
	// Si el id es mayor que la raiz, se va hacia el lado derecho
	else if (n > nodo->numero)
		nodo->derecha = eliminarNodo(nodo->derecha, n);
	// De lo contrario es porque es igual, entonces se procede a eliminar el nodo
	else
	{
		// si el nodo tiene un hijo o si es hoja  
		if (nodo->izquierda == nullptr || nodo->derecha == nullptr)
		{
			NodoAvl* aux = nodo->izquierda ? nodo->izquierda : nodo->derecha; //si el izquierda existe, se le asigna
																			  //de lo contrario se asigna el derecho
			// Si es hoja  
			if (aux == nullptr)
			{
				aux = nodo;
				nodo = nullptr;
			}
			else //si tiene un hijo
				*nodo = *aux; // Copy the contents of  
							   // the non-empty child  
			free(aux);
		}
		else
		{   // Nodo con 2 hijos, se obtiene el menor de su derecha
			NodoAvl* temp = obtenerMenor(nodo->derecha);
			nodo->numero = temp->numero;

			// Delete the inorder successor  
			nodo->derecha = eliminarNodo(nodo->derecha, temp->numero);
		}
	}
	// Si el arbol solo tiene un nodo
	if (nodo == nullptr)
		return nodo;

	// 2. Actualizar las alturas de los nodos  
	nodo->FE = 1 + max(obtenerFE(nodo->izquierda), obtenerFE(nodo->derecha));
	// 3. Obtener el factor de equilibrio del nodo para ver donde esta desequilibrado
	int balance = obtenerFB(nodo);

	// Si el nodo esta desequilibrado, hay 4 casos 

	// rotacion por la izquierda 
	if (balance > 1 && obtenerFB(nodo->izquierda) >= 0)
		return rotacionSimpleD(nodo);
	// doble por la izquierda
	if (balance > 1 && obtenerFB(nodo->izquierda) < 0)
	{
		nodo->izquierda = rotacionSimpleI(nodo->izquierda);
		return rotacionSimpleD(nodo);
	}
	// simple por la derecha  
	if (balance < -1 && obtenerFB(nodo->derecha) <= 0)
		return rotacionSimpleI(nodo);
	// doble por la derecha 
	if (balance < -1 && obtenerFB(nodo->derecha) > 0)
	{
		nodo->derecha = rotacionSimpleD(nodo->derecha);
		return rotacionSimpleI(nodo);
	}

	return nodo;
}

NodoAvl* ArbolAvl::obtenerMenor(NodoAvl* nodo) {
	NodoAvl* actual = nodo;

	while (actual->izquierda != nullptr)
		actual = actual->izquierda;

	return actual;
}


// metodo que devuelve el numero mayor
int ArbolAvl::max(int num1, int num2) {
	if (num1>num2)
	{
		return num1;
	}
	else {
		return num2;
	}
}

//recorridos
void ArbolAvl::enOrden(NodoAvl* nodo) {
	if (nodo != nullptr)
	{
		enOrden(nodo->izquierda);
		cout << " - " << nodo->numero;
		enOrden(nodo->derecha);
	}
}

// Recorrido post orden
void ArbolAvl::postOrden(NodoAvl* nodo) {
	if (nodo != nullptr)
	{
		postOrden(nodo->izquierda);
		postOrden(nodo->derecha);
		cout << nodo->numero << " - ";
	}
}

// Recorrido en pre orden
void ArbolAvl::preOrden(NodoAvl* nodo) {
	if (nodo != nullptr)
	{
		cout << nodo->numero << " - ";
		preOrden(nodo->izquierda);
		preOrden(nodo->derecha);
	}
}

//Metodo para crear las lineas que grafiquen el arbol avl
void ArbolAvl::recorrerParaGraficar(FILE* file, NodoAvl* nodo, string cadena) {
	if (nodo != nullptr)
	{
		if (nodo->izquierda != nullptr) {
			//cout << "entra al nodo izquierda " << nodo->numero;
			//cadena= nodo->activo.id + " [label=\"" + nodo->activo. + "\"]; \n";
			cadena = " " + to_string(nodo->numero) + " -> " + to_string(nodo->izquierda->numero) + " ; \n";
			fprintf(file, cadena.c_str());
		}
		if (nodo->derecha != nullptr) {
			//cout << " entra al nodo derecha " << nodo->numero;
			cadena = " " + to_string(nodo->numero) + " -> " + to_string(nodo->derecha->numero) + " ; \n";
			fprintf(file, cadena.c_str());
		}
		recorrerParaGraficar(file, nodo->izquierda, cadena);
		recorrerParaGraficar(file, nodo->derecha, cadena);
	}
}

void ArbolAvl::graficarArbol() {

	FILE* file;
	string cuerpo = "";
	file = fopen("arbolAvl.txt", "w+");
	fprintf(file, "digraph G{ \n rankdir=TB; \n");
	recorrerParaGraficar(file, this->raiz, cuerpo);
	fprintf(file, "}");
	fclose(file);

	system("dot -Tpng arbolAvl.txt -o arbol.png");
}