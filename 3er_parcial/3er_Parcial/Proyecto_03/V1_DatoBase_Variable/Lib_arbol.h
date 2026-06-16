#ifndef LIB_ARBOL_H
#define LIB_ARBOL_H
#include "../../tipos_comunes.h"
#define MAXN 10

struct NodoArbol {
    int dato;
    int izq, der, padre; // indices en arreglo (-1 = nulo)
};

class Arbol {
public:
    int nNodos, raiz, nAristas;
    NodoArbol nodos[MAXN];
    conexionNodo2Nodo aristas[MAXN*2];
    Arbol();
    void insertar(int val);
    void inorden(int idx);
    void preorden(int idx);
    void posorden(int idx);
    void mostrar();
    void dijkstra(int origen);
    void cargar(string arch, string fmt);
    void guardarSalidas();
};
#endif
