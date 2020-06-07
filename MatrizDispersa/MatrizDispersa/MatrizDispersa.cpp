// MatrizDispersa.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Matriz.h"

int main()
{
    std::cout << "Hello World!\n";
    Matriz* miObjeto = new Matriz();
    
    miObjeto->InsertarElemento("mynor", 1, "max", "Guatemala");
    miObjeto->InsertarElemento("susan", 2, "hp", "jutiapa");
    miObjeto->InsertarElemento("susel", 3, "hp", "jalapa");
    miObjeto->InsertarElemento("roxana", 4, "walmart", "jalapa");
    miObjeto->InsertarElemento("andrea", 5, "walmart", "jalapa");
    miObjeto->InsertarElemento("sebas", 6, "walmart", "jalapa");
    miObjeto->InsertarElemento("andres", 7, "hp", "Guatemala");
    miObjeto->InsertarElemento("willy", 8, "max", "jalapa");
    miObjeto->InsertarElemento("mynor", 9, "walmart", "Guatemala");
}