#ifndef LIB_ARBOL_H
#define LIB_ARBOL_H
#include "../../tipos_comunes.h"
#define MAXN 10

struct NodoArbolL {
    Lugar dato;
    int izq, der, padre;
};

class Arbol {
public:
    int nNodos, raiz, nAristas;
    Lugar nodo; // variable de tipo Lugar
    NodoArbolL nodos[MAXN];
    conexionNodo2Nodo aristas[MAXN*2];
    Arbol();
    void insertar(Lugar l);
    void inorden(int idx);
    void preorden(int idx);
    void posorden(int idx);
    void mostrar();
    void dijkstra(int origen);
    void cargar(string arch, string fmt);
    void guardarSalidas();
};
#endif
