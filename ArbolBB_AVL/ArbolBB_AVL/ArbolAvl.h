#pragma once
#include <iostream>
#include <string>
#include "NodoAvl.h"
using namespace std;

class ArbolAvl
{
public:

	NodoAvl* raiz;
	
	ArbolAvl() {
		raiz = nullptr;
	}

	NodoAvl* insertar(NodoAvl* nodo, int n); //-------------------------------------------------------- N
	void insertarNodoAvl(int n); //------------------------------------------------------------------- N
	int obtenerFB(NodoAvl* nodo);

	NodoAvl* eliminarNodo(NodoAvl* nodo, int n); // eliminar un nodo
	void eliminarNodoAvl(int n);
	NodoAvl* obtenerMenor(NodoAvl* nodo);

	NodoAvl* buscarNodo(int dato, NodoAvl* raiz);

	int obtenerFE(NodoAvl* nodo);
	NodoAvl* rotacionSimpleI(NodoAvl* nodo); //rotacion simple por la izquierda
	NodoAvl* rotacionSimpleD(NodoAvl* nodo); //rotacion simple por la derecha

	void enOrden(NodoAvl* nodo);
	void postOrden(NodoAvl* nodo);
	void preOrden(NodoAvl* nodo);

	int max(int num1, int num2);

	void recorrerParaGraficar(FILE* file, NodoAvl* nodo, string cadena);
	void graficarArbol();

	//-----------------------------------------------------------------------------------------------------------------

};

