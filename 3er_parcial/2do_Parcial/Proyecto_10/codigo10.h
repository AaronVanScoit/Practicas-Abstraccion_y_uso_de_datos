#ifndef CODIGO10_H
#define CODIGO10_H
#include <iostream>
#include <fstream>
#include <string>
#define MAX 10
using namespace std;
class ColaPtrStr {
public:
    void enqueue(string val);
    string dequeue();
    string verFrente();
    void mostrar();
    bool estaVacia();
    void guardarSalidas();
};
#endif
