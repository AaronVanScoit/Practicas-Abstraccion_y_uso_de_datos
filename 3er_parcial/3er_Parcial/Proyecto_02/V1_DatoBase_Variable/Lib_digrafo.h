#ifndef LIB_DIGRAFO_H
#define LIB_DIGRAFO_H
#include "../tipos_comunes.h"
#define MAXN 10
class Digrafo {
public:
    int nNodos, nAristas;
    int matAdj[MAXN][MAXN]; // DIRIGIDO: [u][v] != [v][u]
    conexionNodo2Nodo aristas[MAXN*MAXN];
    Digrafo();
    void agregarArista(int u, int v, float w); // solo u->v
    void mostrar();
    void dijkstra(int origen);
    void cargar(string arch, string fmt);
    void guardarSalidas();
};
#endif
