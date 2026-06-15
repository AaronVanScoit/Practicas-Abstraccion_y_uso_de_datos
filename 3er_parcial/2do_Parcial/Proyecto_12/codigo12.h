#ifndef CODIGO12_H
#define CODIGO12_H
#include <iostream>
#include <fstream>
#include <string>
#define MAX 10
using namespace std;
class ColaLibStr {
public:
    void enqueue(string val);
    string dequeue();
    string verFrente();
    void mostrar();
    bool estaVacia();
    void guardarSalidas();
};
#endif
