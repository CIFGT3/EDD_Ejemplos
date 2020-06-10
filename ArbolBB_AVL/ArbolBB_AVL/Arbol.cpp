#include "Arbol.h"

void Arbol::insertarNodo(int numero) {
	Nodo* nuevo;
	nuevo = new Nodo(numero);

	if (noHayRaiz()) //quiere decir que no hay nodos creados
	{
		raiz = nuevo;
	}
	else {
		Nodo* aux;
		aux = raiz;

		while (true) {
			if (numero < aux->numero) {
				if (aux->izquierda == nullptr) {
					aux->izquierda = nuevo;
					break;
				}
				aux = aux->izquierda;
			}
			else if (numero >= aux->numero) {
				if (aux->derecha == nullptr) {
					aux->derecha = nuevo;
					break;
				}
				aux = aux->derecha;
			}
		}
	}
}


// Metodo para eliminar un nodo
bool Arbol::eliminarNodo(int numero) {
	Nodo* aux = raiz;
	Nodo* padre = raiz;

	bool esIzquierdo = true;
	while (aux->numero!=numero)
	{
		padre = aux;
		if (numero < aux->numero) //se va por la izquierda
		{
			esIzquierdo = true;
			aux = aux->izquierda;
		}
		else { // busca por la parte derecha del arbol
			esIzquierdo = false;
			aux = aux->derecha;
		}
		if (aux==nullptr)
		{
			return false;
		}
	} //
	// si encuentra al nodo sigue con lo siguiente

	if (aux->izquierda==nullptr && aux->derecha== nullptr) // es hoja o raiz
	{
		if (aux == raiz) {
			raiz = nullptr;
		}
		else if (esIzquierdo) { // si es hijo izquierdo
			padre->izquierda = nullptr;
		}
		else {
			padre->derecha = nullptr;
		}
	}
	else if (aux->derecha == nullptr) { // es hoja derecha
		if (aux == raiz) {
			raiz = aux->izquierda;
		}
		else if (esIzquierdo) {
			padre->izquierda = aux->izquierda;
		}
		else {
			padre->derecha = aux->izquierda;
		}
	}
	else if (aux->izquierda==nullptr) //es hoja izquierda
	{
		if (aux == raiz) {
			raiz = aux->derecha;
		}
		else if (esIzquierdo) {
			padre->izquierda = aux->derecha;
		}
		else {
			padre->derecha = aux->derecha;
		}
	}
	else {
		Nodo* reemplazo = obtenerNodoReemplazo(aux);
		if (aux==raiz)
		{
			raiz = reemplazo;
		}
		else if (esIzquierdo)
		{
			padre->izquierda = reemplazo;
		}
		else
		{
			padre->derecha = reemplazo;
		}
		reemplazo->izquierda = aux->izquierda;
	}
	return true;
}

// metodo para modificar
void Arbol::modificarNodo(int valor, int nuevo) {
	eliminarNodo(valor);
	insertarNodo(nuevo);
}


// metodo para obtener el nodo que devuelve el nodo que va a sustituir al que se va a eliminar
Nodo* Arbol::obtenerNodoReemplazo(Nodo* nodo) {
	Nodo* reemplazarPadre = nodo;
	Nodo* reemplazo = nodo;
	Nodo* aux = nodo->derecha;

	while (aux!=nullptr)
	{
		reemplazarPadre = reemplazo;
		reemplazo = aux;
		aux = aux->izquierda;
	}
	if (reemplazo!=nodo->derecha)
	{
		reemplazarPadre->izquierda = reemplazo->derecha;
		reemplazo->derecha = nodo->derecha;
	}
	//cout << "El nodo reemplazo es: " << reemplazo->numero<<endl;
	return reemplazo;
}

// Funcion para buscar un nodo y retornarlo si lo encuentra
Nodo* Arbol::buscar(int numero) {
	Nodo* aux = raiz;
	while (aux->numero!=numero)
	{
		if (numero < aux->numero)
		{
			aux = aux->izquierda;
		}
		else {
			aux = aux->derecha;
		}
		if (aux==nullptr)
		{
			return nullptr;
		}
	}
	return aux;
}

// Recorrido in orden
void Arbol::enOrden(Nodo* nodo) {
	if (nodo!=nullptr)
	{
		enOrden(nodo->izquierda);
		cout << " - "<<nodo->numero;
		enOrden(nodo->derecha);
	}
}

// Recorrido post orden
void Arbol::postOrden(Nodo* nodo) {
	if (nodo!=nullptr)
	{
		postOrden(nodo->izquierda);
		postOrden(nodo->derecha);
		cout << nodo->numero << " - ";
	}
}

// Recorrido en pre orden
void Arbol::preOrden(Nodo* nodo) {
	if (nodo!=nullptr)
	{
		cout << nodo->numero << " - ";
		preOrden(nodo->izquierda);
		preOrden(nodo->derecha);
	}
}

bool Arbol::noHayRaiz() {
	if (raiz==nullptr)
	{
		return true;
	}
	return false;
}

string Arbol::generarTexto(string cadena, Nodo* nodo) {
	if (nodo != nullptr)
	{
		/*if (nodo->izquierda != nullptr) {
			cadena += " " + nodo->numero + " ->m" + nodo->izquierda->numero + ";";
		}*/
		cout << nodo->numero << " - ";
		cadena += nodo->numero+" -> " ;
		preOrden(nodo->izquierda);
		preOrden(nodo->derecha);
	}
}

// metodo para crear el archivo a graficar
void Arbol::graficarArbol() {
	string nombreArchivo = "arbol.txt";
	
	fstream archivo;
	archivo.open(nombreArchivo, ios::out);

	if (archivo.fail())
	{
		cout << "NO SE PUDO CREAR EL ARCHIVO";
	}

	string titulo = "digraph G{ \n";
	string cuerpo;
	string fin = "}";
	string texto;

	

	archivo << "Hola perros";
	archivo.close();
}
/*
digraph G {
 rankdir=TB ;

 25 -> 10;
 25 -> 35;
 10 ->5;
 10 ->20;
 35->30;
 35 -> 40;
}*/