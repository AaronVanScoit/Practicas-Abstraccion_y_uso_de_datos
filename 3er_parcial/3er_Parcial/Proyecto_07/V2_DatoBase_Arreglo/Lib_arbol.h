#ifndef LIB_ARBOL_H
#define LIB_ARBOL_H
#include "../tipos_comunes.h"
#define MAXN 15

class Arbol {
public:
    int datos[MAXN]; // arreglo representacion heap
    bool existe[MAXN];
    int nNodos, nAristas;
    conexionNodo2Nodo aristas[MAXN*2];
    Arbol();
    void insertar(int idx, int val);
    void inorden(int idx);
    void preorden(int idx);
    void posorden(int idx);
    void mostrar();
    void dijkstra(int origen);
    void cargar(string arch, string fmt);
    void guardarSalidas();
};
#endif
