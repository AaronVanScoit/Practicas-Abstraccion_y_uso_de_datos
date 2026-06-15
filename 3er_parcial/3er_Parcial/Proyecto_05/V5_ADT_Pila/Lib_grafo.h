#ifndef LIB_GRAFO_H
#define LIB_GRAFO_H
#include "../tipos_comunes.h"
#include <stack>
#define MAXN 10
class Grafo {
public:
    int nNodos, nAristas;
    stack<Lugar> pilaNodos;     // ADT: Pila de nodos Lugar
    Lugar nodosArr[MAXN];
    float matAdj[MAXN][MAXN];
    conexionNodo2Nodo aristas[MAXN*MAXN];
    Grafo();
    void pushNodo(Lugar l);
    Lugar popNodo();
    void agregarArista(int u,int v,float w);
    void mostrar();
    void dijkstra(int origen);
    void cargar(string arch,string fmt);
    void guardarSalidas();
};
#endif
