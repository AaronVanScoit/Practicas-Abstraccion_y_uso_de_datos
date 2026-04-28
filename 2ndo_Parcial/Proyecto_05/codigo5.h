#ifndef CODIGO5_H
#define CODIGO5_H

#include <stack>

class PilaLib {
private:
    std::stack<int> pila;
public:
    bool estaVacia();
    void push(int valor);
    int pop();
    int peek();
    void mostrar();
};

#endif
