#ifndef CODIGO17_H
#define CODIGO17_H
#include <iostream>
#include <fstream>
#include <deque>
using namespace std;
class FilaLib {
private:
    deque<int> fila;
public:
    void insertarFrente(int val);void insertarFinal(int val);
    int eliminarFrente();int eliminarFinal();
    int verFrente();int verFinal();
    void mostrar();bool estaVacia();void guardarSalidas();
};
#endif
