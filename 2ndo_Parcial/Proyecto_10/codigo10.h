#ifndef CODIGO10_H
#define CODIGO10_H

#include <string>

struct NodoColaStr {
    std::string dato;
    NodoColaStr* siguiente;
};

class ColaPtrStr {
private:
    NodoColaStr* frente;
    NodoColaStr* final;
public:
    ColaPtrStr();
    ~ColaPtrStr();
    bool estaVacia();
    void enqueue(std::string valor);
    std::string dequeue();
    std::string verFrente();
    void mostrar();
};

#endif
