#pragma once
#include "Nodo.h"
#include <iostream>
using namespace std;

class Matriz
{
public:
	Nodo* Cabecera;

	Matriz() {
		Cabecera = new Nodo("admin", 1);
	}

	void InsertarElemento(string usuario, int numero, string empresa, string departamento);
	Nodo* crearEmpresa(string empresa);
	Nodo* crearDepartamento(string departamento);
	
	Nodo* buscarEmpresa(string empresa, Nodo* inicio);
	Nodo* buscarDepa(string departamento, Nodo* inicio);

	bool verificarEmpresa(string empresa, Nodo* inicio,Nodo* usuario);
	bool verificarDepartamento(string departamento, Nodo* inicio, Nodo* usuario);
};

