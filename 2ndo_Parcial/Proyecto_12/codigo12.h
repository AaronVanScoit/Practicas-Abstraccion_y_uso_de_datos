#ifndef CODIGO12_H
#define CODIGO12_H

#include <queue>
#include <string>

class ColaLibStr {
private:
    std::queue<std::string> cola;
public:
    bool estaVacia();
    void enqueue(std::string valor);
    std::string dequeue();
    std::string verFrente();
    void mostrar();
};

#endif
