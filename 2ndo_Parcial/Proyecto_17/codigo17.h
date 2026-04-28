#ifndef CODIGO17_H
#define CODIGO17_H

#include <deque>

class FilaLib {
private:
    std::deque<int> fila;
public:
    bool estaVacia();
    void insertarFrente(int valor);
    void insertarFinal(int valor);
    int eliminarFrente();
    int eliminarFinal();
    int verFrente();
    int verFinal();
    void mostrar();
};

#endif
