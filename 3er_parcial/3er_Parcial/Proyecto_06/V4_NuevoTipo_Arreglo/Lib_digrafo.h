#ifndef LIB_DIGRAFO_H
#define LIB_DIGRAFO_H
#include "../tipos_comunes.h"
#define MAXN 10
class Digrafo {
public:
    int nNodos,nAristas;
    Lugar nodosArr[MAXN];
    float matAdj[MAXN][MAXN];
    conexionNodo2Nodo aristas[MAXN*MAXN];
    Digrafo();
    void agregarNodo(Lugar l);
    void agregarArista(int u,int v,float w);
    int buscarNodo(int id);
    void mostrar();
    void dijkstra(int origen);
    void cargar(string arch,string fmt);
    void guardarSalidas();
};
#endif
