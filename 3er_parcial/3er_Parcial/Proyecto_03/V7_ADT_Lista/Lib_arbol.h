#ifndef LIB_ARBOL_H
#define LIB_ARBOL_H
#include "../tipos_comunes.h"
#include <list>
#define MAXN 10
struct NodoArbolL{Lugar dato;int izq,der,padre;};
class Arbol {
public:
    int nNodos,raiz,nAristas;
    list<Lugar> listaRecorrido; // ADT Lista para almacenar recorrido
    NodoArbolL nodos[MAXN];
    conexionNodo2Nodo aristas[MAXN*2];
    Arbol();
    void insertar(Lugar l);
    void inordenLista(int idx); // recorrido que llena la lista
    void mostrar();
    void dijkstra(int origen);
    void cargar(string arch,string fmt);
    void guardarSalidas();
};
#endif
