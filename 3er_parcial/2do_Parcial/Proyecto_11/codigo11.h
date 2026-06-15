#ifndef CODIGO11_H
#define CODIGO11_H
#include <iostream>
#include <fstream>
#include <string>
#define MAX 10
using namespace std;
class ColaLib {
public:
    void enqueue(int val);
    int dequeue();
    int verFrente();
    void mostrar();
    bool estaVacia();
    void guardarSalidas();
};
#endif
