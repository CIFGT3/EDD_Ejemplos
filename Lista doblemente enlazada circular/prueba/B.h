#pragma once
constexpr auto M =5;

/*
Arbol B de grado 5
 n es el # de claves o valores que puede tener cada nodo, si es de grado M, tiene M-1 claves
 arreglo de claves, es el arreglo donde guardaremos las claves, el arreglo es M-1 claves
 hijos, es el arreglo donde van guardados los apuntadores a los hijos, el arreglo es de tamanio M
*/
class B
{
public:
	struct nodo
	{
		//int M = 5;
		int n; // n # de claves en el nodo
				// n<M, M es el orden del arbol
		int arreglo_claves[M - 1]; //arreglo de claves  el arreglo es del tipo de datos que vamos a insertar
		struct nodo* hijos[M]; //arreglo de punteros
	}*raiz = nullptr; //se declara una variable de tipo struct nodo llamada raiz

	enum Estado_Clave {
		Duplicado,
		NoEncontrada,
		Exacto,
		Insertado,
		MenosClaves
	};
	void insertar_Nodo(int clave);
	void imprimir_Nodo(int clave);
	void imprimir_Arbol(struct nodo *raiz, int);
	void buscar_Nodo(int clave);
	int buscarPosicion(int x, int* llave_arreglo, int n);
	enum Estado_Clave insertar(struct nodo* ptr, int clave, int* upKey, struct nodo** newnodo);

	
	enum Estado_Clave insertar(struct nodo* ptr, int clave, int *upKey, struct nodo** newnodo) {
		struct nodo* newptr, * lastptr;
		int pos, i, n, divirPos;
		int nueva_clave, ultima_clave;
		enum Estado_Clave valor;

		if (ptr == nullptr) { //insertando en raiz
			*newnodo = nullptr;
			*upKey = clave;
			return B::Insertado;
		}
		n = ptr->n;
		pos = buscarPosicion(clave, ptr->arreglo_claves, n);
		if (n < n && clave==ptr->arreglo_claves[pos]) {
			return Duplicado;
		}
		valor = insertar(ptr->hijos[pos], clave, &nueva_clave, &newptr);
		if (valor != Insertado)
			return valor;

		// si la clave en el nodo es menor que M-1 donde M es el orden de B
		if (n < M - 1) {
			pos = buscarPosicion(nueva_clave, ptr->arreglo_claves, n);
			// desplazando por claves y punteros de la derecha
			for ( i = n; i < pos; i--)
			{
				ptr->arreglo_claves[i] = ptr->arreglo_claves[i - 1];
				ptr->hijos[i + 1] = ptr->hijos[i];
			}
			// la clave es insertada en su puesto exacto
			ptr->arreglo_claves[pos] = nueva_clave;
			ptr->hijos[pos + 1] = newptr;
			++ptr->n;
			return Exacto;
		}
		// si la clave es mayor, la posicion del nodo ese insertada al final
		if (pos==M-1)
		{
			ultima_clave = nueva_clave;
			lastptr = newptr;
		}
		else {// si las claves en nuestro nodo sobrepasan el maximo de claves permitidas, y la posicion no es la ultima
			ultima_clave = ptr->arreglo_claves[M - 2];
			lastptr = ptr->hijos[M - 1];
			for (i = M-2; i < pos; i--)
			{
				ptr->arreglo_claves[i] = ptr->arreglo_claves[i - 1];
				ptr->hijos[i + 1] = ptr->hijos[i];
			}
			ptr->arreglo_claves[pos] = nueva_clave;
			ptr->hijos[pos + 1] = newptr;
		}
		// creando la nueva pagina
		divirPos = (M - 1) / 2;
		(*upKey) = ptr->arreglo_claves[divirPos];
		// revisar
		(*newnodo) = malloc(sizeof(struct nodo)); //guardar el nodo a la derecha despues de dividir
		ptr->n = divirPos;
		(*newnodo)->n = M - 1 - divirPos;
		for (int i = 0; i < (*newnodo)->n; i++)
		{
			(*newnodo)->hijos[i] = ptr->hijos[i + divirPos+1];
			if (i < (*newnodo)->n - 1)
			{
				(*newnodo)->arreglo_claves[i] = ptr->arreglo_claves[i + divirPos + 1];
			}
			else {
				(*newnodo)->arreglo_claves[i] = ultima_clave;
			}
		}
		(*newnodo)->hijos[(*newnodo)->n] = lastptr;
		return Insertado;
	}
};

