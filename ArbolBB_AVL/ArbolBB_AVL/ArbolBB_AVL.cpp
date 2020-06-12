// ArbolBB_AVL.cpp : Este archio contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Arbol.h"
#include "ArbolAvl.h"
#include "NodoAvl.h"

// include stdlib.h
//para salir exit(1)
int main()
{
    
    cout << "JULIO EMILIANO CIFUENTES ZABALBA / CARNE 201801677 \n \n";
    ArbolAvl* arbolito = new ArbolAvl();
    arbolito->insertarNodoAvl(4);
    arbolito->insertarNodoAvl(100);
    arbolito->insertarNodoAvl(41);
    arbolito->insertarNodoAvl(13);
    arbolito->insertarNodoAvl(15);
    arbolito->insertarNodoAvl(67);
    arbolito->insertarNodoAvl(46);
    arbolito->insertarNodoAvl(11);
    arbolito->insertarNodoAvl(55);
    arbolito->insertarNodoAvl(21);
    arbolito->insertarNodoAvl(29);
    arbolito->insertarNodoAvl(83);
    arbolito->insertarNodoAvl(71);
    arbolito->insertarNodoAvl(22);
    arbolito->insertarNodoAvl(3);

    arbolito->preOrden(arbolito->raiz);

    arbolito->eliminarNodoAvl(3);
    arbolito->eliminarNodoAvl(46);
    arbolito->eliminarNodoAvl(100);

    arbolito->graficarArbol();




    // CREANDO ARBOL AVL Y NODOS
    /*Arbol *Ab = new Arbol();
    Ab->insertarNodo(25);
    Ab->insertarNodo(10);
    Ab->insertarNodo(35);
    Ab->insertarNodo(5);
    Ab->insertarNodo(20);
    Ab->insertarNodo(30);
    Ab->insertarNodo(40);
    cout << " Recorrido en orden" << endl;
    Ab->enOrden(Ab->raiz);
    Ab->graficarArbol();*/
    /*
    // BUSCAR
    Nodo* nuevo;
    cout <<endl<< " \nNodo a buscar: 40 \n";
    nuevo=Ab->buscar(40); 
    if (nuevo != nullptr) {
        cout << " Nodo encontrado: " << nuevo->numero<<endl<<endl;
    }
    else {
        cout << "Nodo no encontrado"<<endl;
    }

    //ELIMINAR
    cout << "Nodo a eliminar: 35" << endl;
    Ab->eliminarNodo(35);
    cout << " Recorrido en orden" << endl;
    Ab->enOrden(Ab->raiz);

    //MODIFICAR
    cout <<" \n \nNodo a modificar: 10 ---- valor nuevo: 22" << endl;
    Ab->modificarNodo(10, 22);
    cout << " Recorrido en orden" << endl;
    Ab->enOrden(Ab->raiz);

    string a = "zadfkkfkfk122";
    string b = "sdffddddasss";
    if (a<b)
    {
        cout << "a es menor";
    }
    else {
        cout << "a es mayor";
    }
    */
    


    //Ab->graficarArbol();

    //cout << " Recorrido en orden" << endl;
    //Ab->enOrden(Ab->raiz);

    //cout <<endl<<" Recorrido en post orden" << endl;
    //Ab->postOrden(Ab->raiz);

    //cout << endl<<" Recorrido en pre orden" << endl;
    //Ab->preOrden(Ab->raiz);

    //cout << endl << " Eliminando Nodos " << endl;
    //Ab->eliminarNodo(10);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
