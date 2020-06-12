#pragma once
class NodoAvl
{
public:
	int numero, FE;
	NodoAvl* izquierda;
	NodoAvl* derecha;

	NodoAvl(int numero) {
		this->numero = numero;
		this->FE = 0;
		izquierda = nullptr;
		derecha = nullptr;
	}
};

