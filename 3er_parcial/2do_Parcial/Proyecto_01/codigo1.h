#ifndef CODIGO1_H
#define CODIGO1_H

#include <iostream>
#include <fstream>
#include <string>
#define MAX 10
using namespace std;
class Pila {
private:
    int datos[MAX];
    int tope;
public:
    Pila();
    void push(int val);
    int pop();
    int peek();
    void mostrar();
    bool estaLlena();
    bool estaVacia();
    void guardarSalidas();
};
#endif
