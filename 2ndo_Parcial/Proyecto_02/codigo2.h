#ifndef CODIGO2_H
#define CODIGO2_H

#include <string>
#define MAX 100

class PilaString {
private:
    std::string datos[MAX];
    int tope;
public:
    PilaString();
    bool estaVacia();
    bool estaLlena();
    void push(std::string valor);
    std::string pop();
    std::string peek();
    void mostrar();
};

#endif
