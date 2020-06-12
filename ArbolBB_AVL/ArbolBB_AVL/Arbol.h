#pragma once
#include <iostream>
#include <fstream>
#include "Nodo.h"
using namespace std;

class Arbol
{
public:
	Nodo* raiz;

	Arbol() {
		raiz = nullptr;
	}

	void insertarNodo(int numero);
	bool eliminarNodo(int numero);
	Nodo* obtenerNodoReemplazo(Nodo* nuevo); //metodo para obtener el Nodo que va a reemplazar a nodos que sean padres
	void modificarNodo(int valor, int nuevo);

	bool noHayRaiz(); //verifica si el arbol no tiene raiz (si esta vacio)
	Nodo* buscar(int numero); //busca un nodo y lo retorna si lo encuentra

	void recorrerParaGraficar(FILE* archivo, Nodo* cabeza, string cadena);
	void graficarArbol();
	string generarTexto(string cadena, Nodo* nodo);

	// Metodos para recorrer
	void enOrden(Nodo* nodo);
	void postOrden(Nodo* nodo);
	void preOrden(Nodo* nodo);
};

