#pragma once
#include <iostream>;


class Nodo
{
public:
	Nodo* siguiente;
	Nodo* anterior;
	std::string nombre;
	int numero;

	Nodo(std::string dato1, int numero) {
		this->siguiente = nullptr;
		anterior = nullptr;
		nombre = dato1;
		this->numero = numero;
	}
};

