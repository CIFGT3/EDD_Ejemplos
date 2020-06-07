#pragma once
#include <iostream>

class Nodo
{
public:
	Nodo* Siguiente;
	Nodo* Anterior;
	Nodo* Arriba;
	Nodo* Abajo;
	Nodo* Adelante;
	Nodo* Atras;
	std::string nombre;
	int numero;

	Nodo(std::string dato1, int dato2) {
		Siguiente = nullptr;
		Anterior = nullptr;
		Arriba = nullptr;
		Abajo = nullptr;
		Adelante = nullptr;
		Atras = nullptr;
		nombre = dato1;
		numero = dato2;
	}

};

