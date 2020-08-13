#include "B.h"
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <iostream>

using namespace std;

void B::insertar_Nodo(int clave) {
	struct nodo* nuevoNodo;
	int upkey;
	enum Estado_Clave valor;
	valor = insertar(raiz, clave, &upkey, &nuevoNodo);
	
	if (valor==Duplicado)
		cout << " La clave ya esta insertada " << endl;
	if (valor == Insertado) {
		struct nodo* aux = raiz;
		raiz = malloc(sizeof(struct nodo));
		raiz->n = 1;
		raiz->arreglo_claves[0] = upkey;
		raiz->hijos[0] = aux;
		raiz->hijos[1] = nuevoNodo;
	}
}

int B::buscarPosicion(int clave, int* llave_arreglo, int n) {
	int pos = 0;
	while (pos<n && clave>llave_arreglo[pos]) {
		pos++;
	}
	return pos;
}

// metodo para imprimir arbol
void B::imprimir_Arbol(struct nodo* ptr, int espacio) {
	if (ptr!=nullptr)
	{
		int i;
		for ( i = 1; i < espacio; i++)
		{
			cout << "" << endl;
		}
		for ( i = 0; i < ptr->n; i++)
		{
			printf("\t%d", ptr->arreglo_claves[i]);
			printf("\n");
		}for ( i = 0; i < ptr->n; i++)
		{
			imprimir_Arbol(ptr->hijos[i], espacio + 10);
		}
	}
}