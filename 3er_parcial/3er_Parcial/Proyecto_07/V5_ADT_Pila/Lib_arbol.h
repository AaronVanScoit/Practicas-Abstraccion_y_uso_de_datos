#ifndef LIB_ARBOL_H
#define LIB_ARBOL_H
#include "../tipos_comunes.h"
#include <stack>
#define MAXN 10

struct NodoArbolL { Lugar dato; int izq,der,padre; };

class Arbol {
public:
    int nNodos,raiz,nAristas;
    stack<Lugar> pilaRecorrido; // ADT Pila para recorrido
    NodoArbolL nodos[MAXN];
    conexionNodo2Nodo aristas[MAXN*2];
    Arbol();
    void insertar(Lugar l);
    void recorridoPila(); // recorrido iterativo con pila
    void mostrar();
    void dijkstra(int origen);
    void cargar(string arch,string fmt);
    void guardarSalidas();
};
#endif
