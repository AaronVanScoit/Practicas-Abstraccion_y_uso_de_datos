#ifndef LIB_GRAFO_H
#define LIB_GRAFO_H
#include "../tipos_comunes.h"
#include <queue>
#define MAXN 10
class Grafo {
public:
    int nNodos,nAristas;
    queue<Lugar> colaNodos;
    Lugar nodosArr[MAXN];
    float matAdj[MAXN][MAXN];
    conexionNodo2Nodo aristas[MAXN*MAXN];
    Grafo();
    void enqueueNodo(Lugar l);
    Lugar dequeueNodo();
    void agregarArista(int u,int v,float w);
    void mostrar();
    void dijkstra(int origen);
    void cargar(string arch,string fmt);
    void guardarSalidas();
};
#endif
