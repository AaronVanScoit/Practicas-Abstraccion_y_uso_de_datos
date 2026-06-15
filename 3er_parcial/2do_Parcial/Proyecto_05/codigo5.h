#ifndef CODIGO5_H
#define CODIGO5_H
#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
class PilaLib {
private:
    stack<int> pila;
public:
    void push(int val); int pop(); int peek();
    void mostrar(); bool estaVacia(); void guardarSalidas();
};
#endif
