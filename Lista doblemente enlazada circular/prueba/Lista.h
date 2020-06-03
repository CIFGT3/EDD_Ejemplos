#pragma once
#include "Nodo.h";
class Lista
{
public:
	Nodo* Cabeza;
	Nodo* Cola;

	Lista() {
		Cabeza = nullptr;
		Cola = nullptr;
	}

	void InsertarInicio(std::string dato1, int dato2);
	void insertarFin(std::string dato1, int dato2);
	void insertarEnMedio(std::string dato1, int dato2,std::string buscar);
	Nodo* buscarNodo(std::string dato1);
	Nodo* eliminarNodo(std::string dato1);
};

