#include <iostream>
#include "lista.h"

using namespace std;

int main()
{
    ListaEn lista = crearLista();
    int buscado = 0;

    insertarInicio(lista, 65);
    insertarInicio(lista, 5);
    insertarInicio(lista, 85);
    insertarInicio(lista, 98);
    insertarFin(lista, 75);

    mostrarLista(lista);
    cout << "ingrese un numero" << endl;
    cin >> buscado;
    busquedaSecuencial(lista,buscado);
    ordenamientoBurbuja(lista);
    mostrarLista(lista);
    busquedaSecuencial(lista,buscado);

    return 0;
}
