#ifndef LIB_GRAFO_H
#define LIB_GRAFO_H
#include "../tipos_comunes.h"
#define MAXN 10
class Grafo {
public:
    int nNodos, nAristas;
    Lugar nodo;   // variable de tipo Lugar (un solo nodo activo)
    float matAdj[MAXN][MAXN];
    Lugar nodosLista[MAXN];
    conexionNodo2Nodo aristas[MAXN*MAXN];
    Grafo();
    void agregarNodo(Lugar l);
    void agregarArista(int u,int v,float w,string nombre,float t);
    void mostrar();
    void dijkstra(int origen);
    void cargar(string arch,string fmt);
    void guardarSalidas();
};
#endif
