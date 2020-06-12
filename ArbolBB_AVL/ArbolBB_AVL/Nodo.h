#pragma once
#include <iostream>
#include <string>

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

