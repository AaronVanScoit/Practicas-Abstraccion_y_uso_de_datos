#ifndef CODIGO6_H
#define CODIGO6_H

#include <stack>
#include <string>

class PilaLibStr {
private:
    std::stack<std::string> pila;
public:
    bool estaVacia();
    void push(std::string valor);
    std::string pop();
    std::string peek();
    void mostrar();
};

#endif
