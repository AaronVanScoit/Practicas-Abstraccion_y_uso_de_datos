#ifndef CODIGO11_H
#define CODIGO11_H

#include <queue>

class ColaLib {
private:
    std::queue<int> cola;
public:
    bool estaVacia();
    void enqueue(int valor);
    int dequeue();
    int verFrente();
    void mostrar();
};

#endif
