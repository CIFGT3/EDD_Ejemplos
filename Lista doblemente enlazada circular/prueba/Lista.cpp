#include "Lista.h"
#include "Nodo.h"
#include <iostream>

using namespace std;

void Lista::InsertarInicio(string dato1, int dato2) {
	//paso1
	Nodo* nuevo;
	nuevo = new Nodo(dato1, dato2);

	//paso2
	if (Cabeza == nullptr) {
		nuevo->siguiente = nuevo;
		nuevo->anterior = nuevo;

		Cola = nuevo;
	}
	else {
		nuevo->siguiente = Cabeza; //circular
		nuevo->anterior = Cola;	//circular
		Cola->siguiente = nuevo;	//enlaces lineales
		Cabeza->anterior = nuevo;	//enlaces lineales
	}

	//paso 3
	Cabeza = nuevo;
}

void Lista::insertarFin(string dato1, int dato2) {
	//paso 1
	Nodo* nuevo;
	nuevo = new Nodo(dato1, dato2);

	//paso 2, cambios de enlaces
	if (Cabeza = nullptr) {
		nuevo->siguiente = nuevo;
		nuevo->anterior = nuevo;
		Cabeza = nuevo;
	}
	else {
		nuevo->siguiente = Cabeza;
		nuevo->anterior = Cola;

		Cola->siguiente = nuevo;
		Cabeza->anterior = nuevo;
	}

	//paso3
	Cola = nuevo;
}

Nodo* Lista::buscarNodo(string dato1) {
	if (Cabeza != nullptr) {
		Nodo* aux = Cabeza;

		do {
			if (aux->nombre == dato1) {
				//paso3
				return aux;
			}

			//paso1
			aux = aux->siguiente;
		} while (aux != Cabeza);

		//paso1
		/*while (aux != Cola) {
			if (aux->nombre == dato1) {
				//paso3
				return aux;
			}

			//paso1
			aux = aux->siguiente;
		}
		aux = Cola;
		if (aux->nombre == dato1) {
			return aux;
		} */

		cout << "\n Dato no Encontrado";
	}
	cout << "\n Lista Vac�a";
}

Nodo* Lista::eliminarNodo(string dato1) {
	Nodo* aux = buscarNodo(dato1);
	if (aux->siguiente == nullptr) {
		return aux;
	}

	//paso2
	aux->siguiente->anterior = aux->anterior;
	aux->anterior->siguiente = aux->siguiente; //el nodo a eliminar es el aux

	if (aux == Cabeza) {
		Cabeza = aux->siguiente;
	}
	if (aux == Cola) {
		Cola == aux->anterior;
	}

	return aux;
}

void Lista::insertarEnMedio(string dato1, int dato2, string buscar) {
	//paso1
	Nodo* nuevo;
	nuevo = new Nodo(dato1, dato2);

	//paso 2
	Nodo* aux = buscarNodo(buscar);
	
	if (aux->siguiente == nullptr) {
		return;
	}

	//paso2
	nuevo->siguiente = aux->siguiente;
	nuevo->anterior = aux;

	//paso3
	aux->siguiente->anterior = nuevo;
	aux->siguiente = nuevo;

	if (aux->siguiente == Cola) {
		Cola = nuevo;
	}
}