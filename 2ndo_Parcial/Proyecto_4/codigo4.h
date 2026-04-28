#ifndef CODIGO4_H
#define CODIGO4_H

#include <string>

struct NodoStr {
    std::string dato;
    NodoStr* siguiente;
};

class PilaPtrStr {
private:
    NodoStr* tope;
public:
    PilaPtrStr();
    ~PilaPtrStr();
    bool estaVacia();
    void push(std::string valor);
    std::string pop();
    std::string peek();
    void mostrar();
};

#endif
