#ifndef CODIGO09_H
#define CODIGO09_H
#include <iostream>
#include <fstream>
#include <string>
#define MAX 10
using namespace std;
class ColaPtr {
public:
    void enqueue(int val);
    int dequeue();
    int verFrente();
    void mostrar();
    bool estaVacia();
    void guardarSalidas();
};
#endif
