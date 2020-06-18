#include "Matriz.h"
#include "Nodo.h"


// INSERTAR: hay 3 maneras en las que se puede insertar, al inicio de un encabezado, al final de un encabezado y en medio de nodos
void Matriz::InsertarElemento(string usuario, int numero, string empresa, string departamento) {

	Nodo* NodoUser;
	Nodo* NodoDepa;
	Nodo* NodoEmpresa;

	NodoUser = new Nodo(usuario, numero);
	//ver si existen los encabezados

	NodoDepa = buscarDepa(departamento,Cabecera);
	NodoEmpresa = buscarEmpresa(empresa, Cabecera);
	// verificar si existen los encabezados
	if (NodoEmpresa == nullptr)
		NodoEmpresa = crearEmpresa(empresa);
	if (NodoDepa == nullptr)
		NodoDepa = crearDepartamento(departamento);
	
	//Insertar en Nodo Departamento

		//Insertando al incio
	if (NodoDepa->Abajo == nullptr) { //no hay usuarios en el departamento
		NodoDepa->Abajo = NodoUser;
		NodoUser->Arriba = NodoDepa; //aqui ya se crean los enlaces y el departamento apunta al usuario y viceversa
	}
	else if (NodoEmpresa->Abajo == nullptr) { //si la empresa es el ultimo encabezado
		//insertar al final, recorrer el nodo departamento
		Nodo* aux = NodoDepa->Abajo;
		while (aux->Abajo != nullptr) {
			aux = aux->Abajo;
		}
		if (!verificarEmpresa(empresa, aux, NodoUser)) {
			aux->Abajo = NodoUser;
			NodoUser->Arriba = aux;
		}
	}//insertar en medio
	else {
		Nodo* aux = NodoDepa;
		do {
			aux = aux->Abajo;
			if (!verificarEmpresa(empresa, aux, NodoUser)) {
				Nodo* auxEmpresa = aux->Anterior;
				while (auxEmpresa->Anterior != nullptr) {
					auxEmpresa = auxEmpresa->Anterior;
				}
				// hacer recorrido hacia arriba
				while (auxEmpresa->Arriba != nullptr) {
					if (auxEmpresa->nombre == empresa) {
						NodoUser->Abajo = aux;
						NodoUser->Arriba = aux->Arriba;

						aux->Arriba->Abajo = NodoUser;
						aux->Arriba = NodoUser;
					}
					auxEmpresa = auxEmpresa->Arriba;
				}
			}
		} while (aux->Abajo != nullptr && NodoUser == nullptr);

		if (NodoUser->Arriba == nullptr && NodoUser->Adelante == nullptr) {
			aux->Abajo = NodoUser;
			NodoUser = aux;
		}
	}

	if (NodoUser->Adelante != nullptr) {
		return;
	}
	//Insertar en Nodo Empresa

		//Insertando al incio
	if (NodoEmpresa->Siguiente == nullptr) {
		NodoEmpresa->Siguiente = NodoUser;
		NodoUser->Anterior = NodoEmpresa;
	}
	else if (NodoDepa->Siguiente == nullptr) {
		Nodo* aux = NodoEmpresa->Siguiente;
		while (aux->Siguiente != nullptr) {
			aux = aux->Siguiente;
		}

		if (!verificarDepartamento(departamento, aux, NodoUser)) {
			aux->Siguiente = NodoUser;
			NodoUser->Anterior = aux;
		}
	}
	else {
		Nodo* aux = NodoEmpresa;
		do {
			aux = aux->Siguiente;
			if (!verificarDepartamento(departamento, aux, NodoUser)) {
				Nodo* auxDepa = aux->Arriba;
				while (auxDepa->Arriba != nullptr) {
					auxDepa = auxDepa->Arriba;
				}

				while (auxDepa->Anterior != nullptr) {
					if (auxDepa->nombre == departamento) {
						NodoUser->Siguiente = aux;
						NodoUser->Anterior = aux->Anterior;

						aux->Anterior->Siguiente = NodoUser;
						aux->Anterior = NodoUser;
						break;
					}
					auxDepa = auxDepa->Anterior;
				}
			}
		} while (aux->Siguiente != nullptr && NodoUser == nullptr);

		if (NodoUser->Anterior == nullptr && NodoUser->Adelante == nullptr) {
			aux->Siguiente = NodoUser;
			NodoUser->Anterior = aux;
		}
			
	}


}

// crear cabeceras, empresa y departamento
Nodo* Matriz::crearEmpresa(string empresa) {
	Nodo* empre;
	empre = new Nodo(empresa, -1);

	Nodo* aux = Cabecera;
	while (aux->Abajo != nullptr) {
		aux = aux->Abajo;
	}

	aux->Abajo = empre;
	empre->Arriba = aux;
	return empre;
}

Nodo* Matriz::crearDepartamento(string departamento) {
	Nodo* dep;
	dep = new Nodo(departamento, -1);

	Nodo* aux = Cabecera;
	while (aux->Siguiente != nullptr) {
		aux = aux->Siguiente;
	}

	aux->Siguiente = dep;
	dep->Anterior = aux;
	return dep;
}

// _---------------------------------------------------------------------------------------------------------------------------
// estos metodos buscan los nodos de las cabeceras, de departamento y de empresa y retornan el nodo que se esta buscando
Nodo* Matriz::buscarDepa(string departamento, Nodo* inicio){
	Nodo * aux = inicio;
	while (aux != nullptr) {
		if (aux->nombre == departamento) {
			return aux;
		}
		aux = aux->Siguiente;
	}
	return nullptr;
}

Nodo* Matriz::buscarEmpresa(string empresa, Nodo* inicio) {
	Nodo* aux = inicio;
	while (aux != nullptr) {
		if (aux->nombre == empresa) {
			return aux;
		}
		aux = aux->Abajo;
	}
	return nullptr;
}

//-------------------------------------------------------------------------------------------------------------------------------------
// Metodos que verifican si existe una empresa o departamento cuando ya existe un usuario asignado a alguno de los 2
// Verificar empresa, recibe el nombre de la empresa, el nodo donde se va a iniciar el recorrido y el nodo del usuario a agregar
bool Matriz::verificarEmpresa(string empresa, Nodo* inicio, Nodo* usuario) {
	//se crea un nodo auxiliar que se iguala al nodo donde se va a iniciar el recorrido
	// y se va recorriendo a su anterior hasta llegar a null, donde llega a las cabeceras de empresa
	Nodo* aux = inicio->Anterior;
	while (aux->Anterior != nullptr) {
		aux = aux->Anterior;
	}
	if (aux->nombre == empresa) { //si el nombre es la empresa, se empieza a insertar al final
		while (inicio->Atras != nullptr) {
			inicio = inicio->Atras;
		}
		inicio->Atras = usuario;
		usuario->Adelante = inicio;
		return true;
	}
	return false;
}

//
bool Matriz::verificarDepartamento(string departamento, Nodo* inicio, Nodo* usuario) {
	Nodo* aux = inicio->Arriba;
	while (aux->Arriba != nullptr) {
		aux = aux->Arriba;
	}
	if (aux->nombre == departamento) {
		while (inicio->Atras != nullptr) {
			inicio = inicio->Atras;
		}
		inicio->Atras = usuario;
		usuario->Adelante = inicio;
		return true;
	}
	return false;
}