#ifndef CODIGO6_H
#define CODIGO6_H
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
using namespace std;
class PilaLibStr {
private:
    stack<string> pila;
public:
    void push(string val); string pop(); string peek();
    void mostrar(); bool estaVacia(); void guardarSalidas();
};
#endif
