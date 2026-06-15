#ifndef CODIGO08_H
#define CODIGO08_H
#include <iostream>
#include <fstream>
#include <string>
#define MAX 10
using namespace std;
class ColaStr {
public:
    void enqueue(string val);
    string dequeue();
    string verFrente();
    void mostrar();
    bool estaVacia();
    void guardarSalidas();
};
#endif
