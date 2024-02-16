#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

enum estados{FALSE, TRUE, OK};

struct NodoE;
typedef struct NodoE * Nodo;

struct ListaE;
typedef struct ListaE * ListaEn;

//constructores
ListaEn crearLista();
Nodo crearNodo(int item, Nodo prox);

//primitivas
int insertarInicio(ListaEn lista, int item);
int insertar(ListaEn lista, int pos, int item);
int insertarFin(ListaEn lista, int item);

int eliminarInicio(ListaEn lista, int* item);
int eliminar(ListaEn lista, int pos, int* item);
int eliminarFin(ListaEn lista, int* item);

//utiles
int estaVacia(ListaEn lista);
int getElemento(ListaEn lista, int*item, int pos);
int getTamanio(ListaEn lista, int *tam);
void mostrarLista(ListaEn lista);
void ordenamientoBurbuja(ListaEn lista);
int busquedaSecuencial(ListaEn lista, int buscado);

#endif // LISTA_H_INCLUDED
