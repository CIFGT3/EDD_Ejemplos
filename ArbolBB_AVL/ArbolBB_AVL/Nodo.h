#pragma once
#include <iostream>

class Nodo
{
public:
	int numero;
	Nodo* izquierda;
	Nodo* derecha;

	Nodo(int num) {
		numero = num;
		izquierda = nullptr;
		derecha = nullptr;
	}
};

