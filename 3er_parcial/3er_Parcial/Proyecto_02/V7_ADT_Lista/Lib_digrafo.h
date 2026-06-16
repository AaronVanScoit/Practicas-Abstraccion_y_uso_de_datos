#ifndef LIB_DIGRAFO_H
#define LIB_DIGRAFO_H
#include "../../tipos_comunes.h"
#include <list>
#define MAXN 10
class Digrafo {
public:
    int nNodos,nAristas;
    list<Lugar> listaNodos;
    Lugar nodosArr[MAXN];
    float matAdj[MAXN][MAXN];
    conexionNodo2Nodo aristas[MAXN*MAXN];
    Digrafo();
    void insertarNodo(Lugar l);
    void eliminarNodo(int id);
    void agregarArista(int u,int v,float w);
    void mostrar();
    void dijkstra(int origen);
    void cargar(string arch,string fmt);
    void guardarSalidas();
};
#endif
