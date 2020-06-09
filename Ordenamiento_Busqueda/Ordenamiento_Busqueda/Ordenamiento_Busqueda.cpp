

// Ordenamiento_Busqueda.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

void ordenarBurbuja(int a[], int size) {
    int aux;
    for (int i = 0; i < size-1; i++)
    {
        for (int j=i+1; j < size; j++)
        {
            if (a[i] > a[j]) {
                aux = a[i];
                a[i] = a[j];
                a[j] = aux;
            }
        }
    }
}

void ordenarSeleccion(int a[], int size ) {
    int menor, aux;
    int itera = 0;
    for (int i = 0; i < size-1; i++)
    {
        itera++;
        menor = i;
        for (int j = i+1; j < size; j++)
            if (a[menor] > a[j])
                menor = j;
        aux = a[i];
        a[i] = a[menor];
        a[menor] = aux;
        
    }
    std::cout << std::endl<<"iteraciones en Seleccion " << itera;
}

void ordenarInsercion(int a[], int size) {
    int aux, j;
    for ( int i = 0; i < size; i++)
    {
        j = i;
        aux = a[i];
        while (j>0 && a[j-1]>aux)
        {
            a[j] = a[j - 1];
            j--;
        }
        a[j] = aux;
    }
}

void mostrarArreglo(int a[], int size) {
    std::cout << " "<<std::endl;
    for ( int i = 0; i < size; i++)
    {
        std::cout << a[i]<<"-";
    }
}

void ordenarRapido(int a[], int primero, int ultimo) {
    int itera = 0;
    int central = (primero + ultimo) / 2;
    int pivote = a[central];
    int aux;
    int i = primero, j = ultimo;
    do {
        while (a[i] < pivote) i++;
        while (a[j] > pivote) j--;
        if (i <= j) {
            aux = a[i];
            a[i] = a[j];
            a[j] = aux;
            i++;
            j--;
            itera++;
            mostrarArreglo(a,1);
        }
    } while (i <= j);
    if (primero < j)
        ordenarRapido(a, primero, j);
    if (i < ultimo)
        ordenarRapido(a, i, ultimo);
}


int main()
{
    int a[5] = { 17,10,12,7,11 };
    mostrarArreglo(a, 5); //metodo para imprimir el arreglo sin orden
    ordenarInsercion(a, 5);
    mostrarArreglo(a, 5);
    return 0;
}

// BUSQUEDA BINARIA
/*
int ini = 0, pos = 0, itera = 0, valor = 76;
    int fin = 99;;
    //int a[fin + 1];
    int a[100];
    for (int i = 0; i <= fin; i++)
    {
        a[i] = i;
    }
    while (ini <= fin) {
        itera++;
        pos = (fin - ini) / 2 + ini;
        if (a[pos] == valor) {
            std::cout << itera << " iteraciones";
            break;
        }
        else if (valor < a[pos])
            fin = pos - 1;
        else
            ini = pos + 1;
    }
    return 0;
*/