#include <iostream>
#include "lista.h"

struct NodoE{
    int item;
    Nodo prox;
};

struct ListaE{
    int tam;
    Nodo inicio;
};

ListaEn crearLista(){
    ListaEn l= new ListaE;

    l->tam=0;
    l->inicio=NULL;

    return l;
}
Nodo crearNodo(int item, Nodo prox){
    Nodo nodo = new NodoE;

    nodo->item = item;
    nodo->prox = prox;

    return nodo;
}

int insertarInicio(ListaEn lista, int item){

    Nodo nuevoNodo = crearNodo(item, lista->inicio);
    lista->inicio=nuevoNodo;
    lista->tam++;

    return TRUE;
}
int insertar(ListaEn lista, int pos, int item){
    Nodo nuevoNodo;
    if(pos==0){
        insertarInicio(lista, item);
    }else{
        Nodo aux;
        aux = lista->inicio;
        for(int i = 0; i < pos-1; i++){
            aux=aux->prox;
        }
        nuevoNodo = crearNodo(item,aux->prox);
        if (nuevoNodo== NULL)
            return -1;
        aux->prox=nuevoNodo;
        lista->tam++;
    }
    return OK;
}
int insertarFin(ListaEn lista, int item){
    insertar(lista, lista->tam, item);
    return TRUE;
}

int eliminarInicio(ListaEn lista, int* item){
    if(estaVacia(lista)){
        return FALSE;
    }
    Nodo aux=lista->inicio;
    *item=aux->item;
    lista->inicio=aux->prox;
    lista->tam--;

    delete(aux);
    //aux==NULL;

    return TRUE;
}
int eliminar(ListaEn lista, int pos, int* item){
    if(pos==0){
        eliminarInicio(lista, item);
    }else{
        Nodo ant=NULL;
        Nodo actual=lista->inicio;
        //hago esto para ir recorriendo y guardar el pos-1 y pos
        for(int i = 0; i < pos; i++){
            ant=actual;
            actual=actual->prox;
        }
        //aca hago del salgo del pos-1 y pos+1
        ant->prox=actual->prox;
        delete(actual);
        actual=NULL;
        lista->tam--;
    }
    return OK;
}
int eliminarFin(ListaEn lista, int* item){
    eliminar(lista, lista->tam-1, item);
    return OK;
}

int estaVacia(ListaEn lista){
   if(lista->tam==0){
    return TRUE;
   }
   return FALSE;
}
int getElemento(ListaEn lista, int*item, int pos){
    if(estaVacia(lista)){
        return FALSE;
    }
    if (pos < 0 || pos >= lista->tam){
        *item = -1;
        return -1;
    }
    if (item == NULL){
        return -1;
    }

    Nodo aux;
    aux = lista->inicio;
    for(int i=0; i< pos;i++){
        aux=aux->prox;
    }
    *item = aux->item;
    return OK;

}
int getTamanio(ListaEn lista, int *tam){
    *tam = lista->tam;
    return OK;
}

void mostrarLista(ListaEn lista){
    printf("\n");
    int tam;
    getTamanio(lista, &tam);
    for(int i = 0; i < tam; i++){
        int e;
        getElemento(lista,&e, i);
        printf("[%d]", e);
    }
    printf("\n");
}

void ordenamientoBurbuja(ListaEn lista){
    int tam;
    getTamanio(lista, &tam);

    Nodo actual;
    int auxItem;

    for(int i=0; i < tam; i++){
        actual = lista->inicio;
        for(int j=0; j < tam-1; j++){
            if(actual->item > actual->prox->item){
                auxItem = actual->item;
                actual->item =  actual->prox->item;
                actual->prox->item = auxItem;
            }
            actual = actual->prox;//para ir avanzando
        }
    }
}
int busquedaSecuencial(ListaEn lista, int buscado){
    int tam;
    int pos = 0;
    getTamanio(lista, &tam);
    Nodo inodo= lista->inicio;

    for(int i = 0; i < tam; i++){
        if(buscado == inodo->item){
            pos = i;
        }
        inodo=inodo->prox;
    }
    printf("el numero se encuentra en la posicion: %d", pos);

    return pos;
}
